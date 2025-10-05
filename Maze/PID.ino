void PIDGy(int Bspeed) {
  setYawZero();
  while (1) {
    trackgyro(Bspeed);
    if (readSensor(1) < FRONT_THRESHOLD) {
      Motor(-Bspeed,-Bspeed);
      delay(5);
      AO();
      delay(300);
      break;
    }
  }
  //       Turn(100,-90);
}
void GO(int Bspeed,int TotalTime) {
  unsigned long StartTime = millis();
  unsigned long EndTime = StartTime + TotalTime;
  while (millis() <= EndTime) {
   Motor(Bspeed+10,Bspeed-10);
    if (analog(1) > FRONT_THRESHOLD) {
      Motor(-Bspeed,-Bspeed);
      delay(20);
      AO();
      delay(100);
      break;
    }
  }
  //       Turn(100,-90);
}
void wall(int idx, int Bspeed, float kp, float ki, float kd){
  while(1){
  trackWall( idx, Bspeed, kp, ki,kd);
  if(readSensor(1) < FRONT_THRESHOLD ){
 Motor(-50, 50);
 delay(10);
  }
  }

}