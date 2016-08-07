#include<RCSwitch.h>

// Iniciate the radio
RCSwitch mySwitch= RCSwitch();

int sensor_pin = A0;
int waterPump = 2;
unsigned long sensor_val;
int moisture_percentage;
int threshold = 300;
int send_pin=11;
const int MAX_SENS_VAL = 900;

void setup() {
  
  // Declaring which pin we use and what do we use them for
  pinMode(sensor_pin, INPUT);
  pinMode(waterPump, OUTPUT);
  pinMode(send_pin,OUTPUT);
  
  // Set the pump to 0, so it won't start pumping at the begining
  digitalWrite(waterPump, LOW);

  // Enabling transmission
  mySwitch.enableTransmit(send_pin);
}

void loop() {
  // Reading the moisture sensor value
  sensor_val = analogRead(sensor_pin);

  // Converting value to percentage
  moisture_percentage=int(sensor_val*100/MAX_SENS_VAL);
  
  // Sending the moisture_percentage through channel 24
  mySwitch.send(moisture_percentage, 24);
    if (sensor_val <= threshold){
    digitalWrite(waterPump, HIGH);
    delay(500);
    digitalWrite(waterPump, LOW);
    delay(2000);
  }
  else delay(20000);
}
