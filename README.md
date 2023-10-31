Thuật toán xây dựng cho rơ le kỹ thuật số sẽ “copy” được phản ứng của rơ le bảo vệ quá tải theo nguyên lý điện nhiệt

![image](https://github.com/ToanPham2000/Relay/assets/142808050/0547d2a5-4a1a-48ac-8a38-5ce0a4629424)

Đặc tính bảo vệ quá dòng (dụa theo tiêu chuẩn IEEE C37.112-1996) :

- Quá trình tác động: Khi dòng tăng cao (> Ip), nhiệt sinh ra lớn (∆P=I^2 R), làm thanh kim loại kép bị cong, thanh truyền B dịch chuyển sang phải, thanh truyền D dịch chuyển sang trái, tiếp điểm thay đổi trạng thái
  
![CT(1)](https://github.com/ToanPham2000/Relay/assets/142808050/5691cf9b-759d-4fb4-908e-788dc0118093)

- Quá trình ngắt: Khi dòng điện giảm (< Itđ), nhiệt sinh ra nhỏ (I2R) hơn quá trình tỏa nhiệt của môi trường, làm thanh kim loại kép quay trở lại trạng thái bình thường, thanh truyền B dịch chuyển sang trái, thanh truyền D dịch chuyển sang phải, tiếp điểm trở lại trạng thái bình thường.

![image](https://github.com/ToanPham2000/Relay/assets/142808050/1b0a962b-9c41-4380-8c21-19f3d871fc20)
- A, B, p, Tr được tra theo bảng đặc tính tác động của relay

![image](https://github.com/ToanPham2000/Relay/assets/142808050/e5f3b146-0cf8-4244-b4cf-dc88fafbd7e3)

Xác định dòng:
- Vì dòng điện liên tục thay đổi theo thời gian nên ta chia dòng điện thành các đoạn nhỏ và coi như dòng điện không đổi trong khoảng vi phân thời gian đó. Đối với dòng xoay chiều hình sin giá trị trung bình được xác định như sau:

  ![image](https://github.com/ToanPham2000/Relay/assets/142808050/a93ec8ff-fb08-476d-80fa-aa8809c9f385)

  
  Im và T là giá trị cực đại và chu kỳ của dòng điện. Ta suy ra được giá trị hiệu dụng như sau:
  ![Ihd](https://github.com/ToanPham2000/Relay/assets/142808050/ce921a16-c6cd-416f-aaea-fa59a86f4476)
  
- Giả sử như có m mẫu giá trị dòng điện i(k) được lấy mẫu từ bộ biến đổi ADC trong một chu kỳ dòng điện T. Khi đó biểu thức (6) có thể biểu thị như sau:

  ![Ihd(theo_m)](https://github.com/ToanPham2000/Relay/assets/142808050/e47c9e03-5e9f-453b-a3f2-599d46d9980b)
  
Bảo vệ quá dòng:
- Sừ dụng hàm cộng tính tổng thời gian tác động của dòng quá tải

  ![ham_cong_time](https://github.com/ToanPham2000/Relay/assets/142808050/5201370d-c2f6-4779-970e-310c06887926)

Mô phỏng bằng proteus: sử dụng arduino, acs712 viết chương trình đo dòng và tính toán thời gian tác động.

![image](https://github.com/ToanPham2000/Relay/assets/142808050/3b961ec0-c429-4048-b557-1a68cf9e3a63)

Kết quả khi tăng lên dòng quá tải:

![image](https://github.com/ToanPham2000/Relay/assets/142808050/23df2300-fe9e-4d7b-bec6-13c6641b020a)

Kết quả khi tăng lên ngắn mạch:

![image](https://github.com/ToanPham2000/Relay/assets/142808050/bae60e08-db4a-4ffd-aa76-1d2d306b94a0)

