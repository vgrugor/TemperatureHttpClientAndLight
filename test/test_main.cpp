#include <AUnit.h>
#include "domain/Sensor.h"

class MockSensor : public Sensor {
public:
    float value = 0.0;

    float readValue() override {
        return value;
    }

    void update() override {
        // Ничего не делаем
    }
};

test(SensorTest, ReadValue) {
    MockSensor sensor;
    sensor.value = 25.5;

    assertEqual(sensor.readValue(), 25.5);
}

#include <AUnit.h>
#include "domain/Actuator.h"

class MockActuator : public Actuator {
public:
    bool state = false;

    void setState(bool newState) override {
        state = newState;
    }

    void update() override {
        // Ничего не делаем
    }
};

test(ActuatorTest, SetState) {
    MockActuator actuator;
    actuator.setState(true);

    assertTrue(actuator.state);

    actuator.setState(false);
    assertFalse(actuator.state);
}

#include <AUnit.h>
#include "application/SensorService.h"
#include "domain/Sensor.h"
#include "domain/Actuator.h"

class MockSensor : public Sensor {
public:
    float value = 0.0;

    float readValue() override {
        return value;
    }

    void update() override {
        // Ничего не делаем
    }
};

class MockActuator : public Actuator {
public:
    bool state = false;

    void setState(bool newState) override {
        state = newState;
    }

    void update() override {
        // Ничего не делаем
    }
};

test(SensorServiceTest, CheckAndControl) {
    MockSensor sensor;
    MockActuator actuator;
    SensorService service(sensor, actuator);

    // Температура ниже порога
    sensor.value = 20.0;
    service.checkAndControl();
    assertFalse(actuator.state);

    // Температура выше порога
    sensor.value = 30.0;
    service.checkAndControl();
    assertTrue(actuator.state);
}

#include <AUnit.h>
#include "infrastructure/DHT11Sensor.h"

class MockDHT {
public:
    float temperature = 0.0;

    float readTemperature() {
        return temperature;
    }
};

test(DHT11SensorTest, ReadValue) {
    MockDHT mockDHT;
    mockDHT.temperature = 22.5;

    DHT11Sensor sensor(D4);
    sensor.setDHT(&mockDHT);  // Предположим, что у нас есть метод для внедрения mock-объекта

    assertEqual(sensor.readValue(), 22.5);
}

#include <AUnit.h>
#include "infrastructure/RelayActuator.h"

test(RelayActuatorTest, SetState) {
    RelayActuator actuator(D5);

    actuator.setState(true);
    // Здесь можно добавить проверку состояния пина (например, с помощью digitalRead)

    actuator.setState(false);
    // Проверка, что пин выключен
}

#include <AUnit.h>
#include "presentation/WebServer.h"
#include "application/SensorService.h"
#include "domain/Sensor.h"
#include "domain/Actuator.h"

class MockSensor : public Sensor {
public:
    float value = 0.0;

    float readValue() override {
        return value;
    }

    void update() override {
        // Ничего не делаем
    }
};

class MockActuator : public Actuator {
public:
    bool state = false;

    void setState(bool newState) override {
        state = newState;
    }

    void update() override {
        // Ничего не делам
    }
};

test(WebServerTest, HandleRoot) {
    MockSensor sensor;
    MockActuator actuator;
    SensorService service(sensor, actuator);
    WebServer webServer(service);

    // Здесь можно использовать mock-запросы для проверки ответов сервера
    // Например, проверить, что handleRoot возвращает корректный HTML
}

#include <AUnit.h>
#include "infrastructure/WiFiManager.h"

class MockWiFi {
public:
    static wl_status_t status;

    static wl_status_t begin(const char* ssid, const char* password) {
        // Симуляция подключения
        status = WL_CONNECTED;
        return status;
    }

    static wl_status_t getStatus() {
        return status;
    }

    static IPAddress localIP() {
        return IPAddress(192, 168, 1, 100);
    }
};

wl_status_t MockWiFi::status = WL_IDLE_STATUS;

test(WiFiManagerTest, Connect) {
    WiFiManager wifiManager("test_ssid", "test_password");

    // Подключение к Wi-Fi
    wifiManager.connect();

    // Проверка состояния подключения
    assertTrue(wifiManager.isConnected());
    assertEqual(wifiManager.getIPAddress(), "192.168.1.100");
}

#include <AUnit.h>
#include "infrastructure/FileSystem.h"

test(FileSystemTest, WriteAndReadFile) {
    FileSystem fs;

    // Запись файла
    assertTrue(fs.writeFile("/test.txt", "Hello, LittleFS!"));

    // Чтение файла
    String data = fs.readFile("/test.txt");
    assertEqual(data, "Hello, LittleFS!");

    // Удаление файла
    assertTrue(fs.deleteFile("/test.txt"));
    assertFalse(fs.fileExists("/test.txt"));
}

#include <AUnit.h>
#include "infrastructure/WebClient.h"

class MockHTTPClient {
public:
    static int httpCode;
    static String payload;

    static void begin(WiFiClient& client, const String& url) {
        // Ничего не делаем
    }

    static int GET() {
        return httpCode;
    }

    static String getString() {
        return payload;
    }

    static void end() {
        // Ничего не делаем
    }
};

int MockHTTPClient::httpCode = HTTP_CODE_OK;
String MockHTTPClient::payload = "Mock response";

test(WebClientTest, GetRequest) {
    WebClient webClient;
    MockHTTPClient::httpCode = HTTP_CODE_OK;
    MockHTTPClient::payload = "Hello, World!";

    String response = webClient.get("http://example.com/api/data");
    assertEqual(response, "Hello, World!");
}

#include <AUnit.h>
#include "application/Scheduler.h"

test(SchedulerTest, PeriodicTask) {
    Scheduler scheduler(10);
    int counter = 0;

    scheduler.addTask(1000, [&counter]() {
        counter++;
    });

    // Симуляция времени
    unsigned long currentTime = 0;
    for (int i = 0; i < 5; i++) {
        currentTime += 1000;
        scheduler.run();
    }

    assertEqual(counter, 5);
}

test(SchedulerTest, OneTimeTask) {
    Scheduler scheduler(10);
    int counter = 0;

    scheduler.addTask(1000, [&counter]() {
        counter++;
    }, false);

    // Симуляция времени
    unsigned long currentTime = 0;
    for (int i = 0; i < 5; i++) {
        currentTime += 1000;
        scheduler.run();
    }

    assertEqual(counter, 1);
}
