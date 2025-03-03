#ifndef LIGHT_MANAGER_SERVICE_H
    #define LIGHT_MANAGER_SERVICE_H

    #include "domain/Regulator.h"

    class LightManagerService {
        private:
            Regulator& frontRegulator;
            Regulator& middleRegulator;
            Regulator& backRegulator;

        public:
            LightManagerService(Regulator& frontRegulator, Regulator& middleRegulator, Regulator& backRegulator);
            void changeAllLedMatrixLevel(int level);
            void changeTimerMinute(int level);
            void changeFrontLedMatrixLevel(int level);
            void changeMiddleLedMatrixLevel(int level);
            void changeBackLedMatrixLevel(int level);
    };


#endif // LIGHT_MANAGER_SERVICE_H
