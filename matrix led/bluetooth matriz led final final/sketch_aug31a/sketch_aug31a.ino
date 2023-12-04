#include <LedControl.h>
#include <SoftwareSerial.h>

SoftwareSerial miBT(8, 9);
LedControl lc = LedControl(11, 13, 10, 0);

char DATO = 0;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  miBT.begin(9600);
  Serial.begin(9600); // Added this line to initialize the Serial communication
}

void loop() {
  DATO = miBT.read();

  if (DATO == '0') {
    apagarTodo();
    miBT.println("Apagando todo");
  }


  if (DATO == '1') {
    caritaFeliz();
    miBT.println("Mostrando Carita Feliz");
  }

  if (DATO == '2') {
    corazon();
    miBT.println("Mostrando Corazon");
  }

  if (DATO == '3') {
    flecha();
    miBT.println("Mostrando Flecha");
  }

  if (DATO == '4') {
    xd();
    miBT.println("xd");
  }

  if (DATO == '5') {
    sdlg();
    miBT.println("UN SALUDO A LA GRASAA q");
  }

  if (DATO == '6') {
    fantasmita();
    miBT.println("Mostrando un fantasmita");
  }

  if (DATO == '7') {
    invader();
    miBT.println("Mostrando un alien");
  }

  if (DATO == '8') {
    pacman();
    miBT.println(":v");
  }

  if (DATO == '9') {
    bruh();
    miBT.println("bruh");
  }

  if (DATO == 'a') {
    letraA();
    miBT.println("Mostrando letra A"); // Corrected from printIn to println
  }

  if (DATO == 'b') {
    letraB();
    miBT.println("Mostrando Letra B");
  }

  if (DATO == 'c') {
    letraC();
    miBT.println("Mostrando Letra C");
  }

  if (DATO == 'd') {
    letraD();
    miBT.println("Mostrando letra D");
  }

  if (DATO == 'e') {
    letraE();
    miBT.println("Mostrando Letra E");
  }

  if (DATO == 'f') {
    letraF();
    miBT.println("Mostrando Letra F");
  }

  if (DATO == 'g') {
    letraG();
    miBT.println("Mostrando Letra G");
  }

  if (DATO == 'h') {
    letraH();
    miBT.println("Mostrando Letra H");
  }

  if (DATO == 'i') {
    letraI();
    miBT.println("Mostrando Letra I");
  }

  if (DATO == 'j') {
    letraJ();
    miBT.println("Mostrando Letra J");
  }

  if (DATO == 'k') {
    letraK();
    miBT.println("Mostrando Letra K");
  }

  if (DATO == 'l') {
    letraL();
    miBT.println("Mostrando Letra L");
  }

  if (DATO == 'm') {
    letraM();
    miBT.println("Mostrando Letra M");
  }
  
  if (DATO == 'n') {
    letraN();
    miBT.println("Mostrando Letra N");
  }

  if (DATO == 'o') {
    letraO();
    miBT.println("Mostrando Letra O");
  }

  if (DATO == 'p') {
    letraP();
    miBT.println("Mostrando Letra P");
  }

  if (DATO == 'q') {
    letraQ();
    miBT.println("Mostrando Letra Q");
  }

  if (DATO == 'r') {
    letraR();
    miBT.println("Mostrando Letra R");
  }

  if (DATO == 's') {
    letraS();
    miBT.println("Mostrando Letra S");
  }

  if (DATO == 't') {
    letraT();
    miBT.println("Mostrando Letra T");
  }

  if (DATO == 'u') {
    letraU();
    miBT.println("Mostrando Letra U");
  }

  if (DATO == 'v') {
    letraV();
    miBT.println("Mostrando Letra V");
  }

  if (DATO == 'w') {
    letraW();
    miBT.println("Mostrando Letra W");
  }

  if (DATO == 'x') {
    letraX();
    miBT.println("Mostrando Letra X");
  }

  if (DATO == 'y') {
    letraY();
    miBT.println("Mostrando Letra Y");
  }

  if (DATO == 'z') {
    letraZ();
    miBT.println("Mostrando Letra Z");
  }
}


void apagarTodo() {
  for (int fila = 0; fila < 8; fila++) {
    for (int columna = 0; columna < 8; columna++) {
      lc.setLed(0, fila, columna, false);
    }
  }
}

