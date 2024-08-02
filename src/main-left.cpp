#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <esp_sleep.h>
#include "assets/common.h"
#include "power/power.h"
#include "button/button.h"

#define SERVICE_UUID        "edf12be1-1a04-4164-a5de-9a448779dbe5"
#define CHARACTERISTIC_UUID "32d689da-97ee-403e-b913-dced0792a563"

#define OX  30
#define OY  24

#define CLK 10
#define DT  21
#define SW  3
#define BTNL 4
#define BTNR 7

//# IIC version
//ESP32C3 OLED开发板的屏幕接线：scl-->gpio6  sda-->gpio5 如果是Arduino则改为scl-->A5  sda-->A4
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,6,5,U8X8_PIN_NONE); 
PowerManager powerManager(u8g2);
Btn btnSW(false, SW, true, 200);
Btn btnL(true, BTNL, true, 0);
Btn btnR(true, BTNR, true, 0);


void displayJoystickXY(int x, int y);
void displayTrigger(int val);
void displayBtnUp();
void displayBtnDown();
void displayBtnLeft();
void displayBtnRight();
void displayBtnView();
void displayBtnMenu();
void displayBtnA();
void displayBtnB();
void displayBtnX();
void displayBtnY();
void displayBtnLB();
void displayBtnRB();
void displayBtnLT();
void displayBtnRT();
void displayBtnLS();
void displayBtnRS();
void displayIdle();
void uint8ToBinaryString(uint8_t value, char* binaryStr);
void drawFourLines();
void updateEncoder();

uint8_t currTriggerVal = 255;
uint8_t firstByte = 128;
uint8_t secondByte = 0;
uint8_t thirdByte = 0;
uint8_t fourthByte = 0;

volatile int encoderValue = 128;
volatile unsigned long lastInterrupTime = 0;
int lastEncoded = 0;

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      uint8_t* data = pCharacteristic->getData();
      // if data is empty
      if (data == NULL) { return; }
      firstByte = data[0];
      secondByte = data[1];
      thirdByte = data[2];
      fourthByte = data[3];
    //   selectChannel(firstByte);
      currTriggerVal = firstByte;  
    }
};

void setup() {
    Serial.begin(115200);
    while(!Serial);

    u8g2.setContrast(250);
    u8g2.begin();
    u8g2.setFlipMode(1);
  BLEDevice::init("BLEAdaptiveController_Left");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
  pCharacteristic->setCallbacks(new MyCallbacks());
  pCharacteristic->setValue("");
  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();

  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(BTNL, INPUT_PULLUP);
  pinMode(BTNR, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(CLK), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT), updateEncoder, CHANGE);
}

void loop() {
    btnSW.ifPressedDo([](){
        if (secondByte != 255) {
            secondByte = 255;
            powerManager.refresh();
        }
    }, [](){});
    btnSW.ifReleasedDo([](){
        if (secondByte != 0) {
            secondByte = 0;
            powerManager.refresh();
        }
    }, [](){});
    
    btnL.ifPressedDo([](){
        if (thirdByte != 255) {
            thirdByte = 255;
            powerManager.refresh();
        }
    }, [](){});
    btnL.ifReleasedDo([](){
        if (thirdByte != 0) {
            thirdByte = 0;
            powerManager.refresh();
        }
    }, [](){});
    
    btnR.ifPressedDo([](){
        if (fourthByte != 0) {
            fourthByte = 0;
        } else if (fourthByte != 255) {
            fourthByte = 255;
        }
        powerManager.refresh();
    }, [](){});

    if (firstByte != encoderValue) {
        firstByte = encoderValue;
        powerManager.refresh();
        Serial.print("firstByte != encoderValue");
        Serial.print(firstByte);
        Serial.print("  ");
        Serial.println(encoderValue);
    }
  
    if (powerManager.shouldEnterSleep()) {
        Serial.println("powerManager.shouldEnterSleep()");
        powerManager.enterSleep();
    }
    
    if (powerManager.shouldRefresh()) {
        Serial.println("powerManager.shouldRefresh()");
        powerManager.wakeUp();
        drawFourLines();
        powerManager.postDrawing();
    }
    // do {
        // 第一行 代表joystick X Y
        // displayJoystickXY(-255,-255);
        // 第二行 第一列按键图案
        // displayBtnUp();
        // 第二行 第二列按键图案
        // displayBtnLB();
        // 第三行 代表trigger 线性值
        // displayTrigger(currTriggerVal);
        //
        // needRefresh = false;
    // } while (u8g2.nextPage());
    
    // delay(3000);  // Wait for 3 seconds
    
    // // Display blank screen
    // u8g2.clearDisplay();
    
    // delay(1000);  // Wait for 3 seconds
}

