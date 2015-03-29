#include <AFMotor.h>
/*
    Channel 1 & 2                Channel 3 & 4
    MOTOR12_64KHZ          MOTOR34_64KHZ
    MOTOR12_8KHZ            MOTOR34_8KHZ
    MOTOR12_2KHZ            MOTOR34_1KHZ
    MOTOR12_1KHZ

*/
AF_DCMotor motor1(1, MOTOR12_64KHZ);     // Create motor Object at port 1, with frequency
AF_DCMotor motor2(2, MOTOR12_64KHZ);     // Create motor Object at port 2, with frequency
const int buttonPin = 2; // set
int buttonstate = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.print("Hello MoTo");
  Serial.print("\n");
  motor1.setSpeed(255);
  motor2.setSpeed(255);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Going Forward!");
  buttonstate = digitalRead(buttonPin);
  if (buttonstate == HIGH) {
    runrun();
    Serial.println("Wait 3 sec");
    delay(3000);
    buttonstate = 0;
  }
}

void runrun() {
  Serial.print("\n");
  Serial.print("Go!");
    motor1.run(FORWARD); // turn it on going forward
    motor2.run(BACKWARD); // turn it on going forward
  delay(2000);
  Serial.print("Stop!");
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
