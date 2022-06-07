/****
name: Barometer
function: you can see the value of temperature  and air pressure displayed on Serial Monitor
****/

#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;

void setup() {
  Serial.begin(9600);

  if(pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail\n\n");
    while(1);
  }

}

void loop() {
  char status;
  double T,P,p0,a;

  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);

    status = pressure.getTemperature(T);
    if(status !=0)
    {
      Serial.print("Temperature: ");
      Serial.print(T,2);
      Serial.println("deg C ");
      Serial.println("     "); //skip a line

      status = pressure.startPressure(3);
      if(status != 0)
      {
        delay(status);

        status = pressure.getPressure(P,T);
        if(status != 0)
        {
          Serial.print("Pressure: ");
          Serial.print(P,2);
          Serial.println("          "); //skipping lines for easier reading
          Serial.println("          ");
        }
        else Serial.println("error retrieving pressure measurements\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  delay(1000); //pause for 5 seconds
}
