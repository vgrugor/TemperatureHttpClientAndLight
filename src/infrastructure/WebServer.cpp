#include "infrastructure/WebServer.h"

WebServer::WebServer(WebSocket& webSocket, FileSystem& fileSystem) 
    : server(80), 
    webSocket(webSocket), 
    fileSystem(fileSystem) 
{}

void WebServer::begin() {
    // Добавление WebSocket handler
    server.addHandler(webSocket.getWebSocketObject());

    // Инициализация маршрутов
    server.on("/", HTTP_GET, [this](AsyncWebServerRequest* request) {
        handleRoot(request);
    });

    server.serveStatic("/", LittleFS, "/");

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

void WebServer::handleClient() {
    // Можно добавить метод для обработки клиентов, если нужно
}
