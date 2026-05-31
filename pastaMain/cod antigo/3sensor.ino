#include <Arduino.h>

#define trig_1 7
#define echo_1 6

#define trig_2 8
#define echo_2 9

#define trig_3 4
#define echo_3 3

float distancia_1;
float distancia_2;
float distancia_3;

void setup() {

    pinMode(trig_1, OUTPUT);
    pinMode(echo_1, INPUT);

    pinMode(trig_2, OUTPUT);
    pinMode(echo_2, INPUT);

    pinMode(trig_3, OUTPUT);
    pinMode(echo_3, INPUT);

    Serial.begin(9600);
}

void loop() {

    distancia_1 = sensorUltra(trig_1, echo_1);
    distancia_2 = sensorUltra(trig_2, echo_2);
    distancia_3 = sensorUltra(trig_3, echo_3);

    Serial.println("<-===============================->");    
    Serial.print("Distancia 1: ");
    Serial.println(distancia_1);
    delay(500);
    Serial.print("Distancia 2: ");
    Serial.println(distancia_2);
    delay(500);
    Serial.print("Distancia 3: ");
    Serial.println(distancia_3);        
    delay(1000);
}

float sensorUltra(int trig, int echo) {

    digitalWrite(trig, LOW);
    delayMicroseconds(5);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    float distancia = pulseIn(echo, HIGH);
    distancia = distancia / 58.0;

    return distancia;
}