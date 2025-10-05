void pick_up() {
  arm1.write(0);
  delay(500);
  arm2.write(0);
  delay(500);
  Stop();
  Motor(125,125);
  delay(200);
  Stop();
  arm2.write(70);
  delay(500);
  arm1.write(90);
  delay(500);
}