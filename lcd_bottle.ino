#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
 analogWrite(6, 100);
 lcd.begin(16, 2); 
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Hello World");

  lcd.setCursor(0, 10);
  lcd.print("Welcome");
}
