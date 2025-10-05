#include <Wire.h>
#include <MPU6050_light.h>
#include <VL53L0X.h>
#include <TCA9548A.h>
#include <POP32.h>

#define NUM_SENSORS 3
#define FRONT_THRESHOLD 230
#define CENTER_IR 17

TCA9548A mux;
VL53L0X sensor[NUM_SENSORS];
MPU6050 mpu(Wire);
float yaw = 0.0;  
float yawOffset = 0.0; // ตัวแปรสำหรับเก็บค่า Yaw
unsigned long timer = 0;
float error = 0, last_error = 0, output = 0;
float lastYawError = 0.0;
const uint8_t channels[NUM_SENSORS] = { TCA_CHANNEL_0, TCA_CHANNEL_1, TCA_CHANNEL_2 };

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mux.begin(Wire);
  mux.closeAll();
  mux.writeRegister(TCA_CHANNEL_0 | TCA_CHANNEL_1 | TCA_CHANNEL_2);
  set();  
  setYawZero();
  waitAnykey_bmp();
  delay(300);
// GO(50,700);
beep();

  PIDGy(35);
Turn(40,90  );
  PIDGy(40);
  Turn(42,-90);
    PIDGy(35);
    Turn(53,90);
    PIDGy(35);
    Turn(55,90);
    PIDGy(40);
      Turn(40,-90);
      PIDGy(35);
      Turn(40,-90);
      PIDGy(35);
      Turn(55,97);
      PIDGy(45);
      Turn(55,97);
      PIDGy(40);
      GO(50, 800);
      AO();
      delay(300);
      PIDGy(35);
      Turn(42,-90);
      PIDGy(35);
      Turn(55,100);
      PIDGy(35);
      Turn(55,100);
      PIDGy(35);
      Turn(55,100);
      Turn(42,-90);
      PIDGy(35);
      GO(50, 1000);
      PIDGy(35);
// beep();
// wall(2, 40, 3, 0, 1.7);
}

void loop() {
  // Serial.println(readSensor(1));
AO();
  delay(10);

// Turn(50, 90);
// Motor_STOP();
}
