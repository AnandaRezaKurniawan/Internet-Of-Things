#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
int trigPin = 3;
int echoPin = 4;
int ledRed = 5;
int ledGreen = 6;

void setup(){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int duration = pulseIn(echoPin,HIGH);
  int distance = duration / 58;
  
  if(distance <= 30)
  {
    digitalWrite(ledRed,HIGH);
    digitalWrite(ledGreen,LOW);
    lcd.setCursor(0,1);
    lcd.print("STOP");
  }
  if(distance > 30)
  {
    digitalWrite(ledGreen,HIGH);
    digitalWrite(ledRed,LOW);
    lcd.setCursor(0,1);
    lcd.print("AMAN");
  }
  
  lcd.setCursor(0,0);
  lcd.print("Jarak=");
  lcd.print(distance);
  lcd.print("cm");
}
