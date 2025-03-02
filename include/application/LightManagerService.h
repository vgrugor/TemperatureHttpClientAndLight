#include "domain/Regulator.h"

class LightManagerService {
    private:
        Regulator& frontRegulator;
        Regulator& middleRegulator;
        Regulator& backRegulator;

    public:
        LightManagerService(Regulator& frontRegulator, Regulator& middleRegulator, Regulator& backRegulator);
        void setLevelForAll(int level);
        void setLevel(String regulator, int level);
};
