SẼ THAY TRANG NÀY THÀNH 1 TRANG BÌA ĐẸP
---

**BÁO CÁO MÔN HỌC**  
**CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT**  

**Đề tài**: Thiết kế chương trình quản lý nhà hàng  

<div style="page-break-before: always;"></div>

## MỤC LỤC

| Phần | Nội dung                                     | Trang |
|--------------------|--------------------------------|-------|
| I. Phân chia công việc    |                         |       |
| II. Tổng quan     | 1. Cấu trúc Dữ liệu             |       |
|      | 2. Giải thuật                                |       |
|III. Chi tiết Chương trình| 0. Giao diện Đăng nhập   |       |
|      | 1. Chức năng Thêm Hoá đơn                    |       |
|      | 2. Chức năng Sửa Hoá đơn                     |       |
|      | 3. Chức năng Thanh toán                      |       |
|      | 4. Chức năng Xem Menu quán                   |       |
|      | 5. Chức năng Xem Sơ đồ quán                  |       |
|      | 6. Chức năng Xem các Dữ liệu của quán        |       |
|IV. Phụ lục| 1. Thiết kế Menu và Cấu trúc Hương vị   |       |
|      | 2. Tính năng Gợi ý Món ăn                    |       |

<div style="page-break-before: always;"></div>

## I. Phân chia công việc

| Thành viên| Nhiệm vụ chính| Các hàm cần viết|
|--------|-----------------------------------------|-----------------------------------------|
| **Bùi Đức Thông (20234038)** | - Viết hàm `main()`  <br> - Phân chia công việc <br> - Viết comment mô tả chức năng, input-output cho từng hàm <br> - Triển khai tính năng gợi ý | hàm `main()` <br> file `data_structure` <br> file `tinh_nang_goi_y` |
| **Thành viên 2**        | - Viết file `interface` <br> - Tạo menu quán <br> - Viết chức năng (4)Xem menu <br> - Viết chức năng (5)Xem sơ đồ quán | file `4_chuc_nang_menu` <br> file `5_chuc_nang_xem_so_do_quan` <br> file `interface` có 11 hàm con <br> hàm `nhap_so_nguyen` <br> hàm `nhap_chuoi` <br> hàm `to_lowercase_no_accent` <br> hàm `to_lowercase` <br> hàm `add_menu` <br> hàm `init_menu` <br> hàm `init_restaurant` <br> hàm `them_mon_vao_menu` <br> hàm `sua_gia_mon_an` <br> hàm `xoa_mon_an_khoi_menu` |
| **Thành viên 3**        | - Viết chức năng (1)Thêm hoá đơn <br> - Viết chức năng (2)Sửa hoá đơn | file `1_chuc_nang_them_hoa_don` <br> file `2_chuc_nang_sua_hoa_don` <br> hàm `search_table` <br> hàm `add_dish_to_bill` <br> hàm `search_dish` <br> hàm `sua_so_luong_mon` <br> hàm `order_dish` |
| **Thành viên 4**        | - Viết chức năng (3)Thanh toán <br> - Viết chức năng (6)Data            | file `3_chuc_nang_thanh_toan` <br> file `6_chuc_nang_data` <br> hàm `push_to_top_seller_list` <br> hàm `get_point` |

<div style="page-break-before: always;"></div>

## II. Tổng quan

### 1. Cấu trúc dữ liệu

#### a) Menu

```
┌────┐   ┌─────┐   ┌─────┐
│menu│ → │Món 1│ → │Món 2│ → ... → NULL
└────┘   └─────┘   └─────┘
```

#### b) Top\_seller:

```
┌──────────┐   ┌──────────┐   ┌─────────┐
│top_seller│ → │Bestseller│ → │Món Thứ 2│ → ... → NULL
└──────────┘   └──────────┘   └─────────┘
```

#### c) Staff:

```
┌─────────┐   ┌───────────┐   ┌───────────┐
│listStaff│ → │Nhân viên 1│ → │Nhân viên 2│ → ... → NULL
└─────────┘   └───────────┘   └───────────┘
```

#### d) Table

```
┌────────────┐   ┌────────────┐   ┌────────────┐
│            │   │ id: 1      │   │ id: 2      │ 
│ restaurant │ → │ Status: 0  │ → │ Status: 0  │ → ... → NULL
│            │   │ Bill: NULL │   │ Bill: NULL │
└────────────┘   └────────────┘   └────────────┘
```

<div style="page-break-before: always;"></div>

#### e) Bill

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

<div style="page-break-before: always;"></div>

### 2. Giải thuật

