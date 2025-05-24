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
        if (nums_dish == 3) {
            // Nếu đã gọi 3 món: Cộng tổng point của 3 món đã gọi
                // Nếu tổng point bé hơn 100 tức là chưa có món chính, tìm 1 món chính gần nhất với 100 - point (món chính là món có point >40). reason = "Vì bạn chưa có món chính, nên chúng tôi sẽ đề xuất 1 món chính phù hợp để đảm bảo sự hoàn thiện của bữa ăn"
            if (total_point < 100) {
                int min_diff = 100 - total_point;
                    int smallest_diff = 1000;
                    struct Menu* m = menu;
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
                // Nếu tổng point lớn hơn 100, tìm món có point thấp nhất. reason = "bạn đã có 3 món ăn là là đầy đặn, nếu bạn muốn gọi thêm 1 món nữa, chúng tôi đề xuất một món khá là nhẹ nhàng"
                int min_point = 1000;
                struct Menu* m = menu;
                while (m != NULL) {
                    if (m->point < min_point && !is_dish_ordered(listDish, m->name)) {
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
                    if (!is_dish_ordered(listDish, m->name) && !is_dish_ordered(listDish, m2->name)) {
                        if (abs(best_point - sum) < tmp) {
                            strcpy(dish1, m->name);
                            strcpy(dish2, m2->name);
                            tmp = abs(best_point - sum);
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
                strcpy(reason, "Vì bạn chưa gọi món chính nên chúng tôi đề xuất thêm 1 món chính và 1 món ăn kèm để bữa ăn hoàn thiện.");
            }
        } else if (nums_dish == 0) {
            // Nếu đã gọi 0 món: Món đầu chọn món Best_Seller, 2 món còn lại tìm như trên như nums_dish == 1. Kết quả là tên 3 món đó
            // reason: "Vì bạn chưa biết nên ăn gì ở cửa hàng chúng tôi, nên chúng tôi đề xuất 1 món là bestseller của quán, đi kèm là 2 món ăn phù hợp."
            // Lấy món Best_Seller
            struct Top_seller* bestseller = top_seller->next;
            int point_bestseller = get_point(menu, bestseller->name);
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
                    if ((p1 + p2 <= remaining) && (p1 + p2 > best_point) && strcmp(m1->name, bestseller->name) != 0 && strcmp(m2->name, bestseller->name) != 0 && !is_dish_ordered(listDish, m1->name) && !is_dish_ordered(listDish, m2->name)) {
                        best_point = p1 + p2;
                        strcpy(dish1, m1->name);
                        strcpy(dish2, m2->name);
                    }
                    m2 = m2->next;
                }
                m1 = m1->next;
            }
            
            // Kết quả gợi ý
            snprintf(result, sizeof(result), "%s, %s, %s", bestseller->name, dish1, dish2);
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
        if (nums_customers == 2 || nums_customers == 4) {
            combo2 = nums_customers / 2;
            inKetQuaGoiY(nums_customers, combo5, combo3, combo2);
        } else if (nums_customers == 3) {
            combo3 = 1;
            inKetQuaGoiY(nums_customers, combo5, combo3, combo2);
        }
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

