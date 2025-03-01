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

DS18B20Sensor temperatureSensor(TEMPERATURE_SENSOR_PIN, TEMPERATURE_READ_PERIOD);
//RelayActuator relayActuator(D5);    // Реле на пине D5
//SensorService sensorService(dhtSensor, relayActuator);
//SerialMonitor serialMonitor(dhtSensor);
//WebServer webServer(sensorService);

// Настройки Wi-Fi
WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET);

// Файловая система
//FileSystem fileSystem;

// Веб-клиент
WebClient webClient;

// Планировщик задач
Scheduler scheduler(10);  // Максимум 10 задач

void setup() {
    Serial.begin(115200);

    // Подключение к Wi-Fi
    wifiManager.connect();

    // Работа с файловой системой
    //if (fileSystem.writeFile("/config.txt", "Hello, LittleFS!")) {
    //    Serial.println("File written successfully");
    //}

    //String data = fileSystem.readFile("/config.txt");
    //Serial.println("File content: " + data);

    scheduler.addTask(5000, []() {  // Однократно через 5 секунд
        Serial.println("start task 1");
        float temperature = temperatureSensor.getLastValue();
        char buffer[20];
        sprintf(buffer, "%.2f", temperature);
        String serverPath = "http://192.168.1.200:80/outdoor/temperature?temp=" + String(buffer);
        webClient.get(serverPath.c_str());
        Serial.println("Current temperature: " + String(temperature));
    }, false);

    scheduler.addTask(60000, []() {  // Каждые 10 минут
        Serial.println("start task 10");
        float temperature = temperatureSensor.getLastValue();
        char buffer[20];
        sprintf(buffer, "%.2f", temperature);
        String serverPath = "http://192.168.1.200:80/outdoor/temperature?temp=" + String(buffer);
        webClient.get(serverPath.c_str());
        Serial.println("Current temperature: " + String(temperature));
    });

    // Запуск веб-сервера
    //webServer.begin();
}

void loop() {
    temperatureSensor.update();
    //sensorService.checkAndControl();
    //serialMonitor.displayData();
    //webServer.handleClient();  // Обработка HTTP-запросов

    // Выполнение задач из планировщика
    scheduler.run();

    //delay(100);  // Небольшая задержка для стабильности
}
