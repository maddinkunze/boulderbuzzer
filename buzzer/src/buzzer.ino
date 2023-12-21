#include "espnow.h"
#include "ESP8266WiFi.h"

uint8_t mac[] = {0xa8, 0x48, 0xfa, 0xff, 0xb6, 0x2b};

typedef enum {
  BW_CONNECT = 1,
  BW_UPDATE = 2,
  BW_KEEPALIVE = 3,
} bwCommand_t;

typedef enum {
  BW_STATION = 1,
  BW_BUTTON = 2,
  BW_LED_BUTTON = 3,
  BW_RGB_BUTTON = 4,
  BW_MAX_DEVICE
} bwDeviceType_t;

typedef enum {
  BW_RED = 'r',
  BW_GREEN = 'g',
  BW_BLUE = 'b',
  BW_PRESSED = 'P',
  BW_RELEASED = 'R',
} bwUpdateType_t;

int pinRed = 0;
int pinGreen = 1;
int pinBlue = 2;
int pinButton = 3;
#define PENDINGLED pinBlue
#define SUCCESSLED pinGreen
#define ERRORLED pinRed

unsigned long lastButtonPress = 0;
unsigned long lastUpdate = 0;

void updateValues(uint8_t* data, uint8_t length) {
  uint8_t i=0;
  while (i<length) {
    switch (data[i]) {
      case BW_RED:
        analogWrite(pinRed, 255-data[++i]);
        break;
      case BW_GREEN:
        analogWrite(pinGreen, 255-data[++i]);
        break;
      case BW_BLUE:
        analogWrite(pinBlue, 255-data[++i]);
        break;
      default:
        return;
    }
    i++;
  }
}

bwUpdateType_t lastState = BW_RELEASED;
ICACHE_RAM_ATTR void onButtonPress() {
  unsigned long _lastButtonPress = lastButtonPress;
  lastButtonPress = millis();
  if (lastButtonPress - _lastButtonPress < 10) { return; }
  switch (lastState) {
    case BW_RELEASED:
      lastState = BW_PRESSED;
      break;
    default:
      lastState = BW_RELEASED;
      break;
  }
  uint8_t data[] = {BW_UPDATE, lastState};
  sendData(mac, data, 2);
}

void onDataReceive(uint8_t* macAddress, uint8_t* data, uint8_t length) {
  lastUpdate = millis();
  if (length < 1) { return; }
  switch (data[0]) {
    case BW_CONNECT:
    case BW_KEEPALIVE:
      break;
    case BW_UPDATE:
      updateValues(data+1, length-1);
      break;
    default:
      return;
  }
}

void sendData(uint8_t* macAddress, uint8_t* data, uint8_t length) {
  esp_now_send(macAddress, data, length);
}

unsigned long lastKeepalive = 0;
void sendKeepalive() {
  unsigned long timeNow = millis();
  if (timeNow - lastKeepalive < 800) { return; }
  uint8_t data[] = {BW_KEEPALIVE};
  sendData(mac, data, 1);
  lastKeepalive = timeNow;
}

bool isConnected(unsigned long threshold) {
  return lastUpdate && ((millis() - lastUpdate) < threshold);
}

void initConnections() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  if (esp_now_init()) { 
    // TODO show error
    return;
  }
  
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_register_recv_cb(onDataReceive);
  esp_now_add_peer(mac, ESP_NOW_ROLE_COMBO, 0, NULL, 0);
}

void initHardware() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, HIGH);
  pinMode(pinButton, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinButton), onButtonPress, CHANGE);
}

void waitForConnection() {
  unsigned long timeStart = millis();
  unsigned long timeNow;
  unsigned long nTry = 0;
  unsigned long tTry = 500;
  uint8_t data[] = {BW_CONNECT, BW_RGB_BUTTON};
  while (true) {
    timeNow = millis();
    analogWrite(PENDINGLED, floor((cos(0.002 * (timeNow - timeStart)) + 1) * 127));
    if (isConnected(2000)) { break; }
    if (timeNow > timeStart + nTry * tTry) {
      sendData(mac, data, 2);
      nTry++;
    }
    delay(50);
  }

  digitalWrite(PENDINGLED, HIGH);
  
  for (uint8_t i=0; i<3; i++) {
    digitalWrite(SUCCESSLED, HIGH);
    delay(300);
    digitalWrite(SUCCESSLED, LOW);
    delay(300);
  }
  digitalWrite(SUCCESSLED, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  initHardware();
  initConnections();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isConnected(5000)) { 
    sendKeepalive();
    return;
  }
  waitForConnection();
}
