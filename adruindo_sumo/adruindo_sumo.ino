#define EnableLeft 10
#define EnableRight 11

#define MotorLeft1 8
#define MotorLeft2 9
#define MotorRight1 13
#define MotorRight2 12

#define echoPin 6 // listen to distance
#define triggerPin 7 // Start echo

#define LineSensor1 2
#define LineSensor2 3

void setup() {
 pinMode(EnableLeft, OUTPUT);
 pinMode(EnableRight, OUTPUT);
 
 pinMode(MotorRight1, OUTPUT);
 pinMode(MotorRight2, OUTPUT);
 pinMode(MotorLeft1, OUTPUT);
 pinMode(MotorLeft2, OUTPUT);
 
 pinMode(LineSensor1, INPUT);
 pinMode(LineSensor2, INPUT);
 
 pinMode(triggerPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 stop();
 Serial.begin(9600);
}

void loop() {
  listenToSerialInputMotors();
  
  int distance = getDistance(200);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  boolean val1 = digitalRead(LineSensor1); // read the input pin
  Serial.print("Sensor1: ");
  Serial.println(val1);   
  
  boolean val2 = digitalRead(LineSensor2); // read the input pin
  Serial.print("Sensor2: ");
  Serial.println(val2);  
}

void listenToSerialInputMotors() {
  if (Serial.available()) {
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

int getDistance(int delayBetweenMeasures) {
  digitalWrite(triggerPin, LOW);
  delay(delayBetweenMeasures);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034/2;
}
