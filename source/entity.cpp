#include "entity.h"

//enemy
enemyEnt::enemyEnt(float _x, float _y, float _width, float _height)
{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		moveSpeed = 3;
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
        pBullet->x = x - 64;
        pBullet->y = y - 32;
		
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
                pBullet->x = x - 64;
            	pBullet->y = y - 32;
                bullets.push_back(*pBullet);
                start +=1;
            }

            //isfired = true;
        }	
        if(start > 0 && start <= 15)
        {
            start++;
        }
        else if(start >= 15)
        {
            start = 0;
        }
    

}

void playerEnt::Bulletcollision(int enemyX, int enemyY, int enemyW, int enemyH, GRRLIB_texImg* text, std::vector<enemyEnt>& enemy)
{
		for(size_t i = 0; i < bullets.size(); i++)
		{
			if(bullets[i].x > enemyX && bullets[i].x < enemyX + enemyW && bullets[i].y > enemyY && bullets[i].y < enemyY + enemyH )
			{
				GRRLIB_Printf(300, 50, text, GRRLIB_WHITE, 1, "IS COLLIDING");
				for(size_t i = 0; i < enemy.size(); i++)
				{
					enemy.erase(enemy.begin() + i);
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
        GRRLIB_DrawTile(x,y, playerSprite,90,2,2,GRRLIB_WHITE,0);
    }	
	
    for(size_t i = 0; i < bullets.size(); i++)
    {
        
        bullets[i].draw(bullets[i].x, bullets[i].y, bullets[i].frame, bullets[i].bulletSprite);


        if(bullets[i].x >= 700)
        {
            
            bullets.erase(i + bullets.begin());
            
        }
    }
    
    //GRRLIB_PrintfTTF(5,100, text, str,32,0xFFFFFFFF);
    
}


void playerEnt::moveBullet()
{
    for(size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i].x += bullets[i].bulletSpeed;
    }

	
}



