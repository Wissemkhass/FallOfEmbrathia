#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"
#include "mvt_joueur.h"
#include "background.h"
#include "enemi.h"
#include "collision.h"
#include "battle.h"
#include "beforeb.h"
#include "pausej.h"
#include "coin.h"
#include "text.h"


void input_update(joueur *j,mouv_joueur *MJ,backgrd *BG,int *a,SDL_Color couleur,Mix_Chunk *firem,Mix_Chunk *swordm);
void save(int lev,int choix,backgrd *BG,int *score,int *vie,int *i);
void affichage(SDL_Surface *fenetre,joueur *j,mouv_joueur *MJ,backgrd *BG,SDL_Color couleur,enemie *En,int *vie,int *score,int *i,cooin *C,SDL_Surface *text,SDL_Rect postext,SDL_Surface *text0,SDL_Rect postext0,TTF_Font *font,SDL_Color fontcolor,enemie2 *En2);

int arcade(joueur *j,SDL_Surface *fenetre,int level,mouv_joueur *MJ,backgrd *BG,enemie *En,int *score,int *vie,int *i,SDL_Rect *PositionC,int u,int *lev,cooin *C,SDL_Surface *text,SDL_Rect postext,SDL_Surface *text0,SDL_Rect postext0,TTF_Font *font,SDL_Color fontcolor,Mix_Chunk *firem,Mix_Chunk *swordm,enemie2 *En2)
{
int GRAVITE=6;

int saut;
int reponse;//reponse de sous menu (Sauv Quit Load)
	int batt=0;// Test si le joueur rbe7 l Boss wella la
	int a=0;//condition ki tenzel 3Al echappe yarja3 ll menu
	SDL_Color couleur;
	
	//appelle de la fonction de la collision et l input et l update
	couleur=GetPixel(BG->pSurface,j->PositionJ.x+BG->PositionC.x+60,j->PositionJ.y+20);//appelle ll fonction de collision
	input_update(j,MJ,BG,&a,couleur,firem,swordm);//chniya bech y7ot l utilisateur	
	
	

	//elle va etre un fonction
	if(MJ->B==1 && j->PositionB.x<800 && MJ->testleftB==0)//kif tousel le(er l ecran tetna7a(kif yabda lperso 3al limin
		{
    			j->PositionB.x+=30;//
		}
	else if(MJ->B==1 && j->PositionB.x>0 && MJ->testleftB==1)//kif tousel le(er l ecran tetna7a(kif yabda lperso 3al issar
		{
    			j->PositionB.x-=30;//boule avec l enemie
		}
	else
		{
			MJ->B=0;//faire disparaitre la boule si elle n arrive pas a toucher l enemie
		}
  	if((Collision(j->PositionB,En->PositionE)==1)&& En->E==1 && MJ->B==1)//collision boule avec l enemie
		{
			En->E=0;
			j->PositionB.x=-10;             // Initialisation mte3 boule w enemi 
			MJ->B=0;
			
		}

  	if((Collision(j->PositionJ,En->PositionE)==1) && En->E==1 && MJ->jumps!=0)// Collision entre enemi et joueur
  		{
   	 		*i=*i+25;//barre de vie yon9es               
   			 En->E=0;
	 
        	}
if((Collision(j->PositionJ,En->PositionE)==1) && En->E==1 && MJ->jumps==0)// Collision entre enemi et joueur
  		{
   	 		              
   			 En->E=0;MJ->jump=1;MJ->jumps=1;MJ->saut=0;
	 
        	}
		
  	if(a==0)
    		{
			MJ->frame=0;
			MJ->framel=3;
		}
	if(MJ->jump==1 && MJ->jumps==1 && MJ->saut<10)
		{
			MJ->saut=MJ->saut+1;j->PositionJ.y-=18;//le joueur commence a sauter 
		}
	else if(MJ->jump==1 && MJ->jumps==1 && MJ->saut>=10)
		{
			MJ->jumps=0;//si le joueur atteint le maximum de saut jumps va prendre 0
		}
	else if(MJ->jump==1 && (couleur.r!=255 && couleur.g!=255 && couleur.b!=255) && MJ->jumps==0)
		{
			j->PositionJ.y=j->PositionJ.y+GRAVITE*j->masse;//le joueur commence a chutter
		}
	else
		{
			MJ->jump=0;
			MJ->yvel=0;
			MJ->jumps=-1;
			MJ->saut=0;
		}//si le joueur est a terre tous les valeurs de saut sont reinstaller 
	if((couleur.r!=255 && couleur.g!=255 && couleur.b!=255) && (couleur.r!=0 && couleur.g!=0 && couleur.b!=0) && MJ->jumps==-1)
		{
			j->PositionJ.y=j->PositionJ.y+GRAVITE*j->masse;//
		}
	if(MJ->frame>2)
		{
			MJ->frame=0;
		}
	if(MJ->framel>5)
		{
			MJ->framel=3;
		}
	//printf("%d\n",En->framee);
		

//L'affichage	
	 //affichage(j,MJ,BG,couleur,En,*vie,*score,i);//
	 
		
	if(En->PositionE.x!=10){En->PositionE.x-=20;}//avancer l'enemie

	if(En->E==0)
		{
			if(BG->PositionC.x%500==0){En->PositionE.x=750;En->E=1;MJ->B=0;}
			else{En->PositionE.x=-10;}
			
			
			En->PositionE.y=(rand()%120)+330;//(entre 450 -- 330) 
		}
	En->framee++;
	if(En->framee>1 )	
		{
			En->framee=0;
			//En->E=0;
		}
		En2->framee++;
	if(En2->framee>1 )	
		{
			En2->framee=0;
			//En->E=0;
		}int cocoin;SDL_Rect posss;
			for(cocoin=0;cocoin<2;cocoin++)
				{if(En2->pos[cocoin].x!=-10){posss.x=En2->pos[cocoin].x-BG->PositionC.x;
posss.y=En2->pos[cocoin].y;
if(Collision(j->PositionB,posss)==1){En2->pos[cocoin].x=-10;MJ->B=0;}
if(Collision(j->PositionJ,posss)==1 && MJ->jumps!=0){*i=*i+75;En2->pos[cocoin].x=-10;}
if(Collision(j->PositionJ,posss)==1 && MJ->jumps==0){En2->pos[cocoin].x=-10;MJ->jump=1;MJ->jumps=1;MJ->saut=0;}}
}
  

			if(j->PositionJ.y>580){*i=250;}
 if(*i==250 )
	{
		*vie=*vie-1;
	} 
		

		for(cocoin=0;cocoin<14;cocoin++)
			{printf("%d \n",C->posc[cocoin].x);posss.x=C->posc[cocoin].x-BG->PositionC.x;
					posss.y=C->posc[cocoin].y;
					if(Collision22(posss,j->PositionJ)==1)
						{Mix_PlayChannel(-1,swordm,0);printf("1 \n");C->posc[cocoin].x=-10;C->posc[cocoin].y=-10;*score=*score+1;break;}
				
			}
	
	 affichage(fenetre,j,MJ,BG,couleur,En,vie,score,i,C,text,postext,text0,postext0,font,fontcolor,En2);//

 Uint8 *keystate=SDL_GetKeyState(NULL);

if(keystate[SDLK_ESCAPE]){
reponse=pause(fenetre);
if(reponse==0)
{

save(*lev,j->num,BG,score,vie,i);
BG->PositionC.x=8000;
}
else if(reponse==2)
{
BG->PositionC.x=8000;
}
reponse=-1;
}

//Reglage de l'FPS
	int FPS=20;
  	int start;
	SDL_Event event;
  	start=SDL_GetTicks();
	if(1000/FPS>SDL_GetTicks()-start)
	   {
		SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
	   }
if((BG->PositionC.x>4900 && BG->PositionC.x<8000 && *lev!=1) || (BG->PositionC.x>4690 && BG->PositionC.x<8000 && *lev==1))

{bbattleVS(fenetre,*lev,j->num);
while(batt==0 && *vie>0)
{batt=battleVS(fenetre,vie,*lev,j->num);}
if(vie>0){BG->PositionC.x=5500;*lev=*lev+1;}
else{BG->PositionC.x=8000;}
}

 if(*vie==0 || BG->PositionC.x>5000 )
 {
  return 0;
 }

else
 {
  return 1;
 }




}

