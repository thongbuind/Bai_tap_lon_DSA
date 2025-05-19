#include "4_chuc_nang_menu.h"

void chuc_nang_menu(struct Menu* menu) {
    // hiển thị toàn bộ menu kèm giá tiền dưới dạng bảng có khung 54
    // sau khi in ra menu, hiển thị 4 sự lựa chọn: thêm món vào menu, sửa giá món ăn, xoá món ăn khỏi menu, thoát
    // sử dụng vòng lặp và hàm nhập để nhập sự lựa chọn đến khi hợp lệ
    // dùng switch case để thực hiện 4 chức năng
    // In tiêu đề menu
    int choice;

    inMenu(menu);
    printf("╠════════════════════════════════════════════════════╣\n");
    interface_menu();
    
    while (1) {
        printf("Nhập lựa chọn: ");
        nhap_so_nguyen(&choice);
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
            break;
        }
        inThongBao("Lựa chọn không hợp lệ, vui lòng nhập lại!");
    }
    if (choice == 4) {
        return;
    }
    switch (choice) {
        case 1:
            them_mon_vao_menu(menu);
            break;
        case 2:
            sua_gia_mon_an(menu);
            break;
        case 3:
            xoa_mon_an_khoi_menu(menu);
            break;
        default:
            printf("❌ Lựa chọn không hợp lệ!\n");
    }
}
