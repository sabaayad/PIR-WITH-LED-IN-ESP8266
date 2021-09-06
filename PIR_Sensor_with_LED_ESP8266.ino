#include<Wire.h>
const int led = 0; //GPIO0    D3
 const int sensor = 5; //GPI5    D1
int pirState = LOW;
void setup() {
  pinMode(led, OUTPUT); 
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}
 
void loop() {
 
  int sensorval = digitalRead(sensor);
   Serial.print("PIR_Sensor_Value=   \t");
  Serial.println(sensorval);
  delay(1000);
  if (sensorval == HIGH)
  {
    digitalWrite(led, HIGH);
    if (pirState == LOW) 
         {
               Serial.println("Motion detected!");
            // We only want to print on the output change, not state
             pirState = HIGH;
         }
  }
  else 
  {
    digitalWrite(led, LOW);
    if (pirState == HIGH)
     {
            // we have just turned of
             Serial.println("Motion ended!");
           // We only want to print on the output change, not state
           pirState = LOW;
       
     }
  }//elseif
           }//loop
