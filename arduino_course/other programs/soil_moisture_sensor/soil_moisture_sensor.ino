#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);
void setup ()
{
  pinMode(A1, INPUT);
  lcd.begin(16,2);
}

void loop ()
{
  int a = analogRead(A1);
  lcd.clear();
  lcd.print(a);
  delay(1000);
}

