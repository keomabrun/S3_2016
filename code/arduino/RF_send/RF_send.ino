#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int send_pin = 10;
int send_val = 15;

void setup() {
  Serial.begin(9600);

  pinMode(send_pin, OUTPUT);
    
  mySwitch.enableTransmit(send_pin);
}

void loop() {
  mySwitch.send(send_val, 24);
  delay(5000);
}
