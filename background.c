#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
backgrd init_backgrd(int lev,int r)
{
	backgrd BG;//surface du background

	if(lev==2)
	{
	BG.pSurface=IMG_Load("./data/image/ccc1.jpg");
	BG.backg=IMG_Load("./data/image/desert.jpg");
	}
	else if(lev==3)
	{
	BG.pSurface=IMG_Load("./data/image/colisionFFFFF.jpg");
	BG.backg=IMG_Load("./data/image/amirfinalBG.jpg");
	}
	else if(lev==1)
	{
	BG.backg=IMG_Load("./data/image/AAA1.jpg");
	BG.pSurface=IMG_Load("./data/image/aaaaa.jpg");
	}
	//if(r==0){
	BG.PositionC.x=10;
	BG.PositionC.y=0;
	BG.PositionC.w=800;
	BG.PositionC.h=600;
	//}
	BG.danger=IMG_Load("./data/image/Danger2.png");
	BG.Positiond.x=250;
	BG.Positiond.y=250;
	return BG;
}
