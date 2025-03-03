#include <Arduino.h>
#include "infrastructure/DS18B20Sensor.h"
#include "infrastructure/env.h"
#include "infrastructure/WiFiManager.h"
#include "infrastructure/WebClient.h"
#include "application/Scheduler.h"
#include "application/SendTemperatureService.h"
#include "infrastructure/ExternalLedActuator.h"
#include "infrastructure/BuzzerActuator.h"
#include "presentation/observers/LedObserver.h"
#include "presentation/observers/BuzzerObserver.h"
#include "presentation/observers/SerialObserver.h"
#include "presentation/EventNotifier.h"
#include "infrastructure/regulators/FrontRegulator.h"
#include "infrastructure/regulators/MiddleRegulator.h"
#include "infrastructure/regulators/BackRegulator.h"
#include "application/LightManagerService.h"
#include "infrastructure/FileSystem.h"
#include "infrastructure/WebSocket.h"
#include "infrastructure/WebServer.h"

ExternalLedActuator externalLedActuator(GREEN_LED_PIN);
BuzzerActuator buzzerActuator(BUZZER_PIN);

LedObserver ledObserver(externalLedActuator);
BuzzerObserver buzzerObserver(buzzerActuator);
SerialObserver serialObserver;

EventNotifier& eventNotifier = EventNotifier::getInstance();

FrontRegulator frontRegulator(FRONT_LED_MATRIX);
FrontRegulator middleRegulator(MIDDLE_LED_MATRIX);
FrontRegulator backRegulator(BACK_LED_MATRIX);

LightManagerService lightManagerService(frontRegulator, middleRegulator, backRegulator);

DS18B20Sensor temperatureSensor(TEMPERATURE_SENSOR_PIN, TEMPERATURE_READ_PERIOD);
WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET);
WebClient webClient;
SendTemperatureService sendTemperatureService(temperatureSensor, webClient);
Scheduler scheduler(SCHEDULER_MAX_TASKS_COUNT);

FileSystem fileSystem;
WebSocket webSocket;
WebServer webServer(webSocket, fileSystem);

void setup() {
    Serial.begin(115200);

    eventNotifier.addObserver(&ledObserver);
    eventNotifier.addObserver(&buzzerObserver);
    eventNotifier.addObserver(&serialObserver);

    wifiManager.connect();

    scheduler.addTask(TEMPERATURE_FIRST_READ_AFTER_LOAD_INTERVAL, []() {
        sendTemperatureService.send();
    }, false);

    scheduler.addTask(TEMPERATURE_SEND_PERIOD, []() {
        sendTemperatureService.send();
    });

    webServer.begin();
}

void loop() {
    wifiManager.reconnect();

    temperatureSensor.update();
    frontRegulator.update();
    middleRegulator.update();
    backRegulator.update();

    scheduler.run();

    webServer.handleClient();
}
