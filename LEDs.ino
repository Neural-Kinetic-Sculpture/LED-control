/*

      LED Program:
      Controls ~195 WS2812B LEDs (4ft strip) for the Nerual Kinetic Sculpture

      Modfied: March 18, 2025
      By: Letzy Mota and Ashley Nguyen

*/

#include <Adafruit_NeoPixel.h>

#define LEDPin 18 // pin 18 controls strip
#define NumLEDs 195 // about 195 LEDS per 4ft (for 1 panel)
#define Brightness 50 // controls LED brightness (0-255) [significant heat produced over 100]

Adafruit_NeoPixel strip(NumLEDs, LEDPin, NEO_GRB + NEO_KHZ800); // defines strip object (800KHZ, GRB required for strip model)

void SetAllLEDs();

void setup() {

// configure input pins for app instructions??? (analog???)
// ... ???
// read configuration and save instructions (analog to map or switch???)
// ... ???

// configure pins for filtered EEG input (analog) [idk how many channels?]
// ...

    strip.begin(); // initializes LEDS
    strip.show();  // sets all LEDs to off
    strip.setBrightness(Brightness); // adjusts brightness

}

void loop() {

// read the input signal (analog)
// ...

// example code turns all LEDS red, green, then blue for 1 second each
    SetAllLEDs(strip.Color(255, 0, 0)); // All LEDs Red
    delay(1000);

    SetAllLEDs(strip.Color(0, 255, 0)); // All LEDs Green
    delay(1000);

    SetAllLEDs(strip.Color(0, 0, 255)); // All LEDs Blue
    delay(1000);

}

// function to set all LEDs 1 color
void SetAllLEDs(uint32_t color) {
    for (int i = 0; i < NumLEDs; i++) {
        strip.setPixelColor(i, color); //update color
    }
    strip.show(); // apply changes
}

// any other LED animation functions can be included here
// ...