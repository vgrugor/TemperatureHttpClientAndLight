#ifndef WEBSOCKET_H
    #define WEBSOCKET_H

    #include <Arduino.h>
    #include <ESPAsyncWebServer.h>

    class WebSocket {
    private:
        AsyncWebSocket webSocket;
        void handleEvent(AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len);
        void handleMessage(void* arg, uint8_t* data, size_t len);

    public:
        WebSocket();
        AsyncWebSocket* getWebSocketObject();
        void notifyClients();
        void cleanupClients();
    };

#endif // WEBSOCKET_H
