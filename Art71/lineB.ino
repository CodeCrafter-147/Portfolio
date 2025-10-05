void R90B() {
  while (1) {
    if (analog(4) > L1 && analog(5) > R1) {
      motorl();
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
    if (analog(4) < M1 && analog(5) < M2) {
      AO();
      delay(300);
      motors(-70, -70, -70, -70);
      delay(130);
      AO();
      delay(300);
      motorR90();
      break;
    }
  }
  beep();
  back();
}
void L90B() {
  while (1) {
    if (analog(4) > L1 && analog(5) > R1) {
      motorl();
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
    if (analog(4) < M1 && analog(5) < M2) {
      AO();
      delay(300);
      motors(-70, -70, -70, -70);
      delay(150);
      AO();
      delay(300);
      motorL90();
      break;
    }
  }
  beep();
  back();
}