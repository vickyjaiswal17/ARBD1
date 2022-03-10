int buttonpin=A1;
int switch_value;
int p;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonpin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
switch_value=analogRead(buttonpin);
delay(20);
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
       
}
