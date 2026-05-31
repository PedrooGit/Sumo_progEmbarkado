#include <Arduino.h>

#define pinPot A5
int potem, luz;

void setup(){
    pinMode(pinPot, INPUT);

}

void loop(){
    potem = analogRead(pinPot);
    luz = map(potem, 0, 1023, 0, 100);


    
}