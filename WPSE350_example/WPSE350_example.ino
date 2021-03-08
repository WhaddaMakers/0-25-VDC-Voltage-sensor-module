/*
  Analog input, serial output
  Reads an analog input pin, scales the reading to correspond to the voltage
  at the input of a voltage conversion module, prints the results to the Serial Monitor.
  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe
  modified 8 March 2021
  by Midas Gossye (Whadda/Velleman)
  Based on Arduino AnalogInOutSerial code
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the voltage sensor is attached to

int sensorValue = 0;        // value read from the voltage sensor
float sensorVoltage = 0;    // value output to the PWM (analog out)

const float conversion_factor = 0.2; // voltage conversion/scaling factor
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // calculate the voltage:
  sensorVoltage = ((float)sensorValue/1023)*5.0*conversion_factor;

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t voltage = ");
  Serial.println(sensorVoltage,2);

  // wait 10 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(10);
}
