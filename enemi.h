 #ifndef ENEMI_H_
#define ENEMI_H_
typedef struct enemie
{
	SDL_Surface *enemi;
	int E;//test vie 7ay wala miyet
	SDL_Rect PositionE;
	SDL_Rect per2[6];
	int framee;
	SDL_Surface *yem;
}enemie;
typedef struct enemie2
{
	SDL_Surface *yem;
	int j;
	int j2;
	//int E;//test vie 7ay wala miyet
	SDL_Rect per2[6];
	SDL_Rect pos[2];
	int framee;
	
}enemie2;
void setrect2(SDL_Rect *clip);
enemie init_enemie(int lev);
enemie2 init_enemie2(int lev);
void positionenemi(enemie2 *En);
void afficheenemi(SDL_Rect PositionC,enemie2 *En2,SDL_Surface *fenetre);
#endif
