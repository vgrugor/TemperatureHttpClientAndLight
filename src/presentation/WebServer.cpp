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

    server.on("/", HTTP_GET, [this](AsyncWebServerRequest* request) {
        handleRoot(request);
    });

    server.serveStatic("/", LittleFS, "/");
    server.begin();
}

void WebServer::handleRoot(AsyncWebServerRequest* request) {
    String html = fileSystem.readFile("/index.html");

    if (html.length() > 0) {
        request->send(200, "text/html", html);
    } else {
        request->send(404, "text/plain", "File not found");
    }
}

void WebServer::handleClient() {}
