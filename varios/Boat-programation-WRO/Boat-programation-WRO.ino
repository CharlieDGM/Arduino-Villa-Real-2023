
//this is the code for our WRO proyect: CleanBot, a boat like devide that will have autonomus functions to pick
//up trash and oscillate in the walls of a determined area. In the hardware we have UltraSonic Sensor to make
//readings of distances (and we use those readings to activate certain autonomus functions), ServoMotors to use
//our grip/grab trash sistem, a ServoMotor to control the movement of the boat and a DC Motor for the main movement

#include <SoftwareSerial.h>
#include <Servo.h>

//Bluetooth
SoftwareSerial Bluetooth(2, 3); // Bluetooth module connected to pins 2 (RX which is conected to the TX) and 3 (TX, the same but backwards xd)
char Data = 1;

//Ultrasonic sensor for Wall Detection
char trigUp = 8; 
char echoUp = 9;

//Ultrasonic sensor for Object Detection
char trigDown = 4;
char echoDown = 5;

//ServoMotor for the boat movement
Servo servoMotor; 
int forwardMotor = 100;
int rightMotor = 117;
int leftMotor = 77;

//DC motor conected to l298n
char Motor = 13;

//Servo Motors for Grip System
Servo servoGripR;
Servo servoGripL;
int ServoOnR = 86;
int ServoOffR = 0;
int ServoOnL = 0;
int ServoOffL = 86;

//States/Flags MOAI
bool UltrasonicsState = false;
bool AlgoritmsState = false;
bool ServosState = false;

void setup() {
  Serial.begin(9600); // Serial monitor for debugging
  Bluetooth.begin(9600); // Start serial communication with the Bluetooth module

 //Start the mode of the pins of the ultrasonic sensors
  pinMode(trigUp, OUTPUT);
  pinMode(echoUp, INPUT);
  pinMode(trigDown, OUTPUT);
  pinMode(echoDown, INPUT);
  
  servoMotor.attach(A0); // Servo for the movement of the boat motor
  servoMotor.write(forwardMotor); // Servo starts in a "default" position

  servoGripR.attach(A1); // Right servo for the grip system
  servoGripL.attach(A2); // Left servo for the grip system
  servoGripR.write(ServoOffR); //Servo starts in a "default" position
  servoGripL.write(ServoOffL); //Servo also starts in a "default" position

  pinMode(Motor, OUTPUT);
}

void loop() { //the loop where we call the main functions of the code
  control(); //we must call the control function to operate the boat

  if (UltrasonicsState == true) {
    sensorDown();
    sensorUp();
  }

  if (AlgoritmsState == true) { //now, if the readings functions are ON and we have active the autonomus functions it will call this functions
    Oscillate();
    WallDetector();
    TrashDetector();
  }
}

void control() { //bluetooth control, we activate flags, functions and other things based on the bluetooth input we made from our controler
  Data = Bluetooth.read();

  switch (Data) {
    case '0':
      UltrasonicsState = true;
      Bluetooth.println("Ultrasonic sensors ON, making Ultrasonic readings");
    break;

    case '1':
      UltrasonicsState = false;
      Bluetooth.println("Ultrasonic sensors OFF, not making Ultrasonic readings");
    break;

    case '8':
      AlgoritmsState = true;
      Bluetooth.println("Algorithms ON, Searching Trash");
    break;

    case '9':
      AlgoritmsState = false;
      Bluetooth.println("Algorithms OFF, Not Searching Trash");
    break;

    case '2':
      digitalWrite(Motor, LOW);
      servoMotor.write(forwardMotor);
      Bluetooth.println("Motor OFF");
    break;

    case '3':
      digitalWrite(Motor, HIGH);
      servoMotor.write(forwardMotor);
      Bluetooth.println("Motor ON, going forward");
    break;

    case '4':
      digitalWrite(Motor, HIGH);
      servoMotor.write(leftMotor);
      Bluetooth.println("Motor ON, going left");
    break;

    case '5':
      digitalWrite(Motor, HIGH);
      servoMotor.write(rightMotor);
      Bluetooth.println("Motor ON, going right");
    break;

    case '6': //the grab function of the boat, it "turns on the servos"
      if (ServosState == false) {
        servosOn();
        Bluetooth.println("Grip on");
      } else {
        Bluetooth.println("Grip already turned on");
      }
    break;

    case '7': // the same but turns off the grab function
      if (ServosState == true) {
        servosOff();
        Bluetooth.println("Grip off"); 
      } else {
        Bluetooth.println("Grip already turned off");
      }
    break;
  }
}

