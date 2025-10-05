#include <POP32.h>
int L1 = 600;  //a0
int L2 = 600;  //a4
int R1 = 600;  //a1
int R2 = 600;  //a3
int M1 = 600;  //a1
int M2 = 600;
int degree = 0;
void setup() {
  servo(1, 80);
  rov();
}

void loop() {
  // read();
  AO();
}
