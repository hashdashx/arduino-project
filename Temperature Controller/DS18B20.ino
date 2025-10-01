/*
Arduino Temperature Controller


Made by Opensource People
*/

#include <Wire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define RelayToFan  6  // Relay akan membuka atau menutup jalur kabel dari Sumber Tegangan Menuju Kipas

int red = 8; // LED Merah Sebagai Indikator Kipas Sedang Mati dan juga pertanda suhu rendah dari nilai yang ditentukan
int blue = 2; // LED Biru Sebagai Indikator Kipas Sedang Hidup juga pertanda suhu tinggi dari nilai yang ditentukan

#define BACKLIGHT_PIN 13
#define ONE_WIRE_BUS 7
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
  
void setup() {
  Serial.begin(9600);
  sensors.begin();
  lcd.begin(20,4);
  lcd.backlight();

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(RelayToFan, OUTPUT);

    }

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Thermostat Otomatis");

  Serial.print("Thermostat Otomatis"); // Serial Print untuk Memantau Keadaan Alat  di Serial Monitor melalui aplikasi arduino yang ada di komputer
  
  lcd.setCursor(0, 3); // baris keempat di LCD dihitung dari 0,1,2,3
  lcd.print(" By Yore Gwijangge");

  Serial.print("By Jore");

  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 2);
  lcd.print("      ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("\337C");
  
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("\337C");
  

if (temperature >35){
  
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
