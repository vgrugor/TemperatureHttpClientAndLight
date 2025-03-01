#include <Arduino.h>
//#include "domain/Sensor.h"
//#include "domain/Actuator.h"
#include "infrastructure/DS18B20Sensor.h"
//#include "infrastructure/RelayActuator.h"
//#include "infrastructure/FileSystem.h"
//#include "infrastructure/WebClient.h"
//#include "application/SensorService.h"
//#include "application/Scheduler.h"
//#include "presentation/SerialMonitor.h"
//#include "presentation/WebServer.h"
#include "infrastructure/env.h"
#include "infrastructure/WiFiManager.h"

DS18B20Sensor temperatureSensor(TEMPERATURE_SENSOR_PIN, TEMPERATURE_UPDATE_INTERVAL);
//RelayActuator relayActuator(D5);    // Реле на пине D5
//SensorService sensorService(dhtSensor, relayActuator);
//SerialMonitor serialMonitor(dhtSensor);
//WebServer webServer(sensorService);

// Настройки Wi-Fi
WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET);

// Файловая система
//FileSystem fileSystem;

// Веб-клиент
//WebClient webClient;

// Планировщик задач
//Scheduler scheduler(10);  // Максимум 10 задач

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

    // Добавление задач в планировщик
    //scheduler.addTask(5000, []() {  // Каждые 5 секунд
    //    float temperature = dhtSensor.readValue();
    //    Serial.println("Current temperature: " + String(temperature));
    //});

    //scheduler.addTask(10000, []() {  // Каждые 10 секунд
    //    String jsonData = "{\"temperature\": " + String(dhtSensor.readValue()) + "}";
    //    String response = webClient.post("http://example.com/api/data", jsonData);
    //    Serial.println("Server response: " + response);
    //});

    //scheduler.addTask(30000, []() {  // Однократно через 30 секунд
    //    Serial.println("This task runs only once after 30 seconds");
    //}, false);

    // Запуск веб-сервера
    //webServer.begin();
}

void loop() {
    temperatureSensor.update();
    //sensorService.checkAndControl();
    //serialMonitor.displayData();
    //webServer.handleClient();  // Обработка HTTP-запросов

    // Выполнение задач из планировщика
    //scheduler.run();

    //delay(100);  // Небольшая задержка для стабильности
}
