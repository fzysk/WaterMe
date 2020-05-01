#include "api_server.h"
#include "string.h"

// test and error pages
void APIServer::testPage() {
  server.send(200, "text/html", "<h2>Test page!</h2>");
}

void APIServer::notFound() {
  server.send(404, "text/plain", "Sorry, page not found");
};

void APIServer::badRequest(String message) {
  server.send(400, "application/json", "{ \"result\": \"error\", \"message\": \"" + message + "\" }");
}

// handlers for switching valves state
void APIServer::turnValveOn() {
  if (server.hasArg("states")) {
    String states = server.arg("states");
    Serial.println("Received following state: " + states);

    String errorValves = "";
    for (int i = 0; i < states.length(); i++) {
      int valve = (int)(states[i]) - (int)'0';
      Serial.println("Turn on valve: " + String(valve));
      
      if (!manager.TurnOnValve(valve)) {
        errorValves += String(valve) + ",";
      }
    }

    if (errorValves.length() == 0) {
      server.send(200, "application/json", "{ \"result\": \"OK\" }");
    }
    else {
      this->badRequest("Valves that couldn't be turned on: " + errorValves.substring(0, errorValves.length() - 2));
    }
  }
  else {
    this->badRequest("\"states\" argument not found!");
  }
}
void APIServer::turnValveOff() {
  if (server.hasArg("states")) {
    String states = server.arg("states");
    Serial.println("Received following state: " + states);

    String errorValves = "";
    for (int i = 0; i < states.length(); i++) {
      int valve = (int)(states[i]) - (int)'0';
      Serial.println("Turn off valve: " + String(valve));
      
      if (!manager.TurnOnValve(valve)) {
        errorValves += String(valve) + ",";
      }
    }

    if (errorValves.length() == 0) {
      server.send(200, "application/json", "{ \"result\": \"OK\" }");
    }
    else {
      this->badRequest("Valves that couldn't be turned off: " + errorValves.substring(0, errorValves.length() - 2));
    }
  }
  else {
    this->badRequest("\"states\" argument not found!");
  }
}

// handler for showing current valve state
void APIServer::showCurrentState() {
  String state = "{ \"state\": \"" + manager.ShowCurrentState() + "\" }";
  server.send(200, "application/json", state);
}

void APIServer::Start() {
  manager.InitializePins();
  
  server.on("/", std::bind(&APIServer::testPage, this));
  server.on("/state", HTTP_GET, std::bind(&APIServer::showCurrentState, this));
  server.on("/turnOn", HTTP_POST, std::bind(&APIServer::turnValveOn, this));
  server.on("/turnOff", HTTP_POST, std::bind(&APIServer::turnValveOff, this));
  server.onNotFound(std::bind(&APIServer::notFound, this));
  server.begin();
};

void APIServer::Loop() {
  server.handleClient();
};
