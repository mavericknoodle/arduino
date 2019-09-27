#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    16
CRGB leds[NUM_LEDS];

int pinA = 2; //CLK
int pinB = 3; //DT
int pinA_last;
int aVal;
bool clockwise = true;

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    pinMode(pinA,INPUT);
    pinMode(pinB,INPUT);

    pinA_last = digitalRead(pinA);
}

void loop() {
    
    if clockwise = true {
        for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Red;
            FastLED.show();
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            if (dot == NUM_LEDS - 1) {
                dot = 0
            }
            
            delay(100);
        }
    else {
        for(int dot = NUM_LEDS - 1; dot > 0; dot--) {
            leds[dot] = CRGB::Red;
            FastLED.show();
         //clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
             if (dot == 0) {
                dot = NUM_LEDS -1
            }

            delay(100)
        }

}
