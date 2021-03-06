
int  val = 0; 
char code[10]; 
int bytesread = 0; 

void setup() { 

Serial.begin(2400); // RFID reader SOUT pin connected to Serial RX pin at 2400bps 
pinMode(2,OUTPUT);   // Set digital pin 2 as OUTPUT to connect it to the RFID /ENABLE pin 
digitalWrite(2, LOW);                  // Activate the RFID reader
}  


 void loop() { 

  if(Serial.available() > 0) {          // if data available from reader 
    if((val = Serial.read()) == 10) {   // check for header 
      bytesread = 0; 
      while(bytesread<10) {              // read 10 digit code 
        if( Serial.available() > 0) { 
          val = Serial.read(); 
          if((val == 10)||(val == 13)) { // if header or stop bytes before the 10 digit reading 
            break;                       // stop reading 
          } 
          code[bytesread] = val;         // add the digit           
          bytesread++;                   // ready to read next digit  
        } 
      } 
      if(bytesread == 10) {              // if 10 digit read is complete 
        Serial.print("TAG code is: ");   // possibly a good TAG 
        Serial.println(code);            // print the TAG code 
      } 
      bytesread = 0; 
      digitalWrite(2, HIGH);                  // deactivate the RFID reader for a moment so it will not flood
           delay(1500);                       // wait for a bit 
           digitalWrite(2, LOW);                  // Activate the RFID reader
    } 
  } 
} 

// extra stuff
// digitalWrite(2, HIGH);             // deactivate RFID reader
