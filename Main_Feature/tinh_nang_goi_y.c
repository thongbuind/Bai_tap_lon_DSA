#include "tinh_nang_goi_y.h"

int is_dish_ordered(struct Dish_ordered* listDish, const char* name) {
    struct Dish_ordered* ptr = listDish->next;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) return 1;
        ptr = ptr->next;
    }
    return 0;
}

void inKetQuaGoiY(int nums_customers, int combo5, int combo3, int combo2) {
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
}

void tinh_nang_goi_y(struct Table* table, struct Menu* menu, struct Top_seller* top_seller) {
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
        if (nums_dish >= 3) {
            // Kiểm tra xem có món chính (point > 40) trong danh sách món đã gọi hay không
            int has_main_dish = 0;
            struct Dish_ordered* current_dish = listDish->next;
            while (current_dish != NULL) {
                if (get_point(menu, current_dish->name) > 40) {
                    has_main_dish = 1;
                    break;
                }
                current_dish = current_dish->next;
            }

            if (!has_main_dish) {
                // Nếu không có món chính, tìm món chính (point > 40) gần nhất với (100 - total_point)
                int min_diff = 100 - total_point;
                int smallest_diff = 1000;
                struct Menu* m = menu->next;
                char temp_result[100] = "";
                while (m != NULL) {
                    if (m->point > 40 && !is_dish_ordered(listDish, m->name)) {
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
                // Nếu đã có món chính, tìm món có point thấp nhất
                int min_point = 1000;
                struct Menu* m = menu->next;
                char temp_result[100] = "";
                while (m != NULL) {
                    if (m->point < min_point && !is_dish_ordered(listDish, m->name)) {
                        min_point = m->point;
                        strcpy(temp_result, m->name);
                    }
                    m = m->next;
                }
                strcpy(result, temp_result);
                strcpy(reason, "Bạn đã có 3 món ăn đầy đặn, nếu muốn gọi thêm, chúng tôi đề xuất một món khá là nhẹ nhàng.");
            }
        } else if (nums_dish == 2) {
            // Nếu đã gọi 2 món: Tìm món gần nhất với 100 - total_point
            int target = 100 - total_point;
            struct Menu* m = menu;
            int min_diff = 1000;
            char temp_result[100] = "";
            while (m != NULL) {
                if (!is_dish_ordered(listDish, m->name)) {
                    int diff = abs(m->point - target);
                    if (diff < min_diff) {
                        min_diff = diff;
                        strcpy(temp_result, m->name);
                    }
                }
                m = m->next;
            }
            strcpy(result, temp_result);
            strcpy(reason, "Vì bạn đã gọi 2 món nên chúng tôi đề xuất thêm 1 món thứ 3 để đảm bảo sự hoàn thiện của bữa ăn.");
        } else if (nums_dish == 1) {
            int best_point = 100 - total_point;
            struct Menu* m = menu;
            char dish1[100] = "", dish2[100] = "";
            int tmp = 999;

            // Duyệt tất cả các cặp món ăn
            while (m != NULL) {
                struct Menu* m2 = m->next;
                while (m2 != NULL) {
                    if (m->name[0] != '\0' && m2->name[0] != '\0' &&
                        !is_dish_ordered(listDish, m->name) &&
                        !is_dish_ordered(listDish, m2->name) &&
                        strcmp(m->name, m2->name) != 0) {
                        int sum = m->point + m2->point;
                        int diff = abs(best_point - sum);
                        if (diff < tmp) {
                            strcpy(dish1, m->name);
                            strcpy(dish2, m2->name);
                            tmp = diff;
                        }
                    }
                    m2 = m2->next;
                }
                m = m->next;
            }

            snprintf(result, sizeof(result), "%s và %s", dish1, dish2);
            if (total_point >= 40) {
                strcpy(reason, "Vì bạn đã gọi một món chính khá đậm đà, no lâu nên chúng tôi đề xuất món khai vị và tráng miệng như sau.");
            } else {
                strcpy(reason, "Vì bạn chưa gọi món chính nên chúng tôi đề xuất thêm 1 món chính và 1 món ăn kèm, nó sẽ kết hợp cùng món bạn đã gọi để đảm bảo sự hài hòa cân đối cho bữa ăn.");
            }
        } else if (nums_dish == 0) {
            // Nếu đã gọi 0 món: Món đầu chọn món Best_Seller, 2 món còn lại tìm như trên
            struct Top_seller* bestseller = top_seller->next;
            int point_bestseller = get_point(menu, bestseller->name);
            int remaining = 100 - point_bestseller;
            
            int best_diff = 999;
            char dish1[100] = "";
            char dish2[100] = "";
            struct Menu* m1 = menu->next;
            while (m1 != NULL) {
                if (strcmp(m1->name, bestseller->name) == 0 || is_dish_ordered(listDish, m1->name)) {
                    m1 = m1->next;
                    continue;
                }
                int p1 = m1->point;
                struct Menu* m2 = menu->next;
                while (m2 != NULL) {
                    if (m2 == m1 || strcmp(m2->name, bestseller->name) == 0 ||
                        is_dish_ordered(listDish, m2->name) || strcmp(m1->name, m2->name) == 0) {
                        m2 = m2->next;
                        continue;
                    }
                    int p2 = m2->point;
                    int total = p1 + p2;
                    int diff = abs(total - remaining);
                    if (diff < best_diff) {
                        best_diff = diff;
                        strcpy(dish1, m1->name);
                        strcpy(dish2, m2->name);
                    }
                    m2 = m2->next;
                }
                m1 = m1->next;
            }
            
            snprintf(result, sizeof(result), "%s, %s, %s", bestseller->name, dish1, dish2);
            strcpy(reason, "Vì bạn chưa gọi món nào, nên chúng tôi đề xuất 1 món Bestseller của quán, đi kèm là 2 món khai vị và tráng miệng phù hợp.");
        }
        inKhungGoiY(reason, result);
    } else {
        // Ứng dụng thuật toán tham lam
        int current = nums_customers;
        int combo5 = current / 5;
        int remain = current % 5;
        int combo3 = 0, combo2 = 0;
        if (nums_customers == 2 || nums_customers == 4) {
            combo2 = nums_customers / 2;
            inKetQuaGoiY(nums_customers, combo5, combo3, combo2);
        } else if (nums_customers == 3) {
            combo3 = 1;
            inKetQuaGoiY(nums_customers, combo5, combo3, combo2);
        } else {
            while (combo5 >= 0) {
                remain = current - combo5 * 5;
                combo3 = remain / 3;
                remain %= 3;

                if (remain % 2 == 0) {
                    combo2 = remain / 2;
                    inKetQuaGoiY(nums_customers, combo5, combo3, combo2);
                    return;
                }
                combo5--;
            }
        }
    }
}
