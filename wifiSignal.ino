#include <ESP8266WiFi.h>

const char* wifiUsername = "user";
const char* wifiPassword = "pass";

void setup()
{

  pinMode(2, OUTPUT);
  
  Serial.begin(9600);  
  delay(10); 

  WiFi.begin(wifiUsername, wifiPassword); 
   while (WiFi.status() != WL_CONNECTED) { 
    
    delay(50);
    digitalWrite(2, HIGH); 
    delay(50);
    digitalWrite(2, LOW); 
  
  }  
}

  void loop() {  

    const int wifiSignal = WiFi.RSSI(); 
    // ...  
   
}
