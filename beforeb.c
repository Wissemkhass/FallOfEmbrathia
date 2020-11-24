#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "beforeb.h"
int Collision4(SDL_Rect a, SDL_Rect b);
void setrect111(SDL_Rect *clip)
{
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=350/4;
  clip[0].h=100;

  clip[1].x=130;
  clip[1].y=0;
  clip[1].w=300/3;
  clip[1].h=100;

  clip[2].x=390;
  clip[2].y=0;
  clip[2].w=250/2;
  clip[2].h=100;

  clip[3].x=735;
  clip[3].y=0;
  clip[3].w=240;
  clip[3].h=100;

  clip[4].x=595;
  clip[4].y=0;
  clip[4].w=290/3;
  clip[4].h=100;

  clip[5].x=315;
  clip[5].y=0;
  clip[5].w=240/2;
  clip[5].h=100;
  
  clip[6].x=0;
  clip[6].y=0;
  clip[6].w=350/4;
  clip[6].h=100;

}
void setrect222(SDL_Rect *clip)
{
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=100;
  clip[0].h=100;

  clip[1].x=70;
  clip[1].y=0;
  clip[1].w=70;
  clip[1].h=100;
  }


int bbattleVS(SDL_Surface *fenetre,int lev,int choix)
{
//SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
srand(time(NULL)); //initialiser le rand 
int w=0;
int y=0;
 char ch1[50];
     char ch[50];
int frap1=0;;
int frap2=0;
int run=1;
int pppp=0;
int pppp2=0;
//frame de joueur a droite
int frame=0;int frame2=0;
//frame de joueur a gauche
int framel=3;int framel2=3;
//test si le joueur est entrain de sauter
int jump=0;int jump2=0;
//test si le joueur chutte
int jumps=-1;int jumps2=-1;
//test si le joueur est a gauche ou a droite
int LR=0;int LR2=1;
//test si la boule est cliquer ou non
int B=0;int B2=0;
//test si la boule est a gauche
int testleftB=0;int testleftB2=0;
//int y,x;
// la vitesse de joueur
int yvel=0;int yvel2=0;
int xvel2=10;
int xvel=10;
//test de vie de l enemie
int E=1;
int framee=0;
int xb,yb;
xb=0;
yb=0;
int S=0;
int S2=0;
const int FPS=15;
Uint32 start;
//SDL_Surface *fenetre;
SDL_Surface *backg;
SDL_Surface *personage;
SDL_Surface *personagel;
SDL_Surface *personage2;
SDL_Surface *personagel2;
SDL_Surface *speechpe;
SDL_Surface *speechpe2;
SDL_Surface *speechpe3;
SDL_Surface *boule;
SDL_Surface *boule2;
SDL_Surface *sword;
SDL_Surface *sword2;
SDL_Surface *sword1;
SDL_Surface *sword12;
SDL_Surface *enemi;
SDL_Surface *fleche;
SDL_Rect per[7];
SDL_Rect per22[7];
setrect111(per);
setrect111(per22);

//creation d'une nouvelle surface
SDL_Rect Position;
Position.x=0;
Position.y=450;

//creation d'une nouvelle surface
SDL_Rect Position2;
Position2.x=600;
Position2.y=450;

//creation d'une nouvelle surface
SDL_Rect PositionE;
PositionE.x=720;
PositionE.y=450;

//creation d'une nouvelle surface
SDL_Rect Positionsp;
Positionsp.x=20;
Positionsp.y=330;

//creation d'une nouvelle surface
SDL_Rect Positionsp2;
Positionsp2.x=370;
Positionsp2.y=330;

//creation d'une nouvelle surface
SDL_Rect Positionsp3;
Positionsp3.x=370;
Positionsp3.y=330;

//creation d'une nouvelle surface
SDL_Rect PositionS;
PositionS.x=0;
PositionS.y=480;

//creation d'une nouvelle surface
SDL_Rect PositionS1;
PositionS1.x=0;
PositionS1.y=480;

//creation d'une nouvelle surface
SDL_Rect PositionB;
PositionB.x=0;
PositionB.y=450;

//creation d'une nouvelle surface
SDL_Rect PositionB2;
PositionB2.x=0;
PositionB2.y=450;

//creation d'une nouvelle surface
SDL_Rect PositionC;
PositionC.x=10;
PositionC.y=0;
PositionC.w=800;
PositionC.h=600;
//fenetre=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);

if(lev==3)
{backg=IMG_Load("./data/image/amirfinalBG.png");}
if(lev==2)
{backg=IMG_Load("./data/image/desert.jpg");}
if(lev==1)
{backg=IMG_Load("./data/image/AAA1.jpg");}
if(backg==NULL){printf("error");}

sword=IMG_Load("./data/image/swordxx.png");
sword2=IMG_Load("./data/image/swordxx2.png");
sword1=IMG_Load("./data/image/swordxx.png");
sword12=IMG_Load("./data/image/swordxx2.png");
if(choix==4){
personage=IMG_Load("./data/image/perso.png");
personagel=IMG_Load("./data/image/perso2.png");
personage2=IMG_Load("./data/image/quesar1.png");
personagel2=IMG_Load("./data/image/quesar2.png");
boule=IMG_Load("./data/image/boule2.png");
boule2=IMG_Load("./data/image/boule6.png");
}
else if(choix==1){
personage=IMG_Load("./data/image/kali.png");
personagel=IMG_Load("./data/image/kali2.png");
personage2=IMG_Load("./data/image/quesar1.png");
personagel2=IMG_Load("./data/image/quesar2.png");
boule=IMG_Load("./data/image/boule6.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else if(choix==6){
personage=IMG_Load("./data/image/mitch.png");
personagel=IMG_Load("./data/image/mitch2.png");
personage2=IMG_Load("./data/image/kali.png");
personagel2=IMG_Load("./data/image/kali2.png");
boule=IMG_Load("./data/image/boule3.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else if(choix==2){
personage=IMG_Load("./data/image/perrr.png");
personagel=IMG_Load("./data/image/perrr2.png");
personage2=IMG_Load("./data/image/mitch.png");
personagel2=IMG_Load("./data/image/mitch2.png");
boule=IMG_Load("./data/image/boule3.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else if(choix==3){
personage=IMG_Load("./data/image/quesar1.png");
personagel=IMG_Load("./data/image/quesar2.png");
personage2=IMG_Load("./data/image/perrr.png");
personagel2=IMG_Load("./data/image/perrr2.png");
boule=IMG_Load("./data/image/boule3.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else
{
personage=IMG_Load("./data/image/perso.png");
personagel=IMG_Load("./data/image/perso2.png");
personage2=IMG_Load("./data/image/perrr.png");
personagel2=IMG_Load("./data/image/perrr2.png");
boule=IMG_Load("./data/image/boule2.png");
boule2=IMG_Load("./data/image/boule6.png");
}
enemi=IMG_Load("./data/image/enemi2.png");
speechpe=IMG_Load("./data/image/speech3.png");
speechpe2=IMG_Load("./data/image/speech4.png");
speechpe3=IMG_Load("./data/image/speech5.png");
SDL_Rect per2[2];
setrect222(per2);
//fleche=IMG_Load("fleche.png");

//creation d'une nouvelle surface
SDL_Rect PositionF;
PositionF.x=550;
PositionF.y=230;

Uint32 colorkey = SDL_MapRGB( personagel->format,255,255,255);
SDL_SetColorKey( personage, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
SDL_SetColorKey( personagel, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
SDL_BlitSurface(personage,&per[0],fenetre,&Position);
SDL_BlitSurface(personagel2,&per22[3],fenetre,&Position2);
SDL_BlitSurface(speechpe,NULL,fenetre,&Positionsp);
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);
//SDL_BlitSurface(fleche,NULL,fenetre,&PositionF);
SDL_EnableKeyRepeat(120,30);
SDL_Flip(fenetre);
SDL_Event event;
PositionE.x=-2000;
 //creation font 
TTF_Font *font;
font=TTF_OpenFont("./data/font/font.ttf",40);

//Creation fontcolor
SDL_Color fontcolor={200,200,0};
//creation d'un ttf
SDL_Surface *text;
//creation d'un ttf
SDL_Surface *text2;
SDL_Rect postext;
postext.x=50;
postext.y=50;
SDL_Rect postext2;
postext2.x=550;
postext2.y=50;

int boull;
int speech=1;
int speech2222=0;
int speechp=1;
int mvb=1;
int speechb=1;

//SDL_Delay(2000);
while(run==1)
{
 char ch1[50];
     char ch[50];
   start=SDL_GetTicks();
Uint8 *keystate=SDL_GetKeyState(NULL);
  if(speech==1)
	{
			//if(speechp==1){}
//if(keystate[SDLK_SPACE])
//{if(speechb==1){speechb=0;}}
			if(mvb==1)
				{
					if(Position2.x>=390 && Position.x<=380)
						{
							Positionsp.x+=5;
							Position.x+=5;
							Position2.x-=5;
							framel2++;
							frame++;
						}
					else
						{
							mvb=0;
							speechp=0;
							frame=0;
							framel2=3;
						}
					if(framel2>5)
						{
							framel2=3;
						}
				}
			if(frame>2)
				{
					frame=0;
				}
	
				//speechp=0;
			
			if(speechb==0)
				{
					speech=0;
					Position2.x=600;
					Position2.y=450;
				}
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);

if(S2==1)
	{
		SDL_BlitSurface(sword1,NULL,fenetre,&PositionS1);
	}

if(B==1)
	{
		SDL_BlitSurface(boule,NULL,fenetre,&PositionB);
	}
if(B2==1)
	{
		SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);
	}
if(Position.y!=450)
	{
		SDL_BlitSurface(personage,&per[2],fenetre,&Position);
	}
else
	{
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
	}
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);

if(LR2==1)
	{
		SDL_BlitSurface(personagel2,&per22[framel2],fenetre,&Position2);
		if(S==1)
			{
				SDL_BlitSurface(sword2,NULL,fenetre,&PositionS);
			}
	}
else
	{
		SDL_BlitSurface(personage2,&per22[frame2],fenetre,&Position2);
		if(S==1)
			{
				SDL_BlitSurface(sword,NULL,fenetre,&PositionS);
			}
	}
if(speechp==1)
	{
		SDL_BlitSurface(speechpe,NULL,fenetre,&Positionsp);
	}

if(speechb==1 && mvb==0)
	{
		SDL_BlitSurface(speechpe2,NULL,fenetre,&Positionsp2);
	}
SDL_Flip(fenetre);

if(mvb==0)
	{
		speech=0;SDL_Delay(5000);speech2222=1;
	}

	}
else if(speech2222==1)
	{
		SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
		SDL_BlitSurface(personagel2,&per22[framel2],fenetre,&Position2);
		SDL_BlitSurface(speechpe3,NULL,fenetre,&Positionsp);
		SDL_Flip(fenetre);
		SDL_Delay(5000);
		speech2222=0;
	}
else
	{
		Position.x+=14;framel2++;frame++;
		if(framel2>5)
			{
				framel2=3;
			}
		if(frame>2)
			{
				frame=0;
			}
		SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
		SDL_BlitSurface(personagel2,&per22[3],fenetre,&Position2);
		SDL_Flip(fenetre);

if(Position.x>960)
	{
		run=0;
	}

	}
if(1000/FPS>SDL_GetTicks()-start)
   {SDL_Delay(1000/FPS-(SDL_GetTicks()-start));}
S=0;
S2=0;

}
return 0;
/*
SDL_FreeSurface(enemi);
SDL_FreeSurface(boule);
SDL_FreeSurface(personagel);
SDL_FreeSurface(personage);
SDL_FreeSurface(personagel2);
SDL_FreeSurface(personage2);
SDL_FreeSurface(backg);
SDL_FreeSurface(fenetre);
TTF_Quit();
SDL_Quit();*/
}


int Collision4(SDL_Rect a, SDL_Rect b)
{
  
   if((a.x >= b.x+50)    
  || (a.x + 80 <= b.x) 
  || (a.y >= b.y + 50) 
  || (a.y + 30 <= b.y))
          return 0; 
   else
          return 1;
       
}
