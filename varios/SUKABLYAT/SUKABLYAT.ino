#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial miBT(8, 9);  // Bluetooth device connected to pins 0 (RX) and 1 (TX)
char DATO = 0;
int izquierda = 2;
int derecha = 3;
Servo servo1;
Servo servo2;
int trig = 5; //sensor US
int echo= 6; //sensor US
int tiempo;
int distanciaUS;
int distanciaIR = 0;
const int IRSensorPin = A1; //sensor IR
bool USDato = false;
bool TrashDete = false;
int ValorIR;
bool GarraEstado = false;

void setup() {
  Serial.begin(9600);
  miBT.begin(9600);
  pinMode(izquierda, OUTPUT);
  pinMode(derecha, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo1.attach(10); //servo
  servo2.attach(11); //servo

  servo1.write(90);
  servo2.write(90);

}

void loop() {
    Bluetooth();
    sensorUS();
    sensorIR();
    IRDetect();
    USDetect();
    Oscilar();
    impresion();
  }

void Bluetooth() {
  DATO = miBT.read();

    if (DATO == 'A') {
      TrashDete = false;
      miBT.println("sistemas en linea/no hay basura");
    }

    if (DATO == 'a') {
      TrashDete = true;
      miBT.println("sistemas apagados/basura detectada");
    }

    if (DATO == '1') {
      digitalWrite(izquierda, HIGH);  
      miBT.println("motor izquierdo encendido"); 
    }

    if (DATO == '2') {
      digitalWrite(izquierda, LOW);   
      miBT.println("motor izquierdo apagado"); 
    }

    if (DATO == '3') {
      digitalWrite(derecha, HIGH); 
      miBT.println("motor derecho encendido"); 
    }

    if (DATO == '4') {
      digitalWrite(derecha, LOW);  
      miBT.println("motor derecho apagado"); 
    }

    if (DATO == '5') {
      servo1.write(65);
      servo2.write(65);
      delay(15);
      miBT.println("Garra encendida");
      GarraEstado = true;
    }

    if (DATO == '6') {
      servo1.write(0);
      servo2.write(0);
      delay(15);
      miBT.println("Garra apagada");
      GarraEstado = false;
    }

}

void sensorUS() {
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo=pulseIn(echo, HIGH);
  distanciaUS=tiempo/58.2;

}

void sensorIR() {
  ValorIR = analogRead(IRSensorPin);
  distanciaIR = (6787.0 / (ValorIR - 3)) - 4;
}

void IRDetect() {
  if (ValorIR == LOW) {
    servo1.write(65);
    servo2.write(65);
    TrashDete = true;
  }
}

void USDetect() {
  if (tiempo <= 1000) {
    USDato = true;
  } else {
    USDato = false;
  }

  if (USDato) {
    digitalWrite(izquierda, HIGH);
    delay(2000);
    digitalWrite(izquierda, LOW);
    USDato = false;
  }
}

void Oscilar() {
  if (TrashDete) {
    digitalWrite(izquierda, LOW);
    digitalWrite(derecha, LOW);
  } else {
    if (!USDato) {
      digitalWrite(izquierda, HIGH);
      digitalWrite(derecha, HIGH);
    } else {
      digitalWrite(izquierda, LOW);
      digitalWrite(derecha, LOW);
    }
  }
}

void impresion() {
  String mensaje = "Valor US: " + String(tiempo) + ". Valor IR: " + String(ValorIR) + ". Estado US: " + String(USDato) + ". Garra : " + String(TrashDete);

  Serial.println(mensaje);
}
