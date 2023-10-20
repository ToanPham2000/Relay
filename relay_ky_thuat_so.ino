#include <LiquidCrystal_I2C.h>//thư viện LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);//khởi tạo thư viện với số lượng chân giao diện

#define Current_sensor A0
#define PI 3.1416  

float i,irms,Vadc,Vthat,t,t1,c;
float sensor = 0.1;//Độ nhạy ACS712 20A = 0.1 V/A
float offset = 512;//Giá trị bit điện áp đầu ra của ACS khi dòng điện bằng 0
float m = 0, sum = 0;
double deltaT = 0.02;
double Ip = 0.4;//Lấy giá trị I pick up bằng 0.4 A

void setup() {
Serial.begin(9600);
pinMode(Current_sensor, INPUT);
lcd.begin(20, 4); 
pinMode(13, OUTPUT);
}

void loop() {
  int bt = digitalRead(6);
  Vadc = analogRead(Current_sensor);//giá trị analog
  Vthat = (Vadc - offset);//trừ giá trị điện áp nguồn để ra giá trị điện áp thực
  i = (Vthat*5.0/1024)/sensor ;//tính giá trị dòng điện thực
  sum += abs(i);//tính tổng dòng điện
  ++m;
  if(m == 30){
    irms = PI/(2*m*sqrt(2))*sum; //tính dòng điện hiệu dụng i với số lần lấy mẫu: 2m = 60 lần
    m = 0;
    sum = 0;
    }   
    lcd.backlight() ; 
  lcd.display();
  lcd.setCursor(0,0);
  lcd.print("I = ");
  lcd.setCursor(4,0);
  lcd.print(irms,3);//Hiển thị 3 chữ số thập phân sau dấu phẩy
  lcd.setCursor(10,0);
  lcd.print("A");

 //Đặc tính cắt
  double k = irms/Ip;  
  if (k >= 2){
    digitalWrite(13,HIGH);
        lcd.clear();
        lcd.display();
        lcd.setCursor(5,1);
        lcd.print("NGAN MACH");
        }
  if (1 < k && k < 2){
  t = (0.052/(pow(k,0.02) - 1) + 0.114);//chọn đặc tính tác động chậm
  }
  if (1 > k && k >= 0 && t != 0){
  t = 4.85/(pow(k,2) - 1);//thời gian nghỉ
  }
   if(t != 0){ 
     c += deltaT/t;//hệ số tích lũy c
     }
   if(c < 0) c = 0;
   if(c > 1){
        t1 = t;
        digitalWrite(13,HIGH);
        lcd.display();
        lcd.setCursor(5,1);
        lcd.print("SOS: QUA TAI");     
        lcd.display();
        lcd.setCursor(1,3);
        lcd.println("TIME");
        lcd.setCursor(10,3);
        lcd.print(t1,4);
        lcd.setCursor(17,3);
        lcd.print("s"); 
        c = 0;
      }
lcd.setCursor(0,2);
lcd.println("c =");
lcd.setCursor(4,2);
lcd.print(c,3);
if(bt == HIGH){
     lcd.clear();
     digitalWrite(13,LOW);
     c = 0;
     t = 0;
  }
}
