int potPin=A6;
int k;
void setup() {
  // put your setup code here, to run once:
pinMode(potPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  k=analogRead(potPin);
Serial.println(k);
delay(100);
}
