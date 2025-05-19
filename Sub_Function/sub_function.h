#ifndef SUB_FUNCTION_H
#define SUB_FUNCTION_H

#include "data_structure.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void nhap_so_nguyen(int* soKetQua);
void nhap_chuoi(char* ketQua);
void to_lowercase_no_accent(char *str);
void to_lowercase(char *str);
void add_menu(struct Menu** head, const char* name, int price, int point);
struct Menu* init_menu(void);
struct Table* init_restaurant(void);
struct Table* search_table(struct Table* restaurant, int id);
void add_dish_to_bill(struct Bill* bill, char* dishName, int price, int quantity);
struct Menu* search_dish(struct Menu* menu, char* dishName);
int sua_so_luong_mon(struct Bill* bill, char* name_dish, int quantity);
void order_dish(struct Table* table, struct Menu* menu, struct Bill* bill);

void them_mon_vao_menu(struct Menu* menu);
void sua_gia_mon_an(struct Menu* menu);
void xoa_mon_an_khoi_menu(struct Menu* menu);

void push_to_top_seller_list(struct Top_seller** head, char* name, int quantity);

int get_point(struct Menu* menu, char name[100]);
void tinh_nang_goi_y(struct Table* table, struct Menu* menu);

#endif
