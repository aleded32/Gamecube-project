#include "bullet.h"

bullet::bullet(){}

bullet::~bullet(){}

firstBullet::firstBullet()
{
    x = 0;
    y = 0;
    width = 8;
    height = 8;
    frame = 0;

    bulletSpawnTime = 0.5;
    bulletSpeed = 7;

    bulletSprite = GRRLIB_LoadTexture(laserbolts);
    

}

firstBullet::~firstBullet(){}

void firstBullet::draw(int _x, int _y, int _frame, GRRLIB_texImg* bulletSprite)
{
    if(bulletSprite != nullptr)
    {
           GRRLIB_Rectangle(_x, _y, width, height, GRRLIB_WHITE, 0);
    }
    
}