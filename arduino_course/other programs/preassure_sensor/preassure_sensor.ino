// Reads A0 every 100ms and sends voltage value over serial
int ps=A0;
void setup() 
{
  // Start serial at 9600 baud
  Serial.begin(9600); 
}

    void loop() 
{
  // Read the input on analog pin 0:
  ps = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = ps * (5.0 / 1023.0);
  Serial.print("preassure=");
  // Print out the value you read:
  Serial.println(voltage);
  // Wait 100 milliseconds
  delay(1000);
}
