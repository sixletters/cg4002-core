#include <Arduino.h>
#define DECODE_NEC  // Library specifies to do this, based on which protocol you are using

#define IR_RECEIVE_PIN      5 
#define IR_SEND_PIN         3

#include <IRremote.hpp>

#define LED_PIN_1 4


/**************************************************************************************************************************
 * IR Emitter-related variables
 **************************************************************************************************************************/
// Data to be checked in the decoded IR beam
uint8_t rCommand = 0xAA;

byte packet[20];
bool handshakeDone;
byte seqNo;
byte packetCount;
volatile bool sendData = true;
volatile bool startTimer = false;
unsigned long startTime = 0;
unsigned long timeout = 1000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshakeDone = false;
  seqNo = 0;
  packetCount = 0x00;
  sendData = true;
  startTimer = false;
  startTime = 0;
  timeout = 1000;
  pinMode(13, OUTPUT);
  pinMode(LED_PIN_1, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  digitalWrite(LED_PIN_1, HIGH);
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
    sendData = true; 
  }

  if (handshakeDone && data != 65) {
    if (data == 67) {
      writePacket(0x02,packetCount);
      startTime = millis();
    }
    else if (data == 68) {
      sendData = true;
      if (startTimer == true) {
        startTimer = false;
      }
    } else {
      if (IrReceiver.decode()) { // Checks if IR beam is received
        if (IrReceiver.decodedIRData.command == rCommand) {
          if (sendData) {
            Serial.flush();
            writePacket(0x02, packetCount);
            packetCount ++;
            digitalWrite(LED_PIN_1, LOW);
            delay(250);
            digitalWrite(LED_PIN_1, HIGH);
            delay(100);
            digitalWrite(LED_PIN_1, LOW);
            delay(250);
            sendData = false;
            if (startTimer == false) {
              startTimer = true;
              startTime = millis();
            }
          }
        }
          digitalWrite(LED_PIN_1, HIGH);
          IrReceiver.resume(); // Enable receiving of the next value
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
