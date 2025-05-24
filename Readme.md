# Bài tập lớn môn Cấu trúc Dữ liệu và Giải thuật

## Chủ đề: Thiết kế chương trình quản lý nhà hàng

### I. Phân chia công việc

| Thành viên (MSSV)       | Nhiệm vụ chính                                                                 | Các hàm cần viết                                                                                                  |
|-------------------------|----------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **Bùi Đức Thông (20234038)** | - Viết hàm `main()`  <br> - Phân chia công việc <br> - Viết comment mô tả cho từng hàm <br> - Triển khai tính năng gợi ý | hàm `main()` <br> file `data_structure` <br>file `tinh_nang_goi_y`                                                        |
| **Thành viên 2**        | - Viết 11 của file `interface` <br> - Tạo menu quán <br> - Viết chức năng (4)Xem menu <br> - Viết chức năng (5)Xem sơ đồ quán | file `4_chuc_nang_menu` <br> file `5_chuc_nang_xem_so_do_quan` <br> file `interface` có 11 hàm con <br> hàm `nhap_so_nguyen` <br> hàm `nhap_chuoi` <br> hàm `to_lowercase_no_accent` <br> hàm `to_lowercase` <br> hàm `add_menu` <br> hàm `init_menu` <br> hàm `init_restaurant` <br> hàm `them_mon_vao_menu` <br> hàm `sua_gia_mon_an` <br> hàm `xoa_mon_an_khoi_menu`|
| **Thành viên 3**        | - Viết chức năng (1)Thêm hoá đơn <br> - Viết chức năng (2)Sửa hoá đơn| file `1_chuc_nang_them_hoa_don` <br> file `2_chuc_nang_sua_hoa_don` <br> hàm `search_table` <br> hàm `add_dish_to_bill` <br> hàm `search_dish` <br> hàm `sua_so_luong_mon` <br> hàm `order_dish`                  |
| **Thành viên 4**        | - Viết chức năng (3)Thanh toán <br> - Viết chức năng (6)Data            | file `3_chuc_nang_thanh_toan` <br> file `3_chuc_nang_thanh_toan` <br> hàm `push_to_top_seller_list` <br> hàm `get_point`|

### II. Tổng quan

#### 1. Cấu trúc dữ liệu:

##### a) Menu:

```
┌────┐   ┌─────┐   ┌─────┐
│menu│ → │Món 1│ → │Món 2│ → ... → NULL
└────┘   └─────┘   └─────┘
```

##### b) Top\_seller:

```
┌──────────┐   ┌──────────┐   ┌─────────┐
│top_seller│ → │Bestseller│ → │Món Thứ 2│ → ... → NULL
└──────────┘   └──────────┘   └─────────┘
```

##### c) Staff:

```
┌─────────┐   ┌───────────┐   ┌───────────┐
│listStaff│ → │Nhân viên 1│ → │Nhân viên 2│ → ... → NULL
└─────────┘   └───────────┘   └───────────┘
```

##### d) Table

```
┌────────────┐   ┌────────────┐   ┌────────────┐
│            │   │ id: 1      │   │ id: 2      │ 
│ restaurant │ → │ Status: 0  │ → │ Status: 0  │ → ... → NULL
│            │   │ Bill: NULL │   │ Bill: NULL │
└────────────┘   └────────────┘   └────────────┘
```

##### e) Bill

```
┌───────────────────────────────────────────────┐
│                  listBill                     │
└───────────────────────────────────────────────┘
                       ↓
┌───────────────────────────────────────────────┐
│ totalPrice: 0                                 │
│ nameStaff[100]: ""                            │
│ ┌─────────┐   ┌─────┐   ┌─────┐               │
│ │firstDish│ → │Món 1│ → │Món 2│ → ... → NULL  │
│ └─────────┘   └─────┘   └─────┘               │
└───────────────────────────────────────────────┘
                       ↓
┌───────────────────────────────────────────────┐
│ totalPrice: 0                                 │
│ nameStaff[100]: ""                            │
│ ┌─────────┐   ┌─────┐   ┌─────┐               │
│ │firstDish│ → │Món 1│ → │Món 2│ → ... → NULL  │
│ └─────────┘   └─────┘   └─────┘               │
└───────────────────────────────────────────────┘
                       ↓
┌───────────────────────────────────────────────┐
│ totalPrice: 0                                 │
│ nameStaff[100]: ""                            │
│ ┌─────────┐   ┌─────┐   ┌─────┐               │
│ │firstDish│ → │Món 1│ → │Món 2│ → ... → NULL  │
│ └─────────┘   └─────┘   └─────┘               │
└───────────────────────────────────────────────┘
                       ↓
                      ...
                       ↓
                      NULL
```

#### 2. Giải thuật:

##### a) Giải thuật tham lam: Ứng dụng trong tính năng gợi ý chọn món khi người dùng đi theo nhóm nhiều người.

##### b) Brute Force: Ứng dụng trong tính năng gợi ý chọn món khi người dùng đã chọn được 1 món, thuật toán sử dụng 2 vòng lặp lồng nhau để tìm ra 2 món ăn còn lại phù hợp với món ăn đầu để gợi ý.

##### c) Insertion Sort: Ứng dụng trong việc thêm các món ăn vào trong top_seller.

##### d) Duyệt tuyến tính (Linear Search): Được dùng nhiều lần để tìm kiếm.


### III. Chi tiết chương trình

#### 1. Cách thức hoạt động của chương trình:

##### 1.0 Đăng nhập

```
╔════════════════════════════════════════════════════╗
║             HỆ THỐNG QUẢN LÝ NHÀ HÀNG              ║
╠════════════════════════════════════════════════════╣
║     1. Đăng nhập                   2. Thoát        ║
╚════════════════════════════════════════════════════╝
```

Khi bắt đầu chương trình, tuỳ chọn đăng nhập sẽ được hiển thị để nhân viên nhập tên, sau đó, tên sẽ được lưu vào listStaff và bắt đầu ca làm việc.

```
╔════════════════════════════════════════════════════╗
║             HỆ THỐNG QUẢN LÝ NHÀ HÀNG              ║
╠════════════════════════════════════════════════════╣
║ 1. Thêm hoá đơn                   4. Menu          ║
║ 2. Sửa hoá đơn                    5. Sơ đồ quán    ║
║ 3. Thanh toán                     6. Data          ║
║                  7. Đăng xuất                      ║
╚════════════════════════════════════════════════════╝
```

Giao diện chính với 6 chức năng, chọn từng chức năng để làm việc. Khi xong ca làm việc thì tuỳ chọn đăng xuất sẽ cho bạn về màn hình đăng nhập ban đầu.

##### 1.1 Chức năng thêm hoá đơn

##### 1.2 Chức năng sửa hoá đơn

##### 1.3 Chức năng thanh toán

##### 1.4 Chức năng xem menu quán

##### 1.5 Chức năng xem sơ đồ quán

##### 1.1 Chức năng xem các dữ liệu của quán
