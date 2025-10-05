#include <light_CD74HC4067.h>
CD74HC4067 mux(10,11,12,13);
const int signal_pin = A4;
#include <Servo.h>
Servo ESC;

#define PWM1    5
#define INA1    2
#define INB1    3
            
#define PWM2    6
#define INA2    7
#define INB2    4

#define numSensors 16
uint8_t Unit_sensor = numSensors;
uint16_t sensor_pin[numSensors];
uint16_t Black_sensor_values[numSensors] = {1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1};
uint16_t White_sensor_values[numSensors] = {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0};
uint32_t Last_Position;

unsigned int F[numSensors];
int last_value = 0;
int Error, Last_Error, LeftMotor, RightMotor, PowerMotor, Position;



void setup() {
  Serial.begin(9600);
  pinMode(signal_pin, INPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);

 
  // ViewSerial();
 //ViewReadLineSerial();
    
  while (digitalRead(9) == 0)
  delay(500);
   beep();
    delay(500);
   

 
     //motor(20,20);delay(10000);
    // motor(-10,-10);delay(10000);
   // motor(100,100);delay(10000);

//TrackTime(50,0.025,0.8,500);
//motor(100,100);delay(1000);
//motor(100,100);delay(1000);

  }


  


void loop() {
  ViewSerial();
Move(0,0,10);
}
