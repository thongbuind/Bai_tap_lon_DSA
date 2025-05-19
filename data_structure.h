#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

struct Menu {
    char name[100];
    int price;
    int point;
    
    struct Menu* next;
};

struct Dish_ordered {
    char name[100];
    int quantity;
    
    struct Dish_ordered* next;
};

struct Bill {
    struct Dish_ordered* listDish;
    int totalPrice;
    char nameStaff[100];
    
    struct Bill* next;
};

struct Table {
    int id;
    int status;
    struct Bill* bill;
    
    struct Table* next;
};

struct Staff {
    char name[100];
    int totalBill;
    int revenue;
    
    struct Staff* next;
};

struct Top_seller {
    char name[100];
    int quantity;
    
    struct Top_seller* next;
};

#endif
