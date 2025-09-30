# MQ2 Gas Detector with Relay and Buzzer (Arduino)

Proyek sederhana menggunakan **sensor MQ2**, **relay**, dan **buzzer** untuk mendeteksi adanya gas berbahaya (seperti LPG, butane, methane, smoke).  
Ketika gas terdeteksi:
- Relay dimatikan (misalnya memutus aliran listrik / mengaktifkan kipas).
- Buzzer menyala sebagai alarm.
- Serial Monitor akan menampilkan pesan "GAS TERDETEKSI".

Jika tidak ada gas:
- Relay menyala kembali.
- Buzzer mati.
- Serial Monitor menampilkan pesan "TIDAK ADA GAS TERDETEKSI".

---

## 📌 Hardware yang dibutuhkan
- Arduino Uno / Nano / sejenis
- Sensor MQ2
- Relay module (1 channel)
- Buzzer
- Kabel jumper
- Breadboard

---

## ⚡ Wiring
| Komponen | Pin Arduino |
|----------|-------------|
| MQ2 Out  | D12         |
| Relay In | D11         |
| Buzzer   | D13         |
| VCC      | 5V          |
| GND      | GND         |

---

## 🔧 Cara Menggunakan
1. Clone repository ini:
   ```bash
   git clone https://github.com/username/mq2-gas-detector-arduino.git
