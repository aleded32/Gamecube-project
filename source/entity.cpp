#include "entity.h"

//enemy
enemyEnt::enemyEnt(float _x, float _y, float _width, float _height)
{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		moveSpeed = 4;
		enemySprite = GRRLIB_LoadTexture(enemysmall);
}

enemyEnt::~enemyEnt(){}


void enemyEnt::draw(int _x, int _y, float width , float height)
{
		GRRLIB_InitTileSet(enemySprite, width, height, 0);
		GRRLIB_DrawTile(_x,_y, enemySprite, 0, 2,2, GRRLIB_WHITE, 0);
}

//player
playerEnt::playerEnt(float _x, float _y, float _width, float _height) 
{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		moveSpeed = 5;
        pBullet = new firstBullet;
        start = 0;
        pBullet->x = x + 16;
        pBullet->y = y + 16;
		isGameOver = false;
		
		playerSprite = GRRLIB_LoadTexture(ship);		
}

playerEnt::~playerEnt()
{
   // delete bullets;
    //delete pbullet;
}

void playerEnt::MovePlayer() 
{
		
		
		if (x > 675) 
		{
			
			x = 675;
		}
		else if (x - width < 0) 
		{
			
			x=0 + width;
		}

		if (y > 375) 
		{
			
			y = 375;
		}
		else if (y < 0) 
		{
			
			y=0;
		}
		
		if(PAD_ButtonsHeld(0) & PAD_BUTTON_RIGHT)
		{
			x += moveSpeed;
			
		}
		else if(PAD_ButtonsHeld(0) & PAD_BUTTON_LEFT)
		{
			x -= moveSpeed;	
		}
		else if(PAD_ButtonsHeld(0) & PAD_BUTTON_UP)
		{
			y -= moveSpeed;
		}
		else if(PAD_ButtonsHeld(0) & PAD_BUTTON_DOWN)
		{
			y += moveSpeed;	
		}
        if(PAD_ButtonsHeld(0) & PAD_BUTTON_A)
        {
			
            if(start <= 0)
            {
                pBullet->x = x + 16;
            	pBullet->y = y + 16;
                bullets.push_back(*pBullet);
                start +=1;
            }

            //isfired = true;
        }	
        if(start > 0 && start <= 25)
        {
            start++;
        }
        else if(start >= 25)
        {
            start = 0;
        }
    

}

void playerEnt::Bulletcollision(GRRLIB_texImg* text, std::vector<enemyEnt>& enemy, score* ptrScore)
{
		for(size_t i = 0; i < bullets.size(); i++)
		{
			for(size_t j = 0; j < enemy.size(); j++)
			{
				if(bullets[i].x + bullets[i].width > enemy[j].x && bullets[i].x < enemy[j].x + (enemy[j].width * 2) && bullets[i].y + bullets[i].height > enemy[j].y && bullets[i].y < enemy[j].y + (enemy[j].height * 2))
				{
					//GRRLIB_Printf(300, 50, text, GRRLIB_WHITE, 1, "IS COLLIDING");
						ptrScore->updateScore();
						enemy.erase(enemy.begin() + j);
						bullets.erase(bullets.begin() + i);
				}
			}
		}
		
			

}

void playerEnt::draw(GRRLIB_ttfFont* text)
{
    //test bullets
    char str[20];
	sprintf(str, "%d" , (int)bullets.size());
    //
    if(playerSprite != nullptr)
    {
        GRRLIB_InitTileSet(playerSprite, width,height, 0);
        GRRLIB_DrawTile(x,y, playerSprite,0,2,2,GRRLIB_WHITE,0);
    }	
	
    for(size_t i = 0; i < bullets.size(); i++)
    {
        
        bullets[i].draw(bullets[i].x, bullets[i].y, bullets[i].frame, bullets[i].bulletSprite);


        if(bullets[i].x >= 675)
        {
            
            bullets.erase(i + bullets.begin());
            
        }
    }
    
    
    
}


void playerEnt::moveBullet()
{
    for(size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].x += bullets[i].bulletSpeed;
    }

	
}

void playerEnt::enemyCollision(score* ptrScore, std::vector<enemyEnt>& enemy)
{
	for(size_t j = 0; j < enemy.size(); j++)
	{
		if(x + (width * 2) > enemy[j].x && x < enemy[j].x + (enemy[j].width * 2) && y + (height * 2) > enemy[j].y && y < enemy[j].y + (enemy[j].height * 2))
		{
			isGameOver = true;
		}
		if(isGameOver == true)
		{
			
			ptrScore->setHighScore();
			ptrScore->pScore = 0;
			x = 100;
			y = 200;
		}
	}
	
		
}



