#include <Wire.h>
const int MPU = 0x68; // MPU6050 I2C address
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
byte packet[20];
bool handshakeDone;
byte seqNo;
byte packetCount;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshakeDone = false;
  seqNo = 0;
  packetCount = 0x00;
  pinMode(13, OUTPUT);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission
  delay(20);
}

typedef union {
  byte byteValue[4];
  float floatValue;
} floatByteData;

int floatToByte(int index, byte packet[], float data) {
  floatByteData x;
  x.floatValue = data;

  for(int i = 0; i < 4; i++) {
    packet[index] = x.byteValue[i];
    index ++;
  }
  return index;
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
  byte packetType,
  byte packetCount,
  float f1,
  float f2,
  float f3
) {
  byte packet[20];
  int index = 3;
  packet[0] = (byte) idOfBeetle;
  packet[1] = (byte) packetType;
  packet[2] = (byte) packetCount;
  index = floatToByte(index, packet, f1);
  index = floatToByte(index, packet, f2);
  index = floatToByte(index, packet, f3);
  packet[15] = (byte) 0;
  packet[16] = (byte) 0;
  packet[17] = (byte) 0;
  packet[18] = (byte) 0;
  packet[19] = (byte) doCheckSum(packet);
  Serial.write((byte*)&packet, sizeof(packet));
}

void getAccData(byte packetCount) {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  //For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
  writePacket(0x03, 0x00, packetCount, AccX, AccY, AccZ);
}

void getGyroData(byte packetCount) {
  Wire.beginTransmission(MPU);
  Wire.write(0x43); // Gyro data first register address 0x43
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 4 registers total, each axis value is stored in 2 registers
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0; // For a 250deg/s range we have to divide first the raw value by 131.0, according to the datasheet
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroX = GyroX + 11.05; // GyroErrorX ~(-7.58)
  GyroY = GyroY + 6.54; // GyroErrorY ~(-6.87)
  GyroZ = GyroZ - 1.49; // GyroErrorZ ~ (0.11)
  writePacket(0x03, 0x01, packetCount, GyroX, GyroY, GyroZ);
}

void loop() {
  // put your main code here, to run repeatedly:

  int data = Serial.read();
  if (packetCount == 0x200) {
    packetCount = 0x00;
  }
  if (handshakeDone && data != 65) {
    getAccData(packetCount);
    packetCount ++;
    delay(25);
    getGyroData(packetCount);
    packetCount ++;
    delay(25);
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
