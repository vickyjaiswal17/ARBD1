int ldrPin=A7;
int ledR=9;
int k;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledR,OUTPUT);
pinMode(ldrPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  k=analogRead(ldrPin);
Serial.println(k);

  analogWrite(ledR,k*255./1023);
 
  
}
