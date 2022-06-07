#include <DHT.h>
#define DHTTYPE DHT11

DHT dht(3,DHTTYPE); 

void setup() {  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float value2 = dht.readTemperature();  //temp value
  float value3 = dht.readHumidity();  // humi value

  //print the datas on serial monitor
  Serial.print("Temperature = ");
  Serial.print(value2);
  Serial.print("Humidity = ");
  Serial.print(value3);

  delay(2000);
  
}