void updateEncoder() {
    unsigned long interruptTime = millis();
    if (interruptTime - lastInterrupTime > 1/2 * 1000) {
          int MSB = digitalRead(CLK);
          int LSB = digitalRead(DT);
          
          int encoded = (MSB << 1) | LSB;
          int sum = (lastEncoded << 2) | encoded;
          
          if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue++;
          if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue--;
          if (encoderValue > 255) {
            encoderValue = 255;
          } else if (encoderValue < 0) {
              encoderValue = 0;
          }
          
          lastEncoded = encoded;
    }
    lastInterrupTime = interruptTime;
}

void drawFourLines() {
    u8g2.firstPage();
    do {
        u8g2.setFont(u8g2_font_spleen6x12_mu);
        char firstLine[9];
        uint8ToBinaryString(firstByte, firstLine);
        u8g2.drawStr(OX, OY, firstLine);
        
        char secondLine[9];
        uint8ToBinaryString(secondByte, secondLine);
        u8g2.drawStr(OX, OY+8, secondLine);

        char thirdLine[9];
        uint8ToBinaryString(thirdByte, thirdLine);
        u8g2.drawStr(OX, OY+8*2, thirdLine);

        char fourthLine[9];
        uint8ToBinaryString(fourthByte, fourthLine);
        u8g2.drawStr(OX, OY+8*3, fourthLine);
    } while (u8g2.nextPage());
}

void uint8ToBinaryString(uint8_t value, char* binaryStr) {
    for (int i = 7; i >= 0; i--) {
        binaryStr[7-i] = (value & (1 << i)) ? '1' : '0';
    }
    binaryStr[8] = '\0';
}

void displayIdle() {
    u8g2.setFont(u8g2_font_streamline_technology_t);
    int x = random(0,53);
    int y = random(0,29);
    u8g2.drawGlyph(OX+x,OY+y,0x0032);// https://github.com/olikraus/u8g2/wiki/fnticons
}

void displayJoystickXY(int x, int y) {
    u8g2.setFont(u8g2_font_spleen6x12_mu);
    char xyStr[10]; 
    sprintf(xyStr, "%d,%d", x, y);
    u8g2.drawStr(OX, OY, xyStr);
}

void displayTrigger(int val) {
    u8g2.setFont(u8g2_font_spleen6x12_mu);
    char xyStr[10]; 
    sprintf(xyStr, "%d", val);
    u8g2.drawStr(OX, OY+27, xyStr);
}

void displayBtnUp() {
    u8g2.drawXBMP(OX,OY,18,18,btnUp18);
}

void displayBtnDown() {
    u8g2.drawXBMP(OX,OY,18,18,btnDown18);
}

void displayBtnLeft() {
    u8g2.drawXBMP(OX,OY,18,18,btnLeft18);
}

void displayBtnRight() {
    u8g2.drawXBMP(OX,OY,18,18,btnRight18);
}

void displayBtnView() {
    u8g2.drawXBMP(OX,OY,18,18,btnView18);
}

void displayBtnMenu() {
    u8g2.drawXBMP(OX,OY,18,18,btnMenu18);
}

void displayBtnA() {
    u8g2.drawXBMP(OX,OY,18,18,btnA18);
}

void displayBtnB() {
    u8g2.drawXBMP(OX,OY,18,18,btnB18);    
}

void displayBtnX() {
    u8g2.drawXBMP(OX,OY,18,18,btnX18);
}

void displayBtnY() {
    u8g2.drawXBMP(OX,OY,18,18,btnY18);
}

void displayBtnLB() {
    u8g2.drawXBMP(OX+24,OY,30,18,btnLB_30_18);
}

void displayBtnRB() {
    u8g2.drawXBMP(OX+24,OY,30,18,btnRB_30_18);
}

void displayBtnLT() {
    u8g2.drawXBMP(OX+24,OY,17,18,btnLT_17_18);
}

void displayBtnRT() {
    u8g2.drawXBMP(OX+24,OY,17,18,btnRT_17_18);
}

void displayBtnLS() {
    u8g2.drawXBMP(OX+24,OY,24,18,btnLS_24_18);
}

void displayBtnRS() {
    u8g2.drawXBMP(OX+24,OY,24,18,btnRS_24_18);
}

