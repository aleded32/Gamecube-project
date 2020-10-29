#include "entity.h"

//enemy
enemyEnt::enemyEnt(float _x, float _y, float _width, float _height)
{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
}

enemyEnt::~enemyEnt(){}

void enemyEnt::draw()
{
		GRRLIB_Rectangle(x,y, width, height, GRRLIB_RED, true);
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
        isfired = false;
        pBullet->x = x;
        pBullet->y = y;
		
		playerSprite = GRRLIB_LoadTexture(ship);		
}

playerEnt::~playerEnt()
{
   // delete bullets;
    //delete pbullet;
}

void playerEnt::MovePlayer() 
{
		

		if (x > 528) 
		{
			
			x = 528;
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
    

}

void playerEnt::collision(int enemyX, int enemyY, int enemyW, int enemyH, GRRLIB_texImg* text)
{

		if(x > enemyX && x - 50 < enemyX + enemyW && y + height > enemyY && y < enemyY + enemyH )
		{
			if(PAD_ButtonsHeld(0) & PAD_BUTTON_RIGHT)
			{
				GRRLIB_Printf(5, 100, text, GRRLIB_WHITE ,1, "IS COLLIDING");
				x = enemyX - 1;
			}
			else if(PAD_ButtonsHeld(0) & PAD_BUTTON_LEFT)
			{
				GRRLIB_Printf(5, 100, text, GRRLIB_WHITE ,1, "IS COLLIDING");
				x = 52 + enemyX + enemyW - 1;
			}
			else if(PAD_ButtonsHeld(0) & PAD_BUTTON_UP)
			{
				GRRLIB_Printf(5, 100, text, GRRLIB_WHITE ,1, "IS COLLIDING");
				y = enemyY + enemyH + 1;
			}
			else if(PAD_ButtonsHeld(0) & PAD_BUTTON_DOWN)
			{
				GRRLIB_Printf(5, 100, text, GRRLIB_WHITE ,1, "IS COLLIDING");
				y = enemyY - 27;
			}
		}
			

}

void playerEnt::draw()
{
	
    if(playerSprite != nullptr)
    {
        GRRLIB_InitTileSet(playerSprite, width,height, 0);
        GRRLIB_DrawTile(x,y, playerSprite,90,2,2,GRRLIB_WHITE,0);
    }	
	
    if(pBullet->bulletSprite != nullptr)
    {

       for(size_t i = 0; i < bullets.size(); i++)
        {
           GRRLIB_DrawTile(bullets[i]->x, bullets[i]->y, bullets[i]->bulletSprite,0,2,2,GRRLIB_WHITE,0);
        }
    }

}

void playerEnt::spawnBullet(GRRLIB_texImg* text)
{
    
   
    if(PAD_ButtonsHeld(0) && PAD_BUTTON_A)
    {
        bullets.push_back(pBullet);
        GRRLIB_Printf(5, 100, text, GRRLIB_WHITE ,1, bullets.size());
       //isfired = true;
    }
   /* if(start > 120)
    {
        isfired = false;
        start = 0;
    }
    if(isfired == true)
        start ++;
    */
}

void playerEnt::moveBullet()
{
    for(size_t i = 0; i < bullets.size(); i++)
    {
        bullets[i]->x += bullets[i]->bulletSpeed;
    }
}



