
#include <gccore.h>
#include <grrlib.h>
#include "entity.h"
#include "bullet.h"
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
	enemyEnt* E = new enemyEnt(200, 200, 100,100);
	FontLoading fonts;

	while(1)
	{

	     if (PAD_ButtonsDown(0) & PAD_BUTTON_START)  break;
		
		GRRLIB_FillScreen(GRRLIB_BLACK);
		PAD_ScanPads();

			P->MovePlayer();
			P->spawnBullet(GRRLIB_texImg* text);
			P->moveBullet();
			P->collision(E->getX(), E->getY(), E->getWidth(), E->getHeight(), fonts.fontImg1);
			P->draw();
		
			E->draw();
		

		//place every in here to output to screen
		GRRLIB_Render();
	}

	GRRLIB_FreeTexture(P->playerSprite);
	GRRLIB_FreeTexture(fonts.fontImg1);
	GRRLIB_FreeTexture(P->pBullet->bulletSprite);
	
	GRRLIB_Exit();
	delete P;
	delete E;
	return 0;
}