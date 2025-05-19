#include "interface.h"

#define WIDTH 54

int utf8_char_length(const char* str) {
    int length = 0;
    while (*str) {
        // Kiểm tra byte đầu tiên của ký tự UTF-8
        if ((*str & 0xC0) != 0x80) {
            length++;  // Đếm khi không phải byte tiếp theo (10xxxxxx)
        }
        str++;
    }
    return length;
}

void inThongBao(const char* format, ...) {
    char message[256];  // Chuỗi để chứa kết quả format

    // Lấy các tham số không cố định
    va_list args;
    va_start(args, format);
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    int len = utf8_char_length(message);
    int padding = WIDTH - 4 - len;

    // In khung trên
    printf("╔");
    for (int i = 0; i < WIDTH - 2; i++) printf("═");
    printf("╗\n");

    // In thông báo đã format
    printf("║ %s", message);
    for (int i = 0; i < padding; i++) printf(" ");
    printf(" ║\n");

    // In khung dưới
    printf("╚");
    for (int i = 0; i < WIDTH - 2; i++) printf("═");
    printf("╝\n");
}

void inDongGiua(const char* noiDung) {
    int len = utf8_char_length(noiDung);
    int padding = (WIDTH - 2 - len) / 2;
    printf("║%*s%s%*s║\n", padding, "", noiDung, padding + ((WIDTH - len) % 2), "");
}

// Giao diện chính
void interface_main(void) {
    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua("HỆ THỐNG QUẢN LÝ NHÀ HÀNG");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║ 1. Thêm hoá đơn                   4. Menu          ║\n");
    printf("║ 2. Sửa hoá đơn                    5. Sơ đồ quán    ║\n");
    printf("║ 3. Thanh toán                     6. Data          ║\n");
    printf("║                  7. Đăng xuất                      ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
    printf("Nhập lựa chọn: ");
}

// Giao diện đăng nhập
void interface_0(void) {
    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua("HỆ THỐNG QUẢN LÝ NHÀ HÀNG");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║     1. Đăng nhập                   2. Thoát        ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
    printf("Nhập lựa chọn: ");
}

// Giao diện sửa hóa đơn
void interface_sua_hoa_don(int table_id) {
    char tieuDe[50];
    sprintf(tieuDe, "SỬA HOÁ ĐƠN BÀN %d", table_id);

    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua(tieuDe);
    printf("╠════════════════════════════════════════════════════╣\n");
    inDongGiua("1. Thêm món");
    inDongGiua("2. Xóa món");
    inDongGiua("3. Sửa số lượng món");
    inDongGiua("4. Thoát");
    printf("╚════════════════════════════════════════════════════╝\n");
    printf("Nhập lựa chọn: ");
}

void inMenu(struct Menu* menu) {
    struct Menu* current = menu->next;
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                       MENU                         ║\n");
    printf("╠════════════════════════════════════════════════════╣\n");
    while (current != NULL) {
        printf("║ %-41s %8d ║\n", current->name, current->price);
        current = current->next;
    }
}

void interface_menu(void) {
    printf("║ 1. Thêm món vào menu                               ║\n");
    printf("║ 2. Sửa giá món ăn                                  ║\n");
    printf("║ 3. Xóa món ăn khỏi menu                            ║\n");
    printf("║ 4. Thoát.                                          ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
}

void inDongCanTrai(const char* text) {
    int width = WIDTH - 4;  // Trừ đi 2 viền (2 ký tự) và 2 khoảng trắng hai bên
    char line[WIDTH * 4];   // Buffer với kích thước lớn hơn để xử lý UTF-8 (mỗi ký tự tối đa 4 byte)
    line[0] = '\0';         // Khởi tạo chuỗi rỗng
    int line_visible_len = 0;  // Độ dài hiển thị (số ký tự thực sự)
    
    // Tạo bản sao vì strtok() thay đổi chuỗi
    char temp[1000];
    strcpy(temp, text);
    
    // Tách từng từ
    const char* delim = " ";
    char* word = strtok(temp, delim);
    
    while (word != NULL) {
        int word_visible_len = utf8_char_length(word);
        int space_needed = (line_visible_len > 0) ? 1 : 0;  // Cần thêm dấu cách nếu không phải từ đầu dòng
        
        // Nếu thêm từ mới sẽ vượt quá độ rộng dòng, in dòng hiện tại và bắt đầu dòng mới
        if (line_visible_len + word_visible_len + space_needed > width) {
            // Thêm khoảng trắng vào cuối dòng để đạt đủ độ rộng
            int spaces_to_add = width - line_visible_len;
            for (int i = 0; i < spaces_to_add; i++) {
                strcat(line, " ");
            }
            
            // In dòng đã đầy
            printf("║ %s ║\n", line);
            
            // Bắt đầu dòng mới với từ hiện tại
            strcpy(line, word);
            line_visible_len = word_visible_len;
        } else {
            // Thêm khoảng trắng nếu không phải từ đầu tiên trong dòng
            if (line_visible_len > 0) {
                strcat(line, " ");
                line_visible_len++;
            }
            strcat(line, word);
            line_visible_len += word_visible_len;
        }
        
        // Lấy từ tiếp theo
        word = strtok(NULL, delim);
    }
    
    // In dòng cuối cùng còn sót lại
    if (line_visible_len > 0) {
        // Thêm khoảng trắng vào cuối dòng để đạt đủ độ rộng
        int spaces_to_add = width - line_visible_len;
        for (int i = 0; i < spaces_to_add; i++) {
            strcat(line, " ");
        }
        printf("║ %s ║\n", line);
    }
}

void inKhungGoiY(char* reason, char* result) {
    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua("GỢI Ý GỌI MÓN");
    printf("╠════════════════════════════════════════════════════╣\n");
    
    // In lý do (tự động xuống dòng nếu quá 50 ký tự)
    inDongCanTrai(reason);

    // In kết quả (gợi ý món)
    char dish[100];
    snprintf(dish, sizeof(dish), "Món gợi ý: %s", result);
    inDongCanTrai(dish);

    printf("╚════════════════════════════════════════════════════╝\n");
}

void interface_quan_ly(void) {
    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua("CHỨC NĂNG QUẢN LÝ");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║ 1. Dữ liệu thống kê                                ║\n");
    printf("║ 2. Quản lý nhân viên                               ║\n");
    printf("║ 3. Quản lý hoá đơn                                 ║\n");
    printf("║ 4. Thoát.                                          ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");
    printf("Nhập lựa chọn: ");
}
