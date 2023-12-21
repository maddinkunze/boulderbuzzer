#ifdef ESP32
  #include <esp_now.h>
  #include <WiFi.h>
  #include <esp_wifi.h>
#else
  #include "espnow.h"
  #include <ESP8266WiFi.h>
#endif
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"


#define DEBUG 1

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

typedef struct {
  bwDeviceType_t type;
  unsigned long lastSeen;
  uint8_t red;
  uint8_t blue;
  uint8_t green;
  unsigned long resetIn;
  unsigned long pressed;
  unsigned long nextUpdate;
  uint8_t mac[6];
} bwDevice_t;

#define BW_DEVICES 20
bwDevice_t bwDevices[BW_DEVICES];
size_t numBwDevices = 0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define PIN_OUTPUT 15
#define TIME_OUTPUT_ON 1200
unsigned long timeOutputOff = 0;

#ifndef ERR_OK
#define ERR_OK 0
#endif

typedef enum {
  DISPLAY_STATS,
  SELECT_GAME,
  SETTINGS
} bwControlMode_t;
bwControlMode_t bwControlMode;

typedef enum {
  GAME_REACTION = 1,
  GAME_MAX
} bwControlGame_t;
int bwControlGame = GAME_REACTION;

int rotaryEncoderLast = 0;
unsigned long displayLastUpdate = 0;

int reactionLastButton = -1;
void reactionButtonPressed(int pressedButton) {
  if ((reactionLastButton >= 0) && (pressedButton != reactionLastButton)) {
    bwDevices[pressedButton].red = 160;
    bwDevices[pressedButton].green = 0;
    bwDevices[pressedButton].blue = 0;
    bwDevices[pressedButton].nextUpdate = 0;
    bwDevices[pressedButton].resetIn = millis() + 300;
    return;
  }

  reactionButtonNext();
}

void reactionButtonNext() {
  unsigned long timeNow = millis();
  int devicesOnline = 0;
  int devicesOnlineWithoutLast = 0;
  for (int i=0; i<numBwDevices; i++) {
    if ((timeNow - bwDevices[i].lastSeen) > 3000) { continue; }
    devicesOnline++;
    if (i == reactionLastButton) { continue; }
    devicesOnlineWithoutLast++;
  }

  if (reactionLastButton >= 0) {
    bwDevices[reactionLastButton].red = 0;
    bwDevices[reactionLastButton].green = 0;
    bwDevices[reactionLastButton].blue = 0;
    bwDevices[reactionLastButton].nextUpdate = 0;
  }

  if (!devicesOnlineWithoutLast) {
    setButtonRandomColor(reactionLastButton);
    return;
  }

  if (!devicesOnline) { reactionLastButton = -1; return; }
  int nextButton = random(devicesOnlineWithoutLast) + 1;
  int nextButtonIndex = -1;
  while (nextButton && (nextButtonIndex < (int)numBwDevices)) {
    nextButtonIndex++;
    if ((timeNow - bwDevices[nextButtonIndex].lastSeen) > 3000) { continue; }
    if (nextButtonIndex == reactionLastButton) { continue; }
    nextButton--;
  }

  if ((nextButtonIndex < 0) || (nextButtonIndex >= numBwDevices)) {
    reactionLastButton = -1;
    return;
  }

  setButtonRandomColor(nextButtonIndex);
  reactionLastButton = nextButtonIndex;
}

void setButtonRandomColor(int buttonIndex) {
  if (buttonIndex < 0) { return; }
  bwDevice_t& bwDevice = bwDevices[buttonIndex];
  bwDevice.red = 0;
  bwDevice.green = 0;
  bwDevice.blue = 0;
  switch (random(22)) {
    case 0: // RED
      bwDevice.red = 255;
      break;
    case 1: // GREEN
      bwDevice.green = 255;
      break;
    case 2: // BLUE
      bwDevice.blue = 255;
      break;
    case 3: // PURPLE
    case 4:
    case 5: // (3x probability)
      bwDevice.red = 255;
      bwDevice.blue = 220;
      break;
    case 6: // YELLOW
      bwDevice.red = 255;
      bwDevice.green = 180;
      break;
    case 7: // LIGHTER YELLOW
      bwDevice.red = 255;
      bwDevice.green = 220;
      break;
    case 8: // TURQOISE
    case 9: // (2x probability)
      bwDevice.green = 255;
      bwDevice.blue = 255;
      break;
    case 10: // PINK
    case 11: // (2x probability)
      bwDevice.red = 255;
      bwDevice.blue = 110;
      break;
    case 12: // ORANGE
    case 13: // (2x probability)
      bwDevice.red = 255;
      bwDevice.green = 40;
      break;
    case 14: // LIGHT TURQOISE
    case 15:
    case 16: // (3x probability)
      bwDevice.green = 255;
      bwDevice.blue = 120;
      break;
    case 17: // LIGHT BLUE
    case 18: // (2x probability)
      bwDevice.green = 120;
      bwDevice.blue = 255;
      break;
    case 19: // COLD WHITE
      bwDevice.red = 220;
      bwDevice.green = 220;
      bwDevice.blue = 255;
      break;
    case 20: // NEUTRAL WHITE
      bwDevice.red = 255;
      bwDevice.green = 240;
      bwDevice.blue = 180;
      break;
    case 21: // WARM WHITE
      bwDevice.red = 255;
      bwDevice.green = 150;
      bwDevice.blue = 60;
      break;
  }
  bwDevice.nextUpdate = 0;
}

