#include  <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#include "HX711.h" //memasukan library HX711
#define DOUT  5 //mendefinisikan pin arduino yang terhubung dengan pin DT module HX711
#define CLK  6 //mendefinisikan pin arduino yang terhubung dengan pin SCK module HX711

HX711 scale(DOUT, CLK);

float calibration_factor = 48100; //nilai kalibrasi ( sesuaikan dari hasil nilai percobaan program sebelumnya
float berat;

int pinPot = A0; // Memilih pin analog untuk VR
int potVal = 0; // Tempat untuk menerima nilai tegangan dari VR
      
void setup() {  

  lcd.begin(20,4);
  scale.set_scale();
  scale.tare(); // auto zero / mengenolkan pembacaan berat


}  

void loop() {  

    
    potVal = analogRead(pinPot); // terima masukan nilai dari VR potensio sebegai nilai simulasi
    potVal = map(potVal, 0, 1023, 0, 50); // ubah nilai (0-1023) jadi (0-255)  

    lcd.setCursor(0, 0);
    lcd.print("potensio = ");

    lcd.setCursor(11, 0);
    lcd.print(potVal);


    scale.set_scale(calibration_factor); //sesuaikan hasil pembacaan dengan nilai kalibrasi
    berat = scale.get_units(1) + potVal;
  

    lcd.setCursor(0,2);
    lcd.print("berat = ");

    lcd.setCursor(0,3);
    lcd.print(berat);

}  
