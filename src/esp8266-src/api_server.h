#ifndef _API_SERVER_H_
#define _API_SERVER_H_

#include <ESP8266WebServer.h>

class APIServer {

  private:
    ESP8266WebServer server;

    //std::function<void(void)> testPageFunc = []() {this.server.send(200, "text/html", "<h2>Main page</h2>");}
    
    void testPage(void);
    void notFound(void);
  
  public:
    APIServer(): server(80) { }

    void Start();
    void Loop();
};

#endif // _API_SERVER_H_
