//#include "domain/Sensor.h"
//#include "domain/Actuator.h"
//#include "infrastructure/RelayActuator.h"
//#include "infrastructure/FileSystem.h"
//#include "application/SensorService.h"
//#include "presentation/SerialMonitor.h"
//#include "presentation/WebServer.h"
#include <Arduino.h>
#include "infrastructure/DS18B20Sensor.h"
#include "infrastructure/env.h"
#include "infrastructure/WiFiManager.h"
#include "infrastructure/WebClient.h"
#include "application/Scheduler.h"
#include "application/SendTemperatureService.h"

//RelayActuator relayActuator(D5);    // Реле на пине D5
//SensorService sensorService(dhtSensor, relayActuator);
//SerialMonitor serialMonitor(dhtSensor);
//WebServer webServer(sensorService);

DS18B20Sensor temperatureSensor(TEMPERATURE_SENSOR_PIN, TEMPERATURE_READ_PERIOD);
WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET);
WebClient webClient;
SendTemperatureService sendTemperatureService(temperatureSensor, webClient);
Scheduler scheduler(SCHEDULER_MAX_TASKS_COUNT);

// Файловая система
//FileSystem fileSystem;

void setup() {
    Serial.begin(115200);

    wifiManager.connect();

    scheduler.addTask(TEMPERATURE_FIRST_READ_AFTER_LOAD_INTERVAL, []() {
        sendTemperatureService.send();
    }, false);

    scheduler.addTask(TEMPERATURE_SEND_PERIOD, []() {
        sendTemperatureService.send();
    });

    // Работа с файловой системой
    //if (fileSystem.writeFile("/config.txt", "Hello, LittleFS!")) {
    //    Serial.println("File written successfully");
    //}

    //String data = fileSystem.readFile("/config.txt");
    //Serial.println("File content: " + data);

    // Запуск веб-сервера
    //webServer.begin();
}

void loop() {
    temperatureSensor.update();
    scheduler.run();

    //sensorService.checkAndControl();
    //serialMonitor.displayData();
    //webServer.handleClient();  // Обработка HTTP-запросов
    //delay(100);  // Небольшая задержка для стабильности
}
