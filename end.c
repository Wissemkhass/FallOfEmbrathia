#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "end.h"
int Collision9(SDL_Rect a, SDL_Rect b);
void setrect3(SDL_Rect *clip)
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
void setrect4(SDL_Rect *clip)
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


int fin(SDL_Surface *fenetre)
{
//SDL_Init(SDL_INIT_EVERYTHING);
//TTF_Init();
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
SDL_Surface *backg2;
SDL_Surface *personage;
SDL_Surface *personagel;
SDL_Surface *personage2;
SDL_Surface *personagel2;
SDL_Surface *personage3;
SDL_Surface *speechpe;
SDL_Surface *speechpe2;
SDL_Surface *speechpe3;
SDL_Surface *boule;
SDL_Surface *boule2;
SDL_Surface *boule3;
SDL_Surface *boule4;
SDL_Surface *boule5;
SDL_Surface *sword;
SDL_Surface *sword2;
SDL_Surface *sword1;
SDL_Surface *sword12;
SDL_Surface *enemi;
SDL_Surface *fleche;
SDL_Rect per[7];
SDL_Rect per22[7];
setrect3(per);
setrect3(per22);
SDL_Rect Position;
Position.x=0;
Position.y=450;
SDL_Rect Position2;
Position2.x=0;
Position2.y=450;
SDL_Rect Position3;
Position3.x=0;
Position3.y=450;
SDL_Rect PositionE;
PositionE.x=720;
PositionE.y=450;
SDL_Rect Positionsp;
Positionsp.x=20;
Positionsp.y=330;
SDL_Rect Positionsp2;
Positionsp2.x=370;
Positionsp2.y=330;
SDL_Rect Positionsp3;
Positionsp3.x=370;
Positionsp3.y=330;
SDL_Rect PositionS;
PositionS.x=0;
PositionS.y=480;
SDL_Rect PositionS1;
PositionS1.x=0;
PositionS1.y=480;
SDL_Rect PositionB;
PositionB.x=50;
PositionB.y=0;
SDL_Rect PositionB2;
PositionB2.x=200;
PositionB2.y=0;
SDL_Rect PositionB3;
PositionB3.x=350;
PositionB3.y=0;
SDL_Rect PositionB4;
PositionB4.x=500;
PositionB4.y=0;
SDL_Rect PositionB5;
PositionB5.x=650;
PositionB5.y=0;
SDL_Rect PositionC;
PositionC.x=0;
PositionC.y=0;
PositionC.w=800;
PositionC.h=600;
//ecran=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
backg=IMG_Load("./data/image/chaos.png");
backg2=IMG_Load("./data/image/Chaos-pic2.png");
if(backg==NULL){printf("error");}
boule=IMG_Load("./data/image/1.png");
boule2=IMG_Load("./data/image/2.png");
boule3=IMG_Load("./data/image/3.png");
boule4=IMG_Load("./data/image/4.png");
boule5=IMG_Load("./data/image/5.png");
sword=IMG_Load("./data/image/swordxx.png");
sword2=IMG_Load("./data/image/swordxx2.png");
sword1=IMG_Load("./data/image/swordxx.png");
sword12=IMG_Load("./data/image/swordxx2.png");
personage=IMG_Load("./data/image/perso.png");
personagel=IMG_Load("./data/image/perso2.png");
personage2=IMG_Load("./data/image/kali.png");
personage3=IMG_Load("./data/image/mitch.png");
personagel2=IMG_Load("./data/image/perso2.png");
enemi=IMG_Load("./data/image/enemi2.png");
speechpe=IMG_Load("./data/image/speech3.png");
speechpe2=IMG_Load("./data/image/speech4.png");
speechpe3=IMG_Load("./data/image/speech5.png");
SDL_Rect per2[2];
setrect4(per2);
//fleche=IMG_Load("./data/image/fleche.png");
SDL_Rect PositionF;
PositionF.x=550;
PositionF.y=230;
Uint32 colorkey = SDL_MapRGB( personagel->format,255,255,255);
SDL_SetColorKey( personage, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
SDL_SetColorKey( personagel, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
SDL_BlitSurface(personage,&per[0],fenetre,&Position);
SDL_BlitSurface(speechpe,NULL,fenetre,&Positionsp);
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);
//SDL_BlitSurface(fleche,NULL,fenetre,&PositionF);
SDL_EnableKeyRepeat(120,30);
SDL_Flip(fenetre);
SDL_Event event;
PositionE.x=-2000;
 //creation font 
TTF_Font *font;
font=TTF_OpenFont("font2.ttf",40);

//Creation fontcolor
SDL_Color fontcolor={200,200,00};
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
		{Position.x+=10;Position2.x+=6;Position3.x+=2;frame++;if(frame>3){frame=0;}if(Position.x>500){mvb=0;frame=0;}}
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);

if(S2==1){SDL_BlitSurface(sword1,NULL,fenetre,&PositionS1);}
if(B==1){SDL_BlitSurface(boule,NULL,fenetre,&PositionB);}
if(B2==1){SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);}
if(Position.y!=450){SDL_BlitSurface(personage,&per[2],fenetre,&Position);}
else
{SDL_BlitSurface(personage,&per[frame],fenetre,&Position);}
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);
SDL_BlitSurface(personage2,&per[frame],fenetre,&Position2);
SDL_BlitSurface(personage3,&per[frame],fenetre,&Position3);
SDL_Flip(fenetre);
if(mvb==0){speech=0;SDL_Delay(1000);speech2222=1;}
	}
