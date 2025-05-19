#ifndef CHUC_NANG_DATA_H
#define CHUC_NANG_DATA_H

#include "data_structure.h"
#include "sub_function.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void chuc_nang_data(struct Table* restaurant, struct Menu* menu, struct Staff* thisStaff, struct Top_seller* top_seller,  int totalRevenue, struct Bill* listBill, struct Staff* staffList);

#endif

