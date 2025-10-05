void set() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    mux.writeRegister(channels[i]);
    sensor[i].init();
    sensor[i].setTimeout(500);
    sensor[i].startContinuous();
  }

  if (mpu.begin() != 0)
    while (1);
  Serial.println(F("Calibrating MPU..."));
  mpu.calcOffsets();
  yawOffset = mpu.getAngleZ();
  Serial.println(F("Done!"));
}