void updateGame() {
  unsigned long timeNow = millis();
  switch (bwControlGame) {
    case GAME_REACTION:
      if ((reactionLastButton >= 0) && ((timeNow - bwDevices[reactionLastButton].lastSeen) > 5000)) { reactionButtonNext(); }
      break;
  }
}

void updateDevices() {
  for (int i=0; i<numBwDevices; i++) {
    updateDevice(i);
  }
}

void updateDevice(int numDevice) {
  unsigned long timeNow = millis();
  
  if (bwDevices[numDevice].pressed && ((timeNow - bwDevices[numDevice].pressed) > 2000)) {
    bwDevices[numDevice].pressed = 0;
    handleButtonRelease(numDevice);
  }

  if (bwDevices[numDevice].resetIn && (timeNow > bwDevices[numDevice].resetIn)) {
    bwDevices[numDevice].resetIn = 0;
    bwDevices[numDevice].red = 0;
    bwDevices[numDevice].green = 0;
    bwDevices[numDevice].blue = 0;
    bwDevices[numDevice].pressed = 0;
    bwDevices[numDevice].nextUpdate = 0;
  }

  if (bwDevices[numDevice].nextUpdate > timeNow) { return; }
  size_t len = 0;
  uint8_t data[32];
  data[len++] = BW_UPDATE;
  switch (bwDevices[numDevice].type) {
    case BW_RGB_BUTTON:
      data[len++] = BW_RED;
      data[len++] = bwDevices[numDevice].red;
      data[len++] = BW_GREEN;
      data[len++] = bwDevices[numDevice].green;
      data[len++] = BW_BLUE;
      data[len++] = bwDevices[numDevice].blue;
      break;
    default:
      break;
  }
  sendData(bwDevices[numDevice].mac, data, len);
  bwDevices[numDevice].nextUpdate = timeNow + 1000;
}

void initControls() {
#if (DEBUG)
  Serial.begin(115200);
#endif
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
#if (DEBUG)
    Serial.println("Could not initialize display!");
#endif
  }
  bwControlMode = DISPLAY_STATS;
  updateDisplay();

  
  pinMode(0, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), rotaryEncoderRotate, FALLING);
  attachInterrupt(digitalPinToInterrupt(14), rotaryEncoderRotate, FALLING);
}

ICACHE_RAM_ATTR void rotaryEncoderRotate() {
  if (millis() < rotaryEncoderLast + 100) { return; }
  rotaryEncoderLast = millis();
  bwControlGame += digitalRead(0) ? -1 : 1;
  if (bwControlGame < 1) { bwControlGame = 1; }
  if (bwControlGame >= GAME_MAX) { bwControlGame = GAME_MAX-1; }
  displayLastUpdate = 0;
}

ICACHE_RAM_ATTR void rotaryEncoderClick() {
  
}

void updateDisplay() {
  updateDisplay(bwControlMode);
}

void updateDisplay(int modeUpdate) {
  return;
  if (bwControlMode != modeUpdate) { return; }

  unsigned long timeNow = millis();

  display.clearDisplay();
  switch (bwControlMode) {
   case DISPLAY_STATS:
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Devices: ");
    int devicesConnected = 0;
    for (int i=0; i<numBwDevices; i++) {
      if ((timeNow - bwDevices[i].lastSeen) > 3000) { continue; }
      devicesConnected++;
    }
    display.print(devicesConnected);
    display.print("/");
    display.print(numBwDevices);
    display.print("/");
    display.println(BW_DEVICES);
    display.print("Game/Mode: ");
    switch (bwControlGame) {
     case GAME_REACTION:
      display.print("Reaction");
      break;
     default:
      display.print("Invalid");
    }
  }
  display.display();
}

