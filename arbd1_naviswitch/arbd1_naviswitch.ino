int Switch_pin = A1;       
int switch_value;                       //To store the current push button value 
int prev_switch_value;                  //To store the prev value of push buttons
int button;                             //To store which button is pressed
void setup() 
{
    Serial.begin(9600);             //Initialize Serial to show which button is pressed
    pinMode(Switch_pin,INPUT);     //Initialize the analog pin A1 as an Input 
    prev_switch_value = analogRead(Switch_pin);      
    //Store the initial value of Analog pin A1
}

void loop() 
{
    switch_value = analogRead(Switch_pin); 
    //Read the value at Analog pin A1
    if((switch_value > (prev_switch_value+20)) ||
    (switch_value <(prev_switch_value-20)))     
    //If any button is pressed or value change due to noise 
    delay(20) ;                         
    //Wait for 20 ms to avoid any bouncing in the button 
    switch_value = analogRead(Switch_pin) ; 
    //Read again the value at pin A1
    if((switch_value > (prev_switch_value+20)) || (switch_value <(prev_switch_value-20)))
    {
    //If the button is actually pressed
        if(switch_value < 100)  
        //The ADC value for UP button should be approx. 0
            Serial.println("----UP BUTTON IS PRESSED----") ; 
        else if((switch_value > 400) && (switch_value < 600))
        //The ADC value for LEFT button should be approx.512
            Serial.println("----LEFT BUTTON IS PRESSED----");
        else if((switch_value > 600) && (switch_value < 725))
        //The ADC value for CENTRE button should be approx. 676
            Serial.println("----CENTRE BUTTON IS PRESSED") ; 
        else if((switch_value > 725) && (switch_value < 790))
        //The ADC value for RIGHT button should be approx. 768
            Serial.println("----RIGHT BUTTON IS PRESSED") ; 
        else if((switch_value > 790) && (switch_value < 850))
        //The ADC value for DOWN button should be approx. 819
            Serial.println("----DOWN BUTTON IS PRESSED----"); 
        else if(switch_value > 900) 
            Serial.println("----BUTTON IS RELEASED----");    
        prev_switch_value = switch_value ;    
  }   
}
