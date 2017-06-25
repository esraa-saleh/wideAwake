#include <Servo.h>

Servo servo;  

int pos = 0;    
int ledPin = 12; 

int running = 0;
int light =LOW;
int buzzerPin= 8;
void setup() {
  Serial.begin(9600);
  myservo.attach(13);  

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
      startBuzz();
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
         
        
        servo.write(pos);              
        delay(10);                    
         }
         
         startBuzz();
       for (pos = 180; pos >= 0; pos -= 1) { 
        if(pos%45==0){
          
          toggleLight();
          }
        servo.write(pos);              
        delay(10);                       
        }
       Serial.write(2);
       running = 0;
        startBuzz();
      light = LOW;
      digitalWrite(ledPin, light);
        
   }
}
void toggleLight(){

  
  digitalWrite(ledPin, light);
  light = (light==LOW?HIGH:LOW);
  }
void startBuzz () {
 for (long i = 0; i < 3000; i++ ) 
  
 {
   digitalWrite(buzzerPin, HIGH);
   delayMicroseconds(250);
   digitalWrite(buzzerPin, LOW);
   delayMicroseconds(250);
 }
}
