#include "application/LightManagerService.h"

LightManagerService::LightManagerService(Regulator& frontRegulator, Regulator& middleRegulator, Regulator& backRegulator) 
    : frontRegulator(frontRegulator), 
    middleRegulator(middleRegulator),
    backRegulator(backRegulator)
{}

void LightManagerService::setLevelForAll(int level) {
    this->frontRegulator.setLevel(level);
    this->middleRegulator.setLevel(level);
    this->backRegulator.setLevel(level);
}

void LightManagerService::setLevel(String regulator, int level) {

}
