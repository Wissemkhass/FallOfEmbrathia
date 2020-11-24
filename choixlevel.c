#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "choixlevel.h"
int chlevel(SDL_Surface *fenetre)
{int result=1;
int result2=1;
int joueur1=0;
int joueur2=0;
int run=1;
//SDL_Surface *fenetre;
SDL_Surface *choix5=IMG_Load("./data/image/choix1.png");
SDL_Surface *choix6=IMG_Load("./data/image/choix2.png");
SDL_Surface *choix7=IMG_Load("./data/image/choix3.png");
SDL_Surface *choix8=IMG_Load("./data/image/choix4.png");
SDL_Surface *vertt=IMG_Load("MENU03.png");
	//fenetre=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
//SDL_Init(SDL_INIT_EVERYTHING);
srand(time(NULL)); //initialiser le rand 
SDL_Rect PositionE;
PositionE.x=0;
PositionE.y=0;
SDL_Rect PositionV;
PositionV.x=0;
PositionV.y=0;
SDL_BlitSurface(vertt,NULL,fenetre,NULL);SDL_BlitSurface(choix6,NULL,fenetre,&PositionV);SDL_Flip(fenetre);
const int FPS=20;Uint32 start;
while(run==1)
{ start=SDL_GetTicks();
	 SDL_Event event;
  while(SDL_PollEvent(&event))
	{
if(event.type==SDL_KEYDOWN){
			
		if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==0)
			{PositionE.x=5;result=1;}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==5)
			{PositionE.x=10;result=2;}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==10)
			{PositionE.x=15;result=3;}
else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==15)
			{PositionE.x=0;result=0;}
			
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==0)
			{PositionE.x=15;result=3;}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==15)
			{PositionE.x=10;result=2;}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==10)
			{PositionE.x=5;result=1;}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==5)
			{PositionE.x=0;result=0;}
		
		if(event.key.keysym.sym==SDLK_b)
			{run=0;}
				
			
		if(event.key.keysym.sym==SDLK_ESCAPE)
			{result=-1;run=0;}	
	
		}//SDL_BlitSurface(vertt,NULL,fenetre,NULL);
		if(PositionE.x==0){SDL_BlitSurface(choix5,NULL,fenetre,NULL);}
			else if(PositionE.x==5){SDL_BlitSurface(choix6,NULL,fenetre,NULL);}
				else if(PositionE.x==10){SDL_BlitSurface(choix7,NULL,fenetre,NULL);}
			else if(PositionE.x==15){SDL_BlitSurface(choix8,NULL,fenetre,NULL);}
		SDL_Flip(fenetre);
}
 if(1000/FPS>SDL_GetTicks()-start)
   {SDL_Delay(1000/FPS-(SDL_GetTicks()-start));}
}
printf("\n %d",result);
return result;
}
