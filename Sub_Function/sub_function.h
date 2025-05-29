#ifndef SUB_FUNCTION_H
#define SUB_FUNCTION_H

#include "tinh_nang_goi_y.h"
#include "data_structure.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhap_so_nguyen(int* soKetQua); // thành viên 1
void nhap_chuoi(char* ketQua); // thành viên 1
void to_lowercase_no_accent(char *str); // thành viên 1
void to_lowercase(char *str); // thành viên 1
void initStructure(struct Top_seller** top_seller, struct Staff** listStaff, struct Bill** listBill, struct Table** restaurant, struct Menu** menu); // thành viên 1
void initData(struct Top_seller* top_seller, struct Staff* listStaff, struct Bill*  listBill, int* totalRevenue); // Thông
void add_menu(struct Menu** head, const char* name, int price, int point); // thành viên 1
struct Table* search_table(struct Table* restaurant, int id); // thành viên 2
void add_dish_to_bill(struct Bill* bill, char* dishName, int price, int quantity); // thành viên 2
struct Menu* search_dish(struct Menu* menu, char* dishName); // thành viên 2
int sua_so_luong_mon(struct Bill* bill, char* name_dish, int quantity); // thành viên 2
void order_dish(struct Table* table, struct Menu* menu, struct Bill* bill, struct Top_seller* top_seller); // thành viên 2

void them_mon_vao_menu(struct Menu* menu); // thành viên 1
void sua_gia_mon_an(struct Menu* menu); // thành viên 1
void xoa_mon_an_khoi_menu(struct Menu* menu); // thành viên 1

void push_to_top_seller_list(struct Top_seller** head, char* name, int quantity); // thành viên 3

int get_point(struct Menu* menu, char name[100]); // thành viên 3

void free_restaurant(struct Table* restaurant);
void free_menu(struct Menu* menu);
void free_top_seller(struct Top_seller* top_seller);
void free_staff(struct Staff* listStaff);
void free_bill(struct Bill* listBill);

#endif
