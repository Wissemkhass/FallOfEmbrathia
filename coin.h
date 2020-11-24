 #ifndef COIN_H_
#define COIN_H_
typedef struct cooin
{
	SDL_Rect posc[20];
	SDL_Surface *coin;
	

}cooin;

cooin init_coin();
void affichecoin(SDL_Rect PositionC,cooin *C,SDL_Surface *fenetre);
#endif
