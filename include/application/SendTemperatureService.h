#include "infrastructure/WebClient.h"
#include "domain/Sensor.h"

class SendTemperatureService {
    private:
        Sensor& temperatureSensor;
        WebClient& webClient;

    public:
        SendTemperatureService(Sensor& sensor, WebClient& webClient);
        void send();
};
