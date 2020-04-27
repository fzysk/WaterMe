#include "wifi_connector.h"
#include "api_server.h"

APIServer server;
WIFIConnector connector;

void setup() {
  Serial.begin(115200);

  connector.Connect();

  if (connector.IsConnected()) {
    server.Start();
  }
}

void loop() {
  server.Loop();
}
