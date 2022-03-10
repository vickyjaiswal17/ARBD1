int potPin=A6;
int ledR=11;
int k,p;
void setup() {
  // put your setup code here, to run once:
pinMode(potPin,INPUT);
pinMode(ledR,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  k=analogRead(potPin);
Serial.println(k);
p=k*225./1023.;
analogWrite(ledR,p);
delay(100);
}
