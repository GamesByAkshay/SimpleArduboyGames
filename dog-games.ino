/*
Hello, World! example
June 11, 2015
Copyright (C) 2015 David Martinez
All rights reserved.
This code is the most basic barebones code for writing a program for Arduboy.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
*/

#include <Arduboy2.h>

// make an instance of arduboy used for many functions
Arduboy2 arduboy;
Sprites sprites;


const byte PROGMEM pole[] =
{
// width, height,
1, 14,
0xff, 
0x3f, 
};

const byte PROGMEM dog_1[] =
{
  12, 11,
  0x03, 0x03, 0xf6, 0xf8, 0xfc, 0x9c, 0x7c, 0x7c, 0x98, 0xf6, 0x03, 0x03, 
  0x03, 0x00, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x06, 0x00, 0x03, 
  
};
const byte PROGMEM dog_2[] =
{
  14, 11,
0x40, 0x83, 0x03, 0xf6, 0xf8, 0xfc, 0x9c, 0x7c, 0x7c, 0x98, 0xf6, 0x03, 0x83, 0x40, 
0x00, 0x00, 0x04, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x06, 0x00, 0x00, 
};  

int x=128;
int y=44;
char cdir='D';
int score;

byte frame=0;
// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  // initiate arduboy instance
  arduboy.begin();

  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.setFrameRate(15);
}


// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  // pause render until it's time for the next frame
  if (!(arduboy.nextFrame()))
    return;

  // first we clear our screen to black
  arduboy.clear();
  
  // draw a line
  arduboy.drawLine(0,44,128,44,WHITE);
  sprites.drawSelfMasked(x--, 30, pole, frame);
  if (x==0){
    x=132;
  }
  
  if(arduboy.pressed(UP_BUTTON)){
     score=score+1;
    cdir='U';
  }
  else{
    cdir='D';
  }
  
switch(cdir){
  
  case 'U':
  sprites.drawSelfMasked(7,16 , dog_2, frame);
  break;
  
  case 'D':
  sprites.drawSelfMasked(7,32,dog_1,frame);
  break;
}
  
  


  // we set our cursor 5 pixels to the right and 10 down from the top
  // (positions start at 0, 0)
  arduboy.setCursor(99,9);
  arduboy.print("score=");
  
  arduboy.setCursor(124, 9);

  // then we print to screen what is in the Quotation marks ""
  arduboy.print(score);
  

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}
