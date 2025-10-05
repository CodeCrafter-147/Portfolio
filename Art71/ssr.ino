/*#include <POP32.h>
int L1 = 800;  //a0
int L2 = 600;  //a4
int R1 = 900;  //a1
int R2 = 600;  //a3
int M1 = 800;  //a1
int M2 = 800;
int degree = 0;
void setup() {
  servo(1, 70);
  waitSW_A_bmp();
  R90B();
  R90B();
  R90B();
  L90B();
  servo();
  motors(-70, -70, -70, -70);
  delay(420);
  L90();
  back();
  follow();
  motorl();
  delay(180); //สะพาน
  follow();
  motorl();
  delay(180);
  follow();
  motors(-70, -70, -70, -70);
  delay(200);
  AO();
  delay(300);
  R90();
  R90B();
  servo();
  back();
  motorl();
  delay(150);
  R90();
  back();
  L90B();
  L90B();
  follow();
  motors(-70, -70, -70, -70);
  delay(200);
  AO();
  L90();
  back();
  R90B();
  
  L90();
  back();
  motorl();
  delay(1000);
  R90F();
  servoF();
  motors(-70, -70, -70, -70);
  delay(200);
  R90();
  R90();
  L90B();
  servoF();  //เกือบดับรอกลับอยู่
  back();
  L90();
  back();
  motorl();
  delay(590);
  R90();
  back();
  motorl();
  delay(1100);
  L90B();
  motorl();
  delay(1050);
  R90();
  back();
  follow();
  motorl();
  delay(150);
  follow();
  motorl();
  delay(150);
  follow();
  R90B();
  R90B();
  L90B();
  L90B();
  L90B();
  follow();
}

void loop() {
  read();
  AO();
}
*/