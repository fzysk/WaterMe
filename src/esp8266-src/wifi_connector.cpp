#include "wifi_connector.h"

void WIFIConnector::Connect() {
  byte retries = 0;
  
  WiFi.begin(ssid, password);

  IPAddress ip(192,168,0,103);
  IPAddress gateway(192,168,0,1);
  IPAddress subnet(255,255,255,0);
  WiFi.config(ip, gateway, subnet);
  
  Serial.println("");
  Serial.println("START");

  while (WiFi.status() != WL_CONNECTED && retries++ < RECONNECT_RETRIES) 
  {
     delay(500);
     Serial.print("*");
  }

  Serial.println("");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WIFI connection is successful!");
    Serial.print("The IP address is:");
    Serial.print(WiFi.localIP());

    is_connected = true;
  }
  else {
    Serial.println("ERROR: Could not connect to Internet");
    is_connected = false;
  }
}

bool WIFIConnector::IsConnected() {
  return is_connected;
}
