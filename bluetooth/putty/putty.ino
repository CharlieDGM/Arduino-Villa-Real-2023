char DATO = 0;
int LEDROJO = 2;
int LEDVERDE = 3;

void setup() {
  Serial.begin(38400);  // Start the Serial communication
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    DATO = Serial.read();  // Read the incoming character from PuTTY

    if (DATO == '1') {
      digitalWrite(LEDROJO, HIGH);  // Turn on the red LED
      Serial.println("Red LED ON");  // Send a confirmation message
    }

    if (DATO == '2') {
      digitalWrite(LEDROJO, LOW);   // Turn off the red LED
      Serial.println("Red LED OFF");  // Send a confirmation message
    }

    if (DATO == '3') {
      digitalWrite(LEDVERDE, HIGH); // Turn on the green LED
      Serial.println("Green LED ON");  // Send a confirmation message
    }

    if (DATO == '4') {
      digitalWrite(LEDVERDE, LOW);  // Turn off the green LED
      Serial.println("Green LED OFF");  // Send a confirmation message
    }
  }
}
