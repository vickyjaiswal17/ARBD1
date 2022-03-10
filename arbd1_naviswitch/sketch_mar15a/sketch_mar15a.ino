int buttonPin = A1; //Push Button 
int ledPin = 11;    //LED 

int buttonstate;                //Present state of push button 
int prev_buttonstate = LOW;    //Previous state of push button

void setup() 
{
  pinMode(buttonPin,INPUT);                 //Initialize the digital pin 2 as an Input
  pinMode(ledPin,OUTPUT);                   //Initialize the digital pin 13 as an Output 
  digitalWrite(ledPin,prev_buttonstate);
  Serial.begin(9600);//Initially put the Led in ON state
}
void loop() 
{
  buttonstate = digitalRead(buttonPin); //Samples the input at digital pin 2
  if(buttonstate != prev_buttonstate)   //Value Changed due to noise or pressing of push button
  { 
    delay(20);                              //Wait for 20 ms to avoid any noise or bouncing 
    buttonstate = digitalRead(buttonPin);   //Store the current state of push button  
    prev_buttonstate = buttonstate;     
      Serial.println(buttonstate);                                    //Store the current state in prev_buttonstate for the next comparison
  }
  digitalWrite(ledPin,buttonstate) ;        //Drive the Led with the current state of push button 
}
