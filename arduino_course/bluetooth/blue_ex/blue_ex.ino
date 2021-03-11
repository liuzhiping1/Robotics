// Basic bluetooth test sketch 2. Send data to Arduino
//
// Remember to remove the power from the bluetooth module when uploading the code....
 
char serialByte;
const int  LEDPIN = 13; 
 
void setup() 
{
    // Match the baud rate of the bluetooth module.
    Serial.begin(9600); 
    pinMode(LEDPIN, OUTPUT);
 
    Serial.println("on to turn on the LED on PIN 13");
    Serial.println("off to turn off the LED on PIN 13");
}
 
void loop() 
{
 
    // wait until data is available
    while (!Serial.available());  
 
    // read next available byte
    serialByte = Serial.read(); 
 
    // If the byte is a 1 turn on the LED
    if( serialByte == 'on' ) digitalWrite(LEDPIN, HIGH);
 
    // If the byte is a 0 turn off the LED
    if( serialByte == 'off' ) { digitalWrite(LEDPIN, LOW); } 
 
    delay(100);
}
