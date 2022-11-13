from bluepy.btle import Peripheral, DefaultDelegate, BTLEDisconnectError
import struct
import threading
import time
import multiprocessing as mp


idOfBeetle1 = 0
macAddressBeetle1 = "C4:BE:84:20:1A:5C"
idOfBeetle2 = 1
macAddressBeetle2 = "C4:BE:84:20:1C:4D"
idOfBeetle3 = 2
macAddressBeetle3 = "D0:39:72:BF:C1:D2"

idOfBeetle4 = 3
macAddressBeetle4 = "C4:BE:84:20:19:2C"
idOfBeetle5 = 4
macAddressBeetle5 = "D0:39:72:BF:C6:6B"
idOfBeetle6 = 5
macAddressBeetle6 = "B0:B1:13:2D:B5:02"


idOfPlayer1 = 1
idOfPlayer2 = 2
characteristicToWrite = "0000dfb1-0000-1000-8000-00805f9b34fb"


helloBuffer = [0, 0, 0, 0, 0, 0]
nakBuffer = [0, 0, 0, 0, 0, 0]
ackBuffer = [0, 0, 0, 0, 0, 0]


class Delegate(DefaultDelegate):
    def __init__(self, idOfPlayer, idOfBeetle, dataBuffer, lock, receivingBuffer):
        DefaultDelegate.__init__(self)
        self.idOfBeetle = idOfBeetle
        self.dataBuffer = dataBuffer
        self.lock = lock
        self.handshake = False
        self.fullPacketPlayer1 = False
        self.packetOneCountPlayer1 = bytearray(0)
        self.packetTwoCountPlayer1 = bytearray(0)
        self.fullPacketPlayer2 = False
        self.packetOneCountPlayer2 = bytearray(0)
        self.packetTwoCountPlayer2 = bytearray(0)
        self.idOfPlayer = idOfPlayer
        self.receivingBuffer = receivingBuffer

    def doChecksum(self, packetData):
        checksum = 0

        for i in range(19):
            checksum = (checksum ^ packetData[i]) & 0xFF
        
        if checksum == packetData[19]:
            return True
        else:
            return False

    def handleNotification(self, cHandle, data):
        self.receivingBuffer += data
        if(len(self.receivingBuffer) >= 20):
            packet = self.receivingBuffer[0:20]
            self.receivingBuffer = self.receivingBuffer[20:]
            packetType = struct.unpack('b', packet[1:2])
            if self.idOfBeetle == 0 and self.idOfPlayer == 1:
                if self.doChecksum(packet) == True:
                    if self.handshake and packetType == (0,): 
                        self.packetOnePlayer1 = packet[3:15]
                        self.packetOneCountPlayer1 = packet[2]
  
                    elif self.handshake and packetType == (1,):
                        
                        self.packetTwoPlayer1 = packet[3:15]
                        self.packetTwoCountPlayer1 = packet[2]

                        self.fullPacketPlayer1 = True
                    else:
                        pass
                else:
                    print("corrupted Packet 1")
                    self.receivingBuffer = b''
                    pass

                if self.fullPacketPlayer1 == True and (self.packetOneCountPlayer1 + 1 == self.packetTwoCountPlayer1):

                    a1Player1 = float("%.4f" % struct.unpack('<f', self.packetOnePlayer1[0:4]))
                    a2Player1 = float("%.4f" % struct.unpack('<f', self.packetOnePlayer1[4:8]))
                    a3Player1 = float("%.4f" % struct.unpack('<f', self.packetOnePlayer1[8:12]))
                    g1Player1 = float("%.4f" % struct.unpack('<f', self.packetTwoPlayer1[0:4]))
                    g2Player1 = float("%.4f" % struct.unpack('<f', self.packetTwoPlayer1[4:8]))
                    g3Player1 = float("%.4f" % struct.unpack('<f', self.packetTwoPlayer1[8:12]))
                
                    data = {
                        "playerID": self.idOfPlayer,
                        "beetleID": self.idOfBeetle,
                        "payload": {
                            "a1": a1Player1,
                            "a2": a2Player1,
                            "a3": a3Player1,
                            "g1": g1Player1,
                            "g2": g2Player1,
                            "g3": g3Player1
                        }
                    }


                    self.lock.acquire()
                    self.dataBuffer.put(data)
                    self.lock.release()
                    self.fullPacket = False
            
            elif self.idOfBeetle == 3 and self.idOfPlayer == 2:
                if self.doChecksum(packet) == True:
                    if self.handshake and packetType == (0,):
                        
                        self.packetOnePlayer2 = packet[3:15]
                        self.packetOneCountPlayer2 = packet[2]

                    elif self.handshake and packetType == (1,):
                        
                        self.packetTwoPlayer2 = packet[3:15]
                        self.packetTwoCountPlayer2 = packet[2]

                        self.fullPacketPlayer2 = True
                    else:
                        pass
                else:
                    print("corrupted Packet 2")
                    self.receivingBuffer = b''
                    pass

                if self.fullPacketPlayer2 == True and (self.packetOneCountPlayer2 + 1 == self.packetTwoCountPlayer2):
                    a1Player2 = float("%.4f" % struct.unpack('<f', self.packetOnePlayer2[0:4]))
                    a2Player2 = float("%.4f" % struct.unpack('<f', self.packetOnePlayer2[4:8]))
                    a3Player2 = float("%.4f" % struct.unpack('<f', self.packetOnePlayer2[8:12]))
                    g1Player2 = float("%.4f" % struct.unpack('<f', self.packetTwoPlayer2[0:4]))
                    g2Player2 = float("%.4f" % struct.unpack('<f', self.packetTwoPlayer2[4:8]))
                    g3Player2 = float("%.4f" % struct.unpack('<f', self.packetTwoPlayer2[8:12]))
                   

                    data = {
                        "playerID": self.idOfPlayer,
                        "beetleID": self.idOfBeetle,
                        "payload": {
                            "a1": a1Player2,
                            "a2": a2Player2,
                            "a3": a3Player2,
                            "g1": g1Player2,
                            "g2": g2Player2,
                            "g3": g3Player2
                        }
                    }

                    
                    self.lock.acquire()
                    self.dataBuffer.put(data)
                    self.lock.release()
                    self.fullPacket = False

            elif self.idOfBeetle == 1 or self.idOfBeetle == 4:
                if self.doChecksum(packet) == True:
                    if self.handshake:
                        
                        data = {
                            "playerID": self.idOfPlayer,
                            "beetleID": self.idOfBeetle
                        }
                        print("data: ", data)
                        self.lock.acquire()
                        self.dataBuffer.put(data)
                        self.lock.release()
                        ackBuffer[self.idOfBeetle] = 1
                    else:
                        pass
                else:
                    nakBuffer[self.idOfBeetle] = 1
                    print("corrupted packet gun")
                    self.receivingBuffer = b''
                    pass
            
            elif self.idOfBeetle == 2 or self.idOfBeetle == 5:
                if self.doChecksum(packet) == True:
                    if self.handshake:
                       
                        data = {
                            "playerID": self.idOfPlayer,
                            "beetleID": self.idOfBeetle
                        }
                        print("data: ", data)
                        self.lock.acquire()
                        self.dataBuffer.put(data)
                        self.lock.release()
                        ackBuffer[self.idOfBeetle] = 1
                    else:
                        pass
                else:
                    nakBuffer[self.idOfBeetle] = 1
                    print("corrupted packet shield")
                    self.receivingBuffer = b''
                    pass

            else:
                pass
        elif len(self.receivingBuffer) == 1 and self.receivingBuffer == b'A':
            print('ACK SENT')
            self.handshake = True
            helloBuffer[self.idOfBeetle] = 1
            self.receivingBuffer = b''
        else: 
            print("fragmented ", self.idOfBeetle)
            pass
     
