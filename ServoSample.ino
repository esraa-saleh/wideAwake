#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int ledPin = 12; 

int running = 0;
int light =LOW;
int buzzerPin= 8;
void setup() {
  Serial.begin(9600);
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object

  pinMode (ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
 
}


//int ledPin=13;
//
//void setup(){
//  Serial.begin(9600);
//  pinMode(ledPin, OUTPUT);
//  }
//void loop(){
//  //digitalWrite(ledPin,HIGH);
//}
void serialEvent()
{
   while(Serial.available()) 
   {
      playTone();
      Serial.write(2);
//      char start = Serial.read();
//      //Serial.write(start);
//       
//     digitalWrite(ledPin, HIGH);
//     delay(500);
//     Serial.write(2);
//     digitalWrite(ledPin, LOW);
        running = 1;
        char start=Serial.read();
        Serial.write(start);
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
       
        if(pos%45==0){
          
          toggleLight();
          }
         
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
         }
         
         playTone();
       for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        if(pos%45==0){
          
          toggleLight();
          }
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
       Serial.write(2);
       running = 0;
        playTone();
      light = LOW;
      digitalWrite(ledPin, light);
        
   }
}
void toggleLight(){

  
  digitalWrite(ledPin, light);
  light = (light==LOW?HIGH:LOW);
  }
void playTone () {
 for (long i = 0; i < 2048; i++ ) 
   // 1 / 2048Hz = 488uS, or 244uS high and 244uS low to create 50% duty cycle
 {
   digitalWrite(buzzerPin, HIGH);
   delayMicroseconds(244);
   digitalWrite(buzzerPin, LOW);
   delayMicroseconds(244);
 }
}
