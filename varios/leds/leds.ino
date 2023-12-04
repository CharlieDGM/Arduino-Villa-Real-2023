int LedTrasero = 4;
int LedAdelante = 5;

void setup() {
  pinMode(LedTrasero, OUTPUT);
  pinMode(LedAdelante, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Leds();
}

void Leds() {
  digitalWrite(LedTrasero, HIGH);
  digitalWrite(LedAdelante, LOW);
  delay(1000);
  digitalWrite(LedAdelante, HIGH);
  digitalWrite(LedTrasero, LOW);
  delay(1000);
}