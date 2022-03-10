#include <LiquidCrystal.h>
int c=0;
int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
LiquidCrystal  lcd(rs, en, d4, d5, d6, d7);

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0,0);               
    lcd.print("HatchnHack!");  
}

void loop() 
{
        
    lcd.setCursor(0,1);
    c++;
    lcd.print("#");
    lcd.print(c);
    delay(1000);
}
