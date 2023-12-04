#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial miBT(8, 9);  // Bluetooth conectado a los pines 8 (RX) y a los pines 9 (TX)
char DATO = 0;

int izquierda = 2;
int derecha = 3;

void setup() {
  miBT.begin(9600);
  pinMode(izquierda, OUTPUT);
  pinMode(derecha, OUTPUT); //variables para facilitar la programación de los motores
}

void loop() {
    Bluetooth();
  }

void Bluetooth() {
  DATO = miBT.read();

    if (DATO == '1') {
      digitalWrite(izquierda, HIGH);  // prende el motor izquierdo
      miBT.println("motor izquierdo encendido"); // mensaje de confirmacion al controlador serial: motor izquierdo encendido
    }

    if (DATO == '2') {
      digitalWrite(izquierda, LOW);   // apaga el motor izquierdo
      miBT.println("motor izquierdo apagado"); // mensaje de confirmacion al controlador serial: motor izquierdo apagado
    }

    if (DATO == '3') {
      digitalWrite(derecha, HIGH); // prende el motor derecho
      miBT.println("motor derecho encendido"); // mensaje de confirmacion al controlador serial: motor derecho encendido
    }

    if (DATO == '4') {
      digitalWrite(derecha, LOW);  // apaga el motor izquierdo
      miBT.println("motor derecho apagado"); // mensaje de confirmacion al controlador serial: motor derecho apagado
    }
}