Uint32 t_prev;
Uint32 dt=1;
Uint32 dx=1;
//int FPS=100;

void input_update(joueur *j,mouv_joueur *MJ,backgrd *BG,int *a,SDL_Color couleur,Mix_Chunk *firem,Mix_Chunk *swordm)
	{
/*
		t_prev = SDL_GetTicks();
		dt=(SDL_GetTicks()-t_prev);
		
		if(MJ->xvel>0) { 
			MJ->acceleration=-0.001;
			
		}

		if(MJ->xvel <0) {
			MJ->acceleration=0;
			
		}
	*/			


		Uint8 *keystate=SDL_GetKeyState(NULL);
    		SDL_Event event;

   		// SDL_Color couleur;
   		
   		// couleur=GetPixel(BG->pSurface,j->PositionJ.x+BG->PositionC.x,j->PositionJ.y);
		
		 if(keystate[SDLK_b] && MJ->B==0)
                { 
                	Mix_PlayChannel(-1,firem,0);
				 MJ->B=1;
                		j->PositionB.x=j->PositionJ.x;//la boule va prendre la position de joueur (x)
                		j->PositionB.y=j->PositionJ.y+20;// la boule va se decaler un peu
            			*a=1;    
				MJ->testleftB=MJ->LR;//la boule va prendre la position gauche ou droite de l utilisateur
		}
                 if(keystate[SDLK_RIGHT])
                {
                		MJ->frame++;*a=1;
				MJ->LR=0;//joueur  a droite
 	     		if(couleur.r==255 && couleur.g==255 && couleur.b==255 || couleur.r==0 && couleur.g==0 && couleur.b==0)//tester si le joueur est a terre ou non
                    		{ 
					/*
					dt+=2;
					printf("\n****dt=%d****\n",dt);
					MJ->acceleration+=0.5;
					MJ->xvel+=((MJ->acceleration/2) * (dt*dt));
                     			MJ->frame++;
					*/
					MJ->xvel=10;
					
					//BG->PositionC.x+=(MJ->xvel * dt);
					
		    		}	
/*
   			else
				{
					MJ->xvel=5;//par defaut 5 normalement te3a el mouvement ta3 joueur
				}
*/
   			if(((couleur.r==255 && couleur.g==255 && couleur.b==255) || MJ->jump==1 || MJ->jumps==1))
					{
                				if(j->PositionJ.x<340)//tester si le joueur a depasser le milieu d"ecran
                  					{ 
								j->PositionJ.x+=MJ->xvel;
							}

                   				//BG->PositionC.x+=(MJ->xvel * dt);
						BG->PositionC.x+=10;
						
                   
                 			}

				
                 		}
                 	
              /*
	     if(keystate[SDLK_RETURN])
		{
			
					dt+=2;
					printf("\n****dt=%d****\n",dt);
					MJ->acceleration-=2;
					MJ->xvel+=((MJ->acceleration/2) * (dt*dt));
					MJ->frame++;
					if(MJ->xvel <0) {
						MJ->acceleration=0;
						MJ->frame=0;
						//BG->PositionC.x=j->PositionJ.x;
						BG->PositionC.x+=(MJ->xvel * dt);
							}
                     			
			 
		}  
		*/
             if(keystate[SDLK_LEFT])
                { 
			*a=1;
                        MJ->LR=1;
			MJ->framel++;
                     	if(couleur.r==255 && couleur.g==255 && couleur.b==255 || couleur.r==0 && couleur.g==0 && couleur.b==0)
                    		{
					 MJ->xvel=10;
		                         
				}
                        else
				{
					MJ->xvel=5;
				}
                 	       if(((couleur.r==255 && couleur.g==255 && couleur.b==255) || MJ->jump==1 || MJ->jumps==1))
					{
		        	                  j->PositionJ.x-=MJ->xvel;
					}
                               
                          
                 }
            if(keystate[SDLK_UP])
                	{
			 *a=1;
                    	  if(((couleur.r==255 && couleur.g==255 && couleur.b==255) || (couleur.r==0 && couleur.g==0 && couleur.b==0) ) && MJ->jump==0)//tester si le joueur avait deja sauter ou non
                    		 { 
					MJ->jump=1;MJ->jumps=1;//sinon il va sauter et jumps va prendre 1
                       			MJ->yvel=-25;
                       			
                        MJ->frame=0;
                       }
                }
              
		
/*
		if(1000/FPS > SDL_GetTicks() - t_prev)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - t_prev)); //to a constant FPS
*/
	}


