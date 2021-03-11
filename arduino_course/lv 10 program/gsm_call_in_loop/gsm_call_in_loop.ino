#include <SPGSM.h>

SPGSM spgsm;
void setup()
{
  spgsm.begin(9600);
  spgsm.call("9600001628",5000);
  
}
void loop()
{
  
}
