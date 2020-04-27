#include "api_server.h"

void APIServer::testPage() {
  server.send(200, "text/html", "<h2>Test page!</h2>");
}

void APIServer::notFound() {
  server.send(404, "text/plain", "Sorry, page not found");
};

void APIServer::Start() {
  server.on("/", std::bind(&APIServer::testPage, this));
  server.onNotFound(std::bind(&APIServer::notFound, this));
  server.begin();
};

void APIServer::Loop() {
  server.handleClient();
};
