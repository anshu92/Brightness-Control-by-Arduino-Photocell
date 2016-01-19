int sensorPin = A0;    // analog input pin to hook the sensor to
int sensorValue = 0;  // variable to store the value coming from the sensor
const int ledPin = 9;
int high = 0, low = 1023;

const int numReadings = 10;
  
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

 
void setup() { 
  Serial.begin(9600); // initialize serial communications 
  pinMode(ledPin, OUTPUT);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

}
 
void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(sensorPin);
  // add the reading to the total:
    readings[readIndex] = map(readings[readIndex], 0, 1023, 0, 255);

  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.write(average);
  analogWrite(ledPin, average);
  delay(10);        // delay in between reads for stability
  
}


