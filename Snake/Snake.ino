

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
 DrawPx(p1.x,p1.y,Yellow);
 DisplaySlate(); 
 delay(1000);

 ClearSlate();
 DisplaySlate();
 delay(1000);
}


