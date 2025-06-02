#include "2_chuc_nang_sua_hoa_don.h"

void display_dish_list(struct Bill* bill) {
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║ Danh sách món trong hóa đơn                          ║\n");
    printf("║ %-45s %-10s ║\n", "Tên món", "Số lượng");
    printf("╠══════════════════════════════════════════════════════╣\n");
    struct Dish_ordered* dish = bill->listDish->next;
    while (dish != NULL) {
        printf("║ %-42s ║    %-4d ║\n", dish->name, dish->quantity);
        dish = dish->next;
    }
    printf("╚══════════════════════════════════════════════════════╝\n");
}

void chuc_nang_sua_hoa_don(struct Table* restaurant, struct Menu* menu, struct Top_seller* top_seller) {
    int table_id = 0;
    struct Table* table = NULL;
    do {
        printf("Chỉnh sửa hoá đơn ở bàn số: ");
        nhap_so_nguyen(&table_id);
        if (table_id == 0) {
            inThongBao("Đã hủy chỉnh sửa hóa đơn.");
            return;
        }
        table = search_table(restaurant, table_id);
        if (table == NULL) {
            inThongBao("Bàn số %d không tồn tại, vui lòng nhập lại!", table_id);
        } else if (table->status == 0 || table->bill == NULL) {
            inThongBao("Bàn số %d chưa có hoá đơn. (nhập 0 để thoát)", table_id);
            table = NULL;
        }
    } while (table == NULL);

    int choice;
    char dishName[100];
    int quantity;
    struct Bill* bill = table->bill;

    while (1) {
        interface_sua_hoa_don(table_id);
        nhap_so_nguyen(&choice);

        switch (choice) {
            case 1: // Thêm món
                order_dish(table, menu, bill, top_seller);
                inThongBao("Thêm món thành công!");
                break;
            case 2: // Xóa món
                display_dish_list(bill);
                printf("Nhập tên món cần xóa (hoặc '0' để thoát): ");
                scanf(" %[^\n]", dishName);
                if (strcmp(dishName, "0") == 0) {
                    inThongBao("Đã hủy xóa món.");
                    break;
                }

                struct Dish_ordered* prev = NULL;
                struct Dish_ordered* current = bill->listDish;
                int found = 0;
                while (current != NULL) {
                    if (strcmp(current->name, dishName) == 0) {
                        found = 1;
                        if (prev == NULL) {
                            bill->listDish = current->next;
                        } else {
                            prev->next = current->next;
                        }
                        free(current);
                        inThongBao("Xóa món %s thành công!", dishName);
                        break;
                    }
                    prev = current;
                    current = current->next;
                }
                if (!found) {
                    inThongBao("Món %s không tồn tại trong hóa đơn!", dishName);
                }
                break;
            case 3: // Sửa số lượng món
                if (bill->listDish == NULL) {
                    inThongBao("Hóa đơn không có món để sửa!");
                    break;
                }
                display_dish_list(bill);
                printf("Nhập tên món cần sửa số lượng (hoặc '0' để thoát): ");
                scanf(" %[^\n]", dishName);
                if (strcmp(dishName, "0") == 0) {
                    inThongBao("Đã hủy sửa số lượng.");
                    break;
                }

                // Tìm món
                current = bill->listDish;
                found = 0;
                while (current != NULL) {
                    if (strcmp(current->name, dishName) == 0) {
                        found = 1;
                        printf("Nhập số lượng mới cho món %s: ", dishName);
                        nhap_so_nguyen(&quantity);
                        if (quantity <= 0) {
                            inThongBao("Số lượng phải lớn hơn 0!");
                            break;
                        }
                        current->quantity = quantity;
                        inThongBao("Sửa số lượng món %s thành công!", dishName);
                        break;
                    }
                    current = current->next;
                }
                if (!found) {
                    inThongBao("Món %s không tồn tại trong hóa đơn!", dishName);
                }
                break;
            case 4: // Thoát
                inThongBao("Đã thoát chỉnh sửa hóa đơn.");
                return;
            default:
                inThongBao("Lựa chọn không hợp lệ, vui lòng nhập lại!");
                break;
        }
    }
}
