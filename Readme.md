## Video Youtube Báo cáo: https://www.youtube.com/watch?v=fSvEqnTug0w
## Link pdf Báo cáo(bản đẹp mộng mơ): https://drive.google.com/file/d/1Uz3gQ6SgwnJxrre8EykzUzPvjjqHGooS/view?usp=drive_link
## MỤC LỤC

| Phần | Nội dung                                     | Trang |
|--------------------|--------------------------------|-------|
| I. Phân chia công việc    |                         |       |
| II. Tổng quan     | 1. Cấu trúc Dữ liệu             |       |
|      | 2. Giải thuật                                |       |
|III. Chức năng cơ bản| 0. Giao diện Đăng nhập   |       |
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
|-----------|-----------------------------------------|------------------------------------------|
| **Bùi Đức Thông (20234038)** | - Viết hàm `main()`  <br> - Phân chia công việc <br> - Viết comment mô tả chức năng, input-output cho từng hàm <br> - Triển khai tính năng gợi ý | hàm `main()` <br> file `data_structure` <br> file `tinh_nang_goi_y` |
| **Nguyễn Hoàng <br> Văn Thành (20234035)**        | - Viết file `interface` <br> - Tạo menu quán <br> - Viết chức năng (4)Xem menu <br> - Viết chức năng (5)Xem sơ đồ quán | file `4_chuc_nang_menu` <br> file `5_chuc_nang_xem_so_do` <br> file `interface` có 11 hàm con <br> hàm `nhap_so_nguyen` <br> hàm `nhap_chuoi` <br> hàm `to_lowercase_no_accent` <br> hàm `to_lowercase` <br> hàm `initStructure` <br> hàm `add_menu` <br> hàm `them_mon_vao_menu` <br> hàm `sua_gia_mon_an` <br> hàm `xoa_mon_an_khoi_menu` |
| **Văn Nhật Thiên (20234037)**        | - Viết chức năng (1)Thêm hoá đơn <br> - Viết chức năng (2)Sửa hoá đơn | file `1_chuc_nang_them_hoa_don` <br> file `2_chuc_nang_sua_hoa_don` <br> hàm `search_table` <br> hàm `add_dish_to_bill` <br> hàm `search_dish` <br> hàm `sua_so_luong_mon` <br> hàm `order_dish` |
| **Nguyễn Quang Minh <bre> (20234024)**        | - Viết chức năng (3)Thanh toán <br> - Viết chức năng (6)Data            | file `3_chuc_nang_thanh_toan` <br> file `6_chuc_nang_data` <br> hàm `push_to_top_seller_list` <br> hàm `get_point` |

<div style="page-break-before: always;"></div>

## II. Tổng quan

### 1. Cấu trúc dữ liệu

#### a) Menu

```
┌────┐   ┌────────────────┐   ┌─────────────┐
│    │   │name: "goi cuon"│   │name: "salad"│ 
│menu│ → │price: 30000    │ → │price: 25000 │ → ... → NULL
│    │   │point: 15       │   │point: 21    │
└────┘   └────────────────┘   └─────────────┘

```

#### b) Top\_seller:

```
┌──────────┐   ┌─────────────┐   ┌─────────────┐
│top_seller│ → │name: "salad"│ → │name: "sushi"│ → ... → NULL
│          │   │quantity: 62 │   │quantity: 22 │ 
└──────────┘   └─────────────┘   └─────────────┘
```

#### c) Staff:

```
┌─────────┐   ┌────────────┐   ┌────────────┐
│         │   │name: "nv1" │   │name: "nv1" │
│listStaff│ → │totalBill: 3│ → │totalBill: 4│ → ... → NULL
│         │   │revenue: ...│   │revenue: ...│
└─────────┘   └────────────┘   └────────────┘
```

#### d) Table

