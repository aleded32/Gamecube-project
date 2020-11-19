
#include <gccore.h>
#include <grrlib.h>
#include "entity.h"
#include "score.h"
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

	playerEnt* P = new playerEnt(100, 200, 24, 16);
	entitySpawn* S = new entitySpawn();
	FontLoading fonts;
	score* SC = new score(fonts.fontM);
	

	while(1)
	{

	
		GRRLIB_FillScreen(GRRLIB_BLACK);
		PAD_ScanPads();

			SC->setText();

			

			if(P->isGameOver == false)
			{
				P->MovePlayer();
				P->moveBullet();
				S->spawnEnemy(fonts.fontM);
				
				
				P->Bulletcollision(fonts.fontImg1, S->enemies, SC);
				P->draw(fonts.fontM);
			}
			else
			{
				GRRLIB_Printf(100, 188, fonts.fontImg1, GRRLIB_WHITE, 1, "GAME OVER! PRESS B TO RESTART");
				S->enemies.clear();

				if(PAD_ButtonsHeld(0) & PAD_BUTTON_B)
				P->isGameOver = false;

			}
			P->enemyCollision(SC, S->enemies);
			

		//place every in here to output to screen
		GRRLIB_Render();
	}

	GRRLIB_FreeTexture(P->playerSprite);
	GRRLIB_FreeTexture(fonts.fontImg1);
	GRRLIB_FreeTexture(P->pBullet->bulletSprite);
	GRRLIB_FreeTTF(SC->font);
	
	GRRLIB_Exit();

	delete P->pBullet;
	delete P;
	delete S;
	delete SC;
	return 0;
}