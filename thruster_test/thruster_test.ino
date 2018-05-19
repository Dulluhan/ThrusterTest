#include <SoftwareSerial.h>
#include <stdlib.h>
#include <Servo.h>

#define THRUSTER1 3
#define THRUSTER2 5
#define THRUSTER3 6
#define THRUSTER4 9


Servo T1;
Servo T2;
Servo T3; 
Servo T4;
int lx = 0;
int daz = 0; //.delta angular z
int mode = 0;


void setup()  { 
  Serial.begin(115200);
  Serial.println("ready");
  T1.attach(THRUSTER1);
  T2.attach(THRUSTER2);
  T3.attach(THRUSTER3);
  T4.attach(THRUSTER4);
} 

void loop()  { 
  serial_read();  
  drive();
}  
void serial_read(){
    char c = Serial.read();
    if (c == 'w'){
         lx += 1; 
     }
     if (c == 's'){
         lx -= 1;
     }
     if (c == 'a'){
          daz += 1;
     }
     if (c == 'd'){
          daz -= 1;
     } 
     if (c == 'r'){ //r for reset
          lx = 0;
          daz = 0; 
     } 
     if (c == '0'){
         mode = 0;
     }
     if (c == '1'){
         mode = 1;
     }
     if (c == '2'){
         mode = 2;
     }
     if (c == '3'){
         mode = 3;
     }
     if (c == '4'){
         mode = 4;
     }
}

void drive(){
    if (mode == 0){
      int thrust = lx+daz;
      T1.write(91+thrust);
      T3.write(91-thrust);
      //T3.write(lx+daz);
      //T4.write(lx+daz);
    }
    if (mode == 1){
      T1.write(lx+daz);
    }
    if (mode == 2){
      T2.write(lx+daz);
    }
    if (mode == 3){
      T3.write(lx+daz);
    }
    if (mode == 4){
      T4.write(lx+daz);
    }
}