```
┌──────────┐   ┌──────────┐   ┌──────────┐
│          │   │id: 1     │   │id: 2     │ 
│restaurant│ → │Status: 0 │ → │Status: 0 │ → ... → NULL
│          │   │Bill: NULL│   │Bill: NULL│
└──────────┘   └──────────┘   └──────────┘
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

- **Greedy Algorithm**: Ứng dụng để gợi ý món phù hợp cho nhóm nhiều người. Trong menu có các **combo 2,3,5 người**, thuật toán tham lam sẽ ưu tiên lựa chọn **Combo 5 người**, rồi đến **Combo 3 người** và cuối cùng là **Combo 2 người** sao cho tổng chúng bằng số lượng khách.
- **Brute Force**: Sử dụng 2 vòng lặp lồng nhau để duyệt qua từng tổ hợp món và tìm ra tổ hợp phù hợp nhất. Ứng dụng khi đã có 1 món ăn và muốn gợi ý 2 món còn lại.
- **Insertion Sort**: Được sử dụng khi thêm món vào danh sách `top_seller`. Thuật toán hoạt động bằng cách duyệt từ đầu đến cuối trong `danh sách liên kết`. Nếu món ăn chưa xuất liện trong danh sách, một `node` mới sẽ được tạo và chèn vào vị trí đúng theo thứ tự giảm dần số lượng. Insertion Sort hoạt động rất hiệu quả trong tình huống này vì `danh sách liên kết` đã được sắp xếp sẵn.
- **Linear Search**: Duyệt tuần tự từ dầu đến cuối `danh sách liên kết`. Áp dụng để tìm kiếm món ăn, bàn, nhân viên,...

<div style="page-break-before: always;"></div>

## III. Chức năng cơ bản

Chương trình được thiết kế để giúp nhân viên và quản lý ca làm việc dễ dàng thực hiện các thao tác nhận khách, đặt bàn, thêm/sửa/xoá hoá đơn cũng như theo dõi trạng thái hiện tại của nhà hàng.

---

### 0. Giao diện Đăng nhập

```
 ╔════════════════════════════════════════════════════╗
 ║             HỆ THỐNG QUẢN LÝ NHÀ HÀNG              ║
 ╠════════════════════════════════════════════════════╣
 ║     1. Đăng nhập                   2. Thoát        ║
 ╚════════════════════════════════════════════════════╝
```

Sau khi chọn **"Đăng nhập"**, nhân viên nhập tên → tên được lưu vào `listStaff` → bắt đầu ca làm.

```
 ╔════════════════════════════════════════════════════╗
 ║             HỆ THỐNG QUẢN LÝ NHÀ HÀNG              ║
 ╠════════════════════════════════════════════════════╣
 ║ 1. Thêm Hoá đơn                   4. Menu          ║
 ║ 2. Sửa Hoá đơn                    5. Sơ đồ quán    ║
 ║ 3. Thanh toán                     6. Data          ║
 ║                  7. Đăng xuất                      ║
 ╚════════════════════════════════════════════════════╝
