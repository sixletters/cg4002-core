def serialize(data):
    serialzedData = b''
    serialzedData += data["playerID"].to_bytes(2, 'little') 
    serialzedData += data["beetleID"].to_bytes(2, 'little')
    if data["beetleID"] == 0:
        a1 = struct.pack('<f', data["payload"]["a1"])
        a2 = struct.pack('<f', data["payload"]["a2"])
        a3 = struct.pack('<f', data["payload"]["a3"])
        g1 = struct.pack('<f', data["payload"]["g1"])
        g2 = struct.pack('<f', data["payload"]["g2"])
        g3 = struct.pack('<f', data["payload"]["g3"]) 
        serialzedData += a1 + a2 + a3 + g1 + g2 + g3
    return serialzedData
    

def init(dataBuffer):
    data = {
        "playerID" : 1,
        "beetleID": 0,
        "payload" : {
            "a1" : 1.0,
            "a2" : 1.0,
            "a3" : 1.0,
            "g1" : 1.0,
            "g2" : 1.0,
            "g3" : 1.0
        }
    }

    data2 = {
        "playerID" : 1,
        "beetleID": 1
    }

    data3 = {
       "playerID" : 2,
        "beetleID": 0,
        "payload" : {
            "a1" : 1.0,
            "a2" : 1.0,
            "a3" : 1.0,
            "g1" : 1.0,
            "g2" : 1.0,
            "g3" : 1.0
        }
    }


    dataBuffer.put(serialize(data))
    dataBuffer.put(serialize(data2))
    dataBuffer.put(serialize(data3))


def init2(dataBuffer):
    # dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 1})
    # dataBuffer.put({'playerID':1,'beetleID': 1})
    dataBuffer.put({'playerID':2,'beetleID': 1})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    # dataBuffer.put({'playerID':2,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.3, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.1 , 'a3': 1.4, "g1": 1.5, "g2":1.6, "g3": 1.8}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.1, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.3, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.2, 'a2': 2.1 , 'a3': 1.4, "g1": 1.5, "g2":1.6, "g3": 1.8}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})
    dataBuffer.put({'playerID':1,'beetleID': 0, "payload":{'a1': 1.0, 'a2': 2.0 , 'a3': 1.0, "g1": 1.0, "g2":1.0, "g3": 1.0}})