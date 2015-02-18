/* 
	Grove_RGB_Backlight_LCD + Grove_Temperature_Sensor
	Display temperature value on LCD screen
*/



#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 0;
const int colorB = 100;

const int pinTemp = A0;      // pin of temperature sensor
float temperature;
int B = 3975;                // B value of the thermistor
float resistance;

void setup()
{
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  lcd.setRGB(colorR, colorG, colorB);

  // Print a message to the LCD.
  lcd.print("Hey Erwin");

  delay(1000);

}

void loop()
{
  int val = analogRead(pinTemp);                               // get analog value
  resistance = (float)(1023 - val) * 10000 / val;              // get resistance
  temperature = 1 / (log(resistance / 10000) / B + 1 / 298.15) - 273.15; // calc temperature
  Serial.println(temperature);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1); 
  // print the temperature:
  lcd.print(temperature);
  lcd.print(" °C ");
  delay(1000);          // delay 1s
}