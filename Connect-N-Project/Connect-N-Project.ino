#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN 6 //Pin the light strip's dataline is connected to
#define LED_COUNT 30 //Number of LEDs on the lightstrip

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); //Configure strip

void setup() {
  Serial.begin(9600); //Setup Serial port for console
  strip.begin(); //Initialize NeoPixel strip object
  strip.setBrightness(50); //LED brightness (0-255)
}

void loop() {
  Serial.println("Restarting");
  uint32_t p1Color = strip.Color(0, 255, 0);
  uint32_t p2Color = strip.Color(255, 0, 0);

  displayScores(20, 10, p1Color, p2Color, LED_COUNT);
}
