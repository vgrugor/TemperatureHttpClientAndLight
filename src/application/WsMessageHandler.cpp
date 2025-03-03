#include "application/WsMessageHandler.h"

WsMessageHandler::WsMessageHandler(LightManagerService& lightManagerService) 
    : lightManagerService(lightManagerService) 
{}

bool WsMessageHandler::handle(String message) {
    Serial.println("Resolved ws message:");
    
    bool result = false;

    String messageValue = message.substring(2);
    int value = messageValue.toInt();

    if (message.indexOf("1s") >= 0) {
        this->lightManagerService.changeAllLedMatrixLevel(value);
        Serial.println(" - change all led matrix level");
        result = true;
    }

    if (message.indexOf("2s") >= 0) {
        this->lightManagerService.changeTimerMinute(value);
        Serial.println(" - change timer minute");
        result = true;
    }

    if (message.indexOf("3s") >= 0) {
        this->lightManagerService.changeFrontLedMatrixLevel(value);
        Serial.println(" - change left led matrix level");
        result = true;
    }

    if (message.indexOf("4s") >= 0) {
        this->lightManagerService.changeMiddleLedMatrixLevel(value);
        Serial.println(" - change center led matrix level");
        result = true;
    }

    if (message.indexOf("5s") >= 0) {
        this->lightManagerService.changeBackLedMatrixLevel(value);
        Serial.println(" - change right led matrix level");
        result = true;
    }

    if (message.indexOf("getValues") >= 0) {
        Serial.println(" - get values");
        result = true;
    }

    return result;
}
