# Dự án: Chương Trình Quản Lý Phòng Gym (Console Application)
## 1. Giới thiệu đề tài
Đây là một chương trình chạy trên giao diện Console giúp đơn giản hóa việc quản lý hệ thống dịch vụ thành viên của phòng gym. Chương trình hỗ trợ người dùng dễ dàng thao tác, nắm bắt thông tin và theo dõi tiến độ một cách nhanh chóng. 
**Các tính năng nổi bật:**
- **Quản lý hội viên:** Thêm mới và theo dõi thông tin hội viên, tình trạng gói tập (Thường/VIP), thời hạn và chi phí.
- **Giao diện trực quan:** Hiển thị thông tin hội viên dưới dạng bảng console rõ ràng.
- **Tính toán & Thống kê (Nâng cao):** Hỗ trợ tính chỉ số BMI của hội viên, đánh giá phân loại thể trạng, tính toán tổng doanh thu và tỷ lệ các gói VIP.
- **Xử lý dữ liệu an toàn:** Hệ thống validate dữ liệu đầu vào chặt chẽ (chống nhập số âm, dọn bộ nhớ đệm, giới hạn độ dài chuỗi và kiểm tra mã trùng lặp).
## 2. Thành viên và Phân công (Tuần 1)
| Vai trò | Họ và tên | MSSV | Nhiệm vụ | Nhánh làm việc (Branch) |
|---|---|---|---|---|
| **Leader** | Nguyễn Thanh Trung | 26661851 | Khởi tạo Repo, dựng `gym.h`, Menu `main.cpp` & Hàm thêm hội viên (`crud.cpp`). | `feature/crud-hoi-vien` |
| **Thành viên 1** | Trương Trọng Hoàng Tú | 26649481 | Tạo hàm hiển thị danh sách, tìm kiếm và sắp xếp dạng bảng (`display_search.cpp`). | `feature/display-search-sort` |
| **Thành viên 2** | Tạ Hoàng Quang Đạt | 26696291 | Khởi tạo README.md, viết hàm Validate (dọn đệm, chống nhập số âm) và Thống kê, BMI (`stats_valid.cpp`). | `feature/validate-stats-docs` |
## 3. Cách Compile và Run
Chương trình được viết bằng C/C++. Để biên dịch và chạy, bạn cần cài đặt compiler chuẩn như GCC (MinGW trên Windows hoặc g++ trên Linux/macOS).
**Bước 1:** Mở Terminal (hoặc Command Prompt/PowerShell) tại thư mục chứa mã nguồn.
**Bước 2:** Chạy lệnh sau để biên dịch tất cả các file mã nguồn thành file thực thi:
```bash
g++ main.cpp crud.cpp display_search.cpp stats_valid.cpp -o gym_app