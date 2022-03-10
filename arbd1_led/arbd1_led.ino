int pinR=11;
int pinG=9;
int pinB=10;
void setup() {
  // put your setup code here, to run once:
pinMode(pinR,OUTPUT);
pinMode(pinG,OUTPUT);
pinMode(pinB,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinR,HIGH);
delay(500);
digitalWrite(pinR,LOW);
delay(500);
digitalWrite(pinG,HIGH);
delay(500);
digitalWrite(pinG,LOW);
delay(500);
digitalWrite(pinB,HIGH);
delay(500);
digitalWrite(pinB,LOW);
delay(500);
}