- **Greedy Algorithm**: Ứng dụng để gợi ý món phù hợp cho nhóm nhiều người. Trong menu có các combo 2,3,5 người, thuật toán tham lam sẽ ưu tiên lựa chọn **Combo 5 người**, rồi đến **Combo 3 người** và cuối cùng là **Combo 2 người** sao cho tổng chúng bằng số lượng khách.
- **Brute Force**: Sử dụng 2 vòng lặp lồng nhau để duyệt qua từng tổ hợp món và tìm ra tổ hợp phù hợp nhất. Ứng dụng khi đã có 1 món ăn và muốn gợi ý 2 món còn lại.
- **Insertion Sort**: Được sử dụng khi thêm món vào danh sách top_seller. Thuật toán hoạt động bằng cách duyệt từ đầu đến cuối trong danh sách liên kết. Nếu món ăn chưa xuất liện trong danh sách, một `node` mới sẽ được tạo và chèn vào vị trí đúng theo thứ tự giảm dần số lượng. Insertion Sort hoạt động rất hiệu quả trong tình huống này vì danh sách liên kết đã được sắp xếp sẵn.
- **Linear Search**: Áp dụng để tìm kiếm món ăn, bàn, nhân viên,...

<div style="page-break-before: always;"></div>

## III. Chi tiết chương trình

### 0. Giao diện Đăng nhập

```
╔════════════════════════════════════════════════════╗
║             HỆ THỐNG QUẢN LÝ NHÀ HÀNG              ║
╠════════════════════════════════════════════════════╣
║     1. Đăng nhập                   2. Thoát        ║
╚════════════════════════════════════════════════════╝
```

Sau khi chọn đăng nhập, nhân viên nhập tên → tên được lưu vào `listStaff` → bắt đầu ca làm.

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

Giao diện chính với 6 chức năng, chọn từng chức năng để làm việc. Khi xong ca làm việc, tuỳ chọn đăng xuất sẽ cho bạn về màn hình đăng nhập ban đầu.

<div style="page-break-before: always;"></div>

### 1. Chức năng Thêm Hoá đơn

- **Nhập thông tin bàn và khách**: Sử dụng hai vòng lặp `while` để yêu cầu nhập:  
    - `table_id`: Mã số bàn.  
    - `nums_customer`: Số lượng khách.  

- **Khởi tạo hoá đơn**: Tự động thêm `nums_customer` cốc **trà đá miễn phí** vào hoá đơn.  

- **Nhập món ăn**: Sử dụng vòng lặp `while` để yêu cầu nhập tên món ăn, số lượng cho đến khi người dùng nhấn **'xong'**.

- **Hỗ trợ khách hàng**: Nếu khách hàng phân vân, có thể nhập:  
    - **'goi y'**: Hiển thị tính năng gợi ý chọn món (xem **Phụ lục 2**).  
    - **'menu'**: Hiển thị toàn bộ menu.

### 2. Chức năng Sửa Hoá đơn

```
╔════════════════════════════════════════════════════╗
║                 SỬA HOÁ ĐƠN BÀN  1                 ║
╠════════════════════════════════════════════════════╣
║ 1. Thêm món                                        ║
║ 2. Xóa món                                         ║
║ 3. Sửa số lượng món                                ║
║ 4. Thoát                                           ║
╚════════════════════════════════════════════════════╝
```

<div style="page-break-before: always;"></div>

### 3. Chức năng Thanh toán

- **Nhập mã bàn**: Yêu cầu nhập `table_id` của bàn muốn thanh toán.  
- Nếu bàn chưa có khách hoặc không có hóa đơn, hệ thống hiển thị:

```
╔════════════════════════════════════════════════════╗
║ Bàn không tồn tại, trống hoặc không có hóa đơn.    ║
╚════════════════════════════════════════════════════╝
```

- Nếu bàn đã có hóa đơn, hệ thống hiển thị thông tin hóa đơn để xác nhận:  

```
╔════════════════════════════════════════════════════╗
║  Bàn 1 có bill: 1200000 VND                        ║
╠═════════════════════════╦═════════╦════════════════╣
║ Món ăn                  ║ SL      ║ Thành tiền     ║
╠═════════════════════════╬═════════╬════════════════╣
║ goi cuon                ║ 1       ║ 300000         ║
║ pho bo                  ║ 2       ║ 600000         ║
║ tiramisu                ║ 1       ║ 300000         ║
╠═════════════════════════╩═════════╩════════════════╣
║ Xác nhận thanh toán:                               ║
║ 1. Xác nhận                                        ║
║ 2. Hủy                                             ║
╚════════════════════════════════════════════════════╝
```

