#ifndef _WIFI_CONNECTOR_H_
#define _WIFI_CONNECTOR_H_

#include <ESP8266WiFi.h>

class WIFIConnector {
  private:
    const char* ssid = "";
    const char* password = "";  
    const byte RECONNECT_RETRIES = 250;
    
    bool is_connected;

  public:
    WIFIConnector() {}
  
    void Connect();
    bool IsConnected();
};

#endif // _WIFI_CONNECTOR_H_