class Communication:
    def __init__(self, idOfPlayer, idOfBeetle, macAddress, dataBuffer, lock):
        self.idOfBeetle = idOfBeetle
        self.macAddress = macAddress
        self.dev = None
        self.devDelegate = None
        self.dataBuffer = dataBuffer
        self.lock = lock
        self.idOfPlayer = idOfPlayer
        self.receivingBuffer = b''

    def writeToBeetle(self, val):
        characteristics = self.dev.getCharacteristics()
        for characteristic in characteristics:
            if characteristic.uuid == characteristicToWrite:
                print("sending", val, "packet to ", self.idOfBeetle)
                characteristic.write(bytes(val, encoding="utf-8"), withResponse=False)

    def connectToBeetle(self):
        while 1:
            try:
                self.dev = Peripheral(self.macAddress)
                print("connected!")
                devDelegate = Delegate(self.idOfPlayer, self.idOfBeetle, self.dataBuffer, self.lock, self.receivingBuffer)
                self.dev.setDelegate(devDelegate)
                break
            except Exception as e:
                print("Unable to connect: ", e)
                pass
    
    def threeWayHandshake(self):
        handshake = False
        while handshake == False:
            self.dev.waitForNotifications(1.0)
            if len(helloBuffer) != 0 and helloBuffer[self.idOfBeetle] == 1:
                self.writeToBeetle("B")
                handshake = True
                break
            else:
                self.writeToBeetle("A")
        print(self.idOfBeetle, ' handshake completed')
        return handshake

    
    def protocol(self):
       
        
        handshake = False
        while True:
            try:
                if handshake:
                    self.dev.waitForNotifications(0.001)
                    if len(ackBuffer) != 0 and ackBuffer[self.idOfBeetle] == 1:
                        self.writeToBeetle("D")
                        ackBuffer[self.idOfBeetle] = 0
                    elif len(nakBuffer) != 0 and nakBuffer[self.idOfBeetle] == 1:
                        self.writeToBeetle("C")
                        nakBuffer[self.idOfBeetle] = 0
                    
                    pass
                else:
                    self.connectToBeetle()
                    handshake = self.threeWayHandshake()
            except KeyboardInterrupt:
                self.dev.disconnect() 
            except (BTLEDisconnectError, AttributeError):
                print(self.idOfBeetle, ' disconnected!')
                handshake = False
                helloBuffer[self.idOfBeetle] = 0
                self.receivingBuffer = b''