else
{
	if(PositionB.y<150){PositionB.y+=10;}if(PositionB2.y<150){PositionB2.y+=8;}if(PositionB3.y<150){PositionB3.y+=6;}if(PositionB4.y<150){PositionB4.y+=4;}if(PositionB5.y<150){PositionB5.y+=3;}
		SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
		if(Position2.x>0){SDL_BlitSurface(personage2,&per[frame],fenetre,&Position2);}
if(Position3.x>0){SDL_BlitSurface(personage3,&per[frame],fenetre,&Position3);}
		SDL_BlitSurface(boule,NULL,fenetre,&PositionB);
		SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);
		SDL_BlitSurface(boule3,NULL,fenetre,&PositionB3);
		SDL_BlitSurface(boule4,NULL,fenetre,&PositionB4);
		SDL_BlitSurface(boule5,NULL,fenetre,&PositionB5);
		
SDL_Flip(fenetre);
if(PositionB5.y>=150){run=0;SDL_Delay(1000);}
}
if(run==0){
SDL_BlitSurface(backg2,&PositionC,fenetre,NULL);
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
		if(Position2.x>0){SDL_BlitSurface(personage2,&per[frame],fenetre,&Position2);}
if(Position3.x>0){SDL_BlitSurface(personage3,&per[frame],fenetre,&Position3);}
		SDL_BlitSurface(boule,NULL,fenetre,&PositionB);
		SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);
		SDL_BlitSurface(boule3,NULL,fenetre,&PositionB3);
		SDL_BlitSurface(boule4,NULL,fenetre,&PositionB4);
		SDL_BlitSurface(boule5,NULL,fenetre,&PositionB5);
SDL_Flip(fenetre);SDL_Delay(3000);
}
SDL_Flip(fenetre);
if(1000/FPS>SDL_GetTicks()-start)
   {SDL_Delay(1000/FPS-(SDL_GetTicks()-start));}
S=0;
S2=0;

}
return 0;
}


int Collision9(SDL_Rect a, SDL_Rect b)
{
  
   if((a.x >= b.x+50)    
  || (a.x + 80 <= b.x) 
  || (a.y >= b.y + 50) 
  || (a.y + 30 <= b.y))
          return 0; 
   else
          return 1;
       
}
