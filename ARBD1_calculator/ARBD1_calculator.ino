#include <LiquidCrystal.h>
int c=0;
int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
int R[4] = {2,3,4};                
int C[4] = {7,8,12,13};                  
int row  = 0;                          
int column = 0;                        
int i,k=0,n=1,m=1;
float value1=0,value2=0,p[25],key;
float value3;                                                                                                                                                                                                                                                                                                  
int buttonPin=A1; 
bool is_switch_pressed;               
float key_press[12] = {1,2,3,0,4,5,6,0,7,8,9,0}; // fourth row have excluded
                                                 // A->0,B->0,C->0
LiquidCrystal  lcd(rs, en, d4, d5, d6, d7);

void setup()
{
   lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Enter 1st no. :-");                
    for(i=0; i<4;i++) 
  {
    pinMode(R[i],OUTPUT);              
    pinMode(C[i],INPUT);           
  }
  pinMode(buttonPin,INPUT);
}

void loop() {
  for(i =0 ; i< 4; i++) 
  {
    digitalWrite(R[i],HIGH);      
  }
 
  is_switch_pressed = digitalRead(C[0]) || digitalRead(C[1]) || digitalRead(C[2]) || digitalRead(C[3]); 
 
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
    
    lcd.setCursor(k,1); // move to the next position of LCD
    lcd.print(key_press[column+(row*4)]); // print pressed value on the LCD
    p[k]=key_press[column+(row*4)];  //Store in the Array at postion of k
    k++;  //  increase the postion by value 1
    
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
   
    key=analogRead(buttonPin);
    
    if((key > 600) && (key < 725) && n==1)  // condition to chech ENTER button is preesed?
    {
      int c=k-1;
       for(int i=0;i<k;i++)
         {
            value1=value1+p[i]*pow(10,c); //forming a numerical value from Array stored value
             c--;
         }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter 2nd no. :-");  // now it will proceed for next value.
      lcd.setCursor(0,1);
      k=0;                    // restart the position
      n=2;                    // only for controlling the loop
    }

    
     do
    {
      key=analogRead(buttonPin); 
      delay(20); 
    } while((key > 600) && (key < 725) && m==1);
    
    if(n==2)
    {
      m=2;
    }


     
    if((key > 600) && (key < 725) && n==2)
    {
      int c=k-1;
       for(int i=0;i<k;i++)
         {
            value2=value2+p[i]*pow(10,c);
             c--;
         }
       delay(30);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Operation ");
       lcd.setCursor(0,1);
      n=3;
      k=0;
    }
     
    
     do
    {
      key=analogRead(buttonPin); 
      delay(20); 
    }while((key > 600) && (key < 725) && m==2);
    
    if(n==3)
    {
      m=3;
    }

    
      if(n==3)
   {
      if(key < 100)  
        {
          lcd.print("+");
          value3=value1+value2;
          n=4;
        }
     else if((key > 400) && (key < 600))
        {
          lcd.print("*");
           value3=value1*value2;
          n=4; 
        }
    
     else if((key > 725) && (key < 790))
        {
          lcd.print("/");
          value3=value1/value2;
          n=4;
        }

     else if((key > 790) && (key < 850))
        {
          lcd.print("-");
          value3=value1-value2;
          n=4;
        }
   }


    do
    {
      key=analogRead(buttonPin); 
      delay(20); 
    } while((key > 600) && (key < 725) && m==3);
    
    if(n==4)
    {
      m=4;
    }

     
    
    if((key > 600) && (key < 725) && n==4)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Result :-");
      lcd.setCursor(0,1);
      lcd.print(value3);
      n=5;
      
    }


    do
    {
      key=analogRead(buttonPin); 
      delay(20); 
    } while((key > 600) && (key < 725) && m==4);
    
    if(n==5)
    {
      m=5;
    }

    
    if((key > 600) && (key < 725) && n==5)
    {
     lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter 1st no. :-");   
       lcd.setCursor(0,1);
       k=0;
       n=0;
       m=0;
       value1=0;
       value2=0;
       value3=0;
    }


     do
    {
      key=analogRead(buttonPin); 
      delay(20); 
    } while((key > 600) && (key < 725) && m==0);
    
    if(n==0)
    {
      m=1;
      n=1;
    }
}
