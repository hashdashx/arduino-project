#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* SSID = "WIFI_KAMU";
const char* PASS = "PASSWORD_WIFI";

const uint8_t SWITCH_PIN = 0; // GPIO0
ESP8266WebServer server(80);

bool readSwitchRaw(){
  // Aktif LOW (terhubung ke GND = ON)
  return digitalRead(SWITCH_PIN) == LOW;
}

bool debouncedRead(){
  bool a = readSwitchRaw();
  delay(10);
  bool b = readSwitchRaw();
  return a && b;
}

String stateJson(){
  bool on = debouncedRead();
  String s = "{\"on\":"; s += (on ? "true" : "false"); s += "}";
  return s;
}

void handleRoot(){ server.send(200, "text/plain", "ESP01-Switch OK. Use /state"); }
void handleState(){ server.send(200, "application/json", stateJson()); }

void setup(){
  pinMode(SWITCH_PIN, INPUT_PULLUP); // penting!
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  uint32_t t0 = millis();
  while (WiFi.status() != WL_CONNECTED && millis()-t0 < 20000) { delay(250); }

  server.on("/", handleRoot);
  server.on("/state", handleState);
  server.begin();
}

void loop(){
  server.handleClient();
}
