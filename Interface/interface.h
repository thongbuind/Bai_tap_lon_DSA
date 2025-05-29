#ifndef INTERFACE_H
#define INTERFACE_H

#include "data_structure.h"
#include <stdio.h>
#include <stdarg.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utf8_char_length(const char* str);
void inThongBao(const char* format, ...);
void inDongGiua(const char* noiDung);
void inDongCanTrai(const char* text);
void interface_main(void);
void interface_0(void);
void interface_sua_hoa_don(int table_id);
void inMenu(struct Menu* menu);
void interface_menu(void);
void inKhungGoiY(char* reason, char* result);
void interface_quan_ly(void);

#endif

