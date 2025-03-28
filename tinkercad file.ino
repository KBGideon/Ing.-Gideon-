#include <Servo.h>
const int RELAY = 8;
const int trigPin = 9;
const int echoPin = 10;
const int Buzzer = 12;
long duration; 
int distance;

// We start by intializing input and output pins to corresponding components.
void setup()
{
  Serial.begin(9600);
  pinMode(RELAY,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(Buzzer, OUTPUT);


}

// We now initiate the call and response of the components.
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  
  
  if(distance<60)
  {
    digitalWrite(RELAY,HIGH);
    digitalWrite(Buzzer,HIGH);
    
    
  }
  else
  {
    digitalWrite(RELAY,LOW);
    digitalWrite(Buzzer,LOW);
    
  }
}