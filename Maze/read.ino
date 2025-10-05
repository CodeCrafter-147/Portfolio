void updateYaw() {
  mpu.update();  // อ่านค่าจาก MPU6050

  if ((millis() - timer) > 10) {  // ทุกๆ 10ms
    // อ่านค่า rawYaw จาก Gyroscope (Angle Z)
    float rawYaw = mpu.getAngleZ();  

    // หักลบ yawOffset ที่ตั้งตอนเริ่มต้น
    yaw = fmod((rawYaw - yawOffset) + 180.0, 360.0);  // คำนวณ yaw ให้อยู่ในช่วง -180 ถึง 180 องศา
    if (yaw < 0) yaw += 360.0;
    yaw -= 180.0;  // ทำให้ค่า yaw อยู่ในช่วง -180 ถึง 180

    yaw = constrain(yaw, -180.0, 180.0);  // ควบคุมค่า yaw ให้อยู่ในช่วงที่ต้องการ

    timer = millis();  // อัปเดตเวลา
  }
}

void setYawZero() {
  mpu.update();
  yawOffset = mpu.getAngleZ();  // เซ็ตค่า yawOffset เป็นค่าปัจจุบันของ yaw
}
  int readSensor(int idx) {
    mux.writeRegister(channels[idx]);
    return sensor[idx].readRangeContinuousMillimeters();
  }
