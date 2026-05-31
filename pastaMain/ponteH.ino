#include <Arduino.h>

#define pinoMotor_A1 13
#define pinoMotor_B1 12
#define pinoMotor_A2 11
#define pinoMotor_B2 10

void setup(){
    pinMode(pinoMotor_A1, OUTPUT);
    pinMode(pinoMotor_B1, OUTPUT);
    pinMode(pinoMotor_A2, OUTPUT);
    pinMode(pinoMotor_B2, OUTPUT);

}

void loop(){
    motorAtras_1();
    motorAtras_2();
    delay(3000);
    motorParado_1();
    motorParado_2();
    delay(3000);
    motorFrente_1();
    motorFrente_2();    
    delay(3000);
    motorFreio_1();
    motorFreio_2();
    delay(3000);

}

#pragma region senti. Horario Motores 
void motorFrente_1(){

    digitalWrite(pinoMotor_A1, HIGH);
    digitalWrite(pinoMotor_B1, LOW);
}

void motorFrente_2(){

    digitalWrite(pinoMotor_A2, HIGH);
    digitalWrite(pinoMotor_B2, LOW);
}

#pragma endregion

#pragma region senti. Antihorario Motores 

void motorAtras_1(){

    digitalWrite(pinoMotor_B1, HIGH);
    digitalWrite(pinoMotor_A1, LOW);
}

void motorAtras_2(){

    digitalWrite(pinoMotor_B2, HIGH);
    digitalWrite(pinoMotor_A2, LOW);
}

#pragma endregion

#pragma region Parando Motores 

void motorParado_1(){

    digitalWrite(pinoMotor_A1, LOW);
    digitalWrite(pinoMotor_B1, LOW);
}

void motorParado_2(){

    digitalWrite(pinoMotor_A2, LOW);
    digitalWrite(pinoMotor_B2, LOW);
}

#pragma endregion

#pragma region Freiando Motores 

void motorFreio_1(){

    digitalWrite(pinoMotor_A1, HIGH);
    digitalWrite(pinoMotor_B1, HIGH);
}

void motorFreio_2(){

    digitalWrite(pinoMotor_A2, HIGH);
    digitalWrite(pinoMotor_B2, HIGH);
}

#pragma endregion