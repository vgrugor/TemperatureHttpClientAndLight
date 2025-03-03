#include "infrastructure/WebServer.h"

WebServer::WebServer(WebSocket& webSocket, FileSystem& fileSystem) 
    : server(80), webSocket(webSocket), fileSystem(fileSystem) {}

void WebServer::begin() {
    // Добавление WebSocket handler
    server.addHandler(webSocket.getWebSocketObject());

    // Инициализация маршрутов
    server.on("/", HTTP_GET, [this](AsyncWebServerRequest* request) {
        handleRoot(request);
    });

    server.on("/outdoor/temperature", HTTP_GET, [this](AsyncWebServerRequest* request) {
        handleOutdoorTemperature(request);
    });

    server.serveStatic("/", LittleFS, "/");

    // Старт сервера
    Serial.println("Starting web server...");
    server.begin();
    Serial.println("Web server started");
}

void WebServer::handleRoot(AsyncWebServerRequest* request) {
    String html = fileSystem.readFile("/index.html");
    if (html.length() > 0) {
        request->send(200, "text/html", html);
    } else {
        request->send(404, "text/plain", "File not found");
    }
}

void WebServer::handleOutdoorTemperature(AsyncWebServerRequest* request) {
    Serial.println("Start handle /outdoor/temperature request");
    if (request->hasParam("temp")) {
        String outdoorTemperature = request->getParam("temp")->value();
        Serial.println("Outdoor temperature: " + outdoorTemperature);

        //wsData.setOutdoorTemperature(atof(outdoorTemperature.c_str()));
        webSocket.notifyClients();

        request->send(200, "text/plain", "Ok");
        Serial.println("Finish handle /outdoor/temperature request. Status 200");
    } else {
        request->send(400, "text/plain", "Error");
        Serial.println("Finish handle /outdoor/temperature request. Status 400");
    }
}

void WebServer::handleClient() {
    // Можно добавить метод для обработки клиентов, если нужно
}
