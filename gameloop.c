#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "personnage.h"
#include "mvt_joueur.h"
#include "background.h"
#include "enemi.h"
#include "arcade.h"
#include "collision.h"
#include "coin.h"
#include "end.h"
void load(int *lev,int*choix,backgrd *BG,int *score,int *vie,int *i);
void reset_file();
int game_loop(int choix,joueur j,SDL_Surface *fenetre,int reponse1,SDL_Surface *text,SDL_Rect postext,SDL_Surface *text0,SDL_Rect postext0,int *score,int *vie,TTF_Font *font,SDL_Color fontcolor)
{
		
	printf("\n %d",reponse1);
	 Mix_Chunk *firem =Mix_LoadWAV( "./data/music/fire.wav" ); ; 
	Mix_Chunk *swordm =Mix_LoadWAV( "./data/music/coiin.wav" );  
	int i=0;//variable sur la barre de vie
	int u=1;
	int h,d,z;
	int loop=1;
	int lev=1;//numero de stage
	
	*score=0;//score
	*vie=3;//vie 
	mouv_joueur MJ;//variable de type mouv_joueur(structure mvt_joueur.h)
	backgrd BG;//variable de type backgrd(structure background.h)
	enemie En;//variable de type enemie(structure enemi.h)
	enemie2 En2;
	
	cooin C;
	//initialisation
	C=init_coin();//initialisaion du coin
	j=init_joueur(choix);//l initialisation du joueur
	En=init_enemie(1);//l initialisation de l enemie
	En2=init_enemie2(1);
	BG=init_backgrd(lev,reponse1);//l initialisation du background
	MJ=init_mouv();//l initialisation des mouvements du joueur
	
		
	
	SDL_Surface *level;
	SDL_Surface *tend=IMG_Load("./data/image/theend.png");
	SDL_Surface *game_over;
	//coin

	SDL_Surface *coin;
	fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
			game_over=IMG_Load("./data/image/skulll.jpg");
			level=IMG_Load("./data/image/LEVEL1.png");
			coin=IMG_Load("./data/image/coin2.png");
			SDL_Rect PositionC;
			PositionC.x=800;
			PositionC.y=450;
			SDL_BlitSurface(level,NULL,fenetre,NULL);
			
			
			SDL_Flip(fenetre);
			SDL_Delay(2000);


	//la boucle principale
	SDL_Event event;
	SDL_Color couleur;
	

	if(reponse1==1)//selon reponse de menu (new game ou load game) si reponse1==1 --> load game
		{
				load(&lev,&choix,&BG,score,vie,&i);
				j=init_joueur(choix);
  				En=init_enemie(lev);
				En2=init_enemie2(lev);
				MJ=init_mouv();
					reponse1=0;
		}
	//else if(reponse1==0){reset_file();}
		//Mix_FadeOutMusic(10) ; 
	//Mix_PlayMusic(music_level1,1);
	if(lev==1){while(loop!=0)
		{
			
			if(i==250)// si la barre de vie est terminer il va refaire le stage
			{

				j=init_joueur(choix);
  				En=init_enemie(1);
				En2=init_enemie2(1);
				MJ=init_mouv();
				BG=init_backgrd(lev,0);
				i=0;
			}			
			
			
loop=arcade(&j,fenetre,1,&MJ,&BG,&En,score,vie,&i,&PositionC,u,&lev,&C,text,postext,text0,postext0,font,fontcolor,firem,swordm,&En2);
			if(event.type==SDL_QUIT) {return 0;}
			}}
			if((vie!=0 && (BG.PositionC.x>5000 && BG.PositionC.x<6000)) || lev==2)
			{
				loop=1;
				level=IMG_Load("./data/image/LEVEL2.png");
				SDL_BlitSurface(level,NULL,fenetre,NULL);
				
			
			SDL_Flip(fenetre);
			SDL_Delay(2000);
				j=init_joueur(choix);
				 C=init_coin();
  				En=init_enemie(2);
				En2=init_enemie2(2);
				MJ=init_mouv();
				BG=init_backgrd(2,reponse1);
					if(reponse1==1)//selon reponse de menu (new game ou load game) si reponse1==1 --> load game
		{
				load(&lev,&choix,&BG,score,vie,&i);
				j=init_joueur(choix);
  				En=init_enemie(lev);
				En2=init_enemie2(lev);
				MJ=init_mouv();
				reponse1=0;
		}
			while(loop!=0)
			{
			
				if(i==250)
			{	
				j=init_joueur(choix);
  				En=init_enemie(2);
				En2=init_enemie2(2);
				MJ=init_mouv();
				BG=init_backgrd(2,reponse1);
				i=0;
			}			
				
loop=arcade(&j,fenetre,1,&MJ,&BG,&En,score,vie,&i,&PositionC,u,&lev,&C,text,postext,text0,postext0,font,fontcolor,firem,swordm,&En2);
			if(event.type==SDL_QUIT) {return 0;}
			
			}
			}
			if((vie!=0 && (BG.PositionC.x>5000 && BG.PositionC.x<6000)) || lev==3)
			{
				loop=1;
level=IMG_Load("./data/image/LEVEL3.png");
				SDL_BlitSurface(level,NULL,fenetre,NULL);
				
			
			SDL_Flip(fenetre);
			SDL_Delay(2000);
				j=init_joueur(choix);
				 C=init_coin();
  				En=init_enemie(3);
				En2=init_enemie2(3);
				MJ=init_mouv();
				BG=init_backgrd(3,reponse1);
			if(reponse1==1)//selon reponse de menu (new game ou load game) si reponse1==1 --> load game
		{
				load(&lev,&choix,&BG,score,vie,&i);
				j=init_joueur(choix);
  				En=init_enemie(lev);
				En2=init_enemie2(lev);
				MJ=init_mouv();
					reponse1=0;
		}
			
			while(loop!=0)
			{
				if(i==250)
			{
				j=init_joueur(choix);
  				En=init_enemie(3);
				En2=init_enemie2(3);
				MJ=init_mouv();
				BG=init_backgrd(3,reponse1);
				i=0;
			}			
				
loop=arcade(&j,fenetre,1,&MJ,&BG,&En,score,vie,&i,&PositionC,u,&lev,&C,text,postext,text0,postext0,font,fontcolor,firem,swordm,&En2);
			if(event.type==SDL_QUIT) {return 0;}
			if((vie!=0 && (BG.PositionC.x>5000 && BG.PositionC.x<6000)))
				{fin(fenetre);SDL_BlitSurface(tend,NULL,fenetre,NULL);
			SDL_Flip(fenetre);
			SDL_Delay(2000);}
			}
			}	
			if(*vie<1)
			{
			SDL_BlitSurface(game_over,NULL,fenetre,NULL);
			SDL_Flip(fenetre);
			SDL_Delay(2000);
		    
			}
		
	
	
	return 0;

}

void load(int *lev,int*choix,backgrd *BG,int *score,int *vie,int *i)
{
int x,y;
FILE *f;
f=fopen("save","r");
if(f==NULL){printf("ERROR loading file");}
fscanf(f,"%d %d %d %d %d %d %d",lev,choix,&x,&y,score,vie,i);
BG->PositionC.x=x;
BG->PositionC.y=y;
fclose(f);
}
void reset_file()
{
FILE *f;
f=fopen("save","w");
if(f==NULL){printf("ERROR loading file");}
fprintf(f,"%d %d %d %d %d %d %d",1,1,10,0,0,3,0);
}




