#include "application/SendTemperatureService.h"

SendTemperatureService::SendTemperatureService(Sensor& sensor, WebClient& webClient) 
: temperatureSensor(sensor), 
    webClient(webClient) 
{}

void SendTemperatureService::send() {
    float temperature = this->temperatureSensor.getLastValue();
    String temperatureStr = String(temperature, 2);

    String serverPath = TEMPERATURE_SERVER_URL 
        + "?" 
        + TEMPERATURE_SERVER_PARAM_NAME 
        + "=" 
        + temperatureStr;

    EventNotifier::getInstance().notifyObservers(EventType::SEND_TEMPERATURE, temperatureStr);

    webClient.get(serverPath.c_str());
}
