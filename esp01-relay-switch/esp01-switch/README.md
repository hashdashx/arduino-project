
## Hardware Minimal
- ESP-01 / ESP-01S
- Catu daya 3.3 V stabil (≥500 mA)
- Modul relay 1 channel (untuk project relay)
- Saklar 2-pin (untuk project switch)

## Cara Build & Flash
1. Install [Arduino IDE](https://www.arduino.cc/en/software).
2. Tambah Board ESP8266 (`http://arduino.esp8266.com/stable/package_esp8266com_index.json`).
3. Pilih board: **Generic ESP8266 Module**.
4. Buka folder `esp01-relay/` atau `esp01-switch/` dan upload sketch ke ESP-01.

## Cara Pakai
- Hubungkan ESP-01 ke WiFi (SSID & password di kode).
- Akses via browser:
  - Relay: `http://IP-ESP/on` / `off` / `toggle` / `status`
  - Switch: `http://IP-ESP/state`

## Catatan
⚠️ Jika relay dipakai untuk beban AC, pastikan menggunakan modul relay dengan isolasi dan aman dari kontak langsung.