- **Sau khi thanh toán**:
  - Hóa đơn được lưu vào `listBill`.  
  - Các món ăn được thêm vào `top_seller`.  
  - Tổng tiền của bill sẽ được cộng dồn vào `totalRevenue`.

<div style="page-break-before: always;"></div>

### 4. Chức năng Xem Menu quán

```
╔════════════════════════════════════════════════════╗
║                       MENU                         ║
╠════════════════════════════════════════════════════╣
║ Danh sách các món ăn sẽ hiển thị ở đây             ║
╠════════════════════════════════════════════════════╣
║ 1. Thêm món vào menu                               ║
║ 2. Sửa giá món ăn                                  ║
║ 3. Xóa món ăn khỏi menu                            ║
║ 4. Thoát.                                          ║
╚════════════════════════════════════════════════════╝
```

Chức năng này hỗ trợ 3 tuỳ chọn để chỉnh sửa **menu**:

- Thêm món ăn mới: Nhập các thông tin của món ăn, tạo `node` mới và chèn vào cuối **menu**.
- Sửa giá món ăn: Nhập **tên món ăn**, duyệt tuần tự trong **menu** để tìm món ăn có tên trùng khớp và thay đổi giá món.
- Xóa món ăn khỏi menu: Duyệt tương tự, xoá bằng cách gián tiếp. Lưu thông tin `node` tiếp theo vào 1 biến tạm, trỏ `node` hiện tại đến `next->next`, xoá `next`, lấy thông tin của biến tạm để cho vào `node` hiện tại.

<div style="page-break-before: always;"></div>

### 5. Chức năng Xem Sơ đồ quán

```
╔════════════════════════════════════════════════════╗
║                 SƠ ĐỒ QUÁN (10 BÀN)                ║
╠════════════════════════════════════════════════════╣
║ ╔════════════╗   ╔════════════╗    ╔════════════╗  ║
║ ║ B1 [Khách] ║   ║ B2 [Trống] ║    ║ B3 [Khách] ║  ║
║ ╚════════════╝   ╚════════════╝    ╚════════════╝  ║ 
║ ╔════════════╗   ╔════════════╗    ╔════════════╗  ║
║ ║ B4 [Trống] ║   ║ B5 [Trống] ║    ║ B6 [Khách] ║  ║
║ ╚════════════╝   ╚════════════╝    ╚════════════╝  ║ 
║ ╔════════════╗   ╔════════════╗    ╔════════════╗  ║
║ ║ B7 [Trống] ║   ║ B8 [Khách] ║    ║            ║  ║
║ ╚════════════╝   ╚════════════╝    ║ B9 [Trống] ║  ║ 
║ ╔═════════════════════════════╗    ║            ║  ║
║ ║          B10 [Khách]        ║    ║            ║  ║ 
║ ╚═════════════════════════════╝    ╚════════════╝  ║ 
╠════════════════════════════════════════════════════╣
║ 1. Xem chi tiết bàn                                ║
║ 2. Thoát                                           ║
╚════════════════════════════════════════════════════╝
```

Khi chọn xem chi tiết bàn, nhân viên sẽ thấy được các thông tin ví dụ như sau:

```
╔═══════════════════════════╗
║      Chi tiết bàn  1      ║
║ Trạng thái: Bàn có khách  ║
║ Danh sách món đã gọi:     ║
║ - Tra da              x1  ║
║ - goi cuon            x1  ║
║ - bit tet             x1  ║
║ - tiramisu            x1  ║
║ Tổng bill: 900000     VND ║
╚═══════════════════════════╝
```

<div style="page-break-before: always;"></div>

### 6. Chức năng Xem các Dữ liệu của quán

```
╔════════════════════════════════════════════════════╗
║                 CHỨC NĂNG QUẢN LÝ                  ║
╠════════════════════════════════════════════════════╣
║ 1. Dữ liệu thống kê                                ║
║ 2. Quản lý nhân viên                               ║
║ 3. Quản lý hoá đơn                                 ║
║ 4. Thoát.                                          ║
╚════════════════════════════════════════════════════╝
```

```
╔════════════════════════════════════════════════════╗
║                  DỮ LIỆU THỐNG KÊ                  ║
╠════════════════════════════════════════════════════╣
║ Tổng số bill: 17                                   ║
║ Tổng số lượng khách: 24                            ║
║ Trung bình khách/bill: 1.58                        ║
║ Tổng doanh thu: 38700000                           ║
║ Top 1: tiramisu        SL: 62                      ║
║ Top 2: sushi           SL: 22                      ║
║ Top 3: bingsu hoa qua  SL: 18                      ║
║ Top 4: bit tet         SL: 18                      ║
║ Top 5: kem chanh       SL: 9                       ║
╚════════════════════════════════════════════════════╝
```