void caritaFeliz() {
  byte patron[8] = {
    B00000000,
    B00000000,
    B00100100,
    B00000000,
    B00000000,
    B01000010,
    B00111100,
    B00000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void corazon() {
  byte patron[8] = {
    B00000000,
    B01100110,
    B11111111,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void flecha() {
  byte patron[8] = {
    B00010000,
    B00111000,
    B01111100,
    B11111110,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void bruh() {
  byte patron[8] = {
    B01111100,
    B01111100,
    B01100000,
    B01110000,
    B01110000,
    B01111100,
    B01111000,
    B01111100,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void xd() {
  byte patron[8] = {
    B00000010,
    B00000010,
    B10100010,
    B01001110,
    B10101110,
    B00000000,
    B00000000,
    B00000000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void sdlg() {
  byte patron[8] = {
    B00000000,
    B00000000,
    B10010001,
    B00010001,
    B00001010,
    B10001010,
    B00000100,
    B00000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void fantasmita() {
  byte patron[8] = {
    B00111100,
    B01111110,
    B11010111,
    B11111111,
    B11000011,
    B11111111,
    B11111111,
    B11011011
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void invader() {
  byte patron[8] = {
    B00100100,
    B00100100,
    B01111110,
    B11011011,
    B11111111,
    B11111111,
    B10100101,
    B00100100
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void pacman() {
  byte patron[8] = {
    B00111110,
    B01000001,
    B10010010,
    B10000100,
    B10001000,
    B10000110,
    B01000001,
    B00111110
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraA() {
  byte patron[8] = {
    B00111100,
    B01100110,
    B11000011,
    B11000011,
    B11111111,
    B11000011,
    B11000011,
    B00000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraB() {
  byte patron[8] = {
    B11111100,
    B11000110,
    B11000110,
    B11111100,
    B11000011,
    B11000011,
    B11111110,
    B00000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraC() {
  byte patron[8] = {
    B00111110,
    B01100011,
    B11000000,
    B11000000,
    B11000000,
    B01100011,
    B00111110,
    B00000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraD() {
  byte patron[8] = {
    B1111100,
    B1100110,
    B1100011,
    B1100011,
    B1100011,
    B1100110,
    B1111100,
    B0000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraE() {
  byte patterns[8] = {
    B11111111,
    B10000000,
    B10000000,
    B11111111,
    B11111111,
    B10000000,
    B10000000,
    B11111111,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patterns[fila]);
  }  
}

void letraF() {
  byte patron[8] = {
    B11111111,
    B10000000,
    B10000000,
    B11111111,
    B10000000,
    B10000000,
    B10000000,
    B10000000
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraG() {
  byte patron[8] = {
    B01111100,
    B10000000,
    B10000000,
    B10011100,
    B10000010,
    B10000010,
    B01111100,
    B00000000 
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraH() {
  byte patron[8] = {
    B10000001,
    B10000001,
    B10000001,
    B11111111,
    B11111111,
    B10000001,
    B10000001,
    B10000001,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraI() {
  byte patron[8] = {
    B11111111,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B11111111,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraJ() {
  byte patron[8] = {
    B11111111,
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B10000010,
    B01111100,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraK() {
  byte patron[8] = {
    B10001000,
    B10010000,
    B10100000,
    B11000000,
    B10100000,
    B10010000,
    B10001000,
    B10000000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraL() {
  byte patron[8] = {
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B11111111,
    B11111111,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraM() {
  byte patron[8] = {
    B10000001,
    B11000011,
    B10100101,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraN() {
  byte patron[8] = {
    B10000001,
    B11000001,
    B10100001,
    B10010001,
    B10001001,
    B10000101,
    B10000011,
    B10000001,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraO() {
  byte patron[8] = {
    B00111100,
    B01100110,
    B11000011,
    B11000011,
    B11000011,
    B11000011,
    B01100110,
    B00111100,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraP() {
  byte patron[8] = {
    B11111100,
    B11000110,
    B11000110,
    B11111100,
    B11000000,
    B11000000,
    B11000000,
    B11000000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraQ() {
  byte patron[8] = {
    B00111100,
    B01100110,
    B11000011,
    B11000011,
    B11001011,
    B01111100,
    B00100100,
    B00011111,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraR() {
  byte patron[8] = {
    B11111100,
    B11000110,
    B11000110,
    B11111100,
    B11100000,
    B11011000,
    B11001100,
    B11000110,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraS() {
  byte patron[8] = {
    B00111000,
    B01100100,
    B11000000,
    B01110000,
    B00011100,
    B00000110,
    B10000110,
    B01111000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraT() {
  byte patron[8] = {
    B11111111,
    B11111111,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraU() {
  byte patron[8] = {
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00111100,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraV() {
  byte patron[8] = {
    B10000001,
    B10000001,
    B01000010,
    B01000010,
    B00100100,
    B00100100,
    B00011000,
    B00011000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraW() {
  byte patron[8] = {
    B10000001,
    B10000001,
    B10011001,
    B10011001,
    B10100101,
    B10100101,
    B11000011,
    B11000011,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraX() {
  byte patron[8] = {
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B01000010,
    B10000001,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraY() {
  byte patron[8] = {
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}

void letraZ() {
  byte patron[8] = {
    B11111111,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01000000,
    B10000000,
    B11111111,
  };

  for (int fila = 0; fila < 8; fila++) {
    lc.setRow(0, fila, patron[fila]);
  }
}