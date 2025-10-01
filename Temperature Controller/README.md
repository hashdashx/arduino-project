# Arduino Thermostat Otomatis

Proyek ini adalah **Thermostat Otomatis berbasis Arduino** yang dapat mengendalikan kipas secara otomatis berdasarkan suhu.  
Terdapat dua versi implementasi sensor suhu:  
1. **DS18B20** → menggunakan protokol OneWire dan library DallasTemperature.  
2. **LM35** → menggunakan pembacaan analog dengan referensi tegangan internal.  

Suhu ditampilkan pada **LCD I2C 20x4** serta dapat dipantau melalui **Serial Monitor**.  
Relay digunakan untuk mengontrol kipas, sedangkan LED berfungsi sebagai indikator status kipas.  

---

## ✨ Fitur Umum
- Membaca suhu dari sensor (DS18B20 atau LM35).
- Menampilkan hasil suhu pada **LCD I2C 20x4**.
- Monitoring real-time melalui **Serial Monitor**.
- Mengendalikan kipas otomatis via **Relay Module**.
- Indikator LED:
  - **Merah** → suhu rendah, kipas mati.
  - **Biru** → suhu tinggi, kipas hidup.

---

# 🔹 Versi 1: Sensor DS18B20

### 🛠️ Hardware yang Dibutuhkan
- Arduino Uno / Nano / sejenisnya  
- Sensor Suhu **DS18B20**  
- LCD I2C 20x4  
- Relay Module (1 Channel)  
- LED Merah + Resistor  
- LED Biru + Resistor  
- Kabel jumper & breadboard  

### 🔌 Wiring Diagram
| Komponen         | Pin Arduino |
|------------------|-------------|
| DS18B20 Data     | 7           |
| Relay (Kipas)    | 6           |
| LED Merah        | 8           |
| LED Biru         | 2           |
| LCD I2C (0x3F)   | SDA → A4, SCL → A5 |
| LCD Backlight    | 13          |

---

# 🔹 Versi 2: Sensor LM35

### 🛠️ Hardware yang Dibutuhkan
- Arduino Uno / Nano / sejenisnya  
- Sensor Suhu **LM35**  
- LCD I2C 20x4  
- Relay Module (1 Channel)  
- LED Merah + Resistor  
- LED Biru + Resistor  
- Kabel jumper & breadboard  

### 🔌 Wiring Diagram
| Komponen         | Pin Arduino |
|------------------|-------------|
| LM35 (Vout)      | A0          |
| Relay (Kipas)    | 6           |
| LED Merah        | 8           |
| LED Biru         | 2           |
| LCD I2C (0x3F)   | SDA → A4, SCL → A5 |
| LCD Backlight    | 13          |

---

## 🚀 Cara Menjalankan
1. Install library di **Arduino IDE**:
   - [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library) (untuk DS18B20)  
   - [OneWire](https://github.com/PaulStoffregen/OneWire) (untuk DS18B20)  
   - [LiquidCrystal_I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)  

2. Hubungkan rangkaian sesuai wiring.  
3. Upload kode ke board Arduino.  
4. Nyalakan perangkat → suhu tampil di LCD & Serial Monitor.  
5. Jika suhu > 35°C → kipas hidup (LED biru ON).  
   Jika suhu ≤ 35°C → kipas mati (LED merah ON).  

---

## 📸 Demo
_(tambahkan foto hasil rangkaian + LCD agar menarik untuk portofolio GitHub)_

---

## 👤 Author
Project dibuat oleh **Opensource People**  
Kontribusi oleh: **Yore Gwijangge**
