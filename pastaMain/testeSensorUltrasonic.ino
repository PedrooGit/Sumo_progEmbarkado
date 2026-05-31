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

#define pinoBotao 2
bool estadoBotao;
bool CHAVE = false; 

#define pinoMotor_A1 13
#define pinoMotor_B1 12
#define pinoMotor_A2 11
#define pinoMotor_B2 10


void setup(){
    pinMode(pinoBotao, INPUT);
    
    pinMode(trig_1, OUTPUT);
    pinMode(echo_1, INPUT);

    pinMode(trig_2, OUTPUT);
    pinMode(echo_2, INPUT);

    pinMode(trig_3, OUTPUT);
    pinMode(echo_3, INPUT);
    
    pinMode(pinoMotor_A1, OUTPUT);
    pinMode(pinoMotor_B1, OUTPUT);
    pinMode(pinoMotor_A2, OUTPUT);
    pinMode(pinoMotor_B2, OUTPUT);    
}

void loop(){
    estadoBotao = digitalRead(pinoBotao);

    //se o botao estiver no flau
    if (estadoBotao){
        
        //esperar 5s
        if(CHAVE == false){
            delay(5000);
            CHAVE = true;
        }

        //ler a distancia
        distancia_1 = sensorUltra(trig_1, echo_1);
        distancia_2 = sensorUltra(trig_2, echo_2);
        distancia_3 = sensorUltra(trig_3, echo_3);

        if (distancia_1 == 10){

            //fazer alguma coisa

        }
        
        if (distancia_2 == 20){

            //fazer alguma coisa

        }

        if (distancia_3 == 30){

            //fazer alguma coisa

        }

        motorFrente_1();
        motorFrente_2();
    }else{
        motorParado_1();
        motorParado_2();
        CHAVE = false;
    }
}

#pragma region SENSOR ULTRASONICO 

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
#pragma endregion

#pragma region MOTORES/PONTE H 


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


#pragma endregion
