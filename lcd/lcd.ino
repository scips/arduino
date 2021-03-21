#include <LiquidCrystal.h>

//LiquidCrystal lcd(4, 2, 9, 8, 6, 5);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);

void setup()
{
  digitalWrite(13,LOW);
  lcd.clear();
  lcd.begin(16,2);
  lcd.print("hello, world");
}

void loop() {
  
}
