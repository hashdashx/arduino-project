#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


#include "HX711.h" //memasukan library HX711
#define DOUT  5 //mendefinisikan pin arduino yang terhubung dengan pin DT module HX711
#define CLK  6 //mendefinisikan pin arduino yang terhubung dengan pin SCK module HX711

HX711 scale(DOUT, CLK);

float calibration_factor = 48100; //nilai kalibrasi ( sesuaikan dari hasil nilai percobaan program sebelumnya
float berat;


#define ECHOPIN 10                          
#define TRIGPIN 11  


int TS,TT;//ts=tinggi sensor , tt=tinggi tiang
int bmi;




void setup() {


  lcd.begin(20,4);//ukuran lcd 20x4    
  lcd.setCursor(0, 1);
  lcd.print("Tinggi:");
  pinMode(ECHOPIN, INPUT);  //echo menerima suara ultrasonik dari  trigger
  pinMode(TRIGPIN, OUTPUT); //trigger memancarkan suara ultrasonik ke echo
  delay(1000);
  TT=200;
 
  scale.set_scale();
  scale.tare(); // auto zero / mengenolkan pembacaan berat  
}

void loop() {






// program dibawah ini agar trigger memancarakan suara ultrasonic
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
                     
  int distance = pulseIn(ECHOPIN, HIGH); // menerima suara ultrasoni       
                      
  TS=TT-distance/58; //batas diameter pancar dan pantul                    
  lcd.setCursor(7, 1);
  lcd.print(TS); 
  lcd.print(" cm ");
  delay(1000);   

  scale.set_scale(calibration_factor); //sesuaikan hasil pembacaan dengan nilai kalibrasi

  berat = scale.get_units(1);

  lcd.setCursor(0,0);
  lcd.print("berat: ");

  lcd.setCursor(6,0);
  lcd.print(berat);

  lcd.setCursor(10,0);
  lcd.print("kg");


  bmi = berat / TS * TS;


  lcd.setCursor(0,2);
  lcd.print("BMI:");


  lcd.setCursor(4,2);
  lcd.print(bmi);


  lcd.setCursor(0,3);
  if (bmi>=29) {

  lcd.print("Sangat Gemuk");
  
  }else if(bmi>=24) {
        lcd.print("Gemuk         ");
    }else if(bmi>=18) {
        lcd.print("Normal        ");
    }else if(bmi>=16) {
        lcd.print("Kurus         ");
    }else if(bmi<16 ) {
        lcd.print("Sangat Kurus");
    }
  

       
    
}