Nhập lựa chọn: ...
```

Giao diện chính với 6 tuỳ chọn **chức năng**, nhập số tương tứng với từng **chức năng** để tiến hành thao tác.

Khi xong ca làm việc, tuỳ chọn **"Đăng xuất"** sẽ cho bạn về **Giao diện Đăng nhập** ban đầu.

<div style="page-break-before: always;"></div>

### 1. Chức năng Thêm Hoá đơn

Khi có một lượt khách mới đến, chức năng này cho phép **tạo mới hoá đơn** tại bàn mà khách đang ngồi, **tặng Trà đá miễn phí** cho khách, và tiến hành **thêm các món mà khách order**. Đồng thời, **trạng thái của bàn** cũng được cập nhật thành `Đang có khách`.

---

#### ➤ Nhập thông tin bàn và số lượng khách
- Sử dụng hai vòng lặp `while` để yêu cầu nhập:
  - `table_id`: Mã số bàn mà khách đang ngồi.
  - `nums_customer`: Số lượng khách trong bàn.

#### ➤ Khởi tạo hoá đơn
- Một `node Bill` mới sẽ được tạo trong danh sách hoá đơn của `table`.
- Hệ thống sẽ tự động thêm `nums_customer` cốc **Trà đá miễn phí** vào hoá đơn.

#### ➤ Nhập món ăn
- Dùng vòng lặp `while` để liên tục yêu cầu nhập tên món và số lượng.
- Kết thúc khi nhân viên nhập **"xong"**.

---

#### ➤ Tính năng hỗ trợ khách hàng
Khi khách phân vân chưa biết chọn món gì, nhân viên có thể nhập một trong các lệnh đặc biệt sau:

- **`goi y`**: Khi này, **Thuật toán Gợi ý** sẽ chạy và tìm ra những món ăn phù hợp với bữa ăn của quý khách hàng (xem **Phụ lục 2**). 

- **`menu`**: Hiển thị toàn bộ thực đơn để khách hàng tiện lựa chọn.

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

Chức năng này hỗ trợ 3 tuỳ chọn để chỉnh sửa `bill`:

- Thêm món ăn mới: Nhập các thông tin của món ăn, tạo node mới và chèn vào cuối `bill`.

- Xóa món ăn khỏi **bill**: Duyệt duyệt tuần tự trong `bill` để tìm món ăn có tên trùng khớp và xoá bằng cách gián tiếp. Lưu thông tin node tiếp theo vào 1 biến tạm, trỏ node hiện tại đến `next->next`, xoá `next`, lấy thông tin của biến tạm để cho vào `node` hiện tại. Nếu đã là `node` cuối rồi thì xoá là được.

- Sửa số lượng món ăn trong `bill`: Duyệt tương tự và chỉnh sửa số lượng món ăn theo số lượng mới.

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

---

Chức năng này hỗ trợ 3 tuỳ chọn để chỉnh sửa **menu**:

- Thêm món ăn mới: Nhập các thông tin của món ăn, tạo `node` mới và chèn vào cuối **menu**.
- Sửa giá món ăn: Nhập **tên món ăn**, duyệt tuần tự trong **menu** để tìm món ăn có tên trùng khớp và thay đổi giá món.
- Xóa món ăn khỏi menu: Duyệt tương tự, xoá bằng cách gián tiếp. Lưu thông tin `node` tiếp theo vào 1 biến tạm, trỏ `node` hiện tại đến `next->next`, xoá `next`, lấy thông tin của biến tạm để cho vào `node` hiện tại. Nếu đã là `node` cuối rồi thì xoá là được.

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

Chức năng này cung cấp những thông tin chi tiết về dữ liệu của quán, với 3 tuỳ chọn

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

---

| **Loại món** | **Tên món ăn**       | **Point** | **Giá tiền** | **Mô tả món ăn**            |
|--------------------|------------------------|---------|----------------|-----------------------------|
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

| **Loại món** | **Tên món ăn**       | **Point** | **Giá tiền** | **Mô tả món ăn**            |
|--------------------|------------------------|---------|----------------|-----------------------------|
| Tráng miệng    | Kem chanh            | 9         | 300,000            | Ngọt nhẹ, giải nhiệt         |
| Tráng miệng    | Chè Thái             | 12        | 300,000            | Ngọt nhẹ, giải nhiệt         |
| Tráng miệng    | Bingsu hoa quả       | 15        | 300,000            | Béo ngậy, đậm vị             |
| Tráng miệng    | Kem matcha           | 18        | 300,000            | Béo ngậy, đậm vị             |
| Tráng miệng    | Tiramisu             | 22        | 300,000            | Béo ngậy, đậm vị             |
| Combo          | Combo 2 người        | 100       | 1,500,000          | -                            |
| Combo          | Combo 3 người        | 100       | 2,300,000          | -                            |
| Combo          | Combo 5 người        | 100       | 3,500,000          | -                            |

---

`Point` là một số nằm trong khoảng **1 đến 100**, dùng để đánh giá:

- Mức độ đậm vị của món ăn  
- Khả năng ảnh hưởng của món đó đến tổng thể bữa ăn  
- Kích cỡ khẩu phần  

Một bữa ăn hoàn hảo nên có đủ **khai vị – món chính – tráng miệng** với tổng `point` **gần bằng 100** để đảm bảo sự cân bằng về vị giác lẫn độ lớn khẩu phần.

Ví dụ, món **Bít tết** (`point` cao, ~ 81) là món chính có hương vị đậm đà, no lâu nên sẽ phù hợp với món có `point` thấp như **Kem chanh** (~ 9) thanh mát, nhẹ nhàng, đảm bảo sự hài hoà cho bữa ăn.

<div style="page-break-before: always;"></div>

### 2. Tính năng gợi ý món ăn

Tính năng gợi ý món ăn sẽ dựa trên **số lượng khách** trong bàn, các **món khách đã gọi** và danh sách **món bán chạy** của quán để gợi ý món ăn. Tính năng này chú trọng vào độ hài hoà của bữa ăn để gợi ý (tổng `point` ~100).

---

#### 2.1 Với bàn có 1 khách

#### a, Nếu khách **chưa gọi món** nào:

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

---

**Cách Thuật toán Brute Force hoạt động:**

- Đầu tiên, khởi tạo 2 biến lưu trữ:
  - `target_point`: Bằng 100 - `bestseller_point`.
  - `min_gap`: Là khoảng cách giữa tổng point 2 món hiện tại đang xét và `target_point`.
  - `result`: Dùng để lưu **cặp món** phù hợp nhất.

- Triển khai 2 vòng lặp `while` lồng nhau, duyệt qua mỗi cặp món, nếu khoảng cách giữa `point1+point2` và `target_point` nhỏ hơn min_gap thì lưu 2 món này vào `result` và cập nhật `min_gap`. 

<div style="page-break-before: always;"></div>

#### b, Nếu khách đã gọi *1 món*:

Để hoàn thiện bữa ăn, cần gợi ý cho khách thêm **2 món** nữa:

---

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

---

Còn nếu `point` <40 thì tức là khách chưa gọi **món chính**, cần gợi ý **1 món chính** kèm thêm **1 món khác**. Lúc này, hệ thống tiếp tục chạy **Brute Force** để xác định cặp món, kiểm tra điều kiện và đưa ra gợi ý. Ví dụ khách đã gọi 1 món khai vị là **Gỏi cuốn**:

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

<div style="page-break-before: always;"></div>

#### c, Nếu khách đã gọi **2 món**:

Hệ thống sẽ duyệt 1 lần toàn `menu` để tìm ra món có `point` gần nhất với `100 - point1 - point2`.

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

---

```
Code minh hoạ:
else if (nums_dish == 2) {
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
        }
