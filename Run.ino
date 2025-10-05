
void TacNormal(int BaseSpeed, float Kp, float Kd ) {
 
 Error = position() - 7500;
 PowerMotor = (Kp * Error) + (Kd * (Error - Last_Error));
 Last_Error = Error;
 LeftMotor = BaseSpeed + PowerMotor;
 RightMotor = BaseSpeed - PowerMotor;
 if (LeftMotor > 100) LeftMotor = 100;
 if (LeftMotor <= -100) LeftMotor = -60;
 if (RightMotor > 100) RightMotor = 100;
 if (RightMotor <= -100) RightMotor = -60;
 Move(LeftMotor, RightMotor, 0);
}

void motor(int PowL, int PowR) {
 PowL = (PowL * 255) / 100;
 PowR = (PowR * 255) / 100; // 0 - 255
 if (PowL > 0) {
   digitalWrite(INA1, LOW); // 0v
   digitalWrite(INB1, HIGH); // 5V
   analogWrite(PWM1, PowL);
 }
 else if (PowL == 0) {
   digitalWrite(INA1, HIGH);
   digitalWrite(INB1, HIGH);
   analogWrite(PWM1, 0);
 }
 else {
   digitalWrite(INA1, HIGH);
   digitalWrite(INB1, LOW);
   analogWrite(PWM1, -PowL); // 128
 }

 if (PowR > 0) {
   digitalWrite(INA2, LOW);
   digitalWrite(INB2, HIGH);
   analogWrite(PWM2, PowR);
 }
 else if (PowR == 0) {
   digitalWrite(INA2, HIGH);
   digitalWrite(INB2, HIGH);
   analogWrite(PWM2, 0);
 }
 else {
   digitalWrite(INA2, HIGH);
   digitalWrite(INB2, LOW);
   analogWrite(PWM2, -PowR);
 }
}

void Move(int a, int b, int c) {
 motor(a, b);
 delay(c);
}

void TrackCross(int BaseSpeed, float Kp, float Kd, char select) { // PID เช็คแยก

 while (1) {
    
   TacNormal(BaseSpeed, Kp, Kd );
    readADC();
   if ((sensor_pin[0] > 200 && sensor_pin[15] > 200)) {
   break;

 }
}
if (select == 's') {
   //motor(-100, -100);delay(10);
 } else if (select == 'p') {
   //motor(50, 50);
   //delay(10);
 } else if (select == 'l') {
  motor(0, 0);
   TurnLeft();
 } else if (select == 'r') {
  //motor(0, 0);
   TurnRight();
 }
}

void TrackCrosss(int BaseSpeed, float Kp, float Kd, char select) { // PID เช็คแยก

 while (1) {
    
   TacNormal(BaseSpeed, Kp, Kd );
    readADC();
   if ((sensor_pin[0] > 700 && sensor_pin[15] > 700)) {
   break;

 }
}
if (select == 's') {
  motor(0, 0);delay(10);
 } else if (select == 'p') {
  motor(50, 50);
   delay(10);
 } else if (select == 'l') {
  TurnLeft();
 } else if (select == 'r') {
  
   TurnRight();
 }
}


void TrackTime(int BaseSpeed, float Kp , float Kd, int TotalTime) { // Trackเส้นตามเวลาที่กำหนด
 unsigned long StartTime = millis();
 unsigned long EndTime   = StartTime + TotalTime;
 while (millis() <= EndTime) {
   TacNormal(BaseSpeed, Kp, Kd );
 }
}
void ao(){
 motor(0, 0);
 }
 
