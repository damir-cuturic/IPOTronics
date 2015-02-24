#include <Wire.h>
#include "rgb_lcd.h"

const int potentiometer = A0;

rgb_lcd lcd;

int red;
int green;
int blue;

int pin1 = 0;
//int pin2=1;

void setup()
{
  Serial.begin(9600);        // set the serial communication frequency at 9600 bits per sec
  pinMode(potentiometer, INPUT);
  lcd.begin(16, 2);
  lcd.print("I change colors!");

}

void loop()
{
  red = analogRead(pin1);
  red /= 12;
  green = red - 85;

  green = analogRead(pin1);
  blue = green - 170;

  lcd.setRGB(red, green, blue);
  Serial.println(blue);
  delay(1000);
}


