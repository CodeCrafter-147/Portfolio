#include <Arduino.h>
#include <Servo.h>
Servo arm1;
Servo arm2;
#define numsensor 4
int pins[numsensor] = { A0, A1, A2, A3 };
int Max[numsensor] = { 510, 625, 990, 520 };
int Min[numsensor] = { 220, 290, 610, 274 };
unsigned long sensorValue[numsensor];
int Mid0 = (Max[0] + Min[0]) / 2;
int Mid1 = (Max[1] + Min[1]) / 2;
int Mid2 = (Max[2] + Min[2]) / 2;
int Mid3 = (Max[3] + Min[3]) / 2;
int Background = 0;
int last_value;
int last_position;
int state_ = 0;
int leftmotor, rightmotor, powermotor, error, last_error, position, output;
float Kp = 0.1;
float Kd = 2.5;
void setup() {
  Servo_setup();
  RobotSetup();
  OK();
  delay(500);
  //  Motor(200,200);
  //  delay(200);

  PidR(125);
  PidF(100);
  PidL(125);
  PidF(100);
  PidF(100);
  Stop();
   R90(20);
   Stop();
  PidL(100);
  PidS(100);  //pick up
  pick_up();

  // PidF(100);
  // PidF(100);
  // PidL(100);
}
void loop() {
  // sensorRead();
  //  Motor(0,200);
  Stop();
}
