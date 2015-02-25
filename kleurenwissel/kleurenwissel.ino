#include <Wire.h>
#include "rgb_lcd.h"

const int potentiometer = A0;      

rgb_lcd lcd;

int red;
int green;
int blue;

int pin1 = 0;

void setup()
{
  Serial.begin(9600);               // set the serial communication frequency at 9600 bits per sec
  pinMode(potentiometer, INPUT);
  lcd.begin(16, 2);
  lcd.print("I change colors!");
}

void loop()
{
  red = analogRead(pin1);
  red /= 12;                      // convert value from 0-1023 to 0-255 (red/4); and divides the range in 3 equal parts (3 * 4 = 12)
  green = red - 85;               // green = red - (1024/12)
//green = analogRead(pin1);       // overblijfsel uit eerdere probeersels, negeer deze regel
  blue = green;
//blue = green - 85;              // overblijfsel uit eerdere probeersels, negeer deze regel

  lcd.setRGB(red, green, blue);
//Serial.println(blue);           // bekijk de waarden van de kleur terwijl je draait, red|green|blue, onderstaande weergeeft het direct op het LCDscherm
  lcd.setCursor(0, 1);
  lcd.print(red);
  lcd.print("|");
  lcd.print(green );
  lcd.print("|");
  lcd.print(blue);
  delay(100);
}


