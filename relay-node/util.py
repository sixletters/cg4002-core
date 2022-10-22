import numpy as np
import math
import sensor_pb2 as proto
THRESHOLD = 0.9

def get_min(inputs):
    return np.min(inputs)

def get_max(inputs):
    return np.max(inputs)

def get_mean(inputs):
    return np.mean(inputs)

def get_std(inputs):
    return np.std(inputs)

def get_med(inputs):
    arr = np.ma.array(inputs).compressed()
    med = np.median(arr)
    return np.median(np.abs(arr - med))

def get_range(inputs):
    return np.max(inputs)-np.min(inputs)

def get_power_spectrum(inputs):
    ft = np.fft.fft(inputs)
    return np.abs(ft**2/len(inputs))

def get_max_f(inputs):
    S = get_power_spectrum(inputs)
    return np.max(S)

def get_mean_f(inputs):
    S = get_power_spectrum(inputs)
    return np.mean(S)

def get_std_f(inputs):
    S = get_power_spectrum(inputs)
    return np.var(S)

def normalize(inputs):
    mean = np.mean(inputs)
    std = np.std(inputs)
    final = (inputs-mean)/std
    return final

def dataParser(inputs, dataMap, key):
    min = get_min(inputs)
    maxV = get_max(inputs)
    mean = get_mean(inputs)
    std = get_std(inputs)
    med = get_med(inputs)
    rnge = get_range(inputs)
    max_f = get_max_f(inputs)
    mean_f = get_mean_f(inputs)
    std_f = get_std_f(inputs)

    dataMap[key] = [min, maxV, mean, std, med, rnge, max_f, mean_f, std_f]

def idle(a1,a2,a3, threshold):
    std_1 = get_std(a1)
    std_2 = get_std(a2)
    std_3 = get_std(a3)

    avg = math.sqrt(std_1 ** 2 + std_2 ** 2 + std_3 ** 2 )
    if avg < threshold:
        return True
    else:
        return False

def actionStart(data, threshold):
    averageA = math.sqrt(data["payload"]["a1"] ** 2 + data["payload"]["a2"] ** 2 + data["payload"]["a3"] ** 2 )
    if averageA > threshold:
        return True
    return False

def dataTransformation(DATA_BUFFER):
    sensor = proto.Sensor()
    idleChecker = False
    if isinstance(DATA_BUFFER, list):
        a1 = []
        a2 = []
        a3 = []
        sensor.playerID = DATA_BUFFER[0]["playerID"]
        sensor.beetleID = 0
        for data in DATA_BUFFER:
            IMU = sensor.payload.add()
            IMU.a1 = data["payload"]["a1"]
            IMU.a2 = data["payload"]["a2"]
            IMU.a3 = data["payload"]["a3"]
            IMU.g1 = data["payload"]["g1"]
            IMU.g2 = data["payload"]["g2"]
            IMU.g3 = data["payload"]["g3"]
            a1.append(data["payload"]["a1"])
            a2.append(data["payload"]["a2"])
            a3.append(data["payload"]["a3"])
        idleChecker = idle(a1,a2,a3, THRESHOLD)
        return sensor.SerializeToString(), idleChecker

    else:
        sensor.playerID = DATA_BUFFER["playerID"]
        sensor.beetleID= DATA_BUFFER["beetleID"]
    return sensor.SerializeToString(), idleChecker