#ifndef TASK_IDS_H
    #define TASK_IDS_H

    #include <Arduino.h>

    namespace TaskIds {
        const String LIGHT_DISABLE_TASK = "lightDisableTask";
        const String TEMPERATURE_FIRST_READ_AFTER_LOAD = "temperatureFirstReadAfterLoad";
        const String TEMPERATURE_SEND = "temperatureSend";
    }

#endif
