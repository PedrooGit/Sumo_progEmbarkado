#include <Arduino.h>

#define pinPot A5
int potem, luz;

void setup() {

  Serial.begin(9600);
}

void loop() {
    
    potem = analogRead(pinPot);
    luz = map(potem, 0, 1023, 0, 100);
  	Serial.print("O valor é de: ");
  	Serial.println(luz);
    delay(500);
}