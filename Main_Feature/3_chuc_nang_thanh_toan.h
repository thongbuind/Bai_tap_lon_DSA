#ifndef CHUC_NANG_THANH_TOAN_H
#define CHUC_NANG_THANH_TOAN_H

#include "sub_function.h"
#include "data_structure.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void chuc_nang_thanh_toan(struct Table* restaurant, struct Menu* menu, struct Top_seller*, struct Staff* thisStaff, struct Bill* listBill, int* totalRevenue);
#endif
