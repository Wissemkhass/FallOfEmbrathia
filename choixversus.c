#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

int choixvs(SDL_Surface *fenetre,int *choixJ1,int *choixJ2)
{int result=1;
int result2=1;
int joueur1=0;
int joueur2=0;
int run=1;
//SDL_Surface *fenetre;
SDL_Surface *choix1=IMG_Load("./data/image/choixjoueur.png");
SDL_Surface *choix3=IMG_Load("./data/image/choixjoueur_3.png");
SDL_Surface *choix2=IMG_Load("./data/image/choixjoueur_2.png");
SDL_Surface *choix4=IMG_Load("./data/image/choixjoueur_4.png");
SDL_Surface *choix5=IMG_Load("./data/image/choixjoueur_5.png");
SDL_Surface *choix6=IMG_Load("./data/image/choixjoueur_6.png");
SDL_Surface *vertt=IMG_Load("./data/image/veeert2.png");
	//ecran=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
SDL_Init(SDL_INIT_EVERYTHING);
srand(time(NULL)); //initialiser le rand 
SDL_Rect PositionE;
PositionE.x=0;
PositionE.y=0;
SDL_Rect PositionV;
PositionV.x=85;
PositionV.y=410;
SDL_BlitSurface(choix1,NULL,fenetre,NULL);SDL_BlitSurface(vertt,NULL,fenetre,&PositionV);SDL_Flip(fenetre);
const int FPS=20;Uint32 start;
while(run==1)
{ start=SDL_GetTicks();
	 SDL_Event event;
  while(SDL_PollEvent(&event))
	{
if(event.type==SDL_KEYDOWN){
			
		if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==0 && joueur1==0)
			{
				PositionE.x=5;
				result=2;
			}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==5 && joueur1==0)
			{
				PositionE.x=10;
				result=3;
			}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==10 && joueur1==0)
			{
				PositionE.x=15;
				result=4;
			}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==15 && joueur1==0)
			{
				PositionE.x=20;
				result=5;
			}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==20 && joueur1==0)
			{
				PositionE.x=25;
				result=6;
			}
		else if(event.key.keysym.sym==SDLK_RIGHT && PositionE.x==25 && joueur1==0)
			{
				PositionE.x=0;
				result=1;
			}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==0 && joueur1==0)
			{
				PositionE.x=25;
				result=6;
			}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==5 && joueur1==0)
			{
				PositionE.x=0;
				result=1;
			}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==10 && joueur1==0)
			{
				PositionE.x=5;
				result=2;
			}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==15 && joueur1==0)
			{
				PositionE.x=10;
				result=3;
			}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==20 && joueur1==0)
			{
				PositionE.x=15;
				result=4;
			}
		else if(event.key.keysym.sym==SDLK_LEFT && PositionE.x==25 && joueur1==0)
			{
				PositionE.x=20;
				result=5;
			}
		if(event.key.keysym.sym==SDLK_d && PositionV.x==85 && joueur2==0)
			{
				PositionV.x+=110;
				result2=2;
			}
		else if(event.key.keysym.sym==SDLK_d && PositionV.x==85+110 && joueur2==0)
			{
				PositionV.x+=110;
				result2=3;
			}
		else if(event.key.keysym.sym==SDLK_d && PositionV.x==85+220 && joueur2==0)
			{
				PositionV.x+=110;
				result2=4;
			}
		else if(event.key.keysym.sym==SDLK_d && PositionV.x==85+330 && joueur2==0)
			{
				PositionV.x+=110;
				result2=5;
			}
		else if(event.key.keysym.sym==SDLK_d && PositionV.x==85+440 && joueur2==0)
			{
				PositionV.x+=110;
				result2=6;
			}
		else if(event.key.keysym.sym==SDLK_d && PositionV.x==85+550 && joueur2==0)
			{
				PositionV.x=85;
				result2=1;
			}
		else if(event.key.keysym.sym==SDLK_q && PositionV.x==85 && joueur2==0)
			{
				PositionV.x=85+550;
				result2=6;
			}
		else if(event.key.keysym.sym==SDLK_q && PositionV.x==85+110 && joueur2==0)
			{
				PositionV.x=85;
				result2=1;
			}
		else if(event.key.keysym.sym==SDLK_q && PositionV.x==85+220 && joueur2==0)
			{
				PositionV.x=85+110;
				result2=2;
			}
		else if(event.key.keysym.sym==SDLK_q && PositionV.x==85+330 && joueur2==0)
			{
				PositionV.x=85+220;
				result2=3;
			}
		else if(event.key.keysym.sym==SDLK_q && PositionV.x==85+440 && joueur2==0)
			{
				PositionV.x=85+330;
				result2=4;
			}
		else if(event.key.keysym.sym==SDLK_q && PositionV.x==85+550 && joueur2==0)
			{
				PositionV.x=85+440;
				result2=5;
			}
		
		if(event.key.keysym.sym==SDLK_b)
			{
				joueur1=1;
			}	
		if(event.key.keysym.sym==SDLK_k)
			{
				joueur2=1;
			}
		if(event.key.keysym.sym==SDLK_j)
			{
				joueur2=0;
			}
		if(event.key.keysym.sym==SDLK_n)
			{
				joueur1=0;
			}	
		if(event.key.keysym.sym==SDLK_ESCAPE)
			{
				joueur1=0;
				joueur2=0;
				run=0;
			}	
	}
		if(joueur1==1 && joueur2==1)
			{
				run=0;
			}
		if(PositionE.x==0)
			{
				SDL_BlitSurface(choix1,NULL,fenetre,NULL);
			}
		else if(PositionE.x==5)
			{
				SDL_BlitSurface(choix2,NULL,fenetre,NULL);
			}
		else if(PositionE.x==10)
			{
				SDL_BlitSurface(choix3,NULL,fenetre,NULL);
			}
		else if(PositionE.x==15)
			{
				SDL_BlitSurface(choix4,NULL,fenetre,NULL);
			}
		else if(PositionE.x==20)
			{
				SDL_BlitSurface(choix5,NULL,fenetre,NULL);
			}
		else if(PositionE.x==25)
			{
				SDL_BlitSurface(choix6,NULL,fenetre,NULL);
			}
		SDL_BlitSurface(vertt,NULL,fenetre,&PositionV);
		SDL_Flip(fenetre);
}
 if(1000/FPS>SDL_GetTicks()-start)
   {SDL_Delay(1000/FPS-(SDL_GetTicks()-start));}
}
printf("\n %d",result);
*choixJ1=result;
*choixJ2=result2;
return joueur1;
}
