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


  Serial.println("");
  Serial.println(D0);
  Serial.println(D1);
  Serial.println(D2);
  Serial.println(D3);
  Serial.println(D4);
  Serial.println(D5);
  Serial.println(D6);
  Serial.println(D7);
  Serial.println(D8);
  
}

void loop() {
  //delay(120);
  //digitalWrite(D4, HIGH);
  //digitalWrite(D4, HIGH);
  //delay(500);
  //digitalWrite(D4, LOW);
  //delay(500);
  
  server.Loop();
}


// d4
