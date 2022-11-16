//Cardboard Code by Daniel Zuniga//

#include <Servo.h>
//copper tape switch pinout
int s1 = 1;//1 door switch to motor 1
int s2 = 2; //tied to motor 2
int s3 = 3;// 2 door switch
int s4 = 5;//tied to motor 3
int s5 = 4;// 3 door switch
int s6 = 6;//interaction tied to motor 4(ruby)
int s7 = 7;// 4 door switch
int s8 = 8;// interaction to motor 5
int m1 = 9;//servo 1
int m2 = 10;//servo 2
int m3 = 11;//servo 3
int m4 = 12;//servo 4
int m5 = 13;//servo 5
//switch states
int s1state = 0;
int s2state = 0;
int s3state = 0;
int s4state = 0;
int s5state = 0;
int s6state = 0;
int s7state = 0;
int s8state = 0;

//disables interactions
int d1 = 0;
int d2 = 0;
int d3 = 0;
int d4 = 0;
//disables for mid interactions
int d22 = 0;
int pindisable = 0;
int pindisable2 = 0;
// for loop variable
int i;

//Extra Rumble motor pinout
int rumble;

//servos
Servo myservo; 
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int pos = 0;    // variable to store the servo position
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  myservo3.attach(11);
  myservo4.attach(12);
  myservo5.attach(13);
//Pin utilization//
   pinMode(A0, INPUT);
   pinMode(s2, INPUT);
   pinMode(s3, INPUT);
   pinMode(s4, INPUT);
   pinMode(s5, INPUT);
   pinMode(s6, INPUT);
   pinMode(s7, INPUT);
   pinMode(s8, INPUT);
   Serial.begin(9600);
   //Rumble utilization
   pinMode(A1, OUTPUT);
   //
    
}

void loop() {
  //tie in state to pin
  s1state = digitalRead(A0);
  s2state = digitalRead(s2);
  s3state = digitalRead(s3);
  s4state = digitalRead(s4);
  s5state = digitalRead(s5);
  s6state = digitalRead(s6);
  s7state = digitalRead(s7);
  s8state = digitalRead(s8);
  //
  //Checks if servos are at their starting positions//
  if (pindisable == 0){
   pos = 200;
myservo.write(pos); 
  pos2 = 160;
myservo2.write(pos2);
  pos3 = 0;
myservo3.write(pos3); 
  pos4 = 80;
myservo4.write(pos4);
 pos5 = 10;
myservo5.write(pos5);
pindisable = 1;
Serial.println("Servo check " );
  }
  //// Panel 1 interaction
  if (s1state == LOW && d1 == 0) {
    Serial.println("button pressed 1 " ) ;
delay(2000);
pos = 90;
myservo.write(pos);
d1 = 1;
  }
  //// Panel 2 interaction
  if (s3state == LOW && d1 == 1 && d2 == 0) {
     Serial.println("panel 2 " ) ;
    if (s2state == HIGH) {
pos2 = 100;
myservo2.write(pos2);
  delay(15000);
  pos2 = 160;
myservo2.write(pos2);
  d2 = 1;
    }
  }
  //Additional fail safe to make sure servo activates
    if (s4state == HIGH && d22 == 0 && d2 == 1) {
   delay(3000);
pos3 = 100;
myservo3.write(pos3);
  delay(9000);
  pos3 = 0;
myservo3.write(pos3);
  d22 = 1;
    }
  
  //// Panel 3 interaction
  if (s3state == HIGH && d1 == 1 && d2 == 1 && d3 == 0) {
    Serial.println("motor show " ) ;
    if (pindisable2 == 0) {
  delay(3000);
pos3 = 50;
myservo3.write(pos3);
  delay(9000);
  pos3 = 0;
myservo3.write(pos3);
 Serial.println("retract " ) ;
 Serial.println("motor gone " ) ;
pindisable2 = 1;
    }
    //activates servo panel to show the volcano scene//
    if (s6state == LOW) {
     Serial.println("volcanic" ) ; 
  delay(1000);
  //indicator for quick timed event to put alladin into the slider//
pos4 = 80;
myservo4.write(pos4);
delay(500);
pos4 = 60;
myservo4.write(pos4);
delay(500);
pos4 = 80;
myservo4.write(pos4);
pos4 = 80;
myservo4.write(pos4);
delay(500);
pos4 = 60;
myservo4.write(pos4);
delay(500);
pos4 = 80;
//
myservo4.write(pos4);
  delay(1000);
  //Timer to engage the next panel, 15 seconds given to snap alldin to the magnet and move him down towards the last interaction//
for (i = 0; i < 30; i++) {
  pos4 = pos4 - 3;
myservo4.write(pos4);
delay(1000);
d3 = 1;
}
    }
  }
  //// Panel 4 interaction//
  if (s7state == LOW && d1 == 1 && d2 == 1 && d3 == 1 && d4 == 0) {
    Serial.println("panel 4" ) ;
    if (s8state == HIGH) {
       Serial.println("Genie" ) ;
pos5 = 100;
myservo5.write(pos5);
delay(1000);
pos5 = 50;
myservo5.write(pos5);
delay(1000);
pos5 = 100;
myservo5.write(pos5);
pos5 = 100;
myservo5.write(pos5);
delay(1000);
pos5 = 50;
myservo5.write(pos5);
delay(1000);
pos5 = 100;
myservo5.write(pos5);
d4 = 1;
      }
      
    }
  ////End of Sequence and play
}
