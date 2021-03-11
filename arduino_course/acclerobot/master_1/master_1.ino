#include <SoftwareSerial.h>
SoftwareSerial s(10, 11); //RX,TX
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  s.begin(9600);
}

void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);
  int f = analogRead(A2);
  s.print(x);
  s.print(y);
  s.print(f);
}
