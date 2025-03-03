#include <Arduino.h>
#include "infrastructure/sensors/DS18B20Sensor.h"
#include "infrastructure/env.h"
#include "infrastructure/wifi/WiFiManager.h"
#include "infrastructure/web/WebClient.h"
#include "application/Scheduler.h"
#include "application/SendTemperatureService.h"
#include "infrastructure/actuators/ExternalLedActuator.h"
#include "infrastructure/actuators/BuzzerActuator.h"
#include "presentation/observers/LedObserver.h"
#include "presentation/observers/BuzzerObserver.h"
#include "presentation/observers/SerialObserver.h"
#include "presentation/EventNotifier.h"
#include "infrastructure/regulators/FrontRegulator.h"
#include "infrastructure/regulators/MiddleRegulator.h"
#include "infrastructure/regulators/BackRegulator.h"
#include "application/LightManagerService.h"
#include "infrastructure/fs/FileSystem.h"
#include "infrastructure/web/WebSocket.h"
#include "infrastructure/web/WebServer.h"
#include "application/WsMessageHandler.h"
#include "application/WsDataTransformer.h"

ExternalLedActuator externalLedActuator(GREEN_LED_PIN);
BuzzerActuator buzzerActuator(BUZZER_PIN);

LedObserver ledObserver(externalLedActuator);
BuzzerObserver buzzerObserver(buzzerActuator);
SerialObserver serialObserver;

EventNotifier& eventNotifier = EventNotifier::getInstance();

DS18B20Sensor temperatureSensor(TEMPERATURE_SENSOR_PIN, TEMPERATURE_READ_PERIOD);
WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD, WIFI_IP, WIFI_GATEWAY, WIFI_SUBNET);
WebClient webClient;
SendTemperatureService sendTemperatureService(temperatureSensor, webClient);
Scheduler scheduler(SCHEDULER_MAX_TASKS_COUNT);

FileSystem fileSystem;

FrontRegulator frontRegulator(FRONT_LED_MATRIX);
MiddleRegulator middleRegulator(MIDDLE_LED_MATRIX);
BackRegulator backRegulator(BACK_LED_MATRIX);

WsDataTransformer wsDataTransformer(frontRegulator, middleRegulator, backRegulator, temperatureSensor);

LightManagerService lightManagerService(frontRegulator, middleRegulator, backRegulator, scheduler);
WsMessageHandler wsMessageHandler(lightManagerService);
WebSocket webSocket(wsMessageHandler, wsDataTransformer);
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
