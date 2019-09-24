#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    16
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() {
  
        for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Purple;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            delay(100);
        }
    }