void servosOn() { //function just to make easy the task of turning the servos on

  //we must start in the position of the servo that we are already in
  //and we wont be there at the end of the function
  int posServoR1 = ServoOffR;
  int posServoL1 = ServoOffL;
  int moveSpeed1 = 20; //the speed we want the servos to have within each move

  //okay we use a while loop to check if the position of the servos are in the position we want
  //and if it isnt it continues moving it until they are in the wanted position

  while (posServoR1 < ServoOnR || posServoL1 > ServoOnL) { //how does this work bruh
    if (posServoR1 < ServoOnR) {
      posServoR1 += 2;
      servoGripR.write(posServoR1); //we write the position of the servo adding a little more each time
    }
    if (posServoL1 > ServoOnL) { //oooh i get it, yup this should work
      posServoL1 -= 2;
      servoGripL.write(posServoL1); //the same lol
    }
    delay(moveSpeed1); //my broda and all of that just to module the speed of the servo, yep it makes sense
  } 
  ServosState = true; //we change the state of the servos to indicate that we have the servos ON
}

void servosOff() { //the same as the last function but backwards, yep bruh
  int posServoR2 = ServoOnR;
  int posServoL2 = ServoOnL;
  int moveSpeed2 = 20;

  while (posServoR2 > ServoOffR || posServoL2 < ServoOffL) {
    if (posServoR2 > ServoOffR) {
      posServoR2 -= 2;
      servoGripR.write(posServoR2);
    }
    if (posServoL2 < ServoOffL) {
      posServoL2 += 2;
      servoGripL.write(posServoL2);
    }
    delay(moveSpeed2);
  }
  ServosState = false;
}

int sensorUp() { // Up sensor, readings of walls
  digitalWrite(trigUp, HIGH);
  delay(1);
  digitalWrite(trigUp, LOW);
  long timeUp = pulseIn(echoUp, HIGH);
  int distanceUp = timeUp / 58.2; //we convert the readings to CM
  int validDistance1 = 150;

  if (distanceUp > 0 && distanceUp < validDistance1) {
    String messageUp = "DistanceUP: " + String(distanceUp) + " CM . AnalogInputUP: " + String(timeUp) + ".";
    Serial.println(messageUp);
    return distanceUp;
  } else {
    String errorUp = "Error: Invalid distance reading - Objects Ultrasonic. Raw Reading: " + String(timeUp) + ". Raw Distance: " + String(distanceUp) + "CM.";
    Serial.println(errorUp);
    delay(200);
  }
}

int sensorDown() { // Down sensor, reading of objects/trash
  digitalWrite(trigDown, HIGH);
  delay(1);
  digitalWrite(trigDown, LOW);
  long timeDown = pulseIn(echoDown, HIGH);
  int distanceDown = timeDown / 58.2; //we convert the pulse to CM distance
  int validDistance2 = 45;

  if (distanceDown > 0 && distanceDown < validDistance2) {
    String messageDown = "DistanceDOWN: " + String(distanceDown) + " CM . AnalogInputDOWN: " + String(timeDown) + ".";
    Serial.println(messageDown); //serial messages to debugging
    return distanceDown;
  } else {
    String errorDown = "Error: Invalid distance reading - Objects Ultrasonic. Raw Reading: " + String(timeDown) + ". Raw Distance: " + String(distanceDown) + "CM.";
    Serial.println(errorDown);
    delay(200);
  }
}

void Oscillate() { //Oscillate function when no wall of trash is detected
  digitalWrite(Motor, HIGH);
  delay(20);
  digitalWrite(Motor, HIGH);
  delay(20);
  digitalWrite(Motor, HIGH);
  delay(20);
  servoMotor.write(forwardMotor);
}

void WallDetector() { //Wall reading function, makes turns when a wall is detected
  int distanceForTurn = 75;
  int timeOfTurn = 9000;

  if (sensorUp() <= distanceForTurn) {
    digitalWrite(Motor, HIGH);
    servoMotor.write(leftMotor);
    delay(20);
    digitalWrite(Motor, HIGH);
    delay(20);
    digitalWrite(Motor, HIGH);
    Bluetooth.println("Wall Detected, Making a Turn"); //makes a turn when a wall is detected, and starts a little interval
    delay(timeOfTurn);

    servoMotor.write(forwardMotor);
    digitalWrite(Motor, LOW);
    Bluetooth.println("Turn complete");
    delay(1000);
  }
}

void TrashDetector() { // Trash/Objects readings, pick ups trash when it is detected
  int distanceForGrab = 17;

  if (sensorDown() <= distanceForGrab) {
    digitalWrite(Motor, LOW);
    servoMotor.write(forwardMotor);
    Bluetooth.println("Trash detected, lifting it up");
    delay(1000);

    servosOn(); //stops the boat, turns on the grip sistem
    delay(1000);


    servosOff(); //turns off the grip sistem
    Bluetooth.println("Trash lifted up");
    delay(1000);
  }
}

//the one pieeece, the one pieceee is reaaal
//can we get much higheeer, so hiighhhh ooouuu ouououou
//AGghhhAAAahhhggggAAhhghhghggggggg
//-Demoknight TF2