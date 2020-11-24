 #ifndef BACK_H_
#define BACK_H_

typedef struct backgrd
{
	SDL_Surface *backg;//surface de la background 
	SDL_Surface *pSurface;//surface de la background de la collision psurface(esmha le9dim)
	int numb;//le nombre de stage
	SDL_Rect PositionC;//la postion de la caméra
	SDL_Surface *danger;
	SDL_Rect Positiond;
}backgrd;


backgrd init_backgrd(int lev,int r);
#endif
