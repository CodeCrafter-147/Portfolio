void TurnLeft() { // เลี้ยวซ้าย
motor(-100, -100); delay(40);
motor(-100, 100); delay(40);
 while (1) {
   motor(-100, 100);
   readADC();
   if (sensor_pin[3] > 200 ){
     motor(100, -100); delay(20);
     motor(0, 0);
     break;
   }
 }
}

void TurnRight() { // เลี้ยวขวา
 motor(50, 50); delay(20);
motor(100, -100); delay(40);
 while (1) {
   motor(100, -100);  
   readADC();
   if (sensor_pin[12] > 200 ) {
     motor(-100, 100); delay(20);
     motor(0, 0);
     break;
   }
 }
}

