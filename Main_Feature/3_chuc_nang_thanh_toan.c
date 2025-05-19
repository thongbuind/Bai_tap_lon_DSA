#include "3_chuc_nang_thanh_toan.h"
#include <stdio.h>
#include <string.h>

void chuc_nang_thanh_toan(struct Table* restaurant, struct Menu* menu, struct Top_seller* top_seller, struct Staff* thisStaff, struct Bill* listBill, int* totalRevenue) {
    int table_id;
    while (1) {
        printf("Nhập số bàn cần thanh toán (hoặc nhập 0 để thoát): ");
        nhap_so_nguyen(&table_id);
        if (table_id == 0) {
            inThongBao("Đã hủy thanh toán.");
            return;
        }
        if (table_id < 1 || table_id > 10) {
            inThongBao("Bàn không tồn tại, vui lòng nhập lại!");
        } else {
            break;
        }
    }

    struct Table* table = search_table(restaurant, table_id);
    if (table == NULL || table->status == 0 || table->bill == NULL) {
        inThongBao("Bàn không tồn tại, trống hoặc không có hóa đơn.");
        return;
    }

    char billInfo[50];
    sprintf(billInfo, "Bàn %d có bill: %d000 VND", table_id, table->bill->totalPrice / 1000);
    int len = (int)strlen(billInfo);
    if (len > 30) {
        billInfo[30] = '\0';
        len = 30;
    }
    int padding = (32 - len) / 2;
    
    printf("╔════════════════════════════════════════════════════╗\n");
    printf("║%*s%s%*s       ║\n", padding, "", billInfo, 47 - len - padding, "");
    printf("╠═════════════════════════╦═════════╦════════════════╣\n");
    printf("║ %-25s ║ %-7s ║ %-17s ║\n", "Món ăn", "SL", "Thành tiền");
    printf("╠═════════════════════════╬═════════╬════════════════╣\n");
    
    struct Dish_ordered* dish = table->bill->listDish->next;
    while (dish != NULL) {
        struct Menu* thisDish = search_dish(menu, dish->name);
        int price = thisDish->price;
        int total = price >= 0 ? dish->quantity * price : 0;
        printf("║ %-23s ║ %-7d ║ %-14d ║\n", dish->name, dish->quantity, total);
            dish = dish->next;
    }
    printf("╠═════════════════════════╩═════════╩════════════════╣\n");
    printf("║ Xác nhận thanh toán:                               ║\n");
    printf("║ 1. Xác nhận                                        ║\n");
    printf("║ 2. Hủy                                             ║\n");
    printf("╚════════════════════════════════════════════════════╝\n");

    int choice;
    while (1) {
        printf("Nhập lựa chọn: ");
        nhap_so_nguyen(&choice);
        switch (choice) {
            case 1: {
                table->status = 0;
                struct Bill* bill = table->bill;
                bill->next = NULL;

                // Thêm bill vào listBill->next (dummy node)
                struct Bill* ptr = listBill;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = bill;
                table->bill = NULL;

                // Cập nhật top_seller từ top_seller->next
                if (bill->listDish != NULL) {
                    struct Dish_ordered* dish = bill->listDish;
                    while (dish != NULL) {
                        push_to_top_seller_list(&(top_seller->next), dish->name, dish->quantity);
                        dish = dish->next;
                    }
                }

                *totalRevenue += bill->totalPrice;
                strncpy(bill->nameStaff, thisStaff->name, 99);
                bill->nameStaff[99] = '\0';
                thisStaff->totalBill++;
                thisStaff->revenue += bill->totalPrice;

                inThongBao("Thanh toán thành công!");
                return;
            }
            case 2:
                inThongBao("Thanh toán đã bị hủy.");
                return;
            default:
                inThongBao("Lựa chọn không hợp lệ, vui lòng nhập lại!");
        }
    }
}
