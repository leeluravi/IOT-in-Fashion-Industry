#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>

#define PIN 21
#define NUMPIXELS 12

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin("b5a57e25ca114fae87f56aae9ce72e4e","PC-LC","2016nbachamps");
  pixels.begin();
}

BLYNK_WRITE(V1)
{
 int R = param[0].asInt();
 int G = param[1].asInt();
 int B = param[2].asInt();
 Serial.println(R);
 Serial.println(G);
 Serial.println(B);
 for(int i=0;i<NUMPIXELS;i++){
  pixels.setPixelColor(i,pixels.Color(R,G,B));

  pixels.show();
 }
}

void loop()
{
  Blynk.run();
}
