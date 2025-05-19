#include "5_chuc_nang_xem_so_do_quan.h"

void chuc_nang_xem_so_do_quan(struct Table* restaurant, struct Menu* menu) {
    int choice, table_id;
    struct Table* table;

    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║                 SƠ ĐỒ QUÁN (10 BÀN)                ║\n");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║ ╔════════════╗   ╔════════════╗    ╔════════════╗  ║\n");
    printf("║ ║ B1 [%s] ║   ║ B2 [%s] ║    ║ B3 [%s] ║  ║\n",
           search_table(restaurant, 1)->status ? "Khách" : "Trống",
           search_table(restaurant, 2)->status ? "Khách" : "Trống",
           search_table(restaurant, 3)->status ? "Khách" : "Trống");
    printf("║ ╚════════════╝   ╚════════════╝    ╚════════════╝  ║ \n");
    printf("║ ╔════════════╗   ╔════════════╗    ╔════════════╗  ║\n");
    printf("║ ║ B4 [%s] ║   ║ B5 [%s] ║    ║ B6 [%s] ║  ║\n",
           search_table(restaurant, 4)->status ? "Khách" : "Trống",
           search_table(restaurant, 5)->status ? "Khách" : "Trống",
           search_table(restaurant, 6)->status ? "Khách" : "Trống");
    printf("║ ╚════════════╝   ╚════════════╝    ╚════════════╝  ║ \n");
    printf("║ ╔════════════╗   ╔════════════╗    ╔════════════╗  ║\n");
    printf("║ ║ B7 [%s] ║   ║ B8 [%s] ║    ║            ║  ║\n",
           search_table(restaurant, 7)->status ? "Khách" : "Trống",
           search_table(restaurant, 8)->status ? "Khách" : "Trống");
    printf("║ ╚════════════╝   ╚════════════╝    ║ B9 [%s] ║  ║ \n", search_table(restaurant, 9)->status ? "Khách" : "Trống");
    printf("║ ╔═════════════════════════════╗    ║            ║  ║\n");
    printf("║ ║          B10 [%s]        ║    ║            ║  ║ \n",
           search_table(restaurant, 10)->status ? "Khách" : "Trống");
    printf("║ ╚═════════════════════════════╝    ╚════════════╝  ║ \n");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║ 1. Xem chi tiết bàn                                ║\n");
    printf("║ 2. Thoát                                           ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");

    while (1) {
        printf("Nhập lựa chọn: ");
        nhap_so_nguyen(&choice);
        if (choice == 1 || choice == 2) {
            break;
        }
        inThongBao("Lựa chọn không hợp lệ, vui lòng nhập lại!");
    }
    if (choice == 1) {
        printf("Nhập số bàn (1 - 10): ");
        nhap_so_nguyen(&table_id);
        if (table_id < 1 || table_id > 10) {
            inThongBao("Bàn không hợp lệ.");
            return;
        }
        table = search_table(restaurant, table_id);
        if (!table) {
            inThongBao("Bàn %d không tồn tại.", table_id);
            return;
        }

        printf("╔═══════════════════════════╗\n");
        printf("║     🔍 Chi tiết bàn %2d    ║\n", table_id);
        printf("║ Trạng thái: %-16s ║\n", table->status ? "Bàn có khách" : "Bàn trống");
        printf("║ Danh sách món đã gọi:     ║\n");

        if (table->status && table->bill) {
            struct Bill* bill = table->bill;
            struct Dish_ordered* dish = bill->listDish;
            if (dish == NULL) {
                printf("║ (Chưa gọi món nào)        ║\n");
            } else {
                while (dish) {
                    int dishNameLength = utf8_char_length(dish->name);
                    int quantityLength = 4;
                    int remainingLength = 23 - quantityLength;
                    if (dishNameLength > remainingLength) {
                        dish->name[remainingLength] = '\0';
                    }

                    printf("║ - %-*s x%-2d ║\n", remainingLength, dish->name, dish->quantity);
                    dish = dish->next;
                }
                printf("║ Tổng bill: %-10d VND ║\n", bill->totalPrice);
            }
        } else {
            printf("║ Bàn chưa có hóa đơn.      ║\n");
        }
        printf("╚═══════════════════════════╝\n");
    } else if (choice == 2) {
        return;
    }
}
