#include <klasser.h>
#include <Arduino.h>

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
Tomat plante1;
blinkWidget blinker1;
void loop()
{
  // turn the LED on (HIGH is the voltage level)

  plante1.setVand(10.0);
  plante1.getVand();
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a second
  delay(1000);
  blinker1.setBlink(1);
  Serial.println(blinker1.getBlink());
}