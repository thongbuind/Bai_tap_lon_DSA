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

void add_menu(struct Menu** head, const char* name, int price, int point) {
    struct Menu* newNode = (struct Menu*)malloc(sizeof(struct Menu));
    int i = 0;
    while (name[i] != '\0' && i < 99) {
        newNode->name[i] = name[i];
        i++;
    }
    newNode->name[i] = '\0';
    newNode->price = price;
    newNode->point = point;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Menu* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}
struct Menu* init_menu(void) {
    struct Menu* head = NULL;

    // Khai vị
    add_menu(&head, "Goi cuon", 300000, 15);        // Nhẹ nhàng, tươi mát
    add_menu(&head, "Salad ca hoi", 300000, 21);    // Nhẹ nhàng, tươi mát
    add_menu(&head, "Tempura tom", 300000, 29);     // Hương đậm đà
    add_menu(&head, "Cha gio", 300000, 34);         // Hương đậm đà
    add_menu(&head, "Banh kimchi", 300000, 39);     // Hương đậm đà
    // Món chính
    add_menu(&head, "Mi hai san", 300000, 47);      // Thanh nhẹ, tinh tế
    add_menu(&head, "Ca hoi teriyaki", 300000, 54); // Thanh nhẹ, tinh tế
    add_menu(&head, "Tom nuong", 300000, 62);       // Đậm đà, no lâu
    add_menu(&head, "Pho bo", 300000, 70);          // Đậm đà, no lâu
    add_menu(&head, "Bo bit tet", 300000, 81);      // Đậm đà, no lâu

    // Tráng miệng
    add_menu(&head, "Sorbet chanh", 300000, 9);     // Ngọt nhẹ, giải nhiệt
    add_menu(&head, "Che Thai", 300000, 12);        // Ngọt nhẹ, giải nhiệt
    add_menu(&head, "Bingsu dau", 300000, 15);      // Beo ngậy, đậm vị
    add_menu(&head, "Tiramisu", 300000, 18);        // Beo ngậy, đậm vị
    add_menu(&head, "Kem matcha", 300000, 22);      // Beo ngậy, đậm vị

    // Combo
    add_menu(&head, "Combo 2 nguoi", 1500000, 100);
    add_menu(&head, "Combo 3 nguoi", 2300000, 100);
    add_menu(&head, "Combo 5 nguoi", 3500000, 100);
    
    return head;
}

struct Table* init_restaurant(void) {
    struct Table* head = NULL;
    struct Table* current = NULL;

    for (int i = 1; i <= 10; i++) {
        struct Table* newTable = (struct Table*)malloc(sizeof(struct Table));
        newTable->id = i;
        newTable->status = 0;
        newTable->bill = NULL;
        newTable->next = NULL;

        if (head == NULL) {
            head = newTable;
        } else {
            current->next = newTable;
        }
        current = newTable;
    }
    
    return head;
}

