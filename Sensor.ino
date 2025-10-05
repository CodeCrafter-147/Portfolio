void ViewSerial() {
  while (1) {
    for (int i = 0; i < 16; i++) {
      mux.channel(i);
      int x  = analogRead(signal_pin);
      Serial.print(x);
      Serial.print(",\t");
    }
    Serial.println();
  }
} 


void ViewReadLineSerial() {
  while (1) {
     Serial.println(position());
  }
}

int position() {
  readADC();
  bool In_line = false;
  long Average = 0, sum = 0;
  for (uint8_t i = 0; i < Unit_sensor; i++) {
    long value = map(long(sensor_pin[i]), Black_sensor_values[i], White_sensor_values[i], 1000, 0);
    if (value > 1000) {
      value = 1000;
    }
    if (value < 0) {
      value = 0;
    }
    //    Serial.print(value);
    //    Serial.print('\t');
    if (value > 250) {
      In_line = true;
    }
    if (value > 50) {
      Average += (long)value * (i * 1000);
      sum += value;
    }
  }
  //  Serial.println("");
  if (In_line == false) {
    if (Last_Position < (Unit_sensor - 1) * 1000 / 2) {
      return 0;
    } else {
      return (Unit_sensor - 1) * 1000;
    }
  }
  else {
    Last_Position = Average / sum;
  }
  return Last_Position;
}

void readADC() {
  for (byte i = 0; i < 16; i++) {
    mux.channel(i);
    sensor_pin[i] = analogRead(signal_pin);
  }
}