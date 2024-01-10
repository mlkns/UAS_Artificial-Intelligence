#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
const int trigPin = D5; 
const int echoPin = D6; 

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();

  
  lcd.setCursor(2, 0); 
  lcd.print("Hello Mlkns!");

  lcd.setCursor(2, 1); 
  lcd.print("Tinggi Bdn");

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
}

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  
  float distance = (duration * 0.0343) / 2;
  float tinggi_badan = (207.0 - distance);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tinggi Beliau:");
  lcd.setCursor(0, 1);
  lcd.print(tinggi_badan);
  lcd.print(" cm");

  delay(1000);
}
