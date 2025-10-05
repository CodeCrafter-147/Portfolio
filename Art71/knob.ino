
void rov() {
  servo(1, 80);
  while (1) {
    oled.text(0, 0, "%d  ", knob(3));
    oled.show();
    if (SW_A() == 1) {
      while (1) {
        if (knob(3) == 1) {
motorl();
  delay(450);
  L90();
  follow();
  back();
  R90();
  motorl();
  delay(450);
  L90();
  servo();
  back();
  R90();
  L90B();
  motorl();
  delay(1000);
  L90B();
  R90F();
  R90B();
  R90B();
  L90B();
  L90B();
  L90B();
  servo();
 motors(-70, -70, -70, -70);
  delay(420);
  R90();
  R90();
  R90B();
  R90B();
  R90B();
  L90B();
  motorl();
  delay(600);
  L90();
  back();
  motorl();
  delay(590);R90();back();servo();
  back();
  L90();
  motorl();
  delay(460);
  L90();
  R90B();
  servo();motors(-70, -70, -70, -70);
  delay(420);back();R90();
  motorl();
  delay(700);
  L90();
  L90F();
  R90B();
  motorl();
  delay(1000);
  R90B();
  follow();

          break;
        } else if (knob(3) == 2) {
          R90F();
          R90F();
          R90F();
          L90B();
          L90B();

          R90F();
          break;
        } else if (knob(3) == 1) {
          beep();
          sleep(200);
          beep();
          sleep(200);
          beep();
          sleep(200);
          break;
        }
      }
    }
  }
}