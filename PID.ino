int sensor(int i) {
  int x;
  x = map(analogRead(i), Min[i], Max[i], 0, 1000);
  if (x > 900) x = 1000;
  else if (x < 400) x = 0;
  return x;
}
long Position() {
  unsigned long i;
  unsigned long sum;
  unsigned long avg;
  int value;
  bool online;
  sum = 0;
  avg = 0;
  for (i = 0; i < numsensor; i++) {
    value = sensor(i);
    avg += value * (i * 1000);
    sum += value;
    if (sum >= 100) online = true;
    else online = false;
  }
  if (online == false) {
    if (last_position >= ((numsensor - 1) * 1000) / 2) return (numsensor - 1) * 1000;
    else return 0;
  } else last_position = avg / sum;
  return last_position;
}
void Pid(int BaseSpeed) {
  error = Position() - 1500;
  output = (error * Kp) + ((error - last_error) * Kd);
  last_error = error;
  leftmotor = BaseSpeed - output;
  rightmotor = BaseSpeed + output;
  leftmotor = constrain(leftmotor, -255, 255);
  rightmotor = constrain(rightmotor, -255, 255);
  Motor(leftmotor, rightmotor);
}
void Pid_Time(int BaseSpeed, unsigned long Time) {
  unsigned long TT = millis();
  while (millis() - TT <= Time) {
    Pid(BaseSpeed);
  }
}
void PidF(int BaseSpeed) {
  while (true) {
    if (analogRead(0) < Mid0 && analogRead(3) < Mid3 ) {
      W();
      break;
    }
    Pid(BaseSpeed);
  }}
void PidS(int BaseSpeed) {
  while (true) {
    if (analogRead(0) < Mid0 && analogRead(3) < Mid3 ) {
      
      Motor(0,0);
      delay(50);
      break;
    }
    Pid(BaseSpeed);
  }}
  void PidR(int BaseSpeed) {
  while (true) {
    if (analogRead(0) < Mid0 && analogRead(3) < Mid3) {
      Motor(125,125);
      delay(50);
        R();
      break;
    }
    Pid(BaseSpeed);
  }}
  void PidL(int BaseSpeed) {
  while (true) {
    if (analogRead(0) < Mid0 && analogRead(3) < Mid3) {
        Motor(125,125);
  delay(50);
  L();
      break;
    }
    Pid(BaseSpeed);
  }}
