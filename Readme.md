# Bài tập lớn môn Cấu trúc Dữ liệu và Giải thuật

## Chủ đề: Thiết kế chương trình quản lý nhà hàng

### I. Tổng quan

#### 1. Cấu trúc Dữ liệu:

* Sử dụng danh sách liên kết đơn để lưu trữ.
* Các cấu trúc có dạng như sau:

  * Có 1 list **Menu** lưu trữ các món trong menu.
  * Có 1 list **Top\_seller** lưu trữ các món đã được gọi và số lượng của chúng theo thứ tự giảm dần.
  * Có 1 list **Staff** lưu trữ danh sách các nhân viên.
  * Có 1 list **Bill** lưu trữ các bill đã xuất, mỗi bill gồm danh sách các món ăn, tổng tiền, tên nhân viên quản lý.
  * Có 10 **Table** được nối tiếp với nhau trong dslk, mỗi bàn bao gồm số bàn (id), trạng thái bàn (status) và 1 con trỏ trỏ đến 1 bill trong list bill.
  * Có một cấu trúc lưu trữ là **Dish\_ordered**, đây là 1 chuỗi các món ăn mà mỗi bàn đã order, mỗi chuỗi này sẽ nằm trong một bill.

#### 2. Minh họa cấu trúc liên kết

##### a) List Menu:

```
┌────┐   ┌─────┐   ┌─────┐
│menu│ → │Món 2│ → │Món 3│ → ... → NULL
└────┘   └─────┘   └─────┘
```

##### b) List Top\_seller:

```
┌──────────┐   ┌──────────┐   ┌─────────┐
│top_seller│ → │Bestseller│ → │Món Thứ 2│ → ... → NULL
└──────────┘   └──────────┘   └─────────┘
```

##### c) List Staff:

```
┌─────────┐   ┌───────────┐   ┌───────────┐
│listStaff│ → │Nhân viên 1│ → │Nhân viên 2│ → ... → NULL
└─────────┘   └───────────┘   └───────────┘
```

##### d) List Table với Bill liên kết:

```
┌────────────┐   ┌────────────┐   ┌────────────┐
│            │   │ id: 1      │   │ id: 2      │ 
│ restaurant │ → │ Status: 0  │ → │ Status: 0  │ → ... → NULL
│            │   │ Bill: NULL │   │ Bill: NULL │
└────────────┘   └────────────┘   └────────────┘
```

##### e) List Bill và Dish\_ordered:

```
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

