#include <SoftwareSerial.h>

SoftwareSerial miBT(0, 1);  // Bluetooth device connected to pins 0 (RX) and 1 (TX)
char DATO = 0;
int LEDROJO = 2;
int LEDVERDE = 3;

void setup() {
  miBT.begin(9600);
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
}

void loop() {
    DATO = miBT.read();

    if (DATO == '1') {
      digitalWrite(LEDROJO, HIGH);  // prende el led rojo
      miBT.println("Luz Roja encendida"); // mensaje de confirmacion al controlador serial: Luz encendida
    }

    if (DATO == '2') {
      digitalWrite(LEDROJO, LOW);   // apaga el led rojo
      miBT.println("Luz Roja Apagada"); // mensaje de confirmacion al controlador serial: Luz apagada
    }

    if (DATO == '3') {
      digitalWrite(LEDVERDE, HIGH); // prende el led verde
      miBT.println("Luz Verde Encendida"); // mensaje de confirmacion al controlador serial: Luz encendida
    }

    if (DATO == '4') {
      digitalWrite(LEDVERDE, LOW);  // apaga el led verde
      miBT.println("Luz Verde Apagada"); // mensaje de confirmacion al controlador serial: Luz apagada
    }
  }
