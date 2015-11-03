#include <OneWire.h>
#include <DallasTemperature.h>

static int ONE_WIRE_BUS = 2;



// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature TemperatureSensors(&oneWire);

int n = 0;
float MaxT;
float MinT;
float TemperatureArray[2];

void setup()
{
  Serial.begin(9600);
  TemperatureSensors.begin();
  TemperatureSensors.requestTemperatures();
  float Temperature = TemperatureSensors.getTempCByIndex(0);
  TemperatureArray[0] = Temperature;
  TemperatureArray[1] = Temperature;
}

void loop()
{
  // Leser tempratur fra sensor
  TemperatureSensors.requestTemperatures();
  float Temperature = TemperatureSensors.getTempCByIndex(0);
  
 
  
  if (Temperature > TemperatureArray[0])
  {
    TemperatureArray[0] = Temperature;
    n = n+1;
  }
  if (Temperature < TemperatureArray[1])
  {
    TemperatureArray[1] = Temperature;
  }
  
  
  // Skriver temp ut
  Serial.println();
  Serial.print("Temperatur= ");
  Serial.println(Temperature);
  Serial.print("Max= ");
  Serial.println(TemperatureArray[0]);
  Serial.print("Min= ");
  Serial.println(TemperatureArray[1]);
}
