#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* wifiUsername = "<wifi_username>";
const char* wifiPassword = "<wifi_password>";
const char* serverName = "<ip_address>:3333/frequence";

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
    
    HTTPClient http; 
    WiFiClient client_; 

    const int wifiSignal = WiFi.RSSI(); 
    
    http.begin(client_, serverName); 
    http.addHeader("Content-Type", "application/json");
    
    String data = "{\"rssi\": " + String(wifiSignal) + "}";
    int httpCode = http.POST(data);

    if (httpCode == HTTP_CODE_OK) {
      digitalWrite(2, HIGH);
      delay(20);
      digitalWrite(2, LOW);
      delay(20);
    
    } 

    if (httpCode != HTTP_CODE_OK) {
      return;
    }    

  

}