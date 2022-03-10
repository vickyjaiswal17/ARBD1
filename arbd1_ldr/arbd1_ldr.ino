int ldrPin=A7;
int k;
void setup() {
  // put your setup code here, to run once:
pinMode(ldrPin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  k=analogRead(ldrPin);
Serial.println(k);
delay(1000);
}
