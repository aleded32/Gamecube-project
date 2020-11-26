#include "levelManager.h"

levelManager::levelManager()
{
    P = new playerEnt(100, 200, 24, 16);
	S = new entitySpawn();
	SC = new score(fonts.fontM);
    currentLevel = start;
}

levelManager::~levelManager()
{
    delete P->pBullet;
	delete P;
	delete S;
	delete SC;
}

void levelManager::levelSelector()
{


    switch(currentLevel)
    {
        case 0:
            startMenu();
        break;

        case 1:
            level1Func();
    };

}

void levelManager::startMenu()
{
    
    M.drawMenu(640,528,0,0);

    if(PAD_ButtonsHeld(0) & PAD_BUTTON_A)
    {
        currentLevel = level1;
    }
}

void levelManager::level1Func()
{
    SC->setText();

			

			if(P->isGameOver == false && PA.isPaused == false)
			{
				P->MovePlayer();
				P->moveBullet();
				S->spawnEnemy();
                S->draw();
				
                if(PAD_ButtonsDown(0) & PAD_BUTTON_START)
                {
                    PA.isPaused = true;
                }
				
				P->Bulletcollision(fonts.fontImg1, S->enemies, SC);
				P->draw(fonts.fontM);
			}
            else if(P->isGameOver == false && PA.isPaused == true)
            {
                	P->draw(fonts.fontM);
                    S->draw();
                    PA.displayText(300, 188, fonts.fontImg1);

                    if(PAD_ButtonsDown(0) & PAD_BUTTON_START)
                    {
                       PA.isPaused = false;
                    }

            }
			else
			{
				GRRLIB_Printf(100, 188, fonts.fontImg1, GRRLIB_WHITE, 1, "GAME OVER! PRESS X TO RESTART");
                GRRLIB_Printf(100, 288, fonts.fontImg1, GRRLIB_WHITE, 1, "PRESS B TO RETURN TO MENU");
				S->enemies.clear();

				if(PAD_ButtonsHeld(0) & PAD_BUTTON_X)
                {
                    P->isGameOver = false;
                }
                else if(PAD_ButtonsDown(0) & PAD_BUTTON_B)
                {
                    currentLevel = start;
                    P->isGameOver = false;
                }
				

			}
			P->enemyCollision(SC, S->enemies);
			

}

void levelManager::freeTextures()
{
    GRRLIB_FreeTexture(P->playerSprite);
	GRRLIB_FreeTexture(fonts.fontImg1);
	GRRLIB_FreeTexture(P->pBullet->bulletSprite);
	GRRLIB_FreeTTF(SC->font);
    GRRLIB_FreeTexture(M.menuTex);
}