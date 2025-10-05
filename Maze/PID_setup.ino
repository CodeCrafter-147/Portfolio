// void trackWall(int idx, int Bspeed, float kp, int kd) {
//   int sensorRaw = readSensor(idx);
//   int irDist = constrain(map(sensorRaw, 0, 8190, 0, 1000), 0, 80);
//   error = irDist - CENTER_IR;
//   output = kp * error + kd * (error - last_error);
//   last_error = error;
//   Motor(Bspeed - output, Bspeed + output);
//   // Serial.println(error);

// }
void trackWall(int idx, int Bspeed, float kp, float ki, float kd) {
  static float integral = 0;  // บวกสะสมค่า error

  int sensorRaw = readSensor(idx);
  int irDist = constrain(map(sensorRaw, 0, 8190, 0, 1000), 0, 80);

  error = irDist - CENTER_IR;

  float derivative = error - last_error;
  integral += error;

  output = kp * error + ki * integral + kd * derivative;

  output = constrain(output, -100, 100);
  last_error = error;

  Motor(Bspeed + output, Bspeed - output);
}
float previousError = 0.0;
float Kp = 1.5;  // ค่าคงที่ P
float Kd = 0.8;  // ค่าคงที่ D

void trackgyro(int Bspeed) {
  updateYaw();
  float error = 0 - yaw;
  if (error > 180) error -= 360;
  if (error < -180) error += 360;
  float proportional = Kp * error;
  float derivative = Kd * (error - previousError);
  int left = Bspeed + proportional + derivative;
  int right = Bspeed - proportional - derivative;
  left = constrain(left, -100, 100);
  right = constrain(right, -100, 100);
  Motor(left, right);
  previousError = error;
}