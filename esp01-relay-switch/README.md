# ESP-01 Relay & Switch Firmware

Firmware Arduino untuk **ESP-01** yang terdiri dari dua project:

1. **esp01-relay**  
   ESP-01 mengontrol 1 channel relay melalui WiFi (HTTP).  
   Endpoint: `/on`, `/off`, `/toggle`, `/status`.

2. **esp01-switch**  
   ESP-01 membaca status tombol / saklar 2-pin dan menampilkan state melalui HTTP.  
   Endpoint: `/state`.

## Struktur Repo
