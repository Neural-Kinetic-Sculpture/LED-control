/*

      LED Program:
      Controls ~195 WS2812B LEDs (4ft strip) for the Nerual Kinetic Sculpture

      Modfied: March 18, 2025
      By: Letzy Mota and Ashley Nguyen

      Modified: April 15, 2025
      By: Letzy Mota

*/

#include <Adafruit_NeoPixel.h>

#define LEDPin 18 // pin 18 controls strip
#define NumLEDs 196// about 195 LEDS per 4ft (for 1 panel)
#define Brightness 100 // controls LED brightness (0-255) 

void TransitionLEDs(uint32_t color1, uint32_t color2);

Adafruit_NeoPixel strip(NumLEDs, LEDPin, NEO_GRB + NEO_KHZ800); // defines strip object (800KHZ, GRB required for strip model)

void SetAllLEDs();

void setup() {

    strip.begin(); // initializes LEDS
    strip.show();  // sets all LEDs to off
    strip.setBrightness(Brightness); // adjusts brightness

}

void loop() {
    
    TransitionLEDs(0xFF5733, 0xFFB6C1);
   // delay(10);
    TransitionLEDs(0xFFB6C1, 0xFF5733);
   // delay(10);

}

// function to set all LEDs 1 color
void SetAllLEDs(uint32_t color) {
    for (int i = 0; i < NumLEDs; i++) {
        strip.setPixelColor(i, color); //update color
    }
    strip.show(); // apply changes
}

// gradient function
void TransitionLEDs(uint32_t color1, uint32_t color2) {
  int red1 = (color1 >> 16) & 0xff;
  int green1 = (color1 >> 8) & 0xff;
  int blue1 = (color1) & 0xff;

  int red2 = (color2 >> 16) & 0xff;
  int green2 = (color2 >> 8) & 0xff;
  int blue2 = (color2) & 0xff;

  for (int i = 0; i <= 200; i++) {
    float t = i / 200.0;  // Interpolation amount from 0.0 to 1.0

    int newred = round(red1 + (red2 - red1) * t);
    int newgreen = round(green1 + (green2 - green1) * t);
    int newblue = round(blue1 + (blue2 - blue1) * t);

    SetAllLEDs(strip.Color(newred, newgreen, newblue));
   // delay(10);
  }

  SetAllLEDs(color2);
  delay(500);

}
