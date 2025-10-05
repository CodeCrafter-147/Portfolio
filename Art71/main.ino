void back() {
  motorl();
  delay(100);
  AO();
  delay(200);
  while (1) {
    if (analog(2) < L2 && analog(3) < R2) {
      AO();
      delay(300);

      break;
    } else if (analog(2) < L2 && analog(3) > R2) {
      motors(50, -60, 50, -60);
      delay(33);
      
    } else if (analog(2) > L2 && analog(3) < R2) {
      motors(-60, 50, -60, 50);
      delay(33);
      
    } else if (analog(2) > L2 && analog(3) > R2) {
      motors(-40, -42, -40, -42);
      delay(33);
    }
  }
  beep();
}
void follow() {
  while (1) {
    if (analog(4) > M1 && analog(5) > M2) {
      motorl();
    }
    if (analog(4) < M1 && analog(5) < M2) {
      AO();
      delay(100);
      beep();
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