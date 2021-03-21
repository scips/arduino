#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 2, 8,7,6,5);

void setup()
{
  lcd.begin(16,1);
  lcd.print("hello, world!");
}

void loop() {
  
}
