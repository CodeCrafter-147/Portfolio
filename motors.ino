// DO NOT EDIT //

  #define PWMA 3
  #define AIN1 2
  #define AIN2 4

  #define PWMB 5
  #define BIN1 6
  #define BIN2 7

void Motor1(int speedmotor2) {
  bool dir2 = (speedmotor2 >= 0 ? true : false);
  speedmotor2 = abs(speedmotor2);
  if (speedmotor2 > 255) {
    speedmotor2 = 255;
  }
  digitalWrite(BIN1, dir2);
  digitalWrite(BIN2, !dir2);
  analogWrite(PWMB, speedmotor2);
}
void Motor2(int speedmotor1) {
  bool dir1 = (speedmotor1 >= 0 ? true : false);
  speedmotor1 = abs(speedmotor1);
  if (speedmotor1 > 255) {
    speedmotor1 = 255;
  }
  digitalWrite(AIN1, dir1);
  digitalWrite(AIN2, !dir1);
  analogWrite(PWMA, speedmotor1);
}


void Motor(int leftsp, int rightsp) {
  Motor1(leftsp);
  Motor2(rightsp);
}

void Stop() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}
void R90(int Time){
  unsigned long TT = millis();
  while (millis() - TT <= Time) {
    Motor(100,-110);
  }
}
void L90(int Time){
  unsigned long TT = millis();
  while (millis() - TT <= Time) {
    Motor(-110,100);
  }
}
void R(){
  while(1){
    if(analogRead(2) > Mid2 || analogRead(3) > Mid3){
      R90(1);
    }
    else if(analogRead(2) < Mid2 && analogRead(3) < Mid3){
      Stop();
      break;
    }
  }
}
void L(){
  while(1){
    if(analogRead(1) > Mid1 || analogRead(0) > Mid0){
      L90(1);
    }
    else if(analogRead(1) < Mid1&& analogRead(0) < Mid0){
      Stop();
      break;
    }
  }
}
void W(){
  while(1){
    if(analogRead(0) < Mid0 && analogRead(3) < Mid3){
      Motor(135,130);
    }
    else if(analogRead(1) > Mid1&& analogRead(0) > Mid0){
      Pid_Time(100,50);
      Stop();
      break;
    }
  }
}


