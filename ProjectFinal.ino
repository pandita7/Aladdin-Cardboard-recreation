//servo configuration//
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
 
//checks for chronological sequence for proper story progression
int check1 = 0;
int check2 = 0;
//disables sequences to overall code as interactions happen
int disable1 = 0;
int disable2 = 0;
int disable3 = 0;



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
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}
};

///Scene sequences///
void sequence1() {    //sequence one involves the first panel scene where one motor reveals character and the other controls the trap door
  s1state = digitalRead(Switch1); //controls door one magnet switch to servo reveal
  s2state = digitalRead(Switch2); //controls character to trap door
  if (s1state == HIGH && check1 == 0) {
    for (pos1 = 0; pos1 <= 90; pos1 += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   for (pos1 = 90; pos1 >= 0; pos1 -= 1) { // goes from 90 degrees to 0 degrees
    myservo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    check1 = 1;
  }
  }
  if (s2state == HIGH && check1 == 1) { //if character is on top of trap door
        for (pos1 = 0; pos1 <= 90; pos1 += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   for (pos2 = 90; pos2 >= 0; pos2 -= 1) { // goes from 90 degrees to 0 degrees
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  disable1 = 1;
}; 

void sequence2() { //second panel where magic carpet and alladin is involved to interact with enviroment 
  s3state = digitalRead(Switch3); //controls trap door on second panel
  s4state = digitalRead(Switch4); //controls interaction 
  if (s3state == HIGH) { //if character is ontop of trap door
        for (pos3 = 0; pos3 <= 90; pos3 += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservo3.write(pos3);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   for (pos3 = 90; pos3 >= 0; pos3 -= 1) { // goes from 90 degrees to 0 degrees
    myservo3.write(pos3);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
};



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
if (s1state == HIGH && s2state == HIGH && s3state == HIGH && s4state == HIGH && s5state == HIGH) { //allows the sequences to run only if the panels and servos are at their right position 
  if (disable1 == 0) { //checks if sequence was previously ran
  sequence1();
  }
  if (disable1 == 1 && disable2 == 0) {
  sequence2();
  }
  
} 
}
