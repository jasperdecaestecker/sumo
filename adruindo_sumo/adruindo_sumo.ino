#define EnableLeft 10
#define EnableRight 11

#define MotorLeft1 8
#define MotorLeft2 9
#define MotorRight1 13
#define MotorRight2 12

void setup() {
 pinMode(EnableLeft, OUTPUT);
 pinMode(EnableRight, OUTPUT);
 
 pinMode(MotorRight1, OUTPUT);
 pinMode(MotorRight2, OUTPUT);
 pinMode(MotorLeft1, OUTPUT);
 pinMode(MotorLeft2, OUTPUT);
 
 stop();
 Serial.begin(9600);
}

void loop() {
if (Serial.available())
  {
   char character = Serial.read();
    if(character == 'f') {
      Serial.println("Going forward");
      forwards();
    } 
    if(character == 'b') {
      Serial.println("Going backward");
      backwards();
    }
    if(character == 's') {
      Serial.println("Stopping");
      stop();
    }
    if(character == 'l') {
      Serial.println("Turning left");
      turnLeft();
    }
    if(character == 'r') {
      Serial.println("Turning right");
      turnRight();
    }
  }
}

void forwards() {
  enableMotors();
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
}

void backwards() {
  enableMotors();
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
}

void turnLeft() {
  enableMotors();
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
}

void turnRight() {
  enableMotors();
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
}

void enableMotors() {
  digitalWrite(EnableLeft, HIGH);
  digitalWrite(EnableRight, HIGH);
}

void disableMotors() {
  digitalWrite(EnableLeft, LOW);
  digitalWrite(EnableRight, LOW);
}

void stop() {
  disableMotors();
}
