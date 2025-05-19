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

// Hàm giải phóng bộ nhớ
void free_restaurant(struct Table* restaurant) {
    struct Table* current = restaurant;
    while (current != NULL) {
        struct Table* temp = current;
        current = current->next;
        if (temp->bill != NULL) {
            struct Dish_ordered* dish = temp->bill->listDish;
            while (dish != NULL) {
                struct Dish_ordered* dish_temp = dish;
                dish = dish->next;
                free(dish_temp);
            }
            free(temp->bill);
        }
        free(temp);
    }
}

void free_menu(struct Menu* menu) {
    struct Menu* current = menu;
    while (current != NULL) {
        struct Menu* temp = current;
        current = current->next;
        free(temp);
    }
}

void free_top_seller(struct Top_seller* top_seller) {
    struct Top_seller* current = top_seller;
    while (current != NULL) {
        struct Top_seller* temp = current;
        current = current->next;
        free(temp);
    }
}

void free_staff(struct Staff* listStaff) {
    struct Staff* current = listStaff;
    while (current != NULL) {
        struct Staff* temp = current;
        current = current->next;
        free(temp);
    }
}

void free_bill(struct Bill* listBill) {
    struct Bill* current = listBill;
    while (current != NULL) {
        struct Bill* temp = current;
        current = current->next;
        struct Dish_ordered* dish = temp->listDish;
        while (dish != NULL) {
            struct Dish_ordered* dish_temp = dish;
            dish = dish->next;
            free(dish_temp);
        }
        free(temp);
    }
}

int main(void) {
    struct Table* restaurant = init_restaurant();
    struct Menu* menu = init_menu();
    
    struct Top_seller* top_seller = (struct Top_seller*)malloc(sizeof(struct Top_seller));
    top_seller->quantity = 0;
    top_seller->name[0] = '\0';
    top_seller->next = NULL;

    struct Staff* listStaff = (struct Staff*)malloc(sizeof(struct Staff));
    listStaff->totalBill = 0;
    listStaff->revenue = 0;
    listStaff->name[0] = '\0';
    listStaff->next = NULL;

    struct Bill* listBill = (struct Bill*)malloc(sizeof(struct Bill));
    listBill->listDish = NULL;
    listBill->totalPrice = 0;
    listBill->nameStaff[0] = '\0';
    listBill->next = NULL;
    
    int totalRevenue = 0;
    int luaChon = 0;
    char nameStaff[100];

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
                        chuc_nang_them_hoa_don(restaurant, menu);
                        break;
                    case 2:
                        inThongBao("coming soon...");
                        //chuc_nang_sua_hoa_don(restaurant, menu);
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
