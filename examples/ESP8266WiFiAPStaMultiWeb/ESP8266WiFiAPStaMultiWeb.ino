/**
 *  @file     ESP8266WiFiAPStaMultiWeb.ino
 *  @version  0.2
 *  @date     April 2017
 *  @author   Nhu-Hoai Robert VO <nhuhoai.vo@franicflow.ch>
 *  @brief    Demo with the AP+Sta mode on ESP8266 & multiple web server
 */

#include <EEPROM.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAPSta.h>

ESP8266WiFiAPSta WiFiAPSta;
/*
 *  You need an another web server? No problem! Use the default port 80
 */
ESP8266WebServer myServer(80);

/**
 *  
 */
void setup() {
  EEPROM.begin(50);
  WiFiAPSta.init();
  initMyServer();
}

/**
 *  
 */
void loop() {
  WiFiAPSta.handleClient();
  myServer.handleClient();
}

/**
 *  Handle client request for your web server
 */
void initMyServer() {
  myServer.on("/", []() {
    myServer.send(200, "text/html", "<h1>Welcome to my server</h1>");
  });
  
  myServer.onNotFound([]() {
    myServer.send(404, "text/html", "<h1>Oops, page not found (famous 404 error)</h1>");
  });
  
  myServer.begin();
}