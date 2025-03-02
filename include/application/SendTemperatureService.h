#include "infrastructure/WebClient.h"
#include "domain/Sensor.h"
#include "presentation/EventType.h"
#include "presentation/EventNotifier.h"
#include "infrastructure/env.h"

class SendTemperatureService {
    private:
        Sensor& temperatureSensor;
        WebClient& webClient;

    public:
        SendTemperatureService(Sensor& sensor, WebClient& webClient);
        void send();
};
