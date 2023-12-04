#include <SoftwareSerial.h>

SoftwareSerial miBT(0, 1);
char DATO = 0;
int POSITIVOIZQUIERDA = 2;
int POSITIVODERECHA = 3;

void setup() {
  miBT.begin(38400);
  pinMode(POSITIVODERECHA, OUTPUT);
  pinMode(POSITIVOIZQUIERDA, OUTPUT);
}

void loop() {
  DATO = miBT.read();

  if (DATO == '1') {
    parar();
  }

  if (DATO == 'W') {
    adelante();
  }

  if (DATO == 'D') {
    derecha();
  }

  if (DATO == 'A') {
    izquierda();
  }
}

void parar() {
  digitalWrite(POSITIVODERECHA, LOW);
  digitalWrite(POSITIVOIZQUIERDA, LOW);
  miBT.println("Auto Inmovil");
}

void adelante() { 
  digitalWrite(POSITIVODERECHA, HIGH);
  digitalWrite(POSITIVOIZQUIERDA, HIGH);
  miBT.println("Moviendo hacia adelante");
}

void derecha() {
  digitalWrite(POSITIVODERECHA, LOW);
  digitalWrite(POSITIVOIZQUIERDA, HIGH);
  miBT.println("Moviendo hacia la derecha");
}

void izquierda() {
  digitalWrite(POSITIVODERECHA, HIGH);
  digitalWrite(POSITIVOIZQUIERDA, LOW);
  miBT.println("Moviendo hacia la izquierda");
}
