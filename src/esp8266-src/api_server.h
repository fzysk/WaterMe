#ifndef _API_SERVER_H_
#define _API_SERVER_H_

#include <ESP8266WebServer.h>
#include "valve_manager.h"

class APIServer {
  private:
    ESP8266WebServer server;
    ValveManager manager;

    // test and error pages
    void testPage(void);
    void notFound(void);
    void badRequest(String);

    // handlers for switching valves state
    void turnValveOn(void);
    void turnValveOff(void);

    // handler for showing current valve state
    void showCurrentState(void);
  
  public:
    APIServer(): server(80) {}

    void Start();
    void Loop();
};

#endif // _API_SERVER_H_
