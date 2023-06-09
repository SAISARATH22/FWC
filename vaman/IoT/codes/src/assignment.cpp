#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "gvv" // Add your network credentials
#define STAPSK  "abcd1234"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;
int Z,Y,X,W,R,S;
int A,B,C;

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();
pinMode(2,OUTPUT);
	pinMode(5,INPUT);
	pinMode(6,INPUT);
	pinMode(7,INPUT);
	pinMode(8,INPUT);
  //-------------------//
  // Custom setup code //
  //-------------------//
}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  W=digitalRead(5);
	X=digitalRead(6);
	Y=digitalRead(7);
	Z=digitalRead(8);

	A=(!R&&!S&&W)||(!R&&S&&X)||(R&&!S&&Y)||(R&&S&&Z);
	B=(!R&&S)||(R&&!S);
	if(A==B){
		digitalWrite(2,1);
	}
	else{
		digitalWrite(2,0);
	}//-------------------//
  // Custom loop code  //
  //-------------------//
}
