/*
* This code tested (and worked) with XYC-WB-ВС Moving Sensor
* For work this sensor connect
* (+) on sensor - to 5V on Arduino
* (-) on sensor - to GND on Arduino
* (Data or Output) on sensor - to digital pin 2 on Arduino
*/

#include <Arduino.h>

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
volatile float time = 0;

void blink_rising()
{
  if (state == LOW)
  {
    state = HIGH;
  }
  else
  {
    state = LOW;
  }
  time = millis();
  if (time >= 60000)
  {
    Serial.print("In minute: ");
    time = time / 60000;
  }
  else
  {
    Serial.print("In second: ");
    time = time / 1000;
  }

  Serial.print(time);
  Serial.print(" : ");
  Serial.println(digitalRead(interruptPin));
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink_rising, RISING);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(ledPin, state);
}