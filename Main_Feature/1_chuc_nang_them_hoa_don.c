#include "1_chuc_nang_them_hoa_don.h"

void chuc_nang_them_hoa_don(struct Table* restaurant, struct Menu* menu, struct Top_seller* top_seller) {
    int table_id = 0;
    struct Table* table = NULL;
    struct Bill* bill = (struct Bill*)malloc(sizeof(struct Bill));
    bill->totalPrice = 0;
    do {
        printf("📥 Khách vào ở bàn số: ");
        nhap_so_nguyen(&table_id);
        table = search_table(restaurant, table_id);
        if (table == NULL) {
            inThongBao("Bàn số %d không tồn tại, vui lòng nhập lại!", table_id);
        } else if (table->status == 1) {
            inThongBao("Bàn số %d đang có khách, không thể tạo hóa đơn mới.", table_id);
            table = NULL;
        }
    } while (table == NULL);
    
    int nums_customers = 0;
    while (1) {
        printf("Nhập số lượng khách vào ở bàn %d: ", table_id);
        nhap_so_nguyen(&nums_customers);
        if (nums_customers > 0) {
            break;
        } else {
            inThongBao("Số lượng khách không hợp lệ! Vui lòng nhập lại.");
        }
    }
    struct Dish_ordered* firstDish = (struct Dish_ordered*)malloc(sizeof(struct Dish_ordered));
    strncpy(firstDish->name, "Tra da", sizeof(firstDish->name) - 1);
    firstDish->name[sizeof(firstDish->name) - 1] = '\0';
    firstDish->quantity = nums_customers;
    firstDish->next = NULL;

    bill->listDish = firstDish;
    table->status = 1;
    table->bill = bill;
    inThongBao("Đã thêm %d Trà đá miễn phí cho bàn %d.", nums_customers, table_id);
    
    order_dish(table, menu, bill, top_seller);
    inThongBao("Hóa đơn bàn %d đã tạo xong, tổng tiền: %d VND", table_id, bill->totalPrice);
}
