void motors(int m1, int m2, int m3, int m4) {
  motor(1, m1);  //ซ้าย
  motor(2, m2);  //ขวา
  motor(3, m3);  //ซ้าย
  motor(4, m4);  //ขวา
}
void motorR90() {
  motors(100, -100, 100, -100);
  delay(270);
  AO();
  delay(300);
}
void motorL90() {
  motors(-100, 100, -100, 100);
  delay(250);
  AO();
  delay(300);
}
void motorL() {
  motors(40, 0, 40, 0);
}
void motorR() {

  motors(0, 40, 0, 40);
}
void motorl() {
  motors(70, 79, 75, 75);
}