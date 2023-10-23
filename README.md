Thuật toán xây dựng cho rơ le kỹ thuật số sẽ “copy” được phản ứng của rơ le bảo vệ quá tải theo nguyên lý điện nhiệt

![image](https://github.com/ToanPham2000/Relay/assets/142808050/13b277d3-7792-4c36-b80d-887840c6dec2)
Đặc tính bảo vệ quá dòng (dụa theo tiêu chuẩn IEEE C37.112-1996) :

- Quá trình tác động: Khi dòng tăng cao (> Ip), nhiệt sinh ra lớn (∆P=I^2 R), làm thanh kim loại kép bị cong, thanh truyền B dịch chuyển sang phải, thanh truyền D dịch chuyển sang trái, tiếp điểm thay đổi trạng thái
  
![image](https://github.com/ToanPham2000/Relay/assets/142808050/8ab284c3-e25b-4df3-8b86-5d54625f75c3)

- Quá trình ngắt: Khi dòng điện giảm (< Itđ), nhiệt sinh ra nhỏ (I2R) hơn quá trình tỏa nhiệt của môi trường, làm thanh kim loại kép quay trở lại trạng thái bình thường, thanh truyền B dịch chuyển sang trái, thanh truyền D dịch chuyển sang phải, tiếp điểm trở lại trạng thái bình thường.

![image](https://github.com/ToanPham2000/Relay/assets/142808050/f5966b58-2728-4b36-bb0e-2d059abf0225)
- A, B, p, Tr được tra theo bảng đặc tính tác động của relay

![image](https://github.com/ToanPham2000/Relay/assets/142808050/7c3fd002-0f10-4139-afc5-02fc0e7d83d6)
Xác định dòng:
- Vì dòng điện liên tục thay đổi theo thời gian nên ta chia dòng điện thành các đoạn nhỏ và coi như dòng điện không đổi trong khoảng vi phân thời gian đó. Đối với dòng xoay chiều hình sin giá trị trung bình được xác định như sau:
  ![image](https://github.com/ToanPham2000/Relay/assets/142808050/135912ef-3fe4-43db-965f-9ae9ae342ab4)
  Im và T là giá trị cực đại và chu kỳ của dòng điện. Ta suy ra được giá trị hiệu dụng như sau:
  ![image](https://github.com/ToanPham2000/Relay/assets/142808050/d85532b4-dc01-4d9e-b8c0-50e22df08e30)
- Giả sử như có m mẫu giá trị dòng điện i(k) được lấy mẫu từ bộ biến đổi ADC trong một chu kỳ dòng điện T. Khi đó biểu thức (6) có thể biểu thị như sau:
  ![image](https://github.com/ToanPham2000/Relay/assets/142808050/d66102e6-0366-46e2-b029-de58f18a61f5)
Bảo vệ quá dòng:
  ![image](https://github.com/ToanPham2000/Relay/assets/142808050/d9bf5474-b184-42ff-bfde-4c1d708ee641)
