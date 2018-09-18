
#include <Arduino.h>

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
volatile long count = 0;
volatile float time = 0;

void blink_rising()
{
  // state = !state;
  if (state == LOW)
  {
    state = HIGH;
    count = count + 1;
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
  //count += 1;
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink_rising, RISING);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), blink_falling, FALLING);
  Serial.begin(9600);
  // count = millis();
}

void loop()
{
  digitalWrite(ledPin, state);
  //count=0;
}