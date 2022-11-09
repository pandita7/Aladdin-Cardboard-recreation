#include <Servo.h>
Servo myservo;  
Servo myservo2;
Servo myservo3
int pos1 = 0;  
int pos2 = 0;
int pos3 = 0; 

//Copper Switches and their states //
int Switch1 = 3;
int Switch2 = 4;
int Switch3 = 5;
int Switch4 = 6;
int Switch5 = 7
int s1state = 0;
int s2state = 0;
int s3state = 0;
int s4state = 0;
int s5state = 0; 
//

//Switch test for debug and copper contact//
void switchtest() {
   s1state = digitalRead(Switch1); 
   Serial.println( s1state); 
   delay(300);
    s2state = digitalRead(Switch2); 
   Serial.println( s2state);
   delay(300);
    s3state = digitalRead(Switch3); 
   Serial.println( s3state);
   delay(300);
    s4state = digitalRead(Switch4); 
   Serial.println( s4state);
   delay(300);
    s5state = digitalRead(Switch5); 
   Serial.println( s5state);
   delay(300);  
};
// test servo functions and movement//
void servotest() {
   for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 180; pos1 >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}
}

void setup() {
  // Switch and servo utilization//
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
  pinMode(Switch4, INPUT);
  pinMode(Switch5, INPUT);
  Serial.begin(9600); 

}

void loop() {
switchtest();
servotest();
}
