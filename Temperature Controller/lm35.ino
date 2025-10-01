#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BACKLIGHT_PIN 13
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

#define RelayToFan  6 
int red = 8; // LED Merah Sebagai Indikator Kipas Sedang Mati dan juga pertanda suhu rendah dari nilai yang ditentukan
int blue = 2; // LED Biru Sebagai Indikator Kipas Sedang Hidup juga pertanda suhu tinggi dari nilai yang ditentukan

float tempC; // variable ouput LM35
int reading; // variable untuk membuat delay sensor
float referenceVoltage; // variable untuk mengatur volatase

int tempPin = 0; //mendefinisikan pin sensor LM35


void setup()
{  
Serial.begin(9600);  
lcd.begin(20,4);
lcd.backlight();

analogReference(INTERNAL); // penstabil ouput analog
referenceVoltage = 1.1; //mengatur tengang sensor ke voltase ke  = 5, 3.3, 2.56 atau 1.1 

pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(RelayToFan, OUTPUT); 
}

void loop()
{
  // konfigurasi penstabil sensor
  reading = 0;
  for(int i = 0; i < 10; i++) {  
     reading += analogRead(tempPin); 
     delay(20);}
  tempC =  (referenceVoltage * reading * 10) / 1023; 

lcd.setCursor(0,2);
lcd.print("      ");
lcd.print(tempC, 2); // menampilkan output sensor ke LCD dangan 2 angka di belangkang desimal
lcd.print((char)223);
lcd.print("C");

Serial.print("      ");
Serial.print(tempC, 2);
delay(1500);
 

lcd.setCursor(0, 0); // baris pertama di LCD dihtung dari 0,1,2,3
lcd.print("Thermostat Otomatis");

lcd.setCursor(0, 3); // baris keempat di LCD dihitung dari 0,1,2,3
lcd.print(" By Yore Gwijangge");


if (tempC >35){
  
      digitalWrite(blue,HIGH);
      digitalWrite(red,LOW);
      digitalWrite(RelayToFan,1); 

      lcd.setCursor(0, 1); // baris kedua di LCD dihitung dari 0,1,2,3
      lcd.print("Kipas Sedang (Hidup)");
      Serial.print(" ");
      Serial.print("Kipas Sedang (Hidup)");

}

else{
  
      digitalWrite(red,HIGH);
      digitalWrite(blue,LOW);
      digitalWrite(RelayToFan,0);

      lcd.setCursor(0, 1); // baris kedua di LCD dihitung dari 0,1,2,3
      lcd.print("Kipas Sedang (Mati) ");
      Serial.print(" ");
      Serial.print("Kipas Sedang (Mati) ");
}

  }
