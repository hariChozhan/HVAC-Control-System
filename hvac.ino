#include <Wire.h>
float tempC;
int reading;
int tempPin = 0;
int led =13;
#define CW 7
#define CCW 8
void setup(){
  pinMode(led,OUTPUT);
  pinMode(CW,OUTPUT);
  pinMode(CCW, OUTPUT);
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
reading = analogRead(tempPin);
tempC = (5.0*reading*100.0)/1024.0;
Serial.print("temp in C =");
Serial.println(tempC);
if (tempC <  32){
  digitalWrite(led,HIGH);
  digitalWrite(CW,HIGH);
  delay(1000);
  digitalWrite(CW,LOW);
}
else if (tempC > 32){
  digitalWrite(led,LOW);
  digitalWrite(CCW,HIGH);
  delay(1000);
  digitalWrite(CCW,LOW);
  }
}