```
╔════════════════════════════════════════════════════╗
║                 QUẢN LÝ NHÂN VIÊN                  ║
╠═══╦═══════════════════════╦═══════════╦════════════╣
║STT║ Tên nhân viên         ║ Số bill   ║ Doanh thu  ║
╠═══╬═══════════════════════╬═══════════╬════════════╣
║ 1 ║ van thanh             ║     3     ║  9000000   ║
║ 2 ║ quang minh            ║     4     ║ 11300000   ║
║ 3 ║ nhat thien            ║    10     ║ 18400000   ║
╚═══╩═══════════════════════╩═══════════╩════════════╝
```

<div style="page-break-before: always;"></div>

## IV. Phụ lục

### 1. Thiết kế Menu và Cấu trúc Hương vị

Menu gồm đa dạng món ăn được chia thành 3 nhóm: **khai vị**, **món chính**, **tráng miệng**, với nhiều tầng hương vị và phong cách khác nhau, được đánh giá trực quan thông qua chỉ số `Point`.

| **Loại món ăn** | **Tên món ăn**       | **Point** | **Giá tiền (VND)** | **Mô tả món ăn**            |
|--------------------|----------------------|-----------|----------------|------------------------------|
| Khai vị        | Gỏi cuốn             | 15        | 300,000            | Nhẹ nhàng, tươi mát          |
| Khai vị        | Salad                | 21        | 300,000            | Nhẹ nhàng, tươi mát          |
| Khai vị        | Tempura tôm          | 29        | 300,000            | Hương đậm đà                 |
| Khai vị        | Chả giò              | 34        | 300,000            | Hương đậm đà                 |
| Khai vị        | Bánh kimchi          | 39        | 300,000            | Hương đậm đà                 |
| Món chính      | Mì hải sản           | 41        | 300,000            | Thanh nhẹ, tinh tế           |
| Món chính      | Sushi                | 54        | 300,000            | Thanh nhẹ, tinh tế           |
| Món chính      | Tôm nướng            | 62        | 300,000            | Đậm đà, no lâu               |
| Món chính      | Phở bò               | 70        | 300,000            | Đậm đà, no lâu               |
| Món chính      | Bít tết              | 81        | 300,000            | Đậm đà, no lâu               |
| Tráng miệng    | Kem chanh            | 9         | 300,000            | Ngọt nhẹ, giải nhiệt         |
| Tráng miệng    | Chè Thái             | 12        | 300,000            | Ngọt nhẹ, giải nhiệt         |
| Tráng miệng    | Bingsu hoa quả       | 15        | 300,000            | Béo ngậy, đậm vị             |
| Tráng miệng    | Kem matcha           | 18        | 300,000            | Béo ngậy, đậm vị             |
| Tráng miệng    | Tiramisu             | 22        | 300,000            | Béo ngậy, đậm vị             |
| Combo          | Combo 2 người        | 100       | 1,500,000          | -                            |
| Combo          | Combo 3 người        | 100       | 2,300,000          | -                            |
| Combo          | Combo 5 người        | 100       | 3,500,000          | -                            |

`Point` là một số nằm trong khoảng **1 đến 100**, dùng để đánh giá:

- Mức độ đậm vị của món ăn  
- Khả năng ảnh hưởng của món đó đến tổng thể bữa ăn  
- Kích cỡ khẩu phần  

Một bữa ăn hoàn hảo nên có đủ **khai vị – món chính – tráng miệng** với tổng `point` **gần bằng 100** để đảm bảo sự cân bằng về vị giác lẫn độ lớn khẩu phần.

Ví dụ, món **Bít tết** (`point` cao, ~ 81) là món chính có hương vị đậm đà, no lâu nên sẽ phù hợp với món có `point` thấp như **Kem chanh** (~ 9) thanh mát, nhẹ nhàng, đảm bảo sự hài hoà cho bữa ăn.

<div style="page-break-before: always;"></div>

### 2. Tính năng gợi ý món ăn

Tính năng gợi ý món ăn sẽ dựa trên **số lượng khách** trong bàn, các **món khách đã gọi** và danh sách **món bán chạy** của quán để gợi ý món ăn. Tính năng này chú trọng vào độ hài hoà của bữa ăn để gợi ý (tổng `point` ~100).

#### 2.1 Với bàn có 1 khách

#### a, Nếu khách chưa gọi món nào:

Khi này, hệ thống sẽ gợi ý món **Bestseller** của quán, sau đó dựa vào `point` của món này để chạy **Brute Force** tìm ra 2 món tiếp theo sao cho tổng `point` của 3 món gần nhất với 100.

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Vì bạn chưa gọi món nào, nên chúng tôi đề xuất 1   ║
║ món Bestseller của quán, đi kèm là 2 món khai vị   ║
║ và tráng miệng phù hợp.                            ║
║ Món gợi ý: goi cuon, pho bo, bingsu hoa qua        ║
╚════════════════════════════════════════════════════╝
```

#### b, Nếu khách đã gọi 1 món:

Để hoàn thiện bữa ăn, cần gợi ý cho khách thêm 2 món nữa:

Nếu `point` >=40 tức là khách đã gọi 1 **món chính**, cần gợi ý thêm **tráng miệng** và **khai vị**. Ví dụ khách đã gọi 1 món chính là **Bít tết**:

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Vì bạn đã gọi một món chính khá đậm đà, no lâu nên ║
║ chúng tôi đề xuất món khai vị và tráng miệng như   ║
║ sau.                                               ║
║ Món gợi ý: kem chanh và che Thai                   ║
╚════════════════════════════════════════════════════╝
```

<div style="page-break-before: always;"></div>

Còn nếu `point` <40 thì tức là khách chưa gọi **món chính**, cần gợi ý **1 món chính** kèm thêm **1 món khác**. Lúc này, hệ thống sẽ chạy **2 vòng lặp lồng nhau** để xác định cặp món, kiểm tra điều kiện và đưa ra gợi ý. Ví dụ khách đã gọi 1 món khai vị là **Gỏi cuốn**:

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Vì bạn chưa gọi món chính nên chúng tôi đề xuất    ║
║ thêm 1 món chính và 1 món ăn kèm để bữa ăn hoàn    ║
║ thiện.                                             ║
║ Món gợi ý: pho bo và bingsu hoa qua                ║
╚════════════════════════════════════════════════════╝
```

#### c, Nếu khách đã gọi 2 món:

Hệ thống sẽ duyệt 1 lần toàn menu để tìm ra món có `point` gần nhất với `100 - point1 - point2`.

Ví dụ khách đã gọi 2 món là **Mì hải sản** và **Salad**:

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Vì bạn đã gọi 2 món nên chúng tôi đề xuất thêm 1   ║
║ món thứ 3 để đảm bảo sự hoàn thiện của bữa ăn.     ║
║ Món gợi ý: banh kimchi                             ║
╚════════════════════════════════════════════════════╝
```

#### d, Nếu khách đã gọi nhiều hơn 2 món:

Nếu tổng `point` bé hơn 100 tức là khách vẫn chưa gọi **món chính**, gợi ý 1 **món chính** gần nhất với `100 - tong_point`. Ví dụ khách đã gọi 3 món **Tiramisu**, **Gỏi cuốn**, **Kem matcha**:

<div style="page-break-before: always;"></div>

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Vì bạn chưa có món chính, nên chúng tôi sẽ đề xuất ║
║ 1 món chính phù hợp để đảm bảo sự hoàn thiện của   ║
║ bữa ăn.                                            ║
║ Món gợi ý: mi hai san                              ║
╚════════════════════════════════════════════════════╝
```

Nếu tổng `point` đã lớn hơn 100, gợi ý món có `point` thấp nhất. Ví dụ khách đã gọi 3 món **Tôm nướng**, **Bingsu hoa quả**, **Salad**:

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Bạn đã có 3 món ăn đầy đặn, nếu muốn gọi thêm,     ║
║ chúng tôi đề xuất một món khá là nhẹ nhàng.        ║
║ Món gợi ý: kem chanh                               ║
╚════════════════════════════════════════════════════╝
```

#### 2.2 Với bàn có nhiều khách

Ứng dụng **thuật toán tham lam**, gợi ý cho khách gọi những **combo** để tối ưu hoá chi phí, ví dụ nếu nhóm 18 người sẽ được gợi ý 3 **Combo 5 người** và 1 **Combo 3 người**.

```
╔════════════════════════════════════════════════════╗
║                   GỢI Ý GỌI MÓN                    ║
╠════════════════════════════════════════════════════╣
║ Vì bạn đi theo nhóm 18 người nên chúng tôi có gợi  ║
║ ý các Combo sau:                                   ║
║      -  3 Combo 5 người và                         ║
║      -  1 Combo 3 người                            ║
╚════════════════════════════════════════════════════╝
```
