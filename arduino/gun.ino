#include <Arduino.h>

#define IR_RECEIVE_PIN      5 
#define IR_SEND_PIN         3

#include <IRremote.hpp>

#define BUTTON_PIN 2
#define LED_PIN 4
#define SAMPLE_RATE 1000 // Milliseconds -> 1Hz

byte packet[20];
bool handshakeDone;
byte seqNo;
byte packetCount;
volatile bool sendData = true;
volatile bool startTimer = false;
unsigned long startTime = 0;
unsigned long timeout = 1000;

///**************************************************************************************************************************
// * IR Emitter-related variables
// **************************************************************************************************************************/

uint16_t sAddress = 0x0B05; // Data to be encoded in the IR beam
uint8_t sRepeats = 1;
volatile bool sendShot = false;

uint8_t sCommand = 0xAA;

///***************************************************************************************************************************
// * INTERRUPT SERVICE ROUTINE - TO SEND SHOT
// ***************************************************************************************************************************/
void updateState() {
  sendShot = true;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshakeDone = false;
  seqNo = 0;
  packetCount = 0x00;
  sendShot = false;
  sendData = true;
  startTimer = false;
  startTime = 0;
  timeout = 1000;
  pinMode(13, OUTPUT);
  IrSender.begin(); 
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), updateState, FALLING);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

byte doCheckSum(byte packet[]) {
  byte checksum = 0;

  for(int i=0; i < 19; i++) {
    checksum ^= packet[i];
  }

  return checksum;
}

void writePacket(
  byte idOfBeetle,
  byte packetCount
) {
  byte packet[20];
  packet[0] = (byte) idOfBeetle;
  packet[1] = (byte) 0x01;
  packet[2] = (byte) packetCount;
  packet[3] = (byte) 0;
  packet[4] = (byte) 0;
  packet[5] = (byte) 0;
  packet[6] = (byte) 0;
  packet[7] = (byte) 0;
  packet[8] = (byte) 0;
  packet[9] = (byte) 0;
  packet[10] = (byte) 0;
  packet[11] = (byte) 0;
  packet[12] = (byte) 0;
  packet[13] = (byte) 0;
  packet[14] = (byte) 0;
  packet[15] = (byte) 0;
  packet[16] = (byte) 0;
  packet[17] = (byte) 0;
  packet[18] = (byte) 0;
  packet[19] = (byte) doCheckSum(packet);
  Serial.write((byte*)&packet, sizeof(packet));
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = Serial.read();
  if (millis() > startTime + timeout && startTimer) {
    handshakeDone = false;
    startTimer = false;
    packetCount = 0x00;
    sendShot = false;
    sendData = true; 
  }

  if (handshakeDone && data != 65) {
    if (data == 67) {
      writePacket(0x01,packetCount);
      startTime = millis();
    }
    else if (data == 68) {
      sendData = true;
      if (startTimer == true) {
        startTimer = false;
      }
    }
    else {
      if(sendShot && sendData) { // Send SHOT when interrupt is triggered
        IrSender.sendNEC(sAddress, sCommand, sRepeats); // Send IR beam with encoded data
        writePacket(0x01,packetCount);
        packetCount ++;
        digitalWrite(LED_PIN, HIGH);
        delay(1000); // Necessary for encoding data onto IR beam
        sendShot = false;
        sendData = false;
        if (startTimer == false) {
          startTimer = true;
          startTime = millis();
        }
      }
      else {
        digitalWrite(LED_PIN, LOW);
      }
    }
  } else {
    handshakeDone = false;
    if(data == 65) {
      Serial.write("A");
    } 
    else if(data == 66) {
      digitalWrite(13, HIGH);
      handshakeDone = true;
    }
  }
  
}
