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
AF_DCMotor motor1(1, MOTOR12_1KHZ);     // Create motor Object at port 1, with frequency
AF_DCMotor motor2(2, MOTOR12_1KHZ);     // Create motor Object at port 2, with frequency

Servo ballservo;                                                // Servo Object
rgb_lcd lcd;                                                       // LCD object

const int buttonPin = 2;                                     // Enige ongebruikte pin op arduino shield
int buttonstate = 0;
int pos = 90;
int dela = 10;                                                      // delay variabele om het eenkeer aan te passen

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Hello MoTo");
  ballservo.attach(10);                                        // Servo  SER1 on Motorshield == arduino pin10 || SER_2 == pin9
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  lcd.begin(16, 2);
  lcd.setRGB(0, 0, 0);
  lcd.print("Hello");
}

void loop() {
  Serial.println("Going Forward!");
  buttonstate = digitalRead(buttonPin);
  if (buttonstate == HIGH) {
    servomove();
    runrun();
    /*
    for(int i=3; i>=0; i--){
        lcd.setCursor(0,0);
        lcd.print("Balls left");
        lcd.print(i);
      */
  }
  Serial.println("Wait 3 sec");
  delay(3000);
  buttonstate = 0;
}
}

void runrun() {
  Serial.print("\n");
  Serial.print("Go!");
  motor1.run(FORWARD);                                     // turn it on going forward
  motor2.run(BACKWARD);                                   // turn it on going forward
  delay(2000);
  Serial.print("Stop!");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void servomove() {
  for (pos = 0; pos <= 90; pos += 1)                 // goes from 0 degrees to 180 degrees in steps of 1 degree
  {
    ballservo.write(pos);                                   // tell servo to go to position in variable 'pos'
    delay(dela);                                                   // waits 5ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1)             // goes from 180 degrees to 0 degrees
  {
    ballservo.write(pos);                                  // tell servo to go to position in variable 'pos'
    delay(dela);                                               // waits 5ms for the servo to reach the position
  }
}
