#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

const char* SSID = "WIFI_KAMU";
const char* PASS = "PASSWORD_WIFI";

const uint8_t RELAY_PIN = 2; // GPIO2 (ESP-01)
const bool RELAY_ACTIVE_LOW = true;

ESP8266WebServer server(80);
bool relayState = false;

void applyRelay(bool on){
  relayState = on;
  if(RELAY_ACTIVE_LOW){
    digitalWrite(RELAY_PIN, on ? LOW : HIGH);
  } else {
    digitalWrite(RELAY_PIN, on ? HIGH : LOW);
  }
}

String statusJson(){
  String s = "{\"relay\":"; s += (relayState ? "true" : "false"); s += "}";
  return s;
}

void handleRoot(){ server.send(200, "text/plain", "ESP01-Relay OK. Use /on /off /toggle /status"); }
void handleOn(){ applyRelay(true); server.send(200, "application/json", statusJson()); }
void handleOff(){ applyRelay(false); server.send(200, "application/json", statusJson()); }
void handleToggle(){ applyRelay(!relayState); server.send(200, "application/json", statusJson()); }
void handleStatus(){ server.send(200, "application/json", statusJson()); }

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  // Pastikan default HIGH dulu agar tidak “nyetrum” saat boot jika active-low:
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  uint32_t t0 = millis();
  while (WiFi.status() != WL_CONNECTED && millis()-t0 < 20000) { delay(250); }

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/toggle", handleToggle);
  server.on("/status", handleStatus);
  server.begin();
}

void loop() {
  server.handleClient();
}
