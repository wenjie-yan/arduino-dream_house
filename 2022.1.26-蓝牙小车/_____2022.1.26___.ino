#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial BTserial(9, 2); 
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
void setup() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(RELEASE); 
  motor2.run(RELEASE); 
  Serial.begin(9600);
  BTserial.begin(9600);
  Serial.println("success!!!");
  BTserial.println("success!!!");
}

void loop() {
  if(BTserial.available()>0){
    char a=BTserial.read();
  if(a=='w'){
    motor1.run(FORWARD); 
    motor1.setSpeed(255);
    motor2.run(FORWARD); 
    motor2.setSpeed(255);
    delay(15);
    
  }
  else if(a=='s'){
    motor1.run(BACKWARD); 
    motor1.setSpeed(255);
    motor2.run(BACKWARD); 
    motor2.setSpeed(255);
    delay(15);
   
  }
  else if(a=='a'){
    motor1.run(BACKWARD); 
    motor1.setSpeed(200);
    motor2.run(BACKWARD); 
    motor2.setSpeed(255);
    delay(15);
   
  }
 else if(a=='d'){
    motor1.run(BACKWARD); 
    motor1.setSpeed(255);
    motor2.run(BACKWARD); 
    motor2.setSpeed(200);
    delay(15);
    
  }
  else{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    delay(15);
  }
  }
}