def internalComms(dataBuffer, lock):
    beetle1 = Communication(idOfPlayer1, idOfBeetle1, macAddressBeetle1, dataBuffer, lock)
    thread1 = threading.Thread(target=beetle1.protocol, args=())
    beetle2 = Communication(idOfPlayer1, idOfBeetle2, macAddressBeetle2, dataBuffer, lock)
    thread2 = threading.Thread(target=beetle2.protocol, args=())
    beetle3 = Communication(idOfPlayer1, idOfBeetle3, macAddressBeetle3, dataBuffer, lock)
    thread3 = threading.Thread(target=beetle3.protocol, args=())
    beetle4 = Communication(idOfPlayer2, idOfBeetle4, macAddressBeetle4, dataBuffer, lock)
    thread4 = threading.Thread(target=beetle4.protocol, args=())
    beetle5 = Communication(idOfPlayer2, idOfBeetle5, macAddressBeetle5, dataBuffer, lock)
    thread5 = threading.Thread(target=beetle5.protocol, args=())
    beetle6 = Communication(idOfPlayer2, idOfBeetle6, macAddressBeetle6, dataBuffer, lock)
    thread6 = threading.Thread(target=beetle6.protocol, args=())
    thread1.start()
    thread2.start()
    thread3.start()
    thread4.start()
    thread5.start()
    thread6.start()
    thread1.join()
    thread2.join()
    thread3.join()
    thread4.join()
    thread5.join()
    thread6.join()

