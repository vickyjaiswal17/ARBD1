#include <LiquidCrystal.h>
int c=0;
int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
int R[4] = {2,3,4};                   // Rows of the Keypad Matrix
int C[4] = {7,8,12,13};                     // Columns of the keypad Matrix 
int row  = 0;                           //To store which rows button is pressed
int column = 0;                         //To store which column button is pressed
int i; 
bool is_switch_pressed;                //To detect whether the switch is pressed or not 
char key_press[16] = {'1','2','3','*','4','5','6','0','7','8','9','#'}; 
LiquidCrystal  lcd(rs, en, d4, d5, d6, d7);

void setup()
{
   lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("key pressed is: ");                
    for(i=0; i<4;i++) 
  {
    pinMode(R[i],OUTPUT);              // Initialize all rows pin as Output
    pinMode(C[i],INPUT);               //Initialize all column pin as Input
  }
}

void loop() {
  for(i =0 ; i< 4; i++) 
  {
    digitalWrite(R[i],HIGH);           //Put all row pin as HIGH to detect 
  }
  //which button is pressed 
  is_switch_pressed = digitalRead(C[0]) || digitalRead(C[1]) || digitalRead(C[2]) || digitalRead(C[3]); 
  //If any button is pressed 
  if(is_switch_pressed) 
  { 
    delay(30); 
    is_switch_pressed = digitalRead(C[0]) || digitalRead(C[1]) || digitalRead(C[2]) || digitalRead(C[3]); 
  }
  if(is_switch_pressed) 
  {
    for(i = 0 ; i<4 ; i++) 
    {
      for(int j = 0 ; j<4; j++) 
      {
        digitalWrite(R[j],LOW); 
      }
      digitalWrite(R[i],HIGH);          
      for(int j = 0 ; j<4; j++ ) 
      {
        if(digitalRead(C[j])) 
        {
          row = i;                    
          column  = j; 
          exit; 
        }
      }
    }
    
    lcd.setCursor(0,1);
    lcd.print(key_press[column+(row*4)]);
    for(int i =0 ; i<4 ; i++) 
    {
      digitalWrite(R[i],HIGH);
    }
    do
    {
      is_switch_pressed = digitalRead(C[0]) || digitalRead(C[1]) || digitalRead(C[2]) || digitalRead(C[3]); 
      delay(20); 
    } while(is_switch_pressed); 
    
    
  } 
}
