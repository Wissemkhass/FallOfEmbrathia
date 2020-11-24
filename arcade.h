
#ifndef ARCADE_H_
#define ARCADE_H_
#include "background.h"
#include "personnage.h"
#include "mvt_joueur.h"
#include "enemi.h"
#include "coin.h"
int arcade(joueur *j,SDL_Surface *fenetre,int level,mouv_joueur *MJ,backgrd *BG,enemie *En,int *score,int *vie,int *i,SDL_Rect *PositionC,int u,int *lev,cooin *C,SDL_Surface *text,SDL_Rect postext,SDL_Surface *text0,SDL_Rect postext0,TTF_Font *font,SDL_Color fontcolor,Mix_Chunk *firem,Mix_Chunk *swordm,enemie2 *En2);
#endif
