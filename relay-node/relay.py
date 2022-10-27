import socket
import csv
HOST = "0.0.0.0"
import struct
MYTCP_PORT = 8080
import multiprocessing as mp
import sensor_pb2
import json
import util
import threading
import math
from connect import internalComms
import struct  
WINDOW_LEN = 25
A_THRESHOLD = 1.2
import test

def sendToUltra96(data):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((HOST, MYTCP_PORT))
    sock.send(data)
    sock.close()


def relayProcess(dataBuffer, lock):
    P1_IMU_DATA_BUFFER = []  
    P2_IMU_DATA_BUFFER = []  
    collect_for_1 = False
    collect_for_2 = False
    while True:
        if not dataBuffer.empty():
            lock.acquire()
            data = dataBuffer.get()
            lock.release()
            
            if data["beetleID"] != 0:
                serializedData, _= util.dataTransformation(data)
                length = len(serializedData).to_bytes(4,'little')
                sendToUltra96(length + serializedData)
                continue
            
            if data["playerID"] == 1 and util.actionStart(data, A_THRESHOLD) and not collect_for_1:
                collect_for_1 = True

            if data["playerID"] == 2 and util.actionStart(data, A_THRESHOLD) and not collect_for_2:
                collect_for_2 = True

            if data["playerID"] == 1 and collect_for_1:
                P1_IMU_DATA_BUFFER.append(data)
                if len(P1_IMU_DATA_BUFFER) >= WINDOW_LEN:
                    serializedData, idleCheck = util.dataTransformation(P1_IMU_DATA_BUFFER)
                    length = len(serializedData).to_bytes(4,'little')
                    if not idleCheck:
                        print("SENDING")
                    sendToUltra96(length + serializedData)
                    P1_IMU_DATA_BUFFER = []
                    collect_for_1 = False

            if data["playerID"] == 2 and collect_for_2:
                P2_IMU_DATA_BUFFER.append(data)
                if len(P2_IMU_DATA_BUFFER) >= WINDOW_LEN:
                    serializedData, idleCheck = util.dataTransformation(P2_IMU_DATA_BUFFER)
                    length = len(serializedData).to_bytes(4,'little')
                    if not idleCheck:
                        print("SENDING")
                        sendToUltra96(length + serializedData)
                    P2_IMU_DATA_BUFFER = []
                    collect_for_2 = False

                
                

if __name__ == '__main__':
    dataBuffer = mp.Queue()
    lock = mp.Lock()
    relay = mp.Process(target=relayProcess, args=(dataBuffer, lock))
    internalCommsProcess = mp.Process(target=internalComms, args=(dataBuffer, lock))
    # init(dataBuffer)
    # test.init2(dataBuffer)
    relay.start()
    internalCommsProcess.start()
    relay.join()
    internalCommsProcess.join()
    