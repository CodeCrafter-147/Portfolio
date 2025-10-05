void sensorRead() {
  while (1) {
    Serial.print(analogRead(0));
    Serial.print(",");
    Serial.print(analogRead(1));
    Serial.print(",");
    Serial.print(analogRead(2));
    Serial.print(",");
    Serial.println(analogRead(3));
    // Serial.print(",");
    // Serial.print(analogRead(4));
    // Serial.print(",");
    // Serial.print(analogRead(5));
    // Serial.print(",");
    // Serial.print(analogRead(6));
    // Serial.print(",");
    // Serial.println(analogRead(7));
    delay(100);
  }
}
