#include <FastLED.h>
#define LED_PIN 7
#define NUM_LEDS 16
CRGB leds[NUM_LEDS];

void setup() {
  // Add LEDS
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // read pot value & map to number of LEDs
  int led = analogRead(A2);
  led = map(led, 0, 1023, 0, NUM_LEDS -1);
  leds[led] = CRGB::Green;
  FastLED.show();
  leds[led] = CRGB::Black;
  delay(5);
}
