#include <Servo.h>

Servo servo[3];     // Array de servos (se declara su numero de objeto con la variable "i" en el ciclo for)
int trigPin[3] = {2, 4, 6};  // Array de los 3 pines de trig, de los 3 sensores
int echoPin[3] = {3, 5, 7};  //Array para los pines de echo, de los 3 sensores
int tiempo[3]; //x2 Array de variables que se dice cual es con la variable "i" en el ciclo for
int distancia[3]; //x3 Array de variables que se dice cual es con la variable "i" en el ciclo for
int valorServo[3]; //x4 Array de variables que se dice cual es con la variable "i" en el ciclo for

void setup() {
  for (int i = 0; i < 3; i++) {
    servo[i].attach(9 + i);  // Servos a los pines 9, 10 y 11
    pinMode(trigPin[i], OUTPUT);
    pinMode(echoPin[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    sensor(i);
    servoSi(i);
  }
}

void sensor(int sensorIndex) {
  String mensaje = "Sensor " + String(sensorIndex + 1) + ": Distancia: " + String(distancia[sensorIndex]) + "cm. Tiempo: " + String(tiempo[sensorIndex]) + " Valor Servo: " + String(valorServo[sensorIndex]);

  digitalWrite(trigPin[sensorIndex], HIGH);
  delay(1);
  digitalWrite(trigPin[sensorIndex], LOW);
  tiempo[sensorIndex] = pulseIn(echoPin[sensorIndex], HIGH);
  distancia[sensorIndex] = tiempo[sensorIndex] / 58.2;
  valorServo[sensorIndex] = tiempo[sensorIndex] / 105.555;
  Serial.println(mensaje);
}

void servoSi(int sensorIndex) {
  if (tiempo[sensorIndex] <= 1000) {
    servo[sensorIndex].write(180);
    delay(15);
  } else {
    servo[sensorIndex].write(90);
    delay(15);
  }
}