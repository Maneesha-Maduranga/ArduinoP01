int relayPin = 8;
int sensor_pin = A0; 
int output_value ;
void setup()         
{ 
  Serial.begin(9600);                 
  pinMode(relayPin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop()
{
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
 
 if(moisture_percentage<35.0){
  digitalWrite(relayPin, HIGH);
 }
 else
 {
  digitalWrite(relayPin, LOW);       
 }
 delay(1000);
}
