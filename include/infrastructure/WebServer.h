#ifndef WEB_SERVER_FACADE_H
    #define WEB_SERVER_FACADE_H

    #include <Arduino.h>
    #include <ESPAsyncWebServer.h>
    #include "infrastructure/WebSocket.h"
    #include "infrastructure/FileSystem.h"

    class WebServer {
        private:
            AsyncWebServer server;
            WebSocket& webSocket;
            FileSystem& fileSystem;

            void handleRoot(AsyncWebServerRequest* request);
            void handleOutdoorTemperature(AsyncWebServerRequest* request);

        public:
            WebServer(WebSocket& webSocket, FileSystem& fileSystem);
            void begin();
            void handleClient();
    };

#endif // WEB_SERVER_FACADE_H
