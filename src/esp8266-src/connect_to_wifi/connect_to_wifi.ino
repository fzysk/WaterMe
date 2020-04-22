#include <ESP8266WiFi.h>

const char* ssid = "ssid";
const char* password = "password";

void setup() {
  Serial.begin(115200);

  int retries = 0;
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("START");
  while (WiFi.status() != WL_CONNECTED && retries++ < 50) 
  {
     delay(500);
     Serial.print("*");
  }

  Serial.println("");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WIFI connection is successful!");
    Serial.print("The IP address is:");
    Serial.print(WiFi.localIP());// Print the IP address
  }
  else {
    Serial.println("ERROR: Could not connect to Internet");
  }

  String clientMac = WiFi.macAddress();
  Serial.println("MAC Address: " + clientMac);
}

void loop() {

}
