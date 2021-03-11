#include <SPGSM.h>
SPGSM spgsm;
void setup()
{
  spgsm.begin(9600);
  spgsm.call("9600001628",10000);
  delay(2000);
}
void loop()
{
}



