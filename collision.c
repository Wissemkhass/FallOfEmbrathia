#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "collision.h"

SDL_Color GetPixel(SDL_Surface* pSurface, int x, int y)
{
  SDL_Color color;
  Uint32 col = 0;
  //determine position
  char* pPosition = (char*) pSurface->pixels;
  //offset by y
  pPosition += (pSurface->pitch * y);
  //offset by x
  pPosition += (pSurface->format->BytesPerPixel * x);
  //copy pixel data
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
  //convert color
  SDL_GetRGB (col, pSurface->format, &color.r , &color.g, &color.b);
  return (color);
}

int Collision(SDL_Rect a, SDL_Rect b)
{
  
   if((a.x >= b.x+b.w)    
  || (a.x + 100 <= b.x) 
  || (a.y >= b.y + b.h) 
  || (a.y + 120 <= b.y))
          return 0; 
   else
          return 1;
       
}


int Collision2222(SDL_Rect a, SDL_Rect b)
{
  
   if((a.x >= b.x+50)    
  || (a.x + 80 <= b.x) 
  || (a.y >= b.y + 50) 
  || (a.y + 30 <= b.y))
          return 0; 
   else
          return 1;
       
}///////// battle

int Collision222222(SDL_Rect a, SDL_Rect b)
{
  
   if((a.x >= b.x+50)    
  || (a.x + 80 <= b.x) 
  || (a.y >= b.y + 50) 
  || (a.y + 30 <= b.y))
          return 0; 
   else
          return 1;
       
}////versus

/////arcade
int Collision22(SDL_Rect a, SDL_Rect b)
{
  
   if((a.x >= b.x+b.w)    
  || (a.x + 100 <= b.x) 
  || (a.y >= b.y + b.h) 
  || (a.y + 120 <= b.y))
          return 0; 
   else
          return 1;
       
}