```

<div style="page-break-before: always;"></div>

#### d, Nếu khách đã gọi **3 món** hoặc nhiều hơn:

Duyệt qua `listDish` xem có món nào có `point` lớn hơn hoặc bằng 40 không, nếu có tức là khách đã gọi **món chính** rồi, còn nếu không thì tức là khách chưa gọi **món chính**.

Nếu khách chưa gọi **món chính** thì gợi ý 1 **món chính** có `point` gần nhất với `100 - total_point`. Ví dụ khách đã gọi 3 món **Tiramisu**, **Gỏi cuốn**, **Kem matcha**:

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

---

Nếu khách đã gọi **món chính**, gợi ý món có `point` thấp nhất. Ví dụ khách đã gọi 3 món **Tôm nướng**, **Bingsu hoa quả**, **Salad**:

```
 ╔════════════════════════════════════════════════════╗
 ║                   GỢI Ý GỌI MÓN                    ║
 ╠════════════════════════════════════════════════════╣
 ║ Bạn đã có 3 món ăn đầy đặn, nếu muốn gọi thêm,     ║
 ║ chúng tôi đề xuất một món khá là nhẹ nhàng.        ║
 ║ Món gợi ý: kem chanh                               ║
 ╚════════════════════════════════════════════════════╝
```

<div style="page-break-before: always;"></div>

#### 2.2 Với bàn có nhiều khách

Ứng dụng **Thuật toán Tham lam**, gợi ý cho khách gọi những **combo** để tối ưu hoá chi phí, ví dụ nếu nhóm 18 người sẽ được gợi ý 3 **Combo 5 người** và 1 **Combo 3 người**.

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

---

**Cách Thuật toán Tham lam hoạt động**:  

- Đầu tiên, khởi tạo các biến:  
  - `current`: Là tổng số khách cần chia hiện tại.  
  - `combo5`: Là số combo 5 người nhiều nhất có thể chia (`current / 5`).  
  - `remain`: Số người còn lại sau khi chia combo5.  
  - `combo3`, `combo2`: Khởi tạo bằng 0.

- Xử lý nhanh với trường hợp đặc biệt:  
  - Nếu số khách là **2** hoặc **4** → chia thành các `Combo 2 người`.  
  - Nếu là **3** → chia thành 1 `Combo 3 người`.

- Trường hợp còn lại:
  - Sử dụng vòng lặp `while` giảm dần `combo5`.  
    - Cập nhật `remain = current - combo5 * 5`.  
    - Từ đó tính tiếp `combo3 = remain/3`, rồi `remain %= 3`.  
    - Nếu `remain` chia hết cho 2 → tính `combo2 = remain/2`  
    → In kết quả và kết thúc thuật toán.

- Nếu không thể chia hợp lệ → giảm combo5 và thử lại.

