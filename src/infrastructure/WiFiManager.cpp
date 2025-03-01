#include "infrastructure/WiFiManager.h"
#include <Arduino.h>

WiFiManager::WiFiManager(
    const char* ssid, 
    const char* password, 
    const char* ip, 
    const char* gateway, 
    const char* subnet
) : 
    ssid(ssid), 
    password(password), 
    ip(ip), 
    gateway(gateway), 
    subnet(subnet) 
{
}

void WiFiManager::connect() {
    IPAddress ip;
    IPAddress gateway;
    IPAddress subnet;

    ip.fromString(this->ip);
    gateway.fromString(this->gateway);
    subnet.fromString(this->subnet);

    WiFi.mode(WIFI_STA);

    WiFi.config(ip, gateway, subnet);

    WiFi.begin(ssid, password);

    Serial.print("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected to Wi-Fi");
    Serial.println(WiFi.localIP());
}

void WiFiManager::reconnect() {
    if (!isConnected()) {
        Serial.println("Reconnecting to Wi-Fi...");
        connect();
    }
}

bool WiFiManager::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

String WiFiManager::getIPAddress() {
    return WiFi.localIP().toString();
}
