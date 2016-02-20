#include <SoftwareSerial.h>
#include <stdlib.h>
#include <Servo.h>

Servo LeftM;//5
Servo RightM;
int lx,ly,az = 0;

void setup()  { 
  Serial.begin(115200);
  Serial.println("ready");
  LeftM.attach(9);
  RightM.attach(10);
} 

void loop()  { 
  delay(100);
  serial_read();  
  convert();
  drive();
}  
void serial_read(){
  if (Serial.available()>9){
    if (Serial.read() == 'B'){
    lx = (Serial.read()-'0')*100 + (Serial.read()-'0')*10 + (Serial.read()-'0');
    ly =(Serial.read()-'0')*100 + (Serial.read()-'0')*10 + (Serial.read()-'0');
    az = (Serial.read()-'0')*100 + (Serial.read()-'0')*10 + (Serial.read()-'0');
    }
    else{lx = ly = az = 128;}
}
else{  
lx = ly = az = 128;}
//Serial.end();
//Serial.begin(9600);
  Serial.flushRX();

}

void convert(){
 lx = map (lx, 0, 255, 80, 100);
 ly = map (ly, 0, 255, 80, 100);
 az = map (az, 0, 255, 75, 115);
}


void drive(){

 if(lx == 90){
  if(ly == 90){
   if (az == 90){
     LeftM.write(90);
     RightM.write(90);
   }
   else{
    LeftM.write(az);
    RightM.write(az);  
   }
  }
  else{
   LeftM.write(ly);
   RightM.write(ly);
   }
 }
 else{
   if (lx > 90){
   LeftM.write(lx);//if 80 //if 100 
   RightM.write(lx+20);//needs to be 100 //needs to be 80 
   }
   else{LeftM.write(lx);
   RightM.write(lx-20);}
 }
}





