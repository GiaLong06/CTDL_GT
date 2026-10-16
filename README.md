# BÀI TẬP LỚN CẤU TRÚC DỮ LIỆU & GIẢI THUẬT
## Đề tài ĐT12: Ứng dụng Danh bạ Điện thoại & Lịch sử Cuộc gọi
## 📝 Mô tả đề tài
Ứng dụng quản lý danh bạ điện thoại và lưu trữ lịch sử cuộc gọi sử dụng cấu trúc dữ liệu **Danh sách liên kết đôi (Doubly Linked List)**. Chương trình được viết bằng ngôn ngữ C++ nhằm tối ưu hóa việc quản lý bộ nhớ, tránh rò rỉ (memory leak) thông qua việc kiểm soát chặt chẽ các con trỏ `Head`, `Tail`, `prev` và `next`.
### Các tính năng chính:
- **Quản lý danh bạ:** Thêm liên hệ mới, xóa số điện thoại, duyệt danh bạ hai chiều (A-Z và Z-A).
- **Thuật toán Sắp xếp & Tìm kiếm:** 
  - Sắp xếp danh bạ theo tên (Sắp xếp nổi bọt / Sắp xếp chèn).
  - Tìm kiếm số điện thoại/tên nhanh chóng theo thuật toán tìm kiếm chuỗi ký tự theo tiền tố.
- **Lịch sử cuộc gọi:** Ghi nhận và hiển thị danh sách các cuộc gọi gần nhất.
- **Lưu trữ bền vững:** Đọc và ghi dữ liệu danh bạ trực tiếp ra tệp tin (`.txt` hoặc `.dat`).
---
## 🛠️ Hướng dẫn cài đặt & Biên dịch
### Yêu cầu hệ thống
- Trình biên dịch C++ (GCC / G++ bản 11 trở lên) hoặc các IDE như Dev-C++, Code::Blocks, VS Code.
### Các bước biên dịch bằng Terminal (GCC)
1. Di chuyển vào thư mục chứa mã nguồn:
   ```bash
   cd CTDL_GT
   ```
2. Biên dịch chương trình:
   ```bash
   g++ -o chuong_trinh main.cpp
   ```
3. Chạy chương trình:
   - Trên Windows: `chuong_trinh.exe`
   - Trên Linux/macOS: `./chuong_trinh`
---
## 📅 Thiết lập danh mục công việc (Task List)
*Ghi chú cho giảng viên: Tiến độ đóng góp thực tế được phản ánh chi tiết qua Commit History của từng tài khoản thành viên.*
| STT | Hạng mục công việc / Tính năng | Người phụ trách | Hạn nộp (Deadline) | Trạng thái | Tỷ lệ đóng góp |
|:---:|--------------------------------|:---------------:|:------------------:|:----------:|:--------------:|
| 1   | Khởi tạo & Quản lý bộ nhớ & Gộp code| Hoàng Hà Hạnh Ngân  | /10/2026 | **Done** | 100% |
| 2   | Thao Tác Cơ Bản (Thêm & Xóa) | Nguyễn Thị Thanh Hà | 17/10/2026 | **Done** | 100% |
| 3   | Thuật Toán (Sắp Xếp & Tìm Kiếm) | Võ Gia Long | 17/10/2026 | **Done** | 100% |
| 4   | Duyệt Danh Bạ & Đọc/Ghi File | Ứng Thành Nam | 17/10/2026 | **Done** | 100% |
| 5   | Lịch Sử Cuộc Gọi & Giao Diện Menu | trần Hoài Linh | 17/10/2026 | **Done** | 100% |
| 6   | Đọc/Ghi dữ liệu tệp tin (`.txt`/`.dat`) & Rà soát rò rỉ bộ nhớ | Cả nhóm | 18/10/2026 | **Done** | 100% |
---
## 👥 Danh sách thành viên Nhóm 4
1. **Hoàng Hà Hạnh Ngân** (MSSV: 6651020055) - *Phụ trách: Khởi tạo & Quản lý bộ nhớ & Gộp code*
2. Nguyễn Thị Thanh Hà (MSSW: 6651020090) - *Phụ trách: Thao Tác Cơ Bản (Thêm & Xóa)*
3. Võ Gia Long (MSSW: 6651020049) - *Phụ trách: Thuật Toán (Sắp Xếp & Tìm Kiếm)*
4. Ứng Thành Nam (MSSW: 6651020054) - *Phụ trách: Duyệt Danh Bạ & Đọc/Ghi File*
5. Trần Hoài Linh (MSSW: 6651020048) - *Phụ trách: Lịch Sử Cuộc Gọi & Giao Diện Menu*
