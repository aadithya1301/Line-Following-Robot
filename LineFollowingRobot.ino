#define IRSENSOR_RIGHT 11
#define IRSENSOR_LEFT  12

#define MOTOR_SPEED 180

const int RightMotor = 6;
const int rightMotorPin1   = 7;
const int rightMotorPin2   = 8;

const int LeftMotor = 5;
const int leftMotorPin1   = 9;
const int leftMotorPin2   = 10;

void setup() {
  pinMode(RightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(LeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IRSENSOR_RIGHT, INPUT);
  pinMode(IRSENSOR_LEFT, INPUT);

  rotateMotor(0, 0);
}

void loop() {
  int rightIR = digitalRead(IRSENSOR_RIGHT);
  int leftIR  = digitalRead(IRSENSOR_LEFT);

  if (rightIR == LOW && leftIR == LOW) {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  } 
  else if (rightIR == HIGH && leftIR == LOW) {
    rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);
  } 
  else if (rightIR == LOW && leftIR == HIGH) {
    rotateMotor(MOTOR_SPEED, -MOTOR_SPEED);
  } 
  else {
    rotateMotor(0, 0);
  }
}

void rotateMotor(int rightSpeed, int leftSpeed) {
  if (rightSpeed > 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightSpeed < 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  if (leftSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else if (leftSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  analogWrite(RightMotor, abs(rightSpeed));
  analogWrite(LeftMotor, abs(leftSpeed));
}
