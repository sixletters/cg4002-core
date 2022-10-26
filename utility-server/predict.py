from pynq import Overlay
import pynq.lib.dma
from pynq import DefaultIP
from pynq import allocate
import struct
import numpy as np
import time
from struct import pack, unpack
import scipy.stats as stats

path = ''

def normalize(inputs):
    mean = np.mean(inputs)
    std = np.std(inputs)
    final = (inputs-mean)/std
    return final

def get_min(inputs):
    return np.min(inputs)

def get_max(inputs):
    return np.max(inputs)

def get_mean(inputs):
    return np.mean(inputs)

def get_std(inputs):
    return np.std(inputs)

def get_mad(inputs):
    arr = np.ma.array(inputs).compressed()
    med = np.median(arr)
    return np.median(np.abs(arr - med))

def get_range(inputs):
    return np.max(inputs)-np.min(inputs)

def get_kurtosis(inputs):
    return stats.kurtosis(inputs)

def get_power_spectrum(inputs):
    ft = np.fft.fft(inputs)
    return np.abs(ft**2)/len(inputs)

def get_max_f(inputs):
    S = get_power_spectrum(inputs)
    return np.max(S)

def get_mean_f(inputs):
    S = get_power_spectrum(inputs)
    return np.mean(S)

def get_std_f(inputs):
    S = get_power_spectrum(inputs)
    return np.std(S)

def get_kurtosis_f(inputs):
    S = get_power_spectrum(inputs)
    return stats.kurtosis(S)

def get_sum_f(inputs):
    S = get_power_spectrum(inputs)
    return np.sum(S)

def get_skew(inputs):
    return stats.skew(inputs)

def get_skew_f(inputs):
    S = get_power_spectrum(inputs)
    return stats.skew(S)

def get_power(inputs):
    return np.mean(inputs**2)

def get_ptp(inputs):
    return np.ptp(inputs)

def get_peak(inputs):
    return np.max(np.abs(inputs))

def get_peak_f(inputs):
    S = get_power_spectrum(inputs)
    return np.max(np.abs(S))

def get_rms(inputs):
    return np.sqrt(np.mean(inputs**2))

def softmax(x):
    e_x = np.exp(x - np.max(x))
    return np.log(e_x / e_x.sum())

def predicts(inputs, dma): #6 x 25
    output = []
    features = [] # 9 x 6
    inputs = np.asarray(inputs, dtype=np.single)
    #inputs = inputs.transpose()
    acc_x = normalize(inputs[0]) # array of 15 datapoints 
    acc_y = normalize(inputs[1]) # array of 15 datapoints 
    acc_z = normalize(inputs[2]) # array of 15 datapoints 
    gyro_x = normalize(inputs[3]) # array of 15 datapoints 
    gyro_y = normalize(inputs[4]) # array of 15 datapoints 
    gyro_z = normalize(inputs[5]) # array of 15 datapoints 
    stats1 = [get_range, get_mean, get_std, get_mad, get_kurtosis, get_mean_f, get_std_f, get_kurtosis_f, get_skew_f]
    for func in stats1:
        features.append([func(acc_x), func(acc_y), func(acc_z), func(gyro_x), func(gyro_y), func(gyro_z)])
    features = np.asarray(features, dtype=np.single)
    features = features.flatten()
    input_buffer = allocate(shape = (54,), dtype=np.int32)
    for i in range(54):
        input_buffer[i] = unpack('i', pack('f', features[i]))[0]
    output_buffer = allocate(shape = (4,), dtype=np.int32)
    dma.sendchannel.transfer(input_buffer)
    dma.recvchannel.transfer(output_buffer)
    dma.sendchannel.wait()
    dma.recvchannel.wait()
    for i in range(4):
        output.append(unpack('f', pack('i',output_buffer[i]))[0])
    output = softmax(output)
    output = output.tolist().index(max(output))
    return output


# returns category group 0/1/etc input: 6 x 25
def predicts2(inputs, dma):
    output = []
    features = [] # 9 x 6
    inputs = np.asarray(inputs, dtype=np.single)
    #inputs = inputs.transpose()
    acc_x = normalize(inputs[0]) # array of 15 datapoints 
    acc_y = normalize(inputs[1]) # array of 15 datapoints 
    acc_z = normalize(inputs[2]) # array of 15 datapoints 
    gyro_x = normalize(inputs[3]) # array of 15 datapoints 
    gyro_y = normalize(inputs[4]) # array of 15 datapoints 
    gyro_z = normalize(inputs[5]) # array of 15 datapoints 
    stats2 = [get_min, get_max, get_mean, get_std, get_mad, get_kurtosis, get_skew, get_max_f, get_mean_f, get_std_f, get_kurtosis_f, get_skew_f]
    for func in stats2:
        features.append([func(acc_x), func(acc_y), func(acc_z), func(gyro_x), func(gyro_y), func(gyro_z)])
    features = np.asarray(features, dtype=np.single)
    features = features.flatten()
    input_buffer = allocate(shape = (72,), dtype=np.int32)
    for i in range(72):
        input_buffer[i] = unpack('i', pack('f', features[i]))[0]
    output_buffer = allocate(shape = (4,), dtype=np.int32)
    dma.sendchannel.transfer(input_buffer)
    dma.recvchannel.transfer(output_buffer)
    dma.sendchannel.wait()
    dma.recvchannel.wait()
    for i in range(4):
        output.append(unpack('f', pack('i',output_buffer[i]))[0])
    output = softmax(output)
    output = output.tolist().index(max(output))
    return output

def test_predict(inputs, model): # predict function for software ai
    features = [] # 9 x 6
    inputs = np.asarray(inputs, dtype=np.single)
    inputs = inputs.transpose()
    acc_x = normalize(inputs[0]) # array of 15 datapoints 
    acc_y = normalize(inputs[1]) # array of 15 datapoints 
    acc_z = normalize(inputs[2]) # array of 15 datapoints 
    gyro_x = normalize(inputs[3]) # array of 15 datapoints 
    gyro_y = normalize(inputs[4]) # array of 15 datapoints 
    gyro_z = normalize(inputs[5]) # array of 15 datapoints 
    stats1 = [get_range, get_mean, get_std, get_mad, get_kurtosis, get_mean_f, get_std_f, get_kurtosis_f, get_skew_f]
    for func in stats1:
        features.append([func(acc_x), func(acc_y), func(acc_z), func(gyro_x), func(gyro_y), func(gyro_z)])
    features = np.asarray(features, dtype=np.single)
    q = model.predict(features[None])
    q = q[0].tolist()
    maxi = max(q)
    max_index = q.index(maxi)
    return max_index
