# Bài tập lớn môn Cấu trúc Dữ liệu và Giải thuật

## Chủ đề: Thiết kế chương trình quản lý nhà hàng

### I. Tổng quan

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

#### 2. Các giải thuật được sử dụng:

##### a) Giải thuật tham lam: Ứng dụng trong tính năng gợi ý chọn món khi người dùng đi theo nhóm nhiều người.

##### b) Brute Force: Ứng dụng trong tính năng gợi ý chọn món khi người dùng đã chọn được 1 món, thuật toán sử dụng 2 vòng lặp lồng nhau để tìm ra 2 món ăn còn lại phù hợp với món ăn đầu để gợi ý

##### c) Insertion Sort: Ứng dụng trong việc thêm các món ăn vào trong top_seller


##### d) Duyệt tuyến tính (Linear Search): Được dùng nhiều lần để tìm kiếm

#### 3. Cách thức hoạt động của chương trình:


