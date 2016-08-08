int sensor_pin = A0;
int waterPump = 2;
int sensor_val = 0;
int threshold = 300;
const int MAX_SENS_VAL = 770;

void setup() {
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, LOW);
}

void loop() {
  sensor_val = analogRead(sensor_pin);
  Serial.println(sensor_val*100/MAX_SENS_VAL);
  if (sensor_val <= threshold){
    digitalWrite(waterPump, HIGH);
    delay(500);
    digitalWrite(waterPump, LOW);
    delay(2000);
    
  }
  else delay(1000);
}
