int ledR=11;
int buttonPin=A1;
float k;
int c=0,p;
void setup() {
  // put your setup code here, to run once:
pinMode(ledR,OUTPUT);
pinMode(buttonPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
k=digitalRead(buttonPin);
delay(20);
p=k;
k=digitalRead(buttonPin);
if(k!=p)
{c++;}
if(c/2. == 10)
{ 
  digitalWrite(ledR,HIGH);
  
}
else
digitalWrite(ledR,LOW);
Serial.println(c);
}
