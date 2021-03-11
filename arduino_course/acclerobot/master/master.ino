#include <SoftwareSerial.h>
SoftwareSerial s(10, 11); //RX,TX
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  s.begin(9600);
}
void loop()
{
  int x = analogRead(A0);
  int y = analogRead(A1);
  if (x >= 315 && x <= 330 && y >= 315 && y <= 335)
  {
    s.print("a");//stp
  }
  ///////////////////////////////////////////////////////////
  else if (x >= 315 && x <= 330 && y >= 336 && y <= 349)
  {
    s.print("b");//fwd
  }
  else if (x >= 315 && x <= 330 && y >= 350 && y <= 363)
  {
    s.print("c");//fwd
  }
  else if (x >= 315 && x <= 330 && y >= 364 && y <= 377)
  {
    s.print("d");//fwd
  }
  else if (x >= 315 && x <= 330 && y >= 378 && y <= 391)
  {
    s.print("e");//fwd
  }
  ////////////////////////////////////////////////////////
  else if (x >= 315 && x <= 330 && y >= 314 && y <= 298)
  {
    s.print("f");//back
  }
  else if (x >= 315 && x <= 330 && y >= 297 && y <= 284)
  {
    s.print("g");//back
  }
  else if (x >= 315 && x <= 330 && y >= 283 && y <= 270)
  {
    s.print("h");//back
  }
  else if (x >= 315 && x <= 330 && y >= 269 && y <= 256)
  {
    s.print("i");//back
  }
  ///////////////////////////////////////////////////////////////
  else if (x >= 314 && x <= 298 && y >= 315 && y <= 335)
  {
    s.print("j");//left
  }
  else if (x >= 297 && x <= 284 && y >= 315 && y <= 335)
  {
    s.print("k");//left
  }
  else if (x >= 283 && x <= 270 && y >= 315 && y <= 335)
  {
    s.print("l");//left
  }
  else if (x >= 269 && x <= 256 && y >= 315 && y <= 335)
  {
    s.print("m");//left
  }
  /////////////////////////////////////////////////////////////
  else if (x >= 330 && x <= 346 && y >= 315 && y <= 335)
  {
    s.print("n");//right
  }
  else if (x >= 347 && x <= 260 && y >= 315 && y <= 335)
  {
    s.print("o");//right
  }
  else if (x >= 361 && x <= 274 && y >= 315 && y <= 335)
  {
    s.print("p");//right
  }
  else if (x >= 375 && x <= 388 && y >= 315 && y <= 335)
  {
    s.print("q");//right
  }
}

