void Turn(int Bspeed, int degree) {
    setYawZero();
  while (true) {
    updateYaw();
    float error = degree - yaw;
    if (error > 180) error -= 360;
    if (error < -180) error += 360;

    // จำกัดความแรงไม่เกิน farSp
  int left = (Bspeed + error);
  int right = (Bspeed - error);
    Motor(left, right);  // หมุนตามค่า PID เลย ไม่ต้องค่อย ๆ ลดความเร็ว
if(degree>0){
    if (abs(error) < 15) {
      Motor(-100, 100);
      delay(40);
      Motor_STOP();
      break;
    }
    delay(10);}
    else if(degree<0){
      if (abs(error) < 20) {
      Motor(100, -100);
      delay(20);
      Motor_STOP();
      break;
    }
    }
  }
  AO();
    delay(200);
}