const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);
  float ppm = map(voltage, 0.4, 2.0, 0, 400);
  
  Serial.print("Alcohol Concentration: ");
  Serial.print(ppm);
  Serial.println(" ppm");
  
  if (ppm > 80) {
    Serial.println("Warning: Do not drive!");
  }
  
  delay(1000);
}
