#include <Arduboy2.h>

const byte PROGMEM pole[] =
{
// width, height,
1, 14,
0xff, 
0x3f, 
};


const byte PROGMEM pole2[] =
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
  12, 11,
0x83, 0x03, 0xf6, 0xf8, 0xfc, 0x9c, 0x7c, 0x7c, 0x98, 0xf6, 0x03, 0x83, 
0x01, 0x00, 0x01, 0x03, 0x07, 0x05, 0x01, 0x05, 0x05, 0x01, 0x00, 0x01, 
  
};

const byte PROGMEM dog_3[] =
{
 12, 11,
0x83, 0x03, 0xf6, 0xf8, 0xfc, 0x9c, 0x7c, 0x7c, 0x98, 0xf6, 0x03, 0x83, 
0x01, 0x04, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x04, 0x06, 0x01,  
  
};

const byte PROGMEM dog_4[] =
{
  14, 11,
0x40, 0x83, 0x03, 0xf6, 0xf8, 0xfc, 0x9c, 0x7c, 0x7c, 0x98, 0xf6, 0x03, 0x83, 0x40, 
0x00, 0x00, 0x04, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x06, 0x00, 0x00, 
};  



Arduboy2 arduboy;
Sprites sprites;
byte frame = 0;
byte x = 0;
byte y = 0;
char cdir = 'T'; // T, L, R, A

#define CHAR_WIDTH 16
#define CHAR_HEIGHT 16
#define X_MAX (WIDTH - CHAR_WIDTH) // 128-16
#define Y_MAX (HEIGHT - CHAR_HEIGHT)// 64-16
 int pole_x;
int pole_y;
void setup()
{
  
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(60);

  
}
void loop() {
  if (!(arduboy.nextFrame())){
    return;
  }
  
  if(arduboy.pressed(RIGHT_BUTTON) && (x < X_MAX)){
    x++;
    cdir = 'R';
  }
  if(arduboy.pressed(LEFT_BUTTON) && (x > 0)){
    x--;
    cdir = 'L';
  }
  if(arduboy.pressed(UP_BUTTON) && (y > 0)){
    y--;
    cdir = 'A';
  }
  if(arduboy.pressed(DOWN_BUTTON) && (y < Y_MAX)){
    y++;
    cdir = 'T';
  }

  arduboy.clear();
  
 arduboy.setCursor(x, y);
 
  switch(cdir)
  {
    case 'T':
       sprites.drawSelfMasked(x, y, dog_1, frame);
       break;
       
    case 'L':
       sprites.drawSelfMasked(x, y, dog_2, frame);
       break;
       
    case 'R':
        sprites.drawSelfMasked(x, y, dog_3, frame);
        break;
        
    case 'A':
      sprites.drawSelfMasked(x, y, dog_4, frame);
      break;
      
  }
  //for(pol_y=0; pole_x =0 ; pole_x < 128; pole_x++)
 
   // 0,0 1,0 2,0 3,0 
   
 sprites.drawSelfMasked(pole_x++, 14, pole, frame);
  arduboy.display();   
  if(pole_x >=128 ){
    pole_x = -10;
  }
  
   sprites.drawSelfMasked(pole_x++, 50, pole2, frame);
  arduboy.display();   
  if(pole_x >=128 ){
    pole_x = -10;
  }
  
  while (!arduboy.nextFrame()) { }  // Wait for next frame
 

  // if(cdir == 'T'){
  //   sprites.drawSelfMasked(x, y, walk, frame);
  // }
  // else if(cdir == 'L'){
  //   sprites.drawSelfMasked(x, y, walk_left, frame);
  // }
  // else if(cdir == 'R'){
  //   sprites.drawSelfMasked(x, y, walk_right, frame);
  // }
  // else if(cdir == 'A'){
  //   sprites.drawSelfMasked(x, y, walk_away, frame);
  // }
  
  
//  if (arduboy.everyXFrames(60)) frame++;
//  
//  if (frame > 1) frame = 0;
//  
  arduboy.display();
  
}
