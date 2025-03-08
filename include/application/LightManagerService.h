#ifndef LIGHT_MANAGER_SERVICE_H
    #define LIGHT_MANAGER_SERVICE_H

    #include "domain/Regulator.h"
    #include "application/scheduler/Scheduler.h"
    #include "application/SettingsStorage.h"
    #include "presentation/EventNotifier.h"
    #include "presentation/EventType.h"
    #include "application/scheduler/TaskIds.h"

    class LightManagerService {
        private:
            Regulator& frontRegulator;
            Regulator& middleRegulator;
            Regulator& backRegulator;
            Scheduler& scheduler;
            int mapLevel(int level);

        public:
            LightManagerService(Regulator& frontRegulator, Regulator& middleRegulator, Regulator& backRegulator, Scheduler& scheduler);
            void changeAllLedMatrixLevel(int level);
            void changeTimerMinute(int level);
            void changeFrontLedMatrixLevel(int level);
            void changeMiddleLedMatrixLevel(int level);
            void changeBackLedMatrixLevel(int level);
    };

#endif // LIGHT_MANAGER_SERVICE_H
