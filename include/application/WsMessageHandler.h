#ifndef WS_MESSAGE_HANDLER_H
    #define WS_MESSAGE_HANDLER_H

    #include <Arduino.h>
    #include "application/LightManagerService.h"

    class WsMessageHandler
    {
        public:
            WsMessageHandler(LightManagerService& lightManagerService);
            bool handle(String message);

        private:
            LightManagerService& lightManagerService;
    };

#endif
