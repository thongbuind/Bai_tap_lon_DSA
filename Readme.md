SẼ THAY TRANG NÀY THÀNH 1 TRANG BÌA ĐẸP
---

**BÁO CÁO MÔN HỌC**  
**CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT**  

**Đề tài**: Thiết kế chương trình quản lý nhà hàng  

<div style="page-break-before: always;"></div>

## I. Phân chia công việc

| Thành viên (MSSV)       | Nhiệm vụ chính                                                                   | Các hàm cần viết                                                                                                |
|-------------------------|------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| **Bùi Đức Thông (20234038)** | - Viết hàm `main()`  <br> - Phân chia công việc <br> - Viết comment mô tả cho từng hàm <br> - Triển khai tính năng gợi ý | hàm `main()` <br> file `data_structure` <br> file `tinh_nang_goi_y` |
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

<br><br>
<div style="page-break-before: always;"></div>
<br>

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

- **Greedy Algorithm**: Ứng dụng để gợi ý món phù hợp cho nhóm nhiều người. Trong menu có các combo 2,3,5 người, thuật toán tham lam sẽ tìm ra tổ hợp combo phù hợp với số lượng khách.
- **Brute Force**: Gợi ý món theo nhóm món ăn có liên quan, sử dụng 2 vòng lặp lồng nhau.
- **Insertion Sort**: Dùng khi thêm món vào danh sách top_seller.
- **Linear Search**: Áp dụng để tìm kiếm món ăn, bàn, nhân viên,...

<div style="page-break-before: always;"></div>

## III. Chi tiết chương trình

### 1. Cách thức hoạt động của chương trình

#### 1.0 Giao diện đăng nhập

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

#### 1.1 Chức năng thêm hoá đơn

<div style="page-break-before: always;"></div>

#### 1.2 Chức năng sửa hoá đơn

<div style="page-break-before: always;"></div>

#### 1.3 Chức năng thanh toán

<div style="page-break-before: always;"></div>

#### 1.4 Chức năng xem menu quán

<div style="page-break-before: always;"></div>

#### 1.5 Chức năng xem sơ đồ quán

<div style="page-break-before: always;"></div>

#### 1.6 Chức năng xem các dữ liệu của quán

<div style="page-break-before: always;"></div>

## IV. Phụ lục

### 1. Thiết kế Menu và Cấu trúc Hương vị

Menu gồm đa dạng món ăn được chia thành 3 nhóm: **khai vị**, **món chính**, **tráng miệng**, với nhiều tầng hương vị và phong cách khác nhau, được đánh giá trực quan thông qua chỉ số `Point`.

| **Loại món ăn** | **Tên món ăn**       | **Point** | **Giá tiền (VND)** | **Mô tả món ăn**            |
|----------------|----------------------|-----------|--------------------|------------------------------|
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

<div style="page-break-before: always;"></div>

| **Loại món ăn** | **Tên món ăn**       | **Point** | **Giá tiền (VND)** | **Mô tả món ăn**            |
|----------------|----------------------|-----------|--------------------|------------------------------|
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

Khi này, hệ thống sẽ gợi ý món `Bestseller` của quán, sau đó dựa vào `point` của món này để chạy Brute Force tìm ra 2 món tiếp theo sao cho tổng `point` của 3 món gần nhất với 100.

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

Nếu `point` >=40 tức là khách đã gọi 1 món chính, cần gợi ý thêm tráng miệng và khai vị. Ví dụ khách đã gọi 1 món chính là Bít tết:

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

Còn nếu `point` <40 thì tức là khách chưa gọi món chính, cần gợi ý 1 món chính kèm thêm 1 món khác. Lúc này, hệ thống sẽ chạy 2 vòng lặp lồng nhau để xác định cặp món, kiểm tra điều kiện và đưa ra gợi ý. Ví dụ khách đã gọi 1 món khai vị là Gỏi cuốn:

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

Ví dụ khách đã gọi 2 món là Mì hải sản và Salad:

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

Nếu tổng point bé hơn 100 tức là khách vẫn chưa gọi món chính, gợi ý 1 món chính gần nhất với `100 - tong_point`. Ví dụ khách đã gọi 3 món Tiramisu, Gỏi cuốn, Kem matcha:

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

Nếu tổng point đã lớn hơn 100, gợi ý món có point thấp nhất. Ví dụ khách đã gọi 3 món Tôm nướng, Bingsu hoa quả, Salad:

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

Ứng dụng thuật toán tham lam, gợi ý cho khách gọi những combo để tối ưu hoá chi phí, ví dụ nếu nhóm 18 người sẽ được gợi ý 3 Combo 5 người và 1 Combo 3 người.

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
