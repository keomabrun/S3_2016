int sensor_pin = A0;
int sensor_val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
}

void loop() {
  sensor_val = analogRead(sensor_pin);
  Serial.println(sensor_val);
  delay(1000);
}
