// env.h
#ifndef ENV_H
    #define ENV_H

    #include "Arduino.h"

    extern const char* WIFI_SSID;
    extern const char* WIFI_PASSWORD;
    extern const char* WIFI_IP;
    extern const char* WIFI_GATEWAY;
    extern const char* WIFI_SUBNET;

    extern const int GREEN_LED_PIN;
    extern const int BUZZER_PIN;

    extern const int FRONT_LED_MATRIX;
    extern const int MIDDLE_LED_MATRIX;
    extern const int BACK_LED_MATRIX;

    extern const int BOARD_LED;

    extern const unsigned char TEMPERATURE_SENSOR_PIN;
    extern const unsigned long TEMPERATURE_READ_PERIOD;
    extern const unsigned long TEMPERATURE_FIRST_READ_AFTER_LOAD_INTERVAL;
    extern const unsigned long TEMPERATURE_SEND_PERIOD;
    extern const String TEMPERATURE_SERVER_IP;
    extern const String TEMPERATURE_SERVER_PORT;
    extern const String TEMPERATURE_SERVER_URI;
    extern const String TEMPERATURE_SERVER_PARAM_NAME;
    extern const String TEMPERATURE_SERVER_URL;

    extern const int SCHEDULER_MAX_TASKS_COUNT;

#endif // ENV_H