void sendData(const uint8_t* macAddress, const uint8_t* data, uint8_t length) {
  esp_now_send(macAddress, data, length);
#if DEBUG
  Serial.print("Sent Data via ESP_NOW to ");
  for (uint8_t i=0; i<6; i++) {
    if (i) { Serial.print(":"); }
    if (!(macAddress[i]&0xF0)) { Serial.print("0"); }
    Serial.print(macAddress[i], HEX);
  }
  Serial.print(" containing \"");
  Serial.write(data, length);
  Serial.println("\"");
#endif
}

#ifdef ESP32
  esp_now_peer_info_t peerToAdd;
#endif
int addPeer(const uint8_t* mac) {
#ifdef ESP32
  memcpy(peerToAdd.peer_addr, mac, 6);
  peerToAdd.channel = 0;
  peerToAdd.encrypt = false;
  return esp_now_add_peer(&peerToAdd);
#else
  return esp_now_add_peer(mac, ESP_NOW_ROLE_COMBO, 0, NULL, 0);
#endif
}

void addDevice(const uint8_t* macAddress, uint8_t deviceType) {
  if (numBwDevices >= BW_DEVICES) { return; }
  if (deviceType < 1) { return; }
  if (deviceType > BW_MAX_DEVICE) { return; }
  bwDevices[numBwDevices].type = (bwDeviceType_t)deviceType;
  bwDevices[numBwDevices].lastSeen = millis();
  memcpy(bwDevices[numBwDevices].mac, macAddress, 6);
  bwDevices[numBwDevices].red = 0;
  bwDevices[numBwDevices].green = 0;
  bwDevices[numBwDevices].blue = 0;
  bwDevices[numBwDevices].pressed = 0;
  
  int error = addPeer(bwDevices[numBwDevices].mac);
  if (error) { return; }
  uint8_t data[2] = {BW_CONNECT, BW_STATION};
  sendData(macAddress, data, 2);
  numBwDevices++;
  displayLastUpdate = 0;
}

void onDataReceiveESP32(const uint8_t* macAddress, const uint8_t* data, int length) {
  onDataReceive(macAddress, data, (uint8_t)length);
}

void onDataReceive(const uint8_t* macAddress, const uint8_t* data, uint8_t length) {
#if (DEBUG)
  Serial.print("Received Data via ESP_NOW from ");
  for (uint8_t i=0; i<6; i++) {
    if (i) { Serial.print(":"); }
    if (!(macAddress[i]&0xF0)) { Serial.print("0"); }
    Serial.print(macAddress[i], HEX);
  }
  Serial.print(" containing \"");
  Serial.write(data, length);
  Serial.println("\"");
#endif

  int numDevice;
  for (uint8_t i=0; i<numBwDevices; i++) {
    if (strncmp((char*)macAddress, (char*)bwDevices[i].mac, 6)) { continue; }
    numDevice = i;
    break;
  }

  bwDevices[numDevice].lastSeen = millis();

  if (length < 1) { return; }

  switch (data[0]) {
    case BW_CONNECT:
      if (length != 2) { return; }
      addDevice(macAddress, data[1]);
      break;
    case BW_UPDATE:
      if (length < 2) { return; }
      switch (data[1]) {
        case BW_PRESSED:
          bwDevices[numDevice].pressed = millis();
          handleButtonPress(numDevice);
          break;
        case BW_RELEASED:
          bwDevices[numDevice].pressed = 0;
          handleButtonRelease(numDevice);
          break;
        default:
          break;
      }
      break;
    default:
      return;
  }
}

void handleButtonPress(int numDevice) {
  digitalWrite(PIN_OUTPUT, HIGH);
  timeOutputOff = millis() + TIME_OUTPUT_ON;
}

void handleButtonRelease(int numDevice) {
  switch (bwControlGame) {
    case GAME_REACTION:
      reactionButtonPressed(numDevice);
      break;
  }
}

void initConnections() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  esp_wifi_set_mac(WIFI_IF_STA, mac);
  
  if (esp_now_init() != ERR_OK) { 
    // TODO show error
    return;
  }
  
#ifdef ESP32
  esp_now_register_recv_cb(onDataReceiveESP32);
#else
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
  esp_now_register_recv_cb(onDataReceive);
#endif
  
}

void initPins() {
  pinMode(PIN_OUTPUT, OUTPUT);
}

void setup() {
  // put your setup code here, to run once:
  initControls();
  initConnections();
  initPins();
}

void loop() {
  unsigned long timeNow = millis();
  updateDevices();
  updateGame();
  if (timeNow - displayLastUpdate > 3000) {
    updateDisplay();
    displayLastUpdate = timeNow;
  }
  if (timeOutputOff && (timeNow > timeOutputOff)) {
    timeOutputOff = 0;
    digitalWrite(PIN_OUTPUT, LOW);
  }
}
