#include "application/WsMessageHandler.h"

WsMessageHandler::WsMessageHandler(LightManagerService& lightManagerService) 
    : lightManagerService(lightManagerService) 
{}

bool WsMessageHandler::handle(String message) {
    Serial.println("Resolved ws message:");
    
    bool result = false;

    String messageValue = message.substring(2);
    int level = messageValue.toInt();

    if (message.indexOf("1s") >= 0) {
        this->lightManagerService.changeAllLedMatrixLevel(level);
        Serial.println(" - change all led matrix level");
        result = true;
    }

    if (message.indexOf("2s") >= 0) {
        this->lightManagerService.changeTimerMinute(level);
        Serial.println(" - change timer minute");
        result = true;
    }

    if (message.indexOf("3s") >= 0) {
        this->lightManagerService.changeFrontLedMatrixLevel(level);
        Serial.println(" - change left led matrix level");
        result = true;
    }

    if (message.indexOf("4s") >= 0) {
        this->lightManagerService.changeMiddleLedMatrixLevel(level);
        Serial.println(" - change center led matrix level");
        result = true;
    }

    if (message.indexOf("5s") >= 0) {
        this->lightManagerService.changeBackLedMatrixLevel(level);
        Serial.println(" - change right led matrix level");
        result = true;
    }

    if (message.indexOf("getValues") >= 0) {
        Serial.println(" - get values");
        result = true;
    }

    return result;
}
