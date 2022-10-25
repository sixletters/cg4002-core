import socket
import sensor_pb2 as proto
if __name__ == '__main__':
      with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.bind((str(socket.INADDR_ANY),1234))
        sock.listen()
        while True:
            conn, addr = sock.accept()
            with conn:
                print(f"connected with {addr}")
                data = conn.recv(2048)
                sensor = proto.Sensor()
                sensor. 
                conn.sendall("Data Received".encode("utf-8"))
                conn.close()