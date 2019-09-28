//LED setup
#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    16
CRGB leds[NUM_LEDS];

// Rotary encoder stuff
int encA = 2; //CLK
int encB = 3; //DT
int button = 4; //SW (Encoder Button)
int encA_last;
int aVal;
int encoder_pos = 0;
bool dirCW;

//function button
int mode = 1; 
int R = 0;
int G = 0;
int B = 0;
int pos;
/*
0 == control light position
1 == set Red value
2 == set Green value
3 == set Blue value
*/

void setup() {
    pinMode (encA, INPUT);
    pinMode (encB, INPUT);

    encA_last = digitalRead(encA); //set start position
}

void loop() {
    //set mode
    if (button == HIGH) {
        if (mode == 3) {
            mode = 0;
        } else {
            mode ++;
        }
    } else {
        if (mode == 0) {
            leds[pos].setRGB(R, G, B);
            FastLED.show();
            led_pos();
            leds[pos] = CRGB::Black;
        }
        if (mode == 1) {
            leds[0] = CRGB::Red;
            leds[1].setRGB(R, G, B);
            FastLED.show();
            red();
        }
        if (mode == 2) {
            leds[0] = CRGB::Green;
            leds[1].setRGB(R, G, B);
            FastLED.show();
            green();
        }
        if (mode == 3) {
            leds[0] = CRGB::Blue;
            leds[1].setRGB(R, G, B);
            FastLED.show();
            blue();
        }
    }
}

void update_pos() {
    if (aVal != encA_last) { //knob is rotating
        if (digitalRead(encB) != aVal) { //encA changed first, movement is clockwise
            dirCW = true;
            encoder_pos ++;
        } else { //encB changed first, movement is counter-clockwise
            dirCW = false;
            encoder_pos --;
        }
    }
}
void red() {
    encoder_pos = R;
    update_pos();
    constrain(encoder_pos, 0, 255);
    R = encoder_pos;
}
void green() {
    encoder_pos = G;
    update_pos();
    constrain(encoder_pos, 0, 255);
    G = encoder_pos;
}
void blue() {
    encoder_pos = B;
    update_pos();
    constrain(encoder_pos, 0, 255);
    B = encoder_pos;
}
void led_pos() {
    encoder_pos = pos;
    update_pos();
    constrain(encoder_pos, 0, NUM_LEDS - 1);
    pos = encoder_pos;
}