struct Table* search_table(struct Table* restaurant, int id) {
    while (restaurant != NULL) {
        if (restaurant->id == id) {
            return restaurant;
        }
        restaurant = restaurant->next;
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

void order_dish(struct Table* table, struct Menu* menu, struct Bill* bill) {
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
            tinh_nang_goi_y(table, menu);
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
        struct Top_seller* newNode = (struct Top_seller*)malloc(sizeof(struct Top_seller));
        strncpy(newNode->name, name, 99);
        newNode->name[99] = '\0';
        newNode->quantity = quantity;
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    struct Top_seller* current = *head;
    struct Top_seller* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            current->quantity += quantity;

            if (prev != NULL && current->quantity > prev->quantity) {
                prev->next = current->next;

                struct Top_seller* insert_prev = NULL;
                struct Top_seller* insert_curr = *head;
                while (insert_curr != NULL && insert_curr->quantity > current->quantity) {
                    insert_prev = insert_curr;
                    insert_curr = insert_curr->next;
                }

                if (insert_prev == NULL) {
                    current->next = *head;
                    *head = current;
                } else {
                    insert_prev->next = current;
                    current->next = insert_curr;
                }
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    struct Top_seller* newNode = (struct Top_seller*)malloc(sizeof(struct Top_seller));
    strncpy(newNode->name, name, 99);
    newNode->name[99] = '\0';
    newNode->quantity = quantity;
    newNode->next = NULL;
    prev = NULL;
    current = *head;
    while (current != NULL && current->quantity > newNode->quantity) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

int get_point(struct Menu* menu, char name[100]) {
    struct Menu* result = search_dish(menu, name);
    if (result != NULL) {
        return result->point;
    }
    return -1;
}

void tinh_nang_goi_y(struct Table* table, struct Menu* menu) {
    struct Bill* bill = table->bill;
    struct Dish_ordered* listDish = bill->listDish;
    int nums_customers = listDish->quantity;
    int nums_dish = 0;
    int total_point = 0;
    struct Dish_ordered* ptr = listDish->next;
    char reason[300];
    char result[100];
    
    while (ptr != NULL) {
        nums_dish++;
        total_point += get_point(menu, ptr->name);
        ptr = ptr->next;
    }
    if (nums_customers == 1) {
        if (nums_dish == 3) {
            // Nếu đã gọi 3 món: Cộng tổng point của 3 món đã gọi
                // Nếu tổng point bé hơn 100 tức là chưa có món chính, tìm 1 món chính gần nhất với 100 - point (món chính là món có point >40). reason = "Vì bạn chưa có món chính, nên chúng tôi sẽ đề xuất 1 món chính phù hợp để đảm bảo sự hoàn thiện của bữa ăn"
            if (total_point < 100) {
                int min_diff = 100 - total_point;
                    int smallest_diff = 1000;
                    struct Menu* m = menu;
                    char temp_result[100] = "";
                    while (m != NULL) {
                        if (m->point > 40) {
                            int diff = abs(m->point - min_diff);
                            if (diff < smallest_diff) {
                                smallest_diff = diff;
                                strcpy(temp_result, m->name);
                            }
                        }
                        m = m->next;
                    }
                strcpy(result, temp_result);
                strcpy(reason, "Vì bạn chưa có món chính, nên chúng tôi sẽ đề xuất 1 món chính phù hợp để đảm bảo sự hoàn thiện của bữa ăn.");
            } else {
                // Nếu tổng point lớn hơn 100, tìm món có point thấp nhất. reason = "bạn đã có 3 món ăn là là đầy đặn, nếu bạn muốn gọi thêm 1 món nữa, chúng tôi đề xuất một món khá là nhẹ nhàng"
                int min_point = 1000;
                struct Menu* m = menu;
                while (m != NULL) {
                    if (m->point < min_point) {
                        min_point = m->point;
                        strcpy(result, m->name);
                    }
                    m = m->next;
                }
                strcpy(reason, "Bạn đã có 3 món ăn đầy đặn, nếu muốn gọi thêm, chúng tôi đề xuất một món khá là nhẹ nhàng.");
            }
        } else if (nums_dish == 2) {
            // Nếu đã gọi 2 món: Vẫn tính tổng point như trên, tìm món gần nhất với 100 - point. Kết qủa là tên 1 món ăn đó.
            // reason: "vì bạn đã gọi 2 món nên chúng tôi đề xuất thêm 1 món thứ 3 để đảm bảo sự hoàn thiện của bữa ăn."
            int target = 100 - total_point;
            struct Menu* m = menu;
            int min_diff = 1000;
            char temp_result[100] = "";
            while (m != NULL) {
                int diff = abs(m->point - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    strcpy(temp_result, m->name);
                }
                m = m->next;
            }
            strcpy(result, temp_result);
            strcpy(reason, "Vì bạn đã gọi 2 món nên chúng tôi đề xuất thêm 1 món thứ 3 để đảm bảo sự hoàn thiện của bữa ăn.");
        } else if (nums_dish == 1) {
            // Nếu đã gọi 1 món: Tính 100 - point, dùng 2 vòng lặp lồng nhau để tìm tổ hợp các món có tổng gần nhất với 100 - point. Kết quả là tên 2 món đó
                // Nếu point >=40, reason là "vì bạn đã gọi một món chính khá đậm đà, no lâu nên chúng tôi đề xuất món khai vị và tráng miện như sau"
                // Nếu point <40, reason là "Vì bạn chưa gọi món chính nên chúng tôi để xuất thêm 1 món chính và 1 món ăn kèm, nó sẽ kết hợp cùng món bạn đã gọi để đảm bảo sự hài hoàm cân đối cho bữa ăn".
            int best_point = 100 - total_point;
            struct Menu* m = menu;
            char dish1[100], dish2[100];
            int tmp = 1000;
            while (m != NULL) {
                int p1 = m->point;
                struct Menu* m2 = menu;
                while (m2 != NULL) {
                    int p2 = m2->point;
                    int sum = p1 + p2;
                    if (abs(best_point - sum) < tmp) {
                        strcpy(dish1, m->name);
                        strcpy(dish2, m2->name);
                        tmp = abs(best_point - sum);
                    }
                    m2 = m2->next;
                }
                m = m->next;
            }
            snprintf(result, sizeof(result), "%s và %s", dish1, dish2);
            if (total_point >= 40) {
                strcpy(reason, "Vì bạn đã gọi một món chính khá đậm đà, no lâu nên chúng tôi đề xuất món khai vị và tráng miệng như sau.");
            } else {
                strcpy(reason, "Vì bạn chưa gọi món chính nên chúng tôi đề xuất thêm 1 món chính và 1 món ăn kèm để bữa ăn hoàn thiện.");
            }
        } else if (nums_dish == 0) {
            // Nếu đã gọi 0 món: Món đầu chọn món Best_Seller, 2 món còn lại tìm như trên như nums_dish == 1. Kết quả là tên 3 món đó
            // reason: "Vì bạn chưa biết nên ăn gì ở cửa hàng chúng tôi, nên chúng tôi đề xuất 1 món là bestseller của quán, đi kèm là 2 món ăn phù hợp."
            // Lấy món Best_Seller
//            char* bestseller = get_bestseller(menu);
//            int point_best = get_point(menu, bestseller);
//            int remaining = 100 - point_best;
            // vì chưa viết hàm get_bestseller nên tôi lấy giá tị giả, đừng quan tâm đến nó
            char bestseller[100] = "Mi hai san";
            int point_bestseller = 47;
            int remaining = 100 - point_bestseller;
            
            // Tìm 2 món khác sao cho tổng gần nhất với remaining
            int best_point = 0;
            char dish1[100], dish2[100];
            struct Menu* m1 = menu;
            while (m1 != NULL) {
                int p1 = m1->point;
                struct Menu* m2 = menu;
                while (m2 != NULL) {
                    int p2 = m2->point;
                    if ((p1 + p2 <= remaining) && (p1 + p2 > best_point) && strcmp(m1->name, bestseller) != 0 && strcmp(m2->name, bestseller) != 0) {
                        best_point = p1 + p2;
                        strcpy(dish1, m1->name);
                        strcpy(dish2, m2->name);
                    }
                    m2 = m2->next;
                }
                m1 = m1->next;
            }
            
            // Kết quả gợi ý
            snprintf(result, sizeof(result), "%s, %s, %s", bestseller, dish1, dish2);
            strcpy(reason, "Vì bạn chưa gọi món nào, nên chúng tôi đề xuất 1 món Bestseller của quán, đi kèm là 2 món khai vị và tráng miệng phù hợp.");
        }

        // In khung kết quả
        inKhungGoiY(reason, result);
    } else {
        // Ứng dụng thuật toán tham lam
        int current = nums_customers;
        int combo5 = current / 5;
        int remain = current % 5;
        int combo3 = 0, combo2 = 0;
        while (combo5 >= 0) {
            remain = current - combo5 * 5;
            combo3 = remain / 3;
            remain %= 3;

            if (remain % 2 == 0) {
                combo2 = remain / 2;
                printf("╔════════════════════════════════════════════════════╗\n");
                inDongGiua("GỢI Ý GỌI MÓN");
                printf("╠════════════════════════════════════════════════════╣\n");
                printf("║ Vì bạn đi theo nhóm %2d người nên chúng tôi có gợi  ║\n", nums_customers);
                printf("║ ý các Combo sau:                                   ║\n");
                if (combo5 > 0) {
                    printf("║      - %2d Combo 5 người %-24s ║\n", combo5, (combo3 > 0 || combo2 > 0) ? "và" : "");
                }
                if (combo3 > 0) {
                    printf("║      - %2d Combo 3 người %-24s ║\n", combo3, combo2 > 0 ? "và" : "");
                }
                if (combo2 > 0) {
                    printf("║      - %2d Combo 2 người                            ║\n", combo2);
                }
                printf("╚════════════════════════════════════════════════════╝\n");
                return;
            }
            combo5--;
        }
    }
}
