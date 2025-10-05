
void servo() {
  degree=0;
  while (1) {
    if (analog(4) > L1 && analog(5) > R1) {
      motorl();
    } else if (analog(4) < M1 && analog(5) < M2) {
      AO();
      delay(200);
      servo(1, 90);
      delay(300);
      servo(1, 0);
      delay(300);
      while (!(degree >= 80)) {
        degree += 40;
        delay(80);
        servo(1, degree);
      }
      AO();
      delay(200);
      break;
    }
    if (analog(0) < L1 && analog(1) > R1) {
      motorL();
    } else if (analog(0) > L1 && analog(1) < R1) {
      motorR();
    }
    if (analog(4) < M1 && analog(5) > M2) {
      motorR();
    } else if (analog(4) > M1 && analog(5) < M2) {
      motorL();
    }
  }
  beep();
}
void servoF() {
   degree=0;
   
  while (1) {
    if (analog(4) > L1 && analog(5) > R1) {
      motorl();
    }
    if (analog(4) < M1 && analog(5) < M2) {
      motors(-70, -70, -70, -70);
  delay(300);
      AO();
      delay(100);
      servo(1, 90);
      delay(300);
      servo(1, 0);
      delay(300);
      while (!(degree >= 80)) {
        degree += 40;
        delay(80);
        servo(1, degree);
      }
      AO();
      delay(200);
      break;
    }
    if (analog(0) < L1 && analog(1) > R1) {
      motorL();
    } else if (analog(0) > L1 && analog(1) < R1) {
      motorR();
    }
    if (analog(4) < M1 && analog(5) > M2) {
      motorR();
    } else if (analog(4) > M1 && analog(5) < M2) {
      motorL();
    }
  }
  beep();
}