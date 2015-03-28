#include <AFMotor.h>
/*
    Channel 1 & 2                Channel 3 & 4
    MOTOR12_64KHZ          MOTOR34_64KHZ
    MOTOR12_8KHZ            MOTOR34_8KHZ
    MOTOR12_2KHZ            MOTOR34_1KHZ
    MOTOR12_1KHZ

*/
AF_DCMotor motor1(1, MOTOR12_64KHZ);     // Create motor Object at port 1, with frequency
AF_DCMotor motor2(2, MOTOR12_64KHZ);     //

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("Hello MoTo");
motor1.setSpeed(255);
motor2.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.print("Going Forward!")
 Serial.print("\n")
 motor1.run(FORWARD); // turn it on going forward
 motor2.run(FORWARD); // turn it on going forward
 delay(1000);
}
