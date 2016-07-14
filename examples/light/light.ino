// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
   int sensorValue1 = analogRead(A0);
   int sensorValue2 = analogRead(A1);
   Serial.println(sensorValue1);
   Serial.println(sensorValue2);
   delay(500);
}
