void Motor(int l, int r) {
  motor(1, constrain(l, -100, 100));
  motor(2, constrain(r, -100, 100));
}

void Motor_STOP() {
  AO();
  delay(100);
}

void Move(int l, int r, int d) {
  Motor(l, r);
  delay(d);
}
void L(){
Motor(-100,100);
delay(110);
// Motor(50, -500);
      // delay(10);
      Motor_STOP();
      delay(100);

}

void L45(){
Motor(-100,100);
delay(10);
// Motor(50, -500);
      // delay(10);
      Motor_STOP();
      delay(100);

}

void R(){
  Motor(100,-100);
delay(80);
// Motor(-50, 50);
      // delay(10);
      Motor_STOP();
      delay(100);
}

void R45(){
  Motor(100,-100);
delay(10);
// Motor(-50, 50);
      // delay(10);
      Motor_STOP();
}