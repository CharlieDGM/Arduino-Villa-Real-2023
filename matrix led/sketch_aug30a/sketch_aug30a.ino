#include <LedControl.h>
// incluye libreria LedControl

LedControl lc=LedControl(11,13,10,0); // crea objeto
LedControl lc2=LedControl(11,13,10,1); // crea objeto

void setup() {
  lc.shutdown(0,false);     // enciende la matriz
  lc.setIntensity(0,4);     // establece brillo
  lc.clearDisplay(0);

    lc2.shutdown(0,false);     // enciende la matriz
  lc2.setIntensity(0,4);     // establece brillo
  lc2.clearDisplay(0);     // blanquea matriz

     // blanquea matriz
}

void loop(){
  for(int fila = 0; fila < 8; fila++) {     // itera por las filas
    for(int columna = 0; columna < 8; columna++) {  // itera por las columnas
      lc.setLed(0,fila,columna,true);     // enciende LED
      delay(500);         // demora de 100 mseg.
      lc.setLed(0,fila,columna,false);      // apaga LED
      delay(500);         // demora de 100 mseg.
    }
  }
}

  for(int fila2 = 0; fila2 < 8; fila2++) {     // itera por las filas
    for(int columna2 = 0; columna2 < 8; columna2++) {  // itera por las columnas
      lc2.setLed(0,fila2,columna2,true);     // enciende LED
      delay(500);         // demora de 100 mseg.
      lc2.setLed(0,fila2,columna2,false);      // apaga LED
      delay(500);         // demora de 100 mseg.
    }
  }
}