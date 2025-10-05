void read() {
  oled.text(0, 0, "s0=%d  ", analog(0));
  oled.text(1, 0, "s1=%d  ", analog(1));
  oled.text(2, 0, "s2=%d  ", analog(2));
  oled.text(3, 0, "s3=%d  ", analog(3));
  oled.text(4, 0, "s4=%d  ", analog(4));
  oled.text(5, 0, "s5=%d  ", analog(5));
 /* oled.text(6, 0, "s6=%d  ", analog(6));
  oled.text(7, 0, "s7=%d  ", analog(7));
  oled.text(8, 0, "s8=%d  ", analog(8));*/
  oled.show();
}