int ledR=11;
int buttonPin=A1;
float k;

void setup() {
  // put your setup code here, to run once:
pinMode(ledR,OUTPUT);
pinMode(buttonPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
k=digitalRead(buttonPin);
Serial.println(k);
if(k==1)
{digitalWrite(ledR,HIGH);}
else
{digitalWrite(ledR,LOW);}
}
