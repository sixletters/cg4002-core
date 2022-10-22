from bluepy.btle import Peripheral, DefaultDelegate, BTLEDisconnectError
import struct
import threading
import time
import multiprocessing as mp
import numpy

idOfBeetle1 = 0
macAddressBeetle1 = "C4:BE:84:20:1A:5C"
# macAddressBeetle1 = "D0:39:72:BF:BD:B7"

idOfBeetle2 = 1
macAddressBeetle2 = "C4:BE:84:20:1C:4D"
idOfBeetle3 = 2
macAddressBeetle3 = "B0:B1:13:2D:B5:02"
characteristicToWrite = "0000dfb1-0000-1000-8000-00805f9b34fb"

helloBuffer = [0, 0, 0]
receivingBuffer = ""
allBeetlesConnected = []
nakBuffer = [0, 0, 0]
ackBuffer = [0, 0, 0]


class Delegate(DefaultDelegate):
    def __init__(self, idOfBeetle, dataBuffer, lock):
        DefaultDelegate.__init__(self)
        self.idOfBeetle = idOfBeetle
        self.dataBuffer = dataBuffer
        self.lock = lock
        self.handshake = False
        self.fullPacket = False
        self.packetOneCount = bytearray(0)
        self.packetTwoCount = bytearray(0)

    def doChecksum(self, packetData):
        checksum = 0

        for i in range(19):
            checksum = (checksum ^ packetData[i]) & 0xFF
        
        if checksum == packetData[19]:
            return True
        else:
            return False

    def handleNotification(self, cHandle, data):
        global receivingBuffer
        # print("length of data: ", len(data))
        receivingBuffer += data

        if(len(receivingBuffer) >= 20):
            packet = bytearray(receivingBuffer[0:20])
            receivingBuffer = receivingBuffer[20:]
            packetType = struct.unpack('b', packet[1:2])
            # print("packetType: ", packetType, " receiving packet: ", packet)
            if self.idOfBeetle == 0:
                if self.doChecksum(packet) == True:
                    if self.handshake and packetType == (0,):
                        # print("packetCount = ", struct.unpack('b', packet[3:4]))
                        # print("a1 = %.4f" % struct.unpack('<f', packet[4:8]))
                        # print("a2 = %.4f" % struct.unpack('<f', packet[8:12]))
                        # print("a3 = %.4f" % struct.unpack('<f', packet[12:16]))
                        
                        self.packetOne = packet[3:15]
                        self.packetOneCount = packet[2]
                        # print("packetCount: ", self.packetOneCount)
                        # print("packetOneCount = ", self.packetOneCount)
                        # print("packetOne: ", self.packetOne)
                        # q.put(packet)
                    elif self.handshake and packetType == (1,):
                        # print("packetCount = ", struct.unpack('b', packet[3:4]))
                        # print("g1 = %.4f" % struct.unpack('<f', packet[4:8]))
                        # print("g2 = %.4f" % struct.unpack('<f', packet[8:12]))
                        # print("g3 = %.4f" % struct.unpack('<f', packet[12:16]))
                        
                        self.packetTwo = packet[3:15]
                        self.packetTwoCount = packet[2]
                        # print("packetTwoCount = ", self.packetTwoCount)
                        # print("packetTwo: ", self.packetTwo)
                        self.fullPacket = True
                        # print("full = ", self.fullPacket)
                        # print("count = ", self.packetOneCount + 1, self.packetTwoCount)
                        # q.put(packet)
                    else:
                        pass
                else:
                    print("corrupted Packet")
                    pass

                if self.fullPacket and (self.packetOneCount + 1 == self.packetTwoCount):
                    # print("put packet")
                    # print("a1 = %.4f" % struct.unpack('<f', self.packetOne[0:4]))
                    # print("a2 = %.4f" % struct.unpack('<f', self.packetOne[4:8]))
                    # print("a3 = %.4f" % struct.unpack('<f', self.packetOne[8:12]))
                    # print("g1 = %.4f" % struct.unpack('<f', self.packetTwo[0:4]))
                    # print("g2 = %.4f" % struct.unpack('<f', self.packetTwo[4:8]))
                    # print("g3 = %.4f" % struct.unpack('<f',self. packetTwo[8:12]))
                    a1 = float("%.4f" % struct.unpack('<f', self.packetOne[0:4]))
                    a2 = float("%.4f" % struct.unpack('<f', self.packetOne[4:8]))
                    a3 = float("%.4f" % struct.unpack('<f', self.packetOne[8:12]))
                    g1 = float("%.4f" % struct.unpack('<f', self.packetTwo[0:4]))
                    g2 = float("%.4f" % struct.unpack('<f', self.packetTwo[4:8]))
                    g3 = float("%.4f" % struct.unpack('<f',self. packetTwo[8:12]))
                    # array = str(a1) + ", " + str(a2) + ", " + str(a3) + ", " + str(g1) + ", " + str(g2) + ", " + str(g3)
                    # with open('readme.txt', 'a') as f:
                    #     f.write(array)
                    #     f.write('\n')

                    # data = {
                    #     "playerID": 1,
                    #     "beetleID": self.idOfBeetle,
                    #     "packetOne": self.packetOne,
                    #     "packetTwo": self.packetTwo
                    # }

                    data = {
                        "playerID": 1,
                        "beetleID": self.idOfBeetle,
                        "payload": {
                            "a1": a1,
                            "a2": a2,
                            "a3": a3,
                            "g1": g1,
                            "g2": g2,
                            "g3": g3
                        }
                    }

                    # print("data: ", data)
                    self.lock.acquire()
                    self.dataBuffer.put(data)
                    self.lock.release()
                    self.fullPacket = False
                    
            elif self.idOfBeetle == 1:
                if self.doChecksum(packet) == True:
                    if self.handshake:
                        # pdata = packet[1:2]
                        data = {
                            "playerID": 1,
                            "beetleID": 1
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
                    print("corrupted packet 1")
                    pass
            
            elif self.idOfBeetle == 2:
                if self.doChecksum(packet) == True:
                    if self.handshake:
                        # qdata = packet[1:2]
                        data = {
                            "playerID": 2,
                            "beetleID": 2
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
                    print("corrupted packet 2")
                    pass

            else:
                pass
        elif len(receivingBuffer) == 1 and data == str.encode("A"):
            print('ACK SENT')
            self.handshake = True
            helloBuffer[self.idOfBeetle] = 1
            receivingBuffer = ""
        else: 
            print("fragmented")
            pass
     
class Communication:
    def __init__(self, idOfBeetle, macAddress, dataBuffer, lock):
        self.idOfBeetle = idOfBeetle
        self.macAddress = macAddress
        self.dev = None
        self.devDelegate = None
        self.dataBuffer = dataBuffer
        self.lock = lock

    def writeToBeetle(self, val):
        characteristics = self.dev.getCharacteristics()
        for characteristic in characteristics:
            if characteristic.uuid == characteristicToWrite:
                print("sending", val, "packet to ", self.idOfBeetle)
                characteristic.write(bytes(val), withResponse=False)

    def connectToBeetle(self):
        while 1:
            try:
                self.dev = Peripheral(self.macAddress)
                print("connected!")
                devDelegate = Delegate(self.idOfBeetle, self.dataBuffer, self.lock)
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
        # self.connectToBeetle() 
        
        handshake = False
        while True:
            try:
                # self.dev.waitForNotifications(0.2)
                if handshake:
                    # if flag == False:
                    # self.writeToBeetle(3,0)
                    #     flag = True
                    self.dev.waitForNotifications(0.001)
                    if len(ackBuffer) != 0 and ackBuffer[self.idOfBeetle] == 1:
                        self.writeToBeetle("D")
                        ackBuffer[self.idOfBeetle] = 0
                    elif len(nakBuffer) != 0 and nakBuffer[self.idOfBeetle] == 1:
                        self.writeToBeetle("C")
                        nakBuffer[self.idOfBeetle] = 0
                    # print("waiting")
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


def print_data(queue, lock):
    while True:
        try: 
            lock.acquire()
            packet = queue.get()
            lock.release()
            print("packet: ", packet)
            # print("idOfBeetle = ", packet[0])
            # print("a1 = %.4f" % struct.unpack('<f', packet[1:5]))
            # print("a2 = %.4f" % struct.unpack('<f', packet[5:9]))
            # print("a3 = %.4f" % struct.unpack('<f', packet[9:13]))
            # print("g1 = %.4f" % struct.unpack('<f', packet[13:17]))
            # print("g2 = %.4f" % struct.unpack('<f', packet[17:21]))
            # print("g3 = %.4f" % struct.unpack('<f', packet[21:25]))

        except KeyboardInterrupt:
            break

def internalComms(dataBuffer, lock):
    beetle1 = Communication(idOfBeetle1, macAddressBeetle1, dataBuffer, lock)
    thread1 = threading.Thread(target=beetle1.protocol, args=())
    beetle2 = Communication(idOfBeetle2, macAddressBeetle2, dataBuffer, lock)
    thread2 = threading.Thread(target=beetle2.protocol, args=())
    beetle3 = Communication(idOfBeetle3, macAddressBeetle3, dataBuffer, lock)
    thread3 = threading.Thread(target=beetle3.protocol, args=())
    thread1.start()
    thread2.start()
    thread3.start()
    thread1.join()
    thread2.join()
    thread3.join()

