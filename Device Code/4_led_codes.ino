#include <Adafruit_NeoPixel.h>

#if defined(ESP32)
#include <FirebaseESP32.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif

#define WIFI_SSID "Deepak@182002"  //WiFi SSID
#define WIFI_PASSWORD "silkofheaven"  //WiFi Password
#define LedPin 16         // pin d0 as toggle pin
#define NUM_PIXELS 8      //number of rgb led
#define PIN_PIXELS 14     //pin d5 as neopixel input
#define FIREBASE_HOST "led-e68a0-default-rtdb.firebaseio.com" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "XZO7NodvOqFnObMZjr9M8IrCHdMjJ8htNanOyt1u" //Your Firebase Auth Token
FirebaseData firebaseData;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN_PIXELS, NEO_GRB + NEO_KHZ800);
void setup ()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
  
  pixels.begin();
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ") ;
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);     
}
void loop ()
{
  
  if(Firebase.getString(firebaseData, "/LED_STATUS")){
    String ledstatus1 = firebaseData.stringData();
    if(ledstatus1.toInt() == 1){
      Serial.println("ON_1");
      digitalWrite(2, HIGH);
        pixels.setPixelColor(0, pixels.Color(0, 0, 1));  // #2169f3 color blue
        pixels.show();
    }
    else {
      Serial.println("OFF1");
      digitalWrite(2, LOW);
        pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // turn off neopixel
        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  } 
  if(Firebase.getString(firebaseData, "/LED_STATUS2")){
    String ledstatus2 = firebaseData.stringData();
    if(ledstatus2.toInt() == 1){
      Serial.println("ON_2");
      digitalWrite(4, HIGH);
        pixels.setPixelColor(1, pixels.Color(1, 0, 1));  // #f3219c color pink
        pixels.show();
    }
    else {
      Serial.println("OFF_2");
      digitalWrite(4, LOW);
        pixels.setPixelColor(1, pixels.Color(0, 0, 0)); // turn off neopixel
        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }
  if(Firebase.getString(firebaseData, "/LED_STATUS3"))
  {
    String ledstatus3 = firebaseData.stringData();
    if(ledstatus3.toInt() == 1){
      Serial.println("ON_3");
      digitalWrite(5, HIGH);
        pixels.setPixelColor(2, pixels.Color(0, 1, 1));  // #21ecf3 color cyan
        pixels.show();
    }
    else {
      Serial.println("OFF_3");
      digitalWrite(5, LOW);
        pixels.setPixelColor(2, pixels.Color(0, 0, 0)); // turn off neopixel
        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }
  if(Firebase.getString(firebaseData, "/LED_STATUS4")){
    String ledstatus4 = firebaseData.stringData();
    if(ledstatus4.toInt() == 1){
      Serial.println("ON_4");
      digitalWrite(12, HIGH);
        pixels.setPixelColor(3, pixels.Color(0, 1, 0));  // #a3f321 color
        pixels.show();
    }
    else {
      Serial.println("OFF_4");
      digitalWrite(12, LOW);
        pixels.setPixelColor(3, pixels.Color(0, 0, 0)); // turn off neopixel
        pixels.show();
    }
  }
  else{
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }

}   
