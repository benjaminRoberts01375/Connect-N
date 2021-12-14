#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define LED_PIN 6 //Pin the light strip's dataline is connected to
#define LED_COUNT 30 //Number of LEDs on the lightstrip

#define LEDPort PORTB           // Arduino pin 13 is bit 5 of port B
#define LEDPort_Direction DDRB  // DDRB is the port B direction register (0=input, 1=output)
#define LEDBit 5                // Constant for bit 5
#define Clock_MHz 16
#define MilliSec 1000000
#define DelayTime (uint32_t)((Clock_MHz * MilliSec / 5))  // set to any rate desired

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); //Configure strip

void setup() {
  Serial.begin(9600); //Setup Serial port for console
  strip.begin(); //Initialize NeoPixel strip object
  strip.setBrightness(50); //LED brightness (0-255)
  resetStrip(); //Reset the strip to blank
  randomSeed(analogRead(0)); //Setup randomness

  asm volatile (       // shows default parameter use instead of our defines/names
    "sbi %0, %1 \n\t"  // sets port and bit direction
    : : "I" (_SFR_IO_ADDR(DDRB)), "I" (DDB5) // I: 6-bit positive integer constant
  );
}

void loop() {
  Serial.println("Restarting");
  AISetup();
  resetStrip();
  uint32_t p1Color = strip.Color(0, 255, 0);
  uint32_t p2Color = strip.Color(255, 0, 0);

  for (int i = 0; i < strip.numPixels(); i++) {
    int spot = playerSelect();
    playerPlace(spot, p1Color, p2Color);
  }

  displayScores(p1Color, p2Color);
}
