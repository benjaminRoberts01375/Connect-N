#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN 6 //Pin the light strip's dataline is connected to
#define LED_COUNT 30 //Number of LEDs on the lightstrip (RGB = 1)

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); //Configure strip

void setup() {
  strip.begin(); //Initialize NeoPixel strip object
  strip.show(); //Turn off all LEDs
}

void loop() {
  
}
