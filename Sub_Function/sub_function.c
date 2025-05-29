#include "sub_function.h"

void nhap_so_nguyen(int* soKetQua) {
    int ketQua;
    char kyTuDu;
    
    while (1) {
        if (scanf("%d%c", &ketQua, &kyTuDu) == 2 && kyTuDu == '\n') {
            *soKetQua = ketQua;
            break;
        } else {
            printf("❌ Sai định dạng, vui lòng nhập lại: ");
            while (getchar() != '\n');
        }
    }
}

void nhap_chuoi(char* ketQua) {
    int hopLe;
    int i;
    char c = '\0';
    do {
        hopLe = 0;
        i = 0;
        while (i < 99) {
            c = getchar();
            if (c == '\n') break;
            ketQua[i++] = c;
        }
        ketQua[i] = '\0';
        if (c != '\n') {
            while ((c = getchar()) != '\n' && c != EOF);
        }
        for (int j = 0; j < i; j++) {
            if (ketQua[j] != ' ') {
                hopLe = 1;
                break;
            }
        }
        if (!hopLe) {
            printf("❌ Chuỗi không được để trống. Nhập lại: ");
        }
    } while (!hopLe);
}

// Hàm chuyển chuỗi thành chữ thường và loại bỏ dấu
void to_lowercase_no_accent(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// Hàm chuyển chuỗi thành chữ thường (không loại bỏ dấu)
void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void initStructure(struct Top_seller** top_seller, struct Staff** listStaff, struct Bill** listBill, struct Table** restaurant, struct Menu** menu) {
    
    *top_seller = (struct Top_seller*)malloc(sizeof(struct Top_seller));
    (*top_seller)->quantity = 0;
    (*top_seller)->name[0] = '\0';
    (*top_seller)->next = NULL;

    *listStaff = (struct Staff*)malloc(sizeof(struct Staff));
    (*listStaff)->totalBill = 0;
    (*listStaff)->revenue = 0;
    (*listStaff)->name[0] = '\0';
    (*listStaff)->next = NULL;

    *listBill = (struct Bill*)malloc(sizeof(struct Bill));
    (*listBill)->listDish = NULL;
    (*listBill)->totalPrice = 0;
    (*listBill)->nameStaff[0] = '\0';
    (*listBill)->next = NULL;
    
    *restaurant = (struct Table*)malloc(sizeof(struct Table));
    (*restaurant)->id = 0;
    (*restaurant)->status = 0;
    (*restaurant)->bill = NULL;
    (*restaurant)->next = NULL;
    struct Table* current = *restaurant;
    for (int i = 1; i <= 10; i++) {
        struct Table* newTable = (struct Table*)malloc(sizeof(struct Table));
        newTable->id = i;
        newTable->status = 0;
        newTable->bill = NULL;
        newTable->next = NULL;
        current->next = newTable;
        current = newTable;
    }
    
    *menu = (struct Menu*)malloc(sizeof(struct Menu));
    (*menu)->next = NULL;
    (*menu)->name[0] = '\0';
    (*menu)->price = 0;
    (*menu)->point = 0;
    // Khai vị
    add_menu(menu, "goi cuon", 300000, 15);        // Nhẹ nhàng, tươi mát
    add_menu(menu, "salad", 300000, 21);           // Nhẹ nhàng, tươi mát
    add_menu(menu, "tempura tom", 300000, 29);     // Hương đậm đà
    add_menu(menu, "cha gio", 300000, 34);         // Hương đậm đà
    add_menu(menu, "banh kimchi", 300000, 39);     // Hương đậm đà
    // Món chính
    add_menu(menu, "mi hai san", 300000, 41);      // Thanh nhẹ, tinh tế
    add_menu(menu, "sushi", 300000, 54);           // Thanh nhẹ, tinh tế
    add_menu(menu, "tom nuong", 300000, 62);       // Đậm đà, no lâu
    add_menu(menu, "pho bo", 300000, 70);          // Đậm đà, no lâu
    add_menu(menu, "bit tet", 300000, 81);         // Đậm đà, no lâu
    // Tráng miệng
    add_menu(menu, "kem chanh", 300000, 9);        // Ngọt nhẹ, giải nhiệt
    add_menu(menu, "che Thai", 300000, 12);        // Ngọt nhẹ, giải nhiệt
    add_menu(menu, "bingsu hoa qua", 300000, 15);  // Béo ngậy, đậm vị
    add_menu(menu, "kem match", 300000, 18);       // Béo ngậy, đậm vị
    add_menu(menu, "tiramisu", 300000, 22);        // Béo ngậy, đậm vị
    // Combo
    add_menu(menu, "combo 2 nguoi", 1500000, 100);
    add_menu(menu, "combo 3 nguoi", 2300000, 100);
    add_menu(menu, "combo 5 nguoi", 3500000, 100);
}

void initData(struct Top_seller* top_seller, struct Staff* listStaff, struct Bill*  listBill, int* totalRevenue) {
    
    char topSeller[3][100] = {"bit tet", "goi cuon", "kem chanh"};
    int quantity[3] = {54, 43, 34};
    struct Top_seller* ptr = top_seller;
    for (int i=0; i<3; i++) {
        struct Top_seller* dish = (struct Top_seller*)malloc(sizeof(struct Top_seller));
        strcpy(dish->name, topSeller[i]);
        dish->quantity = quantity[i];
        dish->next = NULL;
        
        ptr->next = dish;
        ptr = ptr->next;
        *totalRevenue += quantity[i] * 300000;
    }
    
    char staff[3][100] = {"van thanh", "quang minh", "nhat thien"};
    int revenue[3] = {21600, 7200, 5400};
    int totalBill[3] = {12, 4, 3};
    struct Staff* ptr2 = listStaff;
    for (int i=0; i<3; i++) {
        struct Staff* thisStaff = (struct Staff*)malloc(sizeof(struct Staff));
        strcpy(thisStaff->name, staff[i]);
        thisStaff->revenue = revenue[i];
        thisStaff->totalBill = totalBill[i];
        thisStaff->next = NULL;
        
        ptr2->next = thisStaff;
        ptr2 = ptr2->next;
    }
    
    struct Bill* ptr3 = listBill;
    for (int i=0; i<19; i++) {
        struct Bill* b = (struct Bill*)malloc(sizeof(struct Bill));
        struct Dish_ordered* tmp = (struct Dish_ordered*)malloc(sizeof(struct Dish_ordered));
        tmp->quantity = 2;
        b->listDish = tmp;
        strcpy(b->nameStaff, "nhan vien ao");
        b->totalPrice = 1800;
        b->next = NULL;
        
        ptr3->next = b;
        ptr3 = ptr3->next;
    }
}

void add_menu(struct Menu** menu, const char* name, int price, int point) {
    struct Menu* newNode = (struct Menu*)malloc(sizeof(struct Menu));
    strncpy(newNode->name, name, 99);
    newNode->name[99] = '\0';
    newNode->price = price;
    newNode->point = point;
    newNode->next = NULL;

    if (*menu == NULL) {
        *menu = (struct Menu*)malloc(sizeof(struct Menu));
        (*menu)->next = NULL;
        (*menu)->name[0] = '\0';
        (*menu)->price = 0;
        (*menu)->point = 0;
    }

    struct Menu* ptr = *menu;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

struct Table* search_table(struct Table* restaurant, int id) {
    if (restaurant == NULL) return NULL;
    struct Table* current = restaurant->next;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_dish_to_bill(struct Bill* bill, char* nameDish, int price, int quantity) {
    struct Dish_ordered* newDish = (struct Dish_ordered*)malloc(sizeof(struct Dish_ordered));
    int i = 0;
    while (nameDish[i] != '\0') {
        newDish->name[i] = nameDish[i];
        i++;
    }
    newDish->name[i] = '\0';
    newDish->quantity = quantity;
    newDish->next = NULL;

    struct Dish_ordered* ptr = bill->listDish;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newDish;
    bill->totalPrice += price * quantity;
}

struct Menu* search_dish(struct Menu* menu, char* dishName) {
    char tempName[100];
    strcpy(tempName, dishName);
    
    to_lowercase_no_accent(tempName); 

    while (menu != NULL) {
        char menuName[100];
        strcpy(menuName, menu->name);
        
        to_lowercase_no_accent(menuName);
        
        if (strcmp(menuName, tempName) == 0) {
            return menu;
        }
        menu = menu->next;
    }
    return NULL;
}

int sua_so_luong_mon(struct Bill* bill, char* name_dish, int quantity) {
    struct Dish_ordered* current = bill->listDish;
    while (current != NULL) {
        if (strcmp(current->name, name_dish) == 0) {
            current->quantity += quantity;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void order_dish(struct Table* table, struct Menu* menu, struct Bill* bill, struct Top_seller* top_seller) {
    char name_dish[100];
    int quantity;
    int price;
    while (1) {
        inThongBao("Nếu khách phân vân, nhập 'goi y' hoặc 'menu'");
        printf("Nhập tên món (hoặc 'xong' để kết thúc): ");
        nhap_chuoi(name_dish);
        if (strcmp(name_dish, "xong") == 0) {
            break;
        } else if (strcmp(name_dish, "goi y") == 0 || strcmp(name_dish, "goiy") == 0) {
            tinh_nang_goi_y(table, menu, top_seller);
            continue;
        } else if (strcmp(name_dish, "menu") == 0) {
            inMenu(menu);
            printf("╚════════════════════════════════════════════════════╝\n");
            continue;
        }
        struct Menu* dish = search_dish(menu, name_dish);
        if (dish == NULL) {
            inThongBao("Món không có trong menu, vui lòng nhập lại.");
            continue;
        }
        price = dish->price;
        printf("Số lượng: ");
        nhap_so_nguyen(&quantity);
        
        add_dish_to_bill(bill, name_dish, price, quantity);
        inThongBao("Đã thêm %s x%d (%d VND/món)", name_dish, quantity, price);
    }
}

void them_mon_vao_menu(struct Menu* menu) {
    char name[100];
    int price;
    int point;

    printf("Nhập tên món mới: ");
    nhap_chuoi(name);
    printf("Nhập giá món mới: ");
    nhap_so_nguyen(&price);
    printf("Nhập point: ");
    nhap_so_nguyen(&point);

    struct Menu* newDish = (struct Menu*)malloc(sizeof(struct Menu));
    strncpy(newDish->name, name, 99);
    newDish->name[99] = '\0';
    newDish->price = price;
    newDish->point = point;
    newDish->next = NULL;

    if (menu == NULL) {
        menu = newDish;
    } else {
        struct Menu* ptr = menu;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newDish;
    }
}

void sua_gia_mon_an(struct Menu* menu) {
    char name[100];
    int price;

    printf("Nhập tên món cần sửa giá: ");
    nhap_chuoi(name);

    struct Menu* dish = NULL;
    dish = search_dish(menu, name);

    if (dish == NULL) {
        inThongBao("Không có món '%s' trong menu.", name);
        return;
    }

    printf("Nhập giá mới cho món ăn: ");
    nhap_so_nguyen(&price);
    dish->price = price;

    inThongBao("Giá của '%s' đã được sửa thành %d VND.", name, price);
}

void xoa_mon_an_khoi_menu(struct Menu* menu) {
    char name[100];

    printf("Nhập tên món cần xoá: ");
    nhap_chuoi(name);

    struct Menu* dish = NULL;
    dish = search_dish(menu, name);

    if (dish == NULL) {
        inThongBao("Không có món '%s' trong menu.", name);
        return;
    }

    if (dish->next == NULL) {
        if (dish == menu) {
            menu = NULL;
        } else {
            struct Menu* prev = menu;
            while (prev->next != dish) {
                prev = prev->next;
            }
            prev->next = NULL;
        }
        free(dish);
    } else {
        struct Menu* nextNode = dish->next;
        strcpy(dish->name, nextNode->name);
        dish->price = nextNode->price;
        dish->next = nextNode->next;

        free(nextNode);
    }

    inThongBao("Món '%s' đã được xoá khỏi Menu.", name);
}

void push_to_top_seller_list(struct Top_seller** head, char* name, int quantity) {
    if (*head == NULL) {
            *head = (struct Top_seller*)malloc(sizeof(struct Top_seller));
            if (*head == NULL) return;
            (*head)->name[0] = '\0';
            (*head)->quantity = 0;
            (*head)->next = NULL;
        }

    struct Top_seller* prev = *head;
    struct Top_seller* current = (*head)->next;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->quantity += quantity;
            prev->next = current->next;

            struct Top_seller* insert_prev = *head;
            struct Top_seller* insert_curr = (*head)->next;
            while (insert_curr != NULL && insert_curr->quantity > current->quantity) {
                insert_prev = insert_curr;
                insert_curr = insert_curr->next;
            }
            insert_prev->next = current;
            current->next = insert_curr;
            return;
        }
        prev = current;
        current = current->next;
    }

    struct Top_seller* newNode = (struct Top_seller*)malloc(sizeof(struct Top_seller));
    if (newNode == NULL) return;
    strncpy(newNode->name, name, 99);
    newNode->name[99] = '\0';
    newNode->quantity = quantity;
    newNode->next = NULL;

    prev = *head;
    current = (*head)->next;
    while (current != NULL && current->quantity > newNode->quantity) {
        prev = current;
        current = current->next;
    }
    prev->next = newNode;
    newNode->next = current;
}

int get_point(struct Menu* menu, char name[100]) {
    struct Menu* result = search_dish(menu, name);
    if (result != NULL) {
        return result->point;
    }
    return -1;
}

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
