#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);

int sensorTemp = 0;
int sensorLight = 0;

const float B = 5000;               // B value of the thermistor
const float R0 = 5000;

void setup()
{
  digitalWrite(13,LOW);
  lcd.clear();
  lcd.begin(16,2);
  displayLight(sensorLight);
  displayTemp(sensorTemp);
}

void displayLight(int sensor) 
{
  lcd.setCursor(0,0);
  lcd.print("Luminosite: ");
  // clean the rest of the line
  lcd.print("     ");
  lcd.setCursor(11,0);
  if(sensor > 250) {
    if(sensor > 500) {
      if(sensor > 750) {
        lcd.print("high");
      } else {
        lcd.print("med");  
      }
    } else {
      lcd.print("low");
    }
  } else {
    lcd.print("dark");
  }
}

void displayTemp(int r1)
{
  lcd.setCursor(0,1);
  lcd.print("Temp.:             ");
  lcd.setCursor(6,1);
  float R = 1023.0/r1-1.0;
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  lcd.print(temperature, 10);
  lcd.print(" C");
}


void loop() {
  sensorLight = analogRead(A1);
  sensorTemp = analogRead(A4);
  if(sensorLight > 500) {
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
  }
  displayLight(sensorLight);
  displayTemp(sensorTemp);
  delay(100);        // delay in between reads for stability
}
