int x;
void setup() {
  // put your setup code here, to run once:
pinMode(A6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x=analogRead(A6);
  x=x/1023.*1000;
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,OUTPUT);
digitalWrite(A4,LOW);
pinMode(A5,OUTPUT);
digitalWrite(A5,HIGH);
delay(x);
pinMode(A2,INPUT);
pinMode(A3,OUTPUT);
digitalWrite(A3,LOW);
pinMode(A4,INPUT);
pinMode(A5,OUTPUT);
digitalWrite(A5,HIGH);
delay(x);
}
