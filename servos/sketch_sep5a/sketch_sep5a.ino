    #include <Servo.h>

Servo servo1;
int trig = 2;
int echo = 3;
int tiempo;
int distancia;
int valorServo;
String ESTADO;

void setup() {
  servo1.attach(9);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  servoSi();
  sensor(ESTADO); 
}

void sensor(String estado) { 
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58.2;
  valorServo = tiempo / 105.555;
  
  String mensaje = "A una distancia de: " + String(distancia) + "cm, que son: " + String(tiempo) + " microsegundos. Estado: " + estado;
  Serial.println(mensaje);
}

void servoLectura() {
  servo1.write(valorServo);    
  delay(15);
}

void servoSi() {
  if (tiempo >= 5000) {
    servo1.write(180);
    delay(15);
    ESTADO = "Verdadero";
  }
  else {
    servo1.write(0);
    delay(15);
    ESTADO = "Falso";
  }
}
