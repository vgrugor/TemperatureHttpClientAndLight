#include "application/SendTemperatureService.h"

SendTemperatureService::SendTemperatureService(Sensor& sensor, WebClient& webClient) 
: temperatureSensor(sensor), 
    webClient(webClient) 
{}

void SendTemperatureService::send() {
    float temperature = this->temperatureSensor.getLastValue();

    char buffer[20];
    sprintf(buffer, "%.2f", temperature);

    String serverPath = "http://192.168.1.200:80/outdoor/temperature?temp=" + String(buffer);

    String temperatureStr = String(temperature, 2);
    EventNotifier::getInstance().notifyObservers(EventType::SEND_TEMPERATURE, temperatureStr);

    webClient.get(serverPath.c_str());
}
