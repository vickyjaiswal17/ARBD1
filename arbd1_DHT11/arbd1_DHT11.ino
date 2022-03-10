#include<DHT.h>
float h,t,dhtpin=A1;
DHT dht(dhtpin,DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
}
void loop(){
  h=dht.readHumidity();
  t=dht.readTemperature();
  Serial.print("Humidity:");
  Serial.println(h);
  Serial.print("Temperatute:");
  Serial.println(t);
  delay(1000);
}
