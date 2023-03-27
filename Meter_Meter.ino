#include <LiquidCrystal.h>

#define echoPin 6
#define trigPin 7
#define rs 12
#define en 11
#define d4 5
#define d5 4
#define d6 3
#define d7 2
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

int maxrange = 399;
int minrange = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int range = distance();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(range);
  lcd.print(" cm");

  delay(250);
}

int distance()
{
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);

  if(distance >= maxrange || distance <= minrange)
  return 0;
  return distance;
}
