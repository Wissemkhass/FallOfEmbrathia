#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "battle.h"
#include "pausej.h"
#include "collision.h"
#include "personnage.h"



int battleVS(SDL_Surface *fenetre,int *vie,int lev,int choix)
{

TTF_Init();
srand(time(NULL)); //initialiser le rand 
int w=0;
int y=0;
int i=0;
int j=0;
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
SDL_Surface *personage;
SDL_Surface *personagel;
SDL_Surface *personage2;
SDL_Surface *personagel2;
SDL_Surface *speechpe;
SDL_Surface *speechpe2;
SDL_Surface *boule;
SDL_Surface *boule2;
SDL_Surface *sword;
SDL_Surface *sword2;
SDL_Surface *sword1;
SDL_Surface *sword12;
SDL_Surface *barre;
SDL_Surface *barre2;
SDL_Surface *enemi;
SDL_Surface *fleche;
SDL_Surface *stone;
SDL_Rect per[7];
SDL_Rect per22[7];
setrect1111(per);
setrect1111(per22);

//creation d'une nouvelle surface
SDL_Rect Position;
Position.x=0;
Position.y=450;

//creation d'une nouvelle surface
SDL_Rect Position2;
Position2.x=600;
Position2.y=450;

//creation d'une nouvelle surface
SDL_Rect PositionE;
PositionE.x=720;
PositionE.y=450;

//creation d'une nouvelle surface
SDL_Rect Positionsp;
Positionsp.x=20;
Positionsp.y=330;

//creation d'une nouvelle surface
SDL_Rect Positionsp2;
Positionsp2.x=340;
Positionsp2.y=330;

//creation d'une nouvelle surface
SDL_Rect PositionS;
PositionS.x=0;
PositionS.y=480;

//creation d'une nouvelle surface
SDL_Rect PositionS1;
PositionS1.x=0;
PositionS1.y=480;

//creation d'une nouvelle surface
SDL_Rect PositionB;
PositionB.x=0;
PositionB.y=450;

//creation d'une nouvelle surface
SDL_Rect PositionB2;
PositionB2.x=0;
PositionB2.y=450;

//creation d'une nouvelle surface
SDL_Rect Positionss;
Positionss.x=265;
Positionss.y=430;

//creation d'une nouvelle surface
SDL_Rect PositionC;
PositionC.x=10;
PositionC.y=0;
PositionC.w=800;
PositionC.h=600;

//fenetre=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
printf("%d",lev);
if(lev==3)
{backg=IMG_Load("./data/image/amirfinalBG.png");stone=IMG_Load("./data/image/2.png");}
if(lev==2)
{backg=IMG_Load("./data/image/desert.jpg");stone=IMG_Load("./data/image/3.png");}
if(lev==1)
{backg=IMG_Load("./data/image/AAA1.jpg");stone=IMG_Load("./data/image/5.png");}
if(backg==NULL){printf("error");}
if(choix==4){
personage=IMG_Load("./data/image/perso.png");
personagel=IMG_Load("./data/image/perso2.png");
personage2=IMG_Load("./data/image/kali.png");
personagel2=IMG_Load("./data/image/kali2.png");
boule=IMG_Load("./data/image/boule2.png");
boule2=IMG_Load("./data/image/boule6.png");
}
else if(choix==1){
personage=IMG_Load("./data/image/kali.png");
personagel=IMG_Load("./data/image/kali2.png");
personage2=IMG_Load("./data/image/perso.png");
personagel2=IMG_Load("./data/image/perso2.png");
boule=IMG_Load("./data/image/boule6.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else if(choix==6){
personage=IMG_Load("./data/image/mitch.png");
personagel=IMG_Load("./data/image/mitch2.png");
personage2=IMG_Load("./data/image/perso.png");
personagel2=IMG_Load("./data/image/perso2.png");
boule=IMG_Load("./data/image/boule3.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else if(choix==2){
personage=IMG_Load("./data/image/perrr.png");
personagel=IMG_Load("./data/image/perrr2.png");
personage2=IMG_Load("./data/image/perso.png");
personagel2=IMG_Load("./data/image/perso2.png");
boule=IMG_Load("./data/image/boule3.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else if(choix==3){
personage=IMG_Load("./data/image/quesar1.png");
personagel=IMG_Load("./data/image/quesar2.png");
personage2=IMG_Load("./data/image/perso.png");
personagel2=IMG_Load("./data/image/perso2.png");
boule=IMG_Load("./data/image/boule3.png");
boule2=IMG_Load("./data/image/boule2.png");
}
else
{
personage=IMG_Load("./data/image/perso.png");
personagel=IMG_Load("./data/image/perso2.png");
personage2=IMG_Load("./data/image/kali.png");
personagel2=IMG_Load("./data/image/kali2.png");
boule=IMG_Load("./data/image/boule2.png");
boule2=IMG_Load("./data/image/boule6.png");
}
sword=IMG_Load("./data/image/swordxx.png");
sword2=IMG_Load("./data/image/swordxx2.png");
sword1=IMG_Load("./data/image/swordxx.png");
sword12=IMG_Load("./data/image/swordxx2.png");
enemi=IMG_Load("./data/image/enemi2.png");
speechpe=IMG_Load("./data/image/speech1.png");
speechpe2=IMG_Load("./data/image/speech0.png");

SDL_Rect per2[2];
setrect2222(per2);
//fleche=IMG_Load("fleche.png");
SDL_Rect PositionF;
PositionF.x=550;
PositionF.y=230;
Uint32 colorkey = SDL_MapRGB( personagel->format,255,255,255);
SDL_SetColorKey( personage, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
SDL_SetColorKey( personagel, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
SDL_BlitSurface(personage,&per[0],fenetre,&Position);
SDL_BlitSurface(personagel2,&per22[3],fenetre,&Position2);
SDL_BlitSurface(speechpe,NULL,fenetre,&Positionsp);
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);
//SDL_BlitSurface(fleche,NULL,fenetre,&PositionF);
SDL_EnableKeyRepeat(120,30);
SDL_Flip(fenetre);
SDL_Event event;
PositionE.x=-2000;

 //creation font 
TTF_Font *font;
font=TTF_OpenFont("./data/font/font.ttf",40);

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
int speechp=1;
int mvb=1;
int speechb=1;

barre=IMG_Load("./data/image/barre_vie.jpg");
SDL_Rect posbarre;
posbarre.x=50;
posbarre.y=50;
SDL_Rect barreP;
barreP.x=0;
barreP.y=0;
barreP.w=250-i;
barreP.h=50;

barre2=IMG_Load("./data/image/barre_vert.png");
SDL_Rect posbarre2;
posbarre2.x=450;
posbarre2.y=50;
SDL_Rect barreP2;
barreP2.x=0;
barreP2.y=0;
barreP2.w=250-j;
barreP2.h=50;
//char ch1[50];
  //   char ch[50];
//SDL_Delay(2000);

SDL_Surface *barreN;
barreN=IMG_Load("./data/image/barre_noir.png");
SDL_Surface *barrem;
barrem=IMG_Load("./data/image/minibarre_rouge.png");

//creation d'une nouvelle surface
SDL_Surface *barremn;
barremn=IMG_Load("./data/image/minibarre_noir.png");
SDL_Rect barrePm;
barrePm.x=0;
barrePm.y=0;
barrePm.w=90;
barrePm.h=15;

//creation d'une nouvelle surface
SDL_Surface *barreN2;
barreN2=IMG_Load("./data/image/barre_noir.png");

//creation d'une nouvelle surface
SDL_Surface *barrem2;
barrem2=IMG_Load("./data/image/minibarre_vert.png");

//creation d'une nouvelle surface
SDL_Surface *barremn2;
barremn2=IMG_Load("./data/image/minibarre_noir.png");
SDL_Rect barrePm2;
barrePm2.x=0;
barrePm2.y=0;
barrePm2.w=90;
barrePm2.h=15;


while(run==1)
{
 
   start=SDL_GetTicks();
Uint8 *keystate=SDL_GetKeyState(NULL);
  if(speech==1)
	{
			//if(speechp==1){}
//if(keystate[SDLK_SPACE])
//{if(speechb==1){speechb=0;}}
			if(mvb==1)
				{
					if(Position2.x>=350)
						{
							Position2.x-=5;
							framel2++;
						}
					else
						{
							mvb=0;
							speechp=0;
						}
			if(framel2>5)
				{
					framel2=3;
				}
	
				}//mvb==1;
				
			
   if(speechb==0)
	{
		speech=0;
		Position2.x=600;
		Position2.y=450;
	}
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);

if(S2==1)
	{
		SDL_BlitSurface(sword1,NULL,fenetre,&PositionS1);
	}
if(B==1)
	{
		SDL_BlitSurface(boule,NULL,fenetre,&PositionB);
	}
if(B2==1)
	{
		SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);
	}
if(Position.y!=450)
	{
		SDL_BlitSurface(personage,&per[2],fenetre,&Position);
	}
else
	{
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
	}
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);

if(LR2==1)
	{
		SDL_BlitSurface(personagel2,&per22[framel2],fenetre,&Position2);
		if(S==1)
			{
				SDL_BlitSurface(sword2,NULL,fenetre,&PositionS);
			}
	}

else
	{
		SDL_BlitSurface(personage2,&per22[frame2],fenetre,&Position2);
		if(S==1)
			{
				SDL_BlitSurface(sword,NULL,fenetre,&PositionS);
			}
	}
if(speechp==1)
	{
		SDL_BlitSurface(stone,NULL,fenetre,&Positionss);
		SDL_BlitSurface(speechpe,NULL,fenetre,&Positionsp);
	}
if(speechb==1 && mvb==0)
	{
		SDL_BlitSurface(speechpe2,NULL,fenetre,&Positionsp2);
	}
SDL_Flip(fenetre);

if(mvb==0)
	{
		speech=0;
		Position2.x=600;
		Position2.y=450;
		SDL_Delay(5000);
	}
	}//speech==1
     
    else
{
          //PERSO1
	   if(frap1!=1)
		{
           		if(keystate[SDLK_b] && B==0)
                		{
					B=1;
                			PositionB.x=Position.x;//la boule va prendre la position de joueur (x)
			                PositionB.y=Position.y+20;// la boule va se decaler un peu
			                testleftB=LR;//la boule va prendre la position gauche ou droite de l utilisateur
				}
             		if(keystate[SDLK_RIGHT])
                		{
					LR=0;//joueur  a droite
				 	if(Position.y==450)//tester si le joueur est a terre ou non
                    				{
							xvel=10;
                     					frame++;
						}

   					else
						{
							xvel=5;
						}
                	if(Position.x<750)//tester si le joueur a depasser le milieu d"fenetre
                  		{
 					Position.x+=xvel;
				}
                  		//PositionC.x+=10;//avancer la camera de background
                   
                 		}//keystate[SDLK_RIGHT]
            		 if(keystate[SDLK_LEFT])
                		{ 
                       			LR=1;
                     			if(Position.y==450)
                    				{
							xvel=10;
                     					framel++;
						}
                    			else
						{
							xvel=10;
						}
                          		Position.x-=xvel;
                          
                 		}//keystate[SDLK_LEFT]
           		 if(keystate[SDLK_UP])
                		{ 
                    			if(Position.y==450 && jump==0)//tester si le joueur avait deja sauter ou non
                     				{
							jump=1;
							jumps=1;//sinon il va sauter et jumps va prendre 1
                        				yvel=-25;
                        				frame=0;
                       				}
                		}//keystate[SDLK_UP]
			if(keystate[SDLK_n])
                		{
					S2=1;
					if(LR==1)
						{
							PositionS1.x=Position.x-15;
						}
					else
						{
							PositionS1.x=Position.x+40;
						}
                		}
		}//if(frap1!=1)
 //PERSO2
/*
if(frap2!=1){
           if(keystate[SDLK_k] && B2==0)
                {  B2=1;
                PositionB2.x=Position2.x;//la boule va prendre la position de joueur (x)
                PositionB2.y=Position2.y+20;// la boule va se decaler un peu
                testleftB2=LR2;//la boule va prendre la position gauche ou droite de l utilisateur
}
             if(keystate[SDLK_d])
                {LR2=0;//joueur  a droite
 if(Position2.y==450)//tester si le joueur est a terre ou non
                    { xvel2=10;
                     frame2++;}
   else{xvel2=5;}
               if(Position2.x<750)//tester si le joueur a depasser le milieu d"fenetre
                  {
 Position2.x+=xvel2;
}
                  //PositionC.x+=10;//avancer la camera de background
                   
                 }
             if(keystate[SDLK_q])
                { 
                       LR2=1;
                     if(Position2.y==450)
                    { xvel2=10;
                     framel2++;}
                    else{xvel2=5;}
                          Position2.x-=xvel2;
                          
                 }
            if(keystate[SDLK_z])
                { 
                    if(Position2.y==450 && jump2==0)//tester si le joueur avait deja sauter ou non
                     { jump2=1;jumps2=1;//sinon il va sauter et jumps va prendre 1
                        yvel2=-25;
                        
                        frame2=0;
                       }
                }
		if(keystate[SDLK_j])
                { S=1;
			if(LR2==1){PositionS.x=Position2.x-15;}
else{PositionS.x=Position2.x+40;}
                }
}
*/

if(frap2!=1)
	{
		if(Position.x>Position2.x)
			{
				LR2=0;
			if(B==1 && testleftB==0 && (Position2.x-PositionB.x<200) && (Position2.y==450 && jump2==0))
				{jump2=1;jumps2=1;yvel2=-25;}
			if(B==1 && testleftB==1 && (PositionB.x-Position2.x<200) && (Position2.y==450 && jump2==0))
				{jump2=1;jumps2=1;yvel2=-25;}
				if(Position.x-Position2.x>10)
					{
						Position2.x+=5;
						frame2++;
					}
				else
					{
						frame2=0;
					}
			}
		if(Position.x<Position2.x)
			{
					LR2=1;
					if(Position2.x-Position.x>50)
						{
							Position2.x-=5;
							framel2++;
						}
					else
						{
							framel2=3;
						}
			}
		
		boull=rand()%10 +1;

//if(B2==0){B2=1; PositionB2.x=Position.x;//la boule va prendre la position de joueur (x)
              //  PositionB2.y=Position.y+20;// la boule va se decaler un peu
               // testleftB2=LR2;}

		if(Position.x-Position2.x<20 && S==0)
			{
				S=(rand()%15) +1;
				if(S==1 || S==3 || S==5)
					{
						S=0;
					}
				else
					{
						S=1;
					}
				if(LR2==1)
					{
						PositionS.x=Position2.x-15;
					}
				else
					{
						PositionS.x=Position2.x+15;
					}
			}
}//boucle while

while(SDL_PollEvent(&event))
{         
	if(event.type==SDL_QUIT){run=0;} 
 	if(event.type==SDL_KEYUP)
       		{
             		if(event.key.keysym.sym==SDLK_RIGHT)
                		{ 
                      			if(Position.y==450)
                      			frame=0;
                 		}
             		else if(event.key.keysym.sym==SDLK_LEFT)
                		{ 
                      			if(Position.y==450)
                      			framel=3;
                   		}
		 	if(event.key.keysym.sym==SDLK_d)
		                { 
                		        if(Position2.y==450)
		                        frame2=0;
                 		}
             		else if(event.key.keysym.sym==SDLK_q)
                		{ 
                      			if(Position2.y==450)
                      			framel2=3;
                 		}
            	}
   

}

//Perso1
if(B==1 && PositionB.x<800  && testleftB==0 && (PositionB.x-PositionE.x<-30 || PositionB.x-PositionE.x>30))
	{
    		PositionB.x+=30;
	}//boule avec l enemie

else if(B==1 && PositionB.x>0  && testleftB==1 && (PositionB.x-PositionE.x<-30 || PositionB.x-PositionE.x>30))
	{
    		PositionB.x-=30;
	}//boule avec l enemie

else
	{
		B=0;
	}//faire disparaitre la boule si elle n arrive pas a toucher l enemie

if((PositionB.x-PositionE.x<30 && PositionB.x-PositionE.x>-30) && E==1)
	{
		E=0;PositionB.x=-10;
		B=0;
	}//collision de la boule avec l enemie

if(jump==1 && jumps==1 && Position.y>=300)
	{
		Position.y-=18;
	}//le joueur commence a sauter 

else if(jump==1 && jumps==1 && Position.y<=300)
	{
		jumps=0;
	}//si le joueur atteint le maximum de saut jumps va prendre 0

else if(jump==1 && Position.y<450 && jumps==0)
	{
		Position.y+=18;
	}//le joueur commence a chutter
else
	{
		jump=0;
		yvel=0;
		jumps=-1;
	}//si le joueur est a terre tous les valeurs de saut sont reinstaller 

if(frame>2)
	{
		frame=0;
	}

if(framel>5)
	{
		framel=3;
	}

if(frap1==1 && pppp<80 && LR2==1)
	{
		Position.x-=15;
		pppp+=15;
	}

else if(frap1==1 && pppp<80 && LR2==0)
	{
		Position.x+=15;
		pppp+=15;
	}

else
	{
		frap1=0;
		pppp=0;
	}

//Perso2
if(B2==1 && PositionB2.x<800  && testleftB2==0 && (PositionB2.x-PositionE.x<-30 || PositionB2.x-PositionE.x>30))
	{
    		PositionB2.x+=30;
	}//boule avec l enemie

else if(B2==1 && PositionB2.x>0  && testleftB2==1 && (PositionB2.x-PositionE.x<-30 || PositionB2.x-PositionE.x>30))
	{
    		PositionB2.x-=30;
	}//boule avec l enemie

else
	{
		B2=0;
	}//faire disparaitre la boule si elle n arrive pas a toucher l enemie
if((PositionB2.x-PositionE.x<30 && PositionB2.x-PositionE.x>-30) && E==1)
	{
		E=0;
		PositionB2.x=-10;
		B2=0;
	}//collision de la boule avec l enemie

if(jump2==1 && jumps2==1 && Position2.y>=300)
	{
		Position2.y-=18;
	}//le joueur commence a sauter 

else if(jump2==1 && jumps2==1 && Position2.y<=300)
	{
		jumps2=0;
	}//si le joueur atteint le maximum de saut jumps va prendre 0

else if(jump2==1 && Position2.y<450 && jumps2==0)
	{
		Position2.y+=18;
	}//le joueur commence a chutter

else
	{
		jump2=0;
		yvel2=0;
		jumps2=-1;
	}//si le joueur est a terre tous les valeurs de saut sont reinstaller 

if(frame2>2)
	{
		frame2=0;
	}
if(framel2>5)
	{
		framel2=3;
	}
if(S==1 && Position2.y<450)
	{
		PositionS.y=Position2.y+30;
	}
else
	{
		PositionS.y=480;
	}

if(S2==1 && Position.y<450)
	{
		PositionS1.y=Position.y+30;
	}
else
	{
		PositionS1.y=480;
	}
if(frap2==1 && pppp2<80 && LR==1)
	{
		Position2.x-=15;
		pppp2+=15;
	}
else if(frap2==1 && pppp2<80 && LR==0)
	{
		Position2.x+=15;
		pppp2+=15;
	}
else
	{
		frap2=0;
		pppp2=0;
	}

if(frame>0){S2=0;}
if(frame2>0){S=0;}
if(framel>3){S2=0;}
if(framel2>3){S=0;}

if((Collision2222(Position,Position2)==1 || Collision2222(Position2,Position)==1) && S2==1)
	{
		w++;
		j+=25;
		frap2=1;
		pppp=0;
	}
if((Collision2222(Position,Position2)==1 ||Collision2222(Position2,Position)==1) && S==1)
	{
		y++;
		i+=5;
		frap1=1;
		pppp2=0;
	}
if(Collision2222(PositionB,Position2)==1 && B==1)
	{
		w++;
		j+=25;
		B=0;
	}
if(Collision2222(PositionB2,Position)==1 && B2==1)
	{
		y++;
		i+=5;
		B2=0;
	}
SDL_Rect posbarremr;
if(jump==1 || jumps==1)
	{
		posbarremr.x=Position.x+22;
	}
else
	{
		posbarremr.x=Position.x+5;
	}
posbarremr.y=Position.y-15;
SDL_Rect posbarremr2;
if(jump2==1 || jumps2==1)
	{
		posbarremr2.x=Position2.x+22;
	}
else
	{
		posbarremr2.x=Position2.x+5;
	}
posbarremr2.y=Position2.y-15;
barreP2.x=0;
barreP2.y=0;
barreP2.w=250-j;
barreP2.h=50;
barreP.x=0;
barreP.y=0;
barreP.w=250-i;
barreP.h=50;
barrePm.x=0;
barrePm.y=0;
barrePm.w=90-((i/25)*9);
barrePm.h=15;
barrePm2.x=0;
barrePm2.y=0;
barrePm2.w=90-((j/25)*9);
barrePm2.h=15;
if(LR==0)//si le joueur est a gauche
{
SDL_BlitSurface(backg,&PositionC,fenetre,NULL);

if(S2==1)
	{
		SDL_BlitSurface(sword1,NULL,fenetre,&PositionS1);
	}
if(B==1)
	{
		SDL_BlitSurface(boule,NULL,fenetre,&PositionB);
	}
if(B2==1)
	{
		SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);
	}
if(Position.y!=450)
	{
		SDL_BlitSurface(personage,&per[2],fenetre,&Position);
	}
else
	{
		SDL_BlitSurface(personage,&per[frame],fenetre,&Position);
	}
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);
if(LR2==1)
	{
		SDL_BlitSurface(personagel2,&per22[framel2],fenetre,&Position2);
		if(S==1)
			{
				SDL_BlitSurface(sword2,NULL,fenetre,&PositionS);
			}
	}
else
	{
		SDL_BlitSurface(personage2,&per22[frame2],fenetre,&Position2);
		if(S==1)
			{
				SDL_BlitSurface(sword,NULL,fenetre,&PositionS);
			}
	}
//SDL_Flip(fenetre);
 }//if(LR2==1)

if(LR==1)//si le joueur est a droite
	{
		SDL_BlitSurface(backg,&PositionC,fenetre,NULL);
		if(S2==1)
			{
				SDL_BlitSurface(sword12,NULL,fenetre,&PositionS1);
			}
		if(B==1)
			{
				SDL_BlitSurface(boule,NULL,fenetre,&PositionB);
			}
		if(B2==1)
			{
				SDL_BlitSurface(boule2,NULL,fenetre,&PositionB2);
			}
		if(Position.y!=450)
			{
				SDL_BlitSurface(personagel,&per[5],fenetre,&Position);
			}
		else
			{
				SDL_BlitSurface(personagel,&per[framel],fenetre,&Position);
			}
//SDL_BlitSurface(enemi,&per2[framee],fenetre,&PositionE);

		if(LR2==1)
			{
				SDL_BlitSurface(personagel2,&per22[framel2],fenetre,&Position2);
				if(S==1)
					{
						SDL_BlitSurface(sword2,NULL,fenetre,&PositionS);
					}
			}
		else
			{
				SDL_BlitSurface(personage2,&per22[frame2],fenetre,&Position2);
				if(S==1)
					{
						SDL_BlitSurface(sword,NULL,fenetre,&PositionS);
					}
			}
		//SDL_Flip(fenetre);
 	}//if(LR==0)

sprintf(ch,"score : %d",w);
text=TTF_RenderText_Solid(font,ch,fontcolor);


sprintf(ch1,"score2 : %d",y);
text2=TTF_RenderText_Solid(font,ch1,fontcolor);
//printf("%s",ch);
SDL_BlitSurface(barremn,NULL,fenetre,&posbarremr);
SDL_BlitSurface(barrem,&barrePm,fenetre,&posbarremr);
SDL_BlitSurface(barreN,NULL,fenetre,&posbarre);
SDL_BlitSurface(barremn2,NULL,fenetre,&posbarremr2);
SDL_BlitSurface(barrem2,&barrePm2,fenetre,&posbarremr2);
SDL_BlitSurface(barreN2,NULL,fenetre,&posbarre2);
SDL_BlitSurface(barre,&barreP,fenetre,&posbarre);
SDL_BlitSurface(barre2,&barreP2,fenetre,&posbarre2);
//SDL_BlitSurface(text,NULL,fenetre,&postext);
//SDL_BlitSurface(text2,NULL,fenetre,&postext2);
SDL_Flip(fenetre);

if((Collision2222(Position,Position2)==1) && S2==1)
	{
		w++;
		S2=0;
	}
if(Collision2222(Position,Position2)==1 && S==1)
	{
		y++;
		S=0;
	}
//PositionE.x-=20;//avancer l'enemie
//if(E==0){PositionE.x=750;E=1;B=0;PositionE.y=(rand()%120)+330;}
framee++;

if(framee>1)
	{
		framee=0;
	}
}
if(1000/FPS>SDL_GetTicks()-start)
   {SDL_Delay(1000/FPS-(SDL_GetTicks()-start));}
S=0;
S2=0;
if(j>=250) 
	{
		run=0;
			SDL_Delay(2000);
	}
if(i>=250)
	{
		run=0;
		*vie=*vie-1;
			SDL_Delay(2000);
	}

}
if(i>=250)
{return 0;}
else
{return 1;}
/*SDL_FreeSurface(enemi);
SDL_FreeSurface(boule);
SDL_FreeSurface(personagel);
SDL_FreeSurface(personage);
SDL_FreeSurface(personagel2);
SDL_FreeSurface(personage2);
SDL_FreeSurface(backg);
//SDL_FreeSurface(fenetre);
//TTF_Quit();
//SDL_Quit();*/
}



