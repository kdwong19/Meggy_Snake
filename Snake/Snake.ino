

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
Point p2 = {4,4};
Point p3 = {4,4};
Point p4 = {4,4};
Point snakeArray[64] = {p1,p2,p3,p4};
int marker = 4;       //index of first empty segment of array
int direction = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  updateSnake();
 
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
  //Move Body
  for (int i = marker - 1; i > 0; i--)
  {
    //Copy the value at i-1 into i
    snakeArray[i] = snakeArray[i - 1];
  }
  
  // Move head
  if (direction == 0)
    //updates y
    snakeArray[0].y = snakeArray [0].y + 1;
    
 
    if (snakeArray[0].y > 7)
    {
      snakeArray[0].y = 0;
    }
  if (direction == 90)
    //updates x
    snakeArray[0].x = snakeArray[0].x + 1;
    //corrects for out of bounds
    if (snakeArray[0].x > 7)
    {
     snakeArray[0].x = 0;
    } 
  if (direction == 180)
    //updates y
    snakeArray[0].y = snakeArray[0].y - 1;
    
    if (snakeArray[0].y < 0)
    {
      snakeArray[0].y = 7;
    }
  if (direction == 270)
    //updates x
    snakeArray[0].x = snakeArray[0].x - 1;
    
    if (snakeArray[0].x < 0)
    {
     snakeArray[0].x = 7;
    }
}
void drawSnake()
{
  //Iterate the entire array to draw the snake
  for (int i = 0; i < marker; i++)
  {
    DrawPx(snakeArray[i].x, snakeArray[i].y,Yellow);
  }
}

