#include "presentation/WebServer.h"

WebServer::WebServer(
    WebSocket& webSocket, 
    FileSystem& fileSystem   
) : server(80), 
    webSocket(webSocket), 
    fileSystem(fileSystem) 
{}

void WebServer::begin() {
    server.addHandler(webSocket.getWebSocketObject());

    server.serveStatic("/", LittleFS, "/");

    server.on("/", HTTP_GET, [this](AsyncWebServerRequest* request) {
        this->handleRoot(request);
    });

    server.begin();
}

void WebServer::handleRoot(AsyncWebServerRequest* request) {
    request->send(LittleFS, "/index.html", "text/html");
}

void WebServer::handleClient() {}
