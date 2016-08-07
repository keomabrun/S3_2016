int waterPump = 9; // The output pin to actuate the Water Pump
int pin=A0;
float moisture_value;
float moisture_average;
int moisture_value_counter;
float moisture_sum;
void setup() {
  Serial.begin(9600);
  pinMode(waterPump, OUTPUT); // Declare the Water Pump as an OUTPUT:
  digitalWrite(waterPump, LOW); // Make sure the Water Pump is off.
  pinMode(pin,INPUT);
  moisture_sum=0;
  moisture_value_counter=0;
}

void loop() {

  moisture_value=analogRead(pin);
  //Serial.println(moisture_value);
  /*if (moisture_value<=210)
  {
    digitalWrite(waterPump, HIGH);
    delay(400);
    digitalWrite(waterPump, LOW);
    delay(60000);
  }*/
  //delay(10)
  moisture_sum=moisture_sum+moisture_value;
  moisture_value_counter=moisture_value_counter+1;
  
  if (moisture_value_counter==1000)
  {
   moisture_average=moisture_sum/moisture_value_counter;
   Serial.println(" sum "+String(moisture_sum));
   Serial.println(moisture_value_counter);
   Serial.println(moisture_average);
   delay(1000); 
  
  exit(0);
  }
  
  
  
  
  /*digitalWrite(waterPump, HIGH); // Operate the Water Pump
  delay(400);
  digitalWrite(waterPump, LOW); // Stop the Water Pump
  delay(2000);*/
}
