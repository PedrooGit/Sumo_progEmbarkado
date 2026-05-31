#include <Arduino.h>

#define pinoBotao 2
bool estadoBotao;

void setup(){
    pinMode(pinoBotao, INPUT);
    Serial.begin(9600);

}

void loop(){
    estadoBotao = digitalRead(pinoBotao);
    
    if (estadoBotao){
        Serial.println("apertado");
    }else{
        Serial.println("naum");
    }


}