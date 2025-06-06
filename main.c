#include "data_structure.h"
#include "sub_function.h"
#include "interface.h"
#include "1_chuc_nang_them_hoa_don.h"
#include "2_chuc_nang_sua_hoa_don.h"
#include "3_chuc_nang_thanh_toan.h"
#include "4_chuc_nang_menu.h"
#include "5_chuc_nang_xem_so_do_quan.h"
#include "6_chuc_nang_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Top_seller* top_seller = NULL;
struct Staff* listStaff = NULL;
struct Bill* listBill = NULL;
struct Table* restaurant = NULL;
struct Menu* menu = NULL;

int totalRevenue = 0;
int luaChon = 0;
char nameStaff[100];

int main(void) {
    initStructure(&top_seller, &listStaff, &listBill, &restaurant, &menu);
    initData(top_seller, listStaff, listBill, &totalRevenue);

    while (1) {
        interface_0();
        nhap_so_nguyen(&luaChon);
        if (luaChon == 1) {
            printf("Nhập tên nhân viên: ");
            nhap_chuoi(nameStaff);
            struct Staff* thisStaff = (struct Staff*)malloc(sizeof(struct Staff));
            strncpy(thisStaff->name, nameStaff, 99);
            thisStaff->name[99] = '\0';
            thisStaff->totalBill = 0;
            thisStaff->revenue = 0;
            thisStaff->next = NULL;

            struct Staff* current = listStaff;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = thisStaff;

            while (1) {
                interface_main();
                nhap_so_nguyen(&luaChon);
                switch (luaChon) {
                    case 1:
                        chuc_nang_them_hoa_don(restaurant, menu, top_seller);
                        break;
                    case 2:
                        chuc_nang_sua_hoa_don(restaurant, menu, top_seller);
                        break;
                    case 3:
                        chuc_nang_thanh_toan(restaurant, menu, top_seller, thisStaff, listBill, &totalRevenue);
                        break;
                    case 4:
                        chuc_nang_menu(menu);
                        break;
                    case 5:
                        chuc_nang_xem_so_do_quan(restaurant, menu);
                        break;
                    case 6:
                        chuc_nang_data(restaurant, menu, thisStaff, top_seller, totalRevenue, listBill, listStaff);
                        break;
                    case 7:
                        printf("🔒 Đăng xuất...\n");
                        break;
                    default:
                        printf("❌ Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
                }
                if (luaChon == 7) {
                    break;
                }
            }
        } else if (luaChon == 2) {
            inThongBao("Tạm biệt!");
            break;
        } else {
            inThongBao("Lựa chọn không hợp lệ, vui lòng chọn lại!");
        }
    }

    // Giải phóng bộ nhớ
    free_restaurant(restaurant);
    free_menu(menu);
    free_top_seller(top_seller);
    free_staff(listStaff);
    free_bill(listBill);

    return 0;
}
