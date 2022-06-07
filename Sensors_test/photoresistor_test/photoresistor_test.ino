/**************
name: photoresistor
function: hold the photoresistor with yur fingers and check value at A0 on Serial Monitor
****************/

const int photocellPin = A0;
const int ledPin = 13;

int outputValue = 0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  outputValue = analogRead(photocellPin);
  Serial.println(outputValue);
  if(outputValue >= 400)
  {
    digitalWrite(ledPin,HIGH); //turn on the led
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
  delay(1000); //delay 1s
}
