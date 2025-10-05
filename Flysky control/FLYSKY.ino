#include <POP32.h>
long int ch1;
long int ch2;
long int ch3;
long int ch4;
long int ch5;
long int ch6;
#define MR map(ch3, 1020, 2000, 100, -100)
#define ML map(ch1, 1000, 1990, 100, -100)
#define up 90
#define down 15
#define keep 140
#define arr 20
int degree1,degree2;
void setup() {
  pinMode(0,INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);   
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  servo(0, 90);
  delay(200);
  servo(1, 90);
}
void setmotor(int ml, int mr) {
  int motorL, motorR;
   
  motorL = constrain(ml, -40, 40);//เร็ว ช้า :ซ้าย
  motorR = constrain(mr, -40, 40);//เร็ว ช้า :ขวา
  if (motorL > -40 && motorL < 40) {//ช่วง0
    motorL = 0;
  }
  if (motorR > -40 && motorR < 40) {//ช่วง0
    motorR = 0;
  }
    if (ch3 > 1900) {
    motorR = -40;
    motorL = -40;
  }
  else if(ch3 < 1100) {
    motorR = 40;
    motorL = 40;
  }
  else  if (ch1 > 1900) {
    motorR = 40;
    motorL = -40;
  }
  else if(ch1 < 1100) {
    motorR = -40;
    motorL = 40;
  }
  motor(1, motorL);
  motor(2, motorR);
  motor(3, motorL);
  motor(4, motorR);
  if (ch5 < 1100) {
    degree1=90;
  }           
  else if (ch5 > 1900) {
    degree1=0;
  }
 if (ch6 < 1100) { 
    degree2=70;
  }           
  else if (ch6 > 1900) {
    degree2=0 ;
  }
 servo(0,degree1);
  servo(1,degree1);
  servo(2,degree2);
  servo(3,degree2);
}
void loop() {
  ch1 = pulseIn(0, HIGH, 35000);
  ch3 = pulseIn(1, HIGH, 35000);
  ch5 = pulseIn(2, HIGH, 35000);
  ch6 = pulseIn(3, HIGH, 35000);
  //  oled.text(1, 0, "MR_ch5= %d   ", ch5);
  // oled.text(2, 0, "ML_ch6= %d   ", ch6);
  // oled.text(3, 0, "MR_ch1= %d   ", ch2);
  // oled.text(4, 0, "ML_ch3= %d   ", ch3);
  // oled.show();
  setmotor(ML, MR);
}