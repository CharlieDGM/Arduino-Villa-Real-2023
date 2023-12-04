#include <LedControl.h>
// incluye libreria LedControl

LedControl lc=LedControl(11,13,10,0); // crea objeto
LedControl lc2=LedControl(11,13,10,1);
LedControl lc3=LedControl(11,13,10,2);

void setup() {
  lc.shutdown(0,false);     // enciende la matriz
  lc.setIntensity(0,4);     // establece brillo
  lc.clearDisplay(0);     // blanquea matriz

  lc2.shutdown(0,false);     // enciende la matriz
  lc2.setIntensity(0,4);     // establece brillo
  lc2.clearDisplay(0);     // blanquea matriz

  lc3.shutdown(0,false);     // enciende la matriz
  lc3.setIntensity(0,4);     // establece brillo
  lc3.clearDisplay(0);     // blanquea matriz
}


void loop(){
  lc.setLed(0,2,2,true);
  lc.setLed(0,2,5,true);
  lc.setLed(0,5,1,true);
  lc.setLed(0,6,2,true);
  lc.setLed(0,6,3,true);
  lc.setLed(0,6,4,true);
  lc.setLed(0,6,5,true);
  lc.setLed(0,5,6,true);

  lc2.setLed(0,2,2,true);
  lc2.setLed(0,2,5,true);
  lc2.setLed(0,5,1,true);
  lc2.setLed(0,6,2,true);
  lc2.setLed(0,6,3,true);
  lc2.setLed(0,6,4,true);
  lc2.setLed(0,6,5,true);
  lc2.setLed(0,5,6,true);

  lc3.setLed(0,2,2,true);
  lc3.setLed(0,2,5,true);
  lc3.setLed(0,5,1,true);
  lc3.setLed(0,6,2,true);
  lc3.setLed(0,6,3,true);
  lc3.setLed(0,6,4,true);
  lc3.setLed(0,6,5,true);
  lc3.setLed(0,5,6,true);


}
