#include <Servo.h> //aaaaaa al pin 2 va el triger, pin 3 el echo, al pin 9 va el coso como se llame
                   //ese coso del servo, el data, ye

Servo servo1;
int trig=2;
int echo=3;
int tiempo;
int distancia;
int valorServo;

void setup() {
  servo1.attach(9);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  sensor();
  servoLectura();
}

void sensor() {
String mensaje = "A una distancia de: " + String(distancia) + "cm. Tiempo: " + String(tiempo) + " Valor Servo: " + String(valorServo);
  
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo=pulseIn(echo,HIGH);
  distancia=tiempo/58.2;
  valorServo=tiempo/105.555;
  Serial.println(mensaje);
}

void servoLectura() {
  servo1.write(valorServo);    
  delay(15);
}
