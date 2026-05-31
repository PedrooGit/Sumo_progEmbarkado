#include <Arduino.h>


#include <Servo.h>

Servo meuServo;
#define pinServo 5
int angulo = 0;

void setup() {

    meuServo.attach(pinServo);
}


void loop() {

    for(angulo = 0; angulo <= 180; angulo++) {                                
        meuServo.write(angulo);              
        delay(15);
    }

    for(angulo = 180; angulo >= 0; angulo--) {                                
        meuServo.write(angulo);              
        delay(15);      
    }
}

