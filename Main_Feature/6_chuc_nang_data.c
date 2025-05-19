#include "6_chuc_nang_data.h"

void inDuLieuThongKe(struct Top_seller* top_seller, struct Bill* listBill, int totalRevenue) {
    int totalBill = 0;
    int totalCustomers = 0;

    struct Bill* ptr = listBill->next;
    while (ptr != NULL) {
        totalBill++;
        if (ptr->listDish != NULL) {
            totalCustomers += ptr->listDish->quantity;
        }
        ptr = ptr->next;
    }

    // Tính trung bình khách/bill
    double avgCustomersPerBill = (totalBill == 0) ? 0 : (double)totalCustomers / totalBill;

    // Tìm top 5 món bán chạy
    struct Top_seller* top[5] = {NULL, NULL, NULL, NULL, NULL};
    struct Top_seller* current = top_seller->next;
    while (current != NULL) {
        for (int i = 0; i < 5; i++) {
            if (top[i] == NULL || current->quantity > top[i]->quantity) {
                for (int j = 4; j > i; j--) {
                    top[j] = top[j - 1];
                }
                top[i] = current;
                break;
            }
        }
        current = current->next;
    }

    // In thống kê
    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua("THỐNG KÊ DOANH THU");
    printf("╠════════════════════════════════════════════════════╣\n");
    printf("║ Tổng số bill: %-36d ║\n", totalBill);
    printf("║ Tổng số lượng khách: %-29d ║\n", totalCustomers);
    printf("║ Trung bình khách/bill: %-27.2f ║\n", avgCustomersPerBill);
    printf("║ Tổng doanh thu: %-34d ║\n", totalRevenue);

    if (top_seller->next == NULL) {
        printf("║ Không có món bán chạy nào.                         ║\n");
    } else {
        for (int i = 0; i < 5; i++) {
            if (top[i] != NULL) {
                printf("║ Top %d: %-15s SL: %-24d ║\n",
                       i + 1, top[i]->name, top[i]->quantity);
            }
        }
    }
    printf("╚════════════════════════════════════════════════════╝\n");
}
void inQuanLyNhanVien(struct Staff* staffList) {
    printf("╔════════════════════════════════════════════════════╗\n");
    inDongGiua("QUẢN LÝ NHÂN VIÊN");
    printf("╠═══╦═══════════════════════╦═══════════╦════════════╣\n");
    printf("║STT║ Tên nhân viên         ║ Số bill   ║ Doanh thu  ║\n");
    printf("╠═══╬═══════════════════════╬═══════════╬════════════╣\n");
    
    int count = 1;
    struct Staff* current = staffList->next;
    while (current != NULL) {
        printf("║ %-2d║ %-22s║     %-6d║ %-11d║\n", count++, current->name, current->totalBill, current->revenue);
        current = current->next;
    }
    printf("╚═══╩═══════════════════════╩═══════════╩════════════╝\n");
}

void chuc_nang_data(struct Table* restaurant, struct Menu* menu, struct Staff* thisStaff, struct Top_seller* top_seller, int totalRevenue, struct Bill* listBill, struct Staff* staffList) {
    int choice = 0;
    while (1) {
        interface_quan_ly();
        nhap_so_nguyen(&choice);
        if (choice == 1) {
            inDuLieuThongKe(top_seller, listBill, totalRevenue);
            break;
        } else if (choice == 2) {
            inQuanLyNhanVien(staffList);
            break;
        } else if (choice == 3) {
            inThongBao("Comming soon ...");
            break;
        } else if (choice == 4) {
            break;
        } else {
            inThongBao("Lựa chọn không hợp lệ, vui lòng chọn lại!");
        }
    }
}
