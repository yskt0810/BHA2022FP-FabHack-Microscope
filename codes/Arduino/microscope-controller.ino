#include <FastLED.h>
#define NUM_LEDS 12
#define DATA_PIN 9

const int dirPin = 2;
const int stepPin = 3;

const int steps = 1600;
int stepDelay;
int mode = 2; // 0: stepper control, 1: stepper adjustment, 2: menu
int step_interval = 10;



CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds,NUM_LEDS);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  Serial.begin(9600);
  FastLED.setCorrection(TypicalPixelString);
  FastLED.setTemperature(CoolWhiteFluorescent);
  FastLED.setBrightness(255);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  leds[0] = CRGB::White;
  leds[1] = CRGB::White;
  leds[2] = CRGB::White;
  leds[3] = CRGB::White;
  leds[4] = CRGB::White;
  leds[5] = CRGB::White;
  leds[6] = CRGB::White;
  leds[7] = CRGB::White;
  leds[8] = CRGB::White;
  leds[9] = CRGB::White;
  leds[10] = CRGB::White;
  leds[11] = CRGB::White;
  
  FastLED.show();
  
  control();
  
}

void control(){

  if(Serial.available()){
    stepDelay = 250;
    char val = Serial.read();
    
    if(val == 'U'){
      digitalWrite(dirPin,HIGH);
      for(int x=0; x<step_interval; x++){
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(stepDelay);
      }
    }
    else if(val == 'D'){
      digitalWrite(dirPin,LOW);
      for(int x=0;x<step_interval;x++){
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(stepDelay);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(stepDelay);
        
      }
    }
    else if(val == 'L'){
      step_interval = 100;  
    }
    else if(val == 'S'){
      step_interval = 10;
    }
  }
}
