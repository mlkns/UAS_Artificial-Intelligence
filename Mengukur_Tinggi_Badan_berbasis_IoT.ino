#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display
const int trigPin = D5; // define the trigger pin of the ultrasonic sensor
const int echoPin = D6; // define the echo pin of the ultrasonic sensor

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight(); // Make sure backlight is on

  // Print a message on both lines of the LCD.
  lcd.setCursor(2, 0); // Set cursor to character 2 on line 0
  lcd.print("Hello Mlkns!");

  lcd.setCursor(2, 1); // Move cursor to character 2 on line 1
  lcd.print("Tinggi Bdn");

  pinMode(trigPin, OUTPUT); // set the trigger pin as an output
  pinMode(echoPin, INPUT);  // set the echo pin as an input
}

void loop()
{
  // Ultrasonic sensor code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the pulse on the echo pin
  unsigned long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance based on the speed of sound (343 meters/second)
  // and the time it takes for the sound wave to return.
  // Distance = (time * speed of sound) / 2
  float distance = (duration * 0.0343) / 2;
  float tinggi_badan = (207.0 - distance);
  

  // Print the distance on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tinggi Beliau:");
  lcd.setCursor(0, 1);
  lcd.print(tinggi_badan);
  lcd.print(" cm");

  delay(1000); // delay for readability
}
