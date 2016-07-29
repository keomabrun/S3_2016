int sensor_pin = A0;
int waterPump = 9;

int sensor_val = 0;
int threashold = 200;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, LOW);
}

void loop() {
  sensor_val = analogRead(sensor_pin);
  Serial.println(sensor_val);
  if (sensor_val < threashold){
    digitalWrite(waterPump, HIGH);
    delay(400);
    digitalWrite(waterPump, LOW);
  }
  delay(1000);
}
