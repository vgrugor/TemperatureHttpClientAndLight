// application/SensorService.h
#include "infrastructure/WebClient.h"
#include "application/Scheduler.h"

class SensorService {
private:
    Sensor& sensor;
    Actuator& actuator;
    WebClient& webClient;
    Scheduler& scheduler;

public:
    SensorService(Sensor& sensor, Actuator& actuator, WebClient& webClient, Scheduler& scheduler)
        : sensor(sensor), actuator(actuator), webClient(webClient), scheduler(scheduler) {
        // Добавляем задачу для отправки данных каждые 10 секунд
        scheduler.addTask(10000, [this]() {
            String jsonData = "{\"temperature\": " + String(sensor.readValue()) + "}";
            String response = webClient.post("http://example.com/api/data", jsonData);
            Serial.println("Server response: " + response);
        });
    }

    void checkAndControl() {
        float value = sensor.readValue();
        if (value > 25.0) {
            actuator.setState(true);
        } else {
            actuator.setState(false);
        }
    }

    float getCurrentTemperature() {
        return sensor.readValue();
    }

    void setRelayState(bool state) {
        actuator.setState(state);
    }
};
