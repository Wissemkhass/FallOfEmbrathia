#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "coin.h"


cooin init_coin()
{	
	int i;
	cooin C;
	C.coin=IMG_Load("./data/image/coin2.png");
	C.posc[0].x=0;
	C.posc[0].y=400;
	for(i=1;i<14;i++)
			{
				C.posc[i].x=C.posc[i-1].x+400;
          			 C.posc[i].y=400;
					//printf("%d \n",C.posc[i].x);
			}
return C;

}

void affichecoin(SDL_Rect PositionC,cooin *C,SDL_Surface *fenetre)
{
int i;
SDL_Rect posss;
posss.x=0;
posss.x=0;
for(i=0;i<13;i++)
		{
		
           if(C->posc[i].x!=-10){posss.x=C->posc[i].x-PositionC.x;
					posss.y=C->posc[i].y;SDL_BlitSurface(C->coin,NULL,fenetre,&posss);}
			}
}













