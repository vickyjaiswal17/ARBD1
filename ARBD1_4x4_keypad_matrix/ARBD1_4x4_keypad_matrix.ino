int R[4] = {2,3,4,5};                   // Rows of the Keypad Matrix
int C[4] = {7,8,12,13};                     // Columns of the keypad Matrix 
int row  = 0;                           //To store which rows button is pressed
int column = 0;                         //To store which column button is pressed
int i; 
bool is_switch_pressed;                //To detect whether the switch is pressed or not 
char key_press[16] = {'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'}; 
void setup()
{
  Serial.begin(9600);
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
    Serial.print("The key pressed is : "); 
    Serial.println(key_press[column+(row*4)]);
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
