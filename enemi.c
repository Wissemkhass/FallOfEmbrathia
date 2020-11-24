#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "enemi.h"
#include "arcade.h"
void setrect2(SDL_Rect *clip)
{
  clip[0].x=0;
  clip[0].y=0;
  clip[0].w=107;
  clip[0].h=100;

  clip[1].x=110;
  clip[1].y=0;
  clip[1].w=126;
  clip[1].h=100;
  }

  enemie init_enemie(int lev)
  {
		
  	enemie En;
  	if(lev==1){En.enemi=IMG_Load("./data/image/enemi3.png");}
	else if(lev==2){En.enemi=IMG_Load("./data/image/enemi11.png");}
	else{En.enemi=IMG_Load("./data/image/enemi3.png");}
  	En.E=1;
  	En.PositionE.x=700;
	En.PositionE.y=450;
	setrect2(En.per2);
	En.framee=0;
	
		return En;
  }

 enemie2 init_enemie2(int lev)
  {
		
  	enemie2 En;
  	if(lev==1){En.yem=IMG_Load("./data/image/enemii.png");}
	else if(lev==2){En.yem=IMG_Load("./data/image/enemi10.png");}
	else{En.yem=IMG_Load("./data/image/enemi12.png");}
  	//En.E=1;
	En.j=0;
	En.j2=0;
	setrect2(En.per2);
	En.framee=0;
		En.pos[0].x=2000;
		En.pos[0].y=400;
		En.pos[1].x=3800;
		En.pos[1].y=400;
		return En;
  }
void positionenemi(enemie2 *En2)
{
int i;
if(En2->j==1 && En2->pos[0].x<2600){En2->j=1;}
else{En2->j=-1;}
if(En2->j==-1 && En2->pos[0].x>2000){En2->j=-1;}
else{En2->j=1;}
if(En2->j2==1 && En2->pos[1].x<4100){En2->j2=1;}
else{En2->j2=-1;}
if(En2->j2==-1 && En2->pos[1].x>3800){En2->j2=-1;}
else{En2->j2=1;}
if(En2->pos[0].x!=-10){En2->pos[0].x=En2->pos[0].x+(25*(En2->j));}
if(En2->pos[1].x!=-10){En2->pos[1].x=En2->pos[1].x+(25*(En2->j2));}

}

void afficheenemi(SDL_Rect PositionC,enemie2 *En2,SDL_Surface *fenetre)
{
	int i;
		SDL_Rect posE;
positionenemi(En2);
for(i=0;i<2;i++){	
posE.x=En2->pos[i].x-PositionC.x;
posE.y=En2->pos[i].y;
printf("%d \n",posE.x);
if(En2->pos[i].x!=10){SDL_BlitSurface(En2->yem,&(En2->per2[0]),fenetre,&posE);}
}
}



