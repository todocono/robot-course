int EN_M1 = 9;     //M1 Speed Control
int EN_M2 = 3;     //M2 Speed Control
int directionPin_M1A = 6;     //M1 Direction Control
int directionPin_M1B = 7;     //M1 Direction Control
int directionPin_M2A = 4;     //M1 Direction Control
int directionPin_M2B = 5;     //M1 Direction Control

void setup() {                               // Serial initialization
  pinMode(directionPin_M1A, OUTPUT);
  pinMode(directionPin_M1B, OUTPUT);
  pinMode(directionPin_M2A, OUTPUT);
  pinMode(directionPin_M2B, OUTPUT);
  pinMode(EN_M1, OUTPUT);
  pinMode(EN_M2, OUTPUT);
  digitalWrite (EN_M1, LOW);              //stops the motors
  digitalWrite (EN_M2, LOW);
  digitalWrite(directionPin_M1A, LOW);
  digitalWrite(directionPin_M1B, HIGH);
  digitalWrite(directionPin_M2A, LOW);
  digitalWrite(directionPin_M2B, HIGH);
}

void loop() {
  //do nothing
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);

  if (sensorValue1 < 450) {
    digitalWrite (EN_M1, HIGH);             //no PWM Speed Control yet
  }
  else
  {
    digitalWrite (EN_M1, LOW);             //no PWM Speed Control yet
  }
  if (sensorValue2 < 450) {
    digitalWrite (EN_M2, HIGH);             //no PWM Speed Control yet
  }
  else
  {
    digitalWrite (EN_M2, LOW);             //no PWM Speed Control yet
  }

  delay(500);                                  //WAITS FOR 2 SECONDS
}