void affichage(SDL_Surface *fenetre,joueur *j,mouv_joueur *MJ,backgrd *BG,SDL_Color couleur,enemie *En,int *vie,int *score,int *i,cooin *C,SDL_Surface *text,SDL_Rect postext,SDL_Surface *text0,SDL_Rect postext0,TTF_Font *font,SDL_Color fontcolor,enemie2 *En2)
  {
     char ch1[10];
     char ch[10];
   // SDL_Surface *fenetre;
    fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
      if(MJ->LR==0)//si le joueur est a gauche
	{
		SDL_BlitSurface(BG->backg,&(BG->PositionC),fenetre,NULL);
 		//SDL_BlitSurface(BG->danger,NULL,BG->backg,&(BG->Positiond));
		if(MJ->B==1)
			{
				SDL_BlitSurface(j->boule,NULL,fenetre,&(j->PositionB));
			}
		if((couleur.r!=255 && couleur.g!=255 && couleur.b!=255) && (couleur.r!=0 && couleur.g!=0 && couleur.b!=0))
			{
				SDL_BlitSurface(j->joueur1,&(j->pos[2]),fenetre,&(j->PositionJ));
				
			}
		else
			{
				SDL_BlitSurface(j->joueur1,&(j->pos[MJ->frame]),fenetre,&(j->PositionJ));
			}
		if(En->PositionE.x>0 && En->E==1)
			{
				SDL_BlitSurface(En->enemi,&(En->per2[En->framee]),fenetre,&(En->PositionE));
			}
		else
			{
				En->PositionE.y=750;
				En->E=0;
			}

 	}
	if(MJ->LR==1)//si le joueur est a droite
	{
		SDL_BlitSurface(BG->backg,&BG->PositionC,fenetre,NULL);
		//SDL_BlitSurface(BG->danger,NULL,BG->backg,&(BG->Positiond));
		if(MJ->B==1)
			{
				SDL_BlitSurface(j->boule,NULL,fenetre,&(j->PositionB));
			}
		if((couleur.r!=255 && couleur.g!=255 && couleur.b!=255) && (couleur.r!=0 && couleur.g!=0 && couleur.b!=0))
			{
				SDL_BlitSurface(j->joueur2,&(j->pos[5]),fenetre,&(j->PositionJ));
			}
		else
			{
				SDL_BlitSurface(j->joueur2,&(j->pos[MJ->framel]),fenetre,&(j->PositionJ));
			}
		if(En->PositionE.x>5 && En->E==1)
			{
				SDL_BlitSurface(En->enemi,&(En->per2[En->framee]),fenetre,&(En->PositionE));
			}
		else
			{
				En->PositionE.y=750;
				En->E=0;
			}

 
	}
affichecoin(BG->PositionC,C,fenetre);
afficheenemi(BG->PositionC,En2,fenetre);

//Creation de la barre de vie
//SDL_Color fontcolor={200,200,0};
SDL_Surface *barre;
barre=IMG_Load("./data/image/barre_vie.jpg");

SDL_Surface *barreN;
barreN=IMG_Load("./data/image/barre_noir.png");

SDL_Surface *barrem;
barrem=IMG_Load("./data/image/minibarre_rouge.png");

SDL_Surface *barremn;
barremn=IMG_Load("./data/image/minibarre_noir.png");
SDL_Rect posbarremr;

if(MJ->jump==1 || MJ->jumps==1){posbarremr.x=j->PositionJ.x+22;}
else{posbarremr.x=j->PositionJ.x+5;}
posbarremr.y=j->PositionJ.y-15;

SDL_Rect posbarre;
posbarre.x=280;
posbarre.y=50;

SDL_Rect barreP;
barreP.x=0;
barreP.y=0;
barreP.w=250-*i;
barreP.h=50;

SDL_Rect barrePm;
barrePm.x=0;
barrePm.y=0;
barrePm.w=90-((*i/25)*9);
barrePm.h=15;
/////ttf

/*
//Text txt;

 //creation font 
		TTF_Font *font0;
		font0=TTF_OpenFont("./data/font/font.ttf",40);
//Creation fontcolor
	SDL_Color fontcolor0={255,255,255};



//creation d'un ttf
SDL_Surface *text;
sprintf(ch,"score : %d",*score);
text=TTF_RenderText_Solid(font0,ch,fontcolor0);
SDL_Rect postext;
postext.x=50;
postext.y=50;

 //creation font 
		TTF_Font *font44;
		font44=TTF_OpenFont("./data/font/ktiba.ttf",40);
//Creation fontcolor
	SDL_Color fontcolor2={0,0,0};

//creation d'un ttf
SDL_Surface *text2;
sprintf(ch1,"vies : %d",*vie);
text2=TTF_RenderText_Blended(font44,ch1,fontcolor2);
SDL_Rect postext2;
postext2.x=600;
postext2.y=50;
*/
SDL_BlitSurface(barremn,NULL,fenetre,&posbarremr);
SDL_BlitSurface(barrem,&barrePm,fenetre,&posbarremr);
SDL_BlitSurface(barreN,NULL,fenetre,&posbarre);
SDL_BlitSurface(barre,&barreP,fenetre,&posbarre);
////////
//SDL_BlitSurface(text,NULL,fenetre,&postext);
//SDL_BlitSurface(text2,NULL,fenetre,&postext2);



//affichage du score
char ch8[20];
sprintf(ch8,"score : %d",*score);
text=TTF_RenderText_Solid(font,ch8,fontcolor);
SDL_BlitSurface(text,NULL,fenetre,&postext);
SDL_Flip(fenetre);

//affichage du vie
char ch9[20];
sprintf(ch9,"vie : %d",*vie);
printf("vie000 :%d\n",*vie);

text0=TTF_RenderText_Solid(font,ch9,fontcolor);
SDL_BlitSurface(text0,NULL,fenetre,&postext0);
SDL_Flip(fenetre);

}

void save(int lev,int choix,backgrd *BG,int *score,int *vie,int *i)
{
FILE *f;
f=fopen("save","w");
if(f==NULL){printf("ERROR loading file");}
fprintf(f,"%d %d %d %d %d %d %d",lev,choix,BG->PositionC.x,BG->PositionC.y,*score,*vie,*i);
fclose(f);
}



