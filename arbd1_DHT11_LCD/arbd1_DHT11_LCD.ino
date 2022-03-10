#include<DHT.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
       
float  dhtpin=A0;
unsigned long  loop_timer, sec = 120000;    
DHT dht(dhtpin,  DHT11);

void setup() {
 
    dht.begin();
     lcd.begin(16, 2);
    analogWrite(6,120);
    //loop_timer = millis();
}
void loop(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if(isnan(h) || isnan(t)){
        lcd.println("Error!! Reading from DHT sensor");
        return;
    }
    
    lcd.setCursor(0,0);
    lcd.print("temp:");
    lcd.setCursor(5,0);
    lcd.print(t*1.25);
    lcd.print("C");
    

    
    //loop_timer = millis();
}
