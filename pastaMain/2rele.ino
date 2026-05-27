#include <Arduino.h>

#define rele_dir 13
#define rele_esq 12

void setup() {
  pinMode(rele_dir, OUTPUT);
  pinMode(rele_esq, OUTPUT);
}


void loop() {
  digitalWrite(rele_dir, LOW);  
  digitalWrite(rele_esq, HIGH);
  delay(3000);


  digitalWrite(rele_dir, HIGH);  
  digitalWrite(rele_esq, LOW);
  delay(3000);
}

