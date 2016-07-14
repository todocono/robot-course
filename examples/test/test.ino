// Dim an LED using a PWM pin
int PWMpin = 10; // LED in series with 470 ohm resistor on pin 10

void setup()
{
  // no setup needed
  Serial.begin(9600);
}

void loop()
{
   for (int x=0; x <= 100; x++){
      Serial.println(x);
       tone(8,x*4,x/1);
      delay(100);
   } 
}
