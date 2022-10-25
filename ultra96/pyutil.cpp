#include "sensor.pb.h"
#include <vector>
void payloadParser(std::unique_ptr<Sensor> &dataPtr, Action (&playActionBuffer)[2]){
}
class Pyutil{
    public:
        Pyutil (int port): port(port){};
        int predict(Sensor &sensorData){
            std::string data;
            sensorData.SerializeToString(&data);
        };
        std::string formatData(std::string){};
        void sendToEval(){};
    private:
    int port;


};