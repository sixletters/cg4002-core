import socket
import sensor_pb2 as proto
from Cryptodome.Cipher import AES
import base64
from Cryptodome.Random import get_random_bytes
from Crypto.Util.Padding import pad
key = "connecttoevalkey".encode("utf-8")
iv = get_random_bytes(AES.block_size)
import sensor_pb2 as proto
import numpy as np
# import predict
# from pynq import Overlay
# from tensorflow import keras

# model = keras.models.load_model('./testModel_64x64_15hz_9features_left/')
# overlay = Overlay('/home/xilinx/cg4002-core/Ultra96/utility-server/testModel_64x64_15hz_9features_left/design_3_wrapper.bit')
# dma = overlay.axi_dma_0
actionString = ["shield", "grenade","reload","exit"]
def formatData(gameState, key, iv):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    gameStateData = pad(gameState, AES.block_size)
    encoded = base64.b64encode(iv + cipher.encrypt(gameStateData ))
    prefix = (str(len(encoded)) + "_").encode("utf-8")
    encoded = prefix + encoded
    return encoded


if __name__ == '__main__':
      with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind((str(socket.INADDR_ANY),1234))
        sock.listen()
        while True:
            conn, addr = sock.accept()
            with conn:
                print(f"connected with {addr}")
                apiRequestType = conn.recv(1)
                payload = conn.recv(2048)
                if apiRequestType == b'\x00':
                  sensor = proto.Sensor()
                  sensor.ParseFromString(payload)
                  predictionInputs = [[],[],[],[],[],[]]
                  for i in sensor.payload:
                    predictionInputs[0].append(i.a1)
                    predictionInputs[1].append(i.a2)
                    predictionInputs[2].append(i.a3)
                    predictionInputs[3].append(i.g1)
                    predictionInputs[4].append(i.g2)
                    predictionInputs[5].append(i.g3)

                  # prediction = predict.predicts(predictionInputs, dma)
                  # print(actionString[prediction])
                  # prediction = str(prediction).encode("utf-8")
                  prediction = str("0").encode("utf-8")
                  # prediction = str(input(f"PLEASE ENTER ACTION FOR PLAYER {sensor.playerID}")).encode("utf-8")
                  conn.sendall(prediction)
                  conn.close()
                else:
                  encoded = formatData(payload,key,iv)
                  prefix = (str(len(encoded)) + "_").encode("utf-8")
                  encoded = prefix + encoded
                  conn.sendall(encoded)
                  conn.close()


