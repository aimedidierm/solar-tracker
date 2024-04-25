#include <Servo.h>

Servo servoX, servoY;
int LDR1 = A0, LDR2 = A1, LDR3 = A2, LDR4 = A3;
int rRDL1 = 0, rRDL2 = 0, rRDL3 = 0, rRDL4 = 0;
int maxTop = 30, maxBot = 30, maxRight = 200, maxLeft = 200;
int angleX = 80, angleY = 0;
int clockwise = 0, stop = 90, anticlockwise = 180;

void setup() {
  // Attaching the servos to pins
  servoX.attach(9);   // MG996 servo
  servoY.attach(10);  // MG995 servo

  // Starting the serial communication
  Serial.begin(9600);
}

void loop() {
  // Reading and scaling the values from LDRs
  rRDL1 = analogRead(LDR1);
  rRDL2 = analogRead(LDR2);
  rRDL3 = analogRead(LDR3);
  rRDL4 = analogRead(LDR4);

  int avgtop = (rRDL4 + rRDL3) / 2;    //average of top LDRs
  int avgbot = (rRDL1 + rRDL2) / 2;    //average of bottom LDRs
  int avgleft = (rRDL4 + rRDL1) / 2;   //average of left LDRs
  int avgright = (rRDL3 + rRDL2) / 2;  //average of right LDRs
  int difTop = avgtop - avgbot;
  int difBot = avgbot - avgtop;
  int difRight = avgright - avgleft;
  int difLeft = avgleft - avgright;

  if (avgtop < avgbot && difBot > maxBot) {
    servoX.write(clockwise);
    delay(8);
  } else if (avgbot < avgtop && difTop > maxTop) {
    servoX.write(anticlockwise);
    delay(8);
  } else {
    servoX.write(stop);
  }

  if (avgright < avgleft && difLeft > maxLeft) {
    servoY.write(anticlockwise);
    delay(8);
  } else if (avgleft < avgright && difRight > maxRight) {
    servoY.write(clockwise);
    delay(8);
  } else {
    servoY.write(stop);
  }
}
