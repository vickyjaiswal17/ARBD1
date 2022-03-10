byte BodyLeg[] = {
  B00000,
  B00000,
  B00000,
  B00011,
  B11111,
  B10000,
  B00000,
  B00000
};
byte HeadArm[] = {
   B00000,
  B00000,
  B00110,
  B11110,
  B11000,
  B00111,
  B00000,
  B00000
};
byte ObsticleUp[] = {
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B01110,
  B00100,
  B00100
};
byte ObsticleDown[] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111
};

#include <LiquidCrystal.h>
#include<TimerOne.h>
int key,n=1,m=1,pos=0,i,obstNo;
int buttonPin=A1;
long int score=0;
int rs = 4, en = 5, d4 = 0, d5 = 1, d6 = 2, d7 = 3;
LiquidCrystal  lcd(rs, en, d4, d5, d6, d7);
  int obstCpos;
  int obstype;
  int obstRpos;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, BodyLeg);
  lcd.createChar(1,HeadArm);
  lcd.createChar(2,ObsticleUp);
  lcd.createChar(3,ObsticleDown);
  pinMode(buttonPin,INPUT);
  lcd.home();
  lcd.print("Strat Game");
  Timer1.initialize(200000);
  Timer1.attachInterrupt(obsticle);
}

void loop() {
   key=analogRead(buttonPin);
    if((key > 600) && (key < 725) && n==1)
    {
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.write((byte)0);
        lcd.setCursor(2,0);
        lcd.write((byte)1);  
        n=2;
        i=0;
        obstCpos=16;
        obstype=3;
        obstRpos=1;
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
    
    
     
    if(key < 100 && n==2)  
     {
      pos=0;
      lcd.clear();
      lcd.setCursor(1,pos);
      lcd.write((byte)0);
      lcd.setCursor(2,pos);
      lcd.write((byte)1);
   
      lcd.setCursor(obstCpos,obstRpos);
      lcd.write((byte)obstype);
      
     }

   
   if((key > 790) && (key < 850) && n==2)
      { 
         pos=1;
         lcd.clear();
         lcd.setCursor(1,pos);
         lcd.write((byte)0);
         lcd.setCursor(2,pos);
         lcd.write((byte)1);
         
      
         lcd.setCursor(obstCpos,obstRpos);
         lcd.write((byte)obstype);
     }
     
    
      if(obstRpos==pos && (obstCpos==1 || obstCpos==2 ))
     {
      n=3;
      obstCpos=16;
      pos=0;
      delay(1000);
      lcd.clear();
      lcd.print("OUT");
      lcd.setCursor(0,1);
      lcd.print("score:");
      lcd.print(score);
      score=0;
     }
    
     if((key > 600) && (key < 725) && n==3)
     { 
       lcd.clear();
       lcd.print("Strat Game");
       m=3;
       n=1;
     }

     do
    {
      key=analogRead(buttonPin); 
      delay(20); 
    } while((key > 600) && (key < 725) && m==3);
    
    if(n==1)
    {
      m=1;
    }
    

  }
  
void obsticle()
  {
    if(n==2)
    {
      lcd.clear();
      lcd.setCursor(1,pos);
      lcd.write((byte)0);
      lcd.setCursor(2,pos);
      lcd.write((byte)1);

      
      lcd.setCursor(obstCpos,obstRpos);
      lcd.write((byte)obstype);
      obstCpos--;
      score+=1;
    }
   
    if(obstCpos==0)
       {
        obstCpos=16;
        randomGen();
       }
    
     return;
}
void randomGen()
{
  obstype=random(2,4);
      if(obstype==2)
        {
          obstRpos=0;
        }
      else
        {
          obstRpos=1;
        }
}


  
