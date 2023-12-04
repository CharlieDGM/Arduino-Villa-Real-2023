#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial miBT(0 ,1);
char DATO = 0;
Servo servo1;
Servo servo2;
Servo servo3;
int LUZ = 12;

void setup() {
  miBT.begin(9600);
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  pinMode(LUZ, OUTPUT);
}

void loop() {

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);

  DATO = miBT.read();

  if (DATO == '1') {
    servo1.write(0);
    delay(15);
    Serial.println("Servo 1 encendido");
    miBT.println("Puerta principal abierta");
  }

  if (DATO == '2') {
    servo1.write(90);
    delay(15);
    Serial.println("Servo 1 apagado");
    miBT.println("Puerta principal cerrada");
  }

  if (DATO == '3') {
    servo2.write(0);
    delay(15);
    Serial.println("Servo 2 encendido");
    miBT.println("Puerta trasera abierta");
  }

  if (DATO == '4') {
    servo2.write(90);
    delay(15);
    Serial.println("Servo 2 apagado");
    miBT.println("Puerta trasera cerrada");
  }

  if (DATO == '5') {
    servo3.write(0);
    delay(15);
    Serial.println("Servo 3 encendido");
    miBT.println("Parqueo Abierto");
  }

  if (DATO == '6') {
    servo3.write(90);
    delay(15);
    Serial.println("Servo 3 apagado");
    miBT.println("Parqueo Cerrado");
  }

  if (DATO == '7') {
    digitalWrite(LUZ, HIGH);
    Serial.println("transistor encendido");
    miBT.println("Luz encendida");
  }

  if (DATO == '8') {
    digitalWrite(LUZ, LOW);
    Serial.println("transistor apagado");
    miBT.println("Luz apagada");
  }
}