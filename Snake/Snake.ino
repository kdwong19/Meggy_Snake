

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

int xapple = random(8);
int yapple = random(8);
int speed = 250;
int binary = 0;
boolean gameOver = false;
struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
Point p2 = {4,4};

Point snakeArray[64] = {p1,p2};
int marker = 2;       //index of first empty segment of array
int direction = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  
if (gameOver == false) //makes sure game isn't over
  {
  drawSnake();
  DrawPx(xapple,yapple,Red);
 
  //Checks for overlap to end game
  if (ReadPx(snakeArray[0].x,snakeArray[0].y) == Yellow)
  {
    gameOver = true;
    //sets endgame
  }
 CheckButtonsDown(); // movement script
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
 

  if (ReadPx(snakeArray[0].x,snakeArray[0].y) == Red) 
  {   // adds apple code and length growth code
  xapple = random(8);
  yapple = random(8);
  Tone_Start(18182, 50);
  binary = binary * 2 + 1;
  marker = marker + 1;
  }
  if (binary > 255)
  {
    binary = 0;
    Tone_Start(9000, 50);
    speed = speed - 25;
  }
 SetAuxLEDs(binary);
 DisplaySlate(); 
 delay(speed);
 ClearSlate();
  }
else
death();
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
  DrawPx(snakeArray[0].x,snakeArray[0].y,Blue);
  for (int i = 1; i < marker; i++)
  {
   
    DrawPx(snakeArray[i].x, snakeArray[i].y,Yellow);
    
  }
}

void death()
{
  DrawPx(0,0,DimAqua);
  DrawPx(1,1,DimAqua);
  DrawPx(2,2,DimAqua);
  DrawPx(3,3,DimAqua);
  DrawPx(4,4,DimAqua);
  DrawPx(5,5,DimAqua);
  DrawPx(6,6,DimAqua);
  DrawPx(7,7,DimAqua);
  DrawPx(7,0,DimAqua);
  DrawPx(6,1,DimAqua);
  DrawPx(5,2,DimAqua);
  DrawPx(4,3,DimAqua);
  DrawPx(3,4,DimAqua);
  DrawPx(2,5,DimAqua);
  DrawPx(1,6,DimAqua);
  DrawPx(0,7,DimAqua);
  DisplaySlate();
  delay(2000);
}


