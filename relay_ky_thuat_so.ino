
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4); 

const int acs712 = 0;
const int Relay = 12;

int sampleCount = 0;
int number_of_sample =  1000;     //số mẫu cần lấy 
float k = 0.0048828125; //5:1024
float counter = 0;
float voltage = 0;
float sum = 0;
float sensitivity = 0.066;    // độ nhạy
float Ip  = 1;          //dòng tác động quá tải
float Inm = 10;      //dòng tác động ngắn mạch
float Irms = 0;
float check = 0;
float t_trip  = 0;
float t_res = 0;

static bool error  =   false;
float A = 0.052;
float B = 0.114;
float p = 0.02;
float Tr  = 4.85;
float m1=0;
float delta=328;     //Chu kỳ tính (ms)
 
void setup() 
{
  Serial.begin(9600);

  pinMode(acs712, INPUT);
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);

  lcd.init();                    
  lcd.backlight();
  m1=millis();

}
 
void loop(){
  // Tính dòng hiệu dụng
  voltage = analogRead(acs712)*k-2.5;
  if  (voltage > 0){
    sum +=  voltage; 
  }
  else{
    sum -=  voltage;
  }

  sampleCount++;
  if  (sampleCount  ==  number_of_sample ){
    m1=millis();
    Irms = 3.1416*sum/(2*sqrt(2)*sampleCount*sensitivity);
    if(!error){
      lcd.setCursor(0,0);
      lcd.print("Irms = ");
      lcd.setCursor(7,0);
      lcd.print(Irms,3);
      lcd.setCursor(12,0);
      lcd.print("A");
      lcd.setCursor(1,1);
      lcd.print("C = ");
      lcd.print(counter,3);
    }
  }
  // Tính thời gian tác động
  if(!error){
    if  (sampleCount  ==  number_of_sample ){
    if((Irms  > Ip) && (Irms<Inm)){
      t_trip = A/(pow(Irms/Ip,p)-1)+B;
      counter += delta/(t_trip*1000);
    }
    if(Irms  <= Ip){
      if(counter!=0){
          t_res = Tr/(1-Irms*Irms/Ip);
          counter -=  delta/(t_res*1000);
      }  
    }
    sum  = 0;
    sampleCount = 0;
    }
     if(Irms >= Inm){
      digitalWrite(Relay,HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("NGAN MACH ");
      lcd.setCursor(0,1);
      lcd.print("CAT NGAY ");
      error=true;
    }
    if(counter  < 0){
      counter = 0;
    }
    if(counter>=1){
      digitalWrite(Relay,HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("QUA TAI ");
      lcd.print(Irms,2);
      lcd.print("A");
      lcd.setCursor(0,1);
      lcd.print("cat sau ");
      lcd.print(t_trip,3);
      lcd.print("s");
      lcd.setCursor(0,2);
      lcd.print("C = ");
      lcd.print(counter,3);
      error = true;
    }
  }
}

