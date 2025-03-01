#include "application/SendTemperatureService.h"

SendTemperatureService::SendTemperatureService(Sensor& sensor, WebClient& webClient) 
: temperatureSensor(sensor), 
    webClient(webClient) 
{}

void SendTemperatureService::send() {
    float temperature = temperatureSensor.getLastValue();

    char buffer[20];
    sprintf(buffer, "%.2f", temperature);

    String serverPath = "http://192.168.1.200:80/outdoor/temperature?temp=" + String(buffer);

    webClient.get(serverPath.c_str());
}
