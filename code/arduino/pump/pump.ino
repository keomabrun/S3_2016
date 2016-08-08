int waterPump = 9; // The output pin to actuate the Water Pump

void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT); // Declare the Water Pump as an OUTPUT:
  digitalWrite(waterPump, LOW); // Make sure the Water Pump is off.
}

void loop() {
  digitalWrite(waterPump, HIGH); // Operate the Water Pump
  delay(400);
  digitalWrite(waterPump, LOW); // Stop the Water Pump
  delay(2000);
}
