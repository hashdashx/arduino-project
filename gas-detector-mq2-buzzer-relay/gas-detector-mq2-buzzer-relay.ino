int mq2Pin = 12; // mendefinisikan pin sensor mq2
int relayPin = 11; //  mendefinisikan pin relay
int buzzerPin = 13; // mendefinisikan pin  buzzer
void setup() { // kondisi awal saat alat dijalankan

pinMode(mq2Pin, INPUT); // mendefinisikan sensor mq2 sebagai input
pinMode(relayPin, OUTPUT);// mendefinisikan relay sebagai output
pinMode(buzzerPin, OUTPUT);// mendefinisikan buzzer sebagai output
digitalWrite(relayPin, HIGH); // inisiasi relay menyala terlebih dahulu
Serial.begin(9600);
}


void loop() { // kondisi pembacaan berulang

if (digitalRead(mq2Pin) ==LOW){ // jika sensor mq2 mendeteksi ada gas maka relay non-aktif buzzer akan menyala
digitalWrite(relayPin, LOW);
digitalWrite(buzzerPin, HIGH);
Serial.println("GAS TERDETEKSI");
}

else { // kondisi sebaliknya jika tidak ada gas yg terdeteksi oleh sensor mq2 maka relay akan menyala dan buzzer akan non-aktif
digitalWrite(relayPin, HIGH);
digitalWrite(buzzerPin, LOW);
Serial.println("TIDAK ADA GAS TERDETEKSI");
}
delay(1000);
}
