

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int xapple = random(8);
int yapple = random(8);
int speed = 250;
int binary = 0;

struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};

int direction = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
 
 CheckButtonsDown();
 if (Button_Up)
 {
  direction = 0;
 }
 if (Button_Right)
 {
  direction = 90;
 }
 if (Button_Down)
 {
  direction = 180;
 }
 if (Button_Left)
 {
  direction = 270;
 }
 
 updateSnake();
 drawSnake();
 DrawPx(xapple,yapple,Red);
  if (ReadPx(p1.x,p1.y) == Red)
  {
  xapple = random(8);
  yapple = random(8);
  Tone_Start(18182, 50);
  binary = binary * 2 + 1;
  }
  if (binary > 255)
  {
    binary = 0;
    Tone_Start(9000, 50);
  }
 SetAuxLEDs(binary);
 DisplaySlate(); 
 delay(speed);
 ClearSlate();
}

//checks the direction and updates the x or y value.
void updateSnake()
{
  if (direction == 0)
//updates y
  p1.y = p1.y + 1;
  //corrects for out of bounds
  if (p1.y > 7)
  {
    p1.y = 0;
  }
  if (direction == 90)
//updates x
  p1.x = p1.x + 1;
  //corrects for out of bounds
  if (p1.x > 7)
  {
    p1.x = 0;
  }
  if (direction == 180)
//updates y
  p1.y = p1.y - 1;
  //corrects for out of bounds
  if (p1.y < 0)
  {
    p1.y = 7;
  }
  if (direction == 270)
//updates x
  p1.x = p1.x - 1;
  //corrects for out of bounds
  if (p1.x < 0)
  {
    p1.x = 7;
  }
}

void drawSnake()
{
  DrawPx(p1.x,p1.y,Yellow);
}

