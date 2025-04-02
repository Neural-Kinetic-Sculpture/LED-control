/*

      LED Program:
      Controls ~195 WS2812B LEDs (4ft strip) for the Nerual Kinetic Sculpture

      Modfied: March 18, 2025
      By: Letzy Mota and Ashley Nguyen

*/

#include <Adafruit_NeoPixel.h>

#define LEDPin 18 // pin 18 controls strip
#define NumLEDs 195 // about 195 LEDS per 4ft (for 1 panel)
#define Brightness 30 // controls LED brightness (0-255) [significant heat produced over 100]

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
    
    /*SetAllLEDs(strip.Color(255, 0, 0)); // All LEDs Red
    delay(1000);

    SetAllLEDs(strip.Color(0, 255, 0)); // All LEDs Green
    delay(1000);

    SetAllLEDs(strip.Color(0, 0, 255)); // All LEDs Blue
    delay(1000);*/
    
    //To test out, gradients from blue to orange porportionally in 2s
    TransitionLEDs(strip.Color(255,0,0), strip.Color(0,0,255));
    delay(1000);
    TransitionLEDs(strip.Color(0,0,255), strip.Color(255,0,0));
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

//WIP CODE to test out
void TransitionLEDs(uint32_t color1, uint32_t color2){
  int red1 = (color1 >> 16) & 0xff;
  int green1 = (color1 >> 8) & 0xff;
  int blue1 = (color1) & 0xff;

  int red2 = (color2 >> 16) & 0xff;
  int green2 = (color2 >> 8) & 0xff;
  int blue2 = (color2) & 0xff;

  int redchange = (red2 - red1)/200;
  int greenchange = (green2 - green1)/200;
  int bluechange = (blue2 - blue1)/200;

  int newred;
  int newgreen;
  int newblue;

  for (int i = 0; i<199;i++){
    newred = int(red1 + (redchange * i));
    newgreen = int(green1 + (greenchange * i));
    newblue = int(blue1 + (bluechange * i));

    SetAllLEDs(strip.Color(newred, newgreen, newblue));
    delay(10);
  }

  SetAllLEDs(strip.Color(red2, green2, blue2));
}


