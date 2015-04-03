#include <rgb_lcd.h>
#include <Wire.h>
#include <Servo.h>
#include <AFMotor.h>
/*
    Channel 1 & 2                Channel 3 & 4
    MOTOR12_64KHZ          MOTOR34_64KHZ
    MOTOR12_8KHZ            MOTOR34_8KHZ
    MOTOR12_2KHZ            MOTOR34_1KHZ
    MOTOR12_1KHZ

*/
AF_DCMotor motor1(1, MOTOR12_64KHZ);     				// Create motor Object at port 1, with frequency
AF_DCMotor motor2(2, MOTOR12_64KHZ);     				// Create motor Object at port 2, with frequency

Servo ballservo;                                        // Servo Object
rgb_lcd lcd;                                            // LCD object

const int buttonPin = 2;                                // Enige ongebruikte pin op arduino shield
int buttonstate = 0;                                      // buttonstate
int pos = 0;                                                // Position servo
int ServoDelay = 10;                                    // delay variabele om het eenkeer aan te passen
int teller = 3;                                                // begin value servo 

void setup() {
  pinMode(buttonPin, INPUT);                     // Button pin 
  Serial.begin(9600);                                 // Begin Serial communication voor debugging
  Serial.println("Hello MoTo");                    // Print 
  ballservo.attach(10);                                // Servo  SER1 on Motorshield == arduino pin10 || SER_2 == pin9
  motor1.setSpeed(100);                            // Set motor1 speed
  motor2.setSpeed(100);                            // Set motor2 speed
  lcd.begin(16, 2);                                       // Begin LCD.screen
  lcd.setRGB(0, 0, 255);                             // LCD color
  lcd.setCursor(0, 0);                                  // Set Cursor
  lcd.print("Hello");                                      // Print "Hello" to LCD
}

void loop() {
  Serial.println("Going Forward!");            // Debugging 
  lcd.setCursor(0, 0);                                 // Set Cursor LCD
  buttonstate = digitalRead(buttonPin);     // Read Button State

  if (teller == 0) {
    Serial.print("Start Teller");                    // Debugging
    lcd.clear();                                            // Clear LCD screen
    lcd.setCursor(0, 0);                              // Place Crusor
    lcd.print("RELOAD! RELOAD!");          // Print Message 
    teller = 3;                                              // Reset counter to 3 
    delay(1000);                                         // delay
    lcd.clear();                                            // Clear LCD
    Serial.print("END Teller");                    // Debugging
  }
  else {
    if (buttonstate == HIGH) {                      // If button pressed 
      servomove();                                      // Run servomove see bottom
      runrun();                                            // Run runrun see bottom
      Serial.println("teset");                       // Debugging
      lcd.clear();                                         // Clear LCD
      teller--;                                              // substract 1 from teller
      lcd.setCursor(1, 0);                            // set cursor to row 2
      lcd.print("Ball Count ");                       // print to lcd
      lcd.print(teller);                                    // print to lcd
      Serial.println("Wait 3 sec");                // debugging
      delay(3000);                                            // delay
      buttonstate = 0;                                   // reset buttonstate
    }
  }
}

void runrun() {
  Serial.print("\n");                        // debugging
  Serial.print("Go!");                    // debugging
  motor1.run(FORWARD);                                  // turn it on going forward
  motor2.run(BACKWARD);                                 // turn it on going forward
  delay(2000);
  Serial.print("Stop!");                                        // debugging
  motor1.run(RELEASE);                                   // stop motor     
  motor2.run(RELEASE);                                   // stop motor
}

void servomove() {
  for (pos = 0; pos <= 90; pos += 1)                    // goes from 0 degrees to 180 degrees in steps of 1 degree
  {
    ballservo.write(pos);                               // tell servo to go to position in variable 'pos'
    delay(ServoDelay);                                  // waits 5ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1)                    // goes from 180 degrees to 0 degrees
  {
    ballservo.write(pos);                               // tell servo to go to position in variable 'pos'
    delay(ServoDelay);                                  // waits 5ms for the servo to reach the position
  }
}
