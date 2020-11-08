
#include <gccore.h>
#include <grrlib.h>
#include "entity.h"
#include "bullet.h"
#include "entitySpawner.h"
#include "fontload.h"
#include <ogc/pad.h>




#define GRRLIB_BLACK     0x000000FF
#define GRRLIB_RED		 0xFF0000FF
#define GRRLIB_WHITE     0xFFFFFFFF



//#define click() PAD_ButtonsDown(0) & PAD_BUTTON_RIGHT
//#define release() PAD_ButtonsUp(0) & PAD_BUTTON_RIGHT






int main()
{
	PAD_Init();
	GRRLIB_Init();

	playerEnt* P = new playerEnt(100, 200, 16, 24);
	//enemyEnt* E = new enemyEnt(200, 200, 100,100);
	entitySpawn* S = new entitySpawn();
	FontLoading fonts;

	while(1)
	{

	     if (PAD_ButtonsDown(0) & PAD_BUTTON_START)  break;
		
		GRRLIB_FillScreen(GRRLIB_BLACK);
		PAD_ScanPads();

			P->MovePlayer();
			
			P->moveBullet();
			
			//placeHolder For Score wil be put into own class(for demostartion only)
			 char str[20];
			 sprintf(str, "%d" ,  0);
			 GRRLIB_PrintfTTF(5,50, fonts.fontM,  "SCORE:" ,32,0xFFFFFFFF);
			 GRRLIB_PrintfTTF(110,50, fonts.fontM,  str ,32,0xFFFFFFFF);
			 //
			
			P->draw(fonts.fontM);

			S->spawnEnemy(fonts.fontM);
			
			//collision not yet fully working(so leave unabled during midpoint)
			for(size_t j = 0; j < S->enemies.size(); j++)
			{
				//P->Bulletcollision(S->enemies[j].getX(), S->enemies[j].getY(), S->enemies[j].getWidth(), S->enemies[j].getHeight(), fonts.fontImg1, S->enemies);
			}
			//

		//place every in here to output to screen
		GRRLIB_Render();
	}

	GRRLIB_FreeTexture(P->playerSprite);
	GRRLIB_FreeTexture(fonts.fontImg1);
	GRRLIB_FreeTexture(P->pBullet->bulletSprite);
	
	GRRLIB_Exit();

	delete P->pBullet;
	delete P;
	delete S;
	return 0;
}