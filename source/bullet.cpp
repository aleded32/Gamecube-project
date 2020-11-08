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
    bulletSpeed = 10;

    bulletSprite = GRRLIB_LoadTexture(laserbolts);
    GRRLIB_InitTileSet(bulletSprite, width, height, frame);

}

firstBullet::~firstBullet(){}

void firstBullet::draw(int _x, int _y, int _frame, GRRLIB_texImg* bulletSprite)
{
    if(bulletSprite != nullptr)
    {
           GRRLIB_DrawTile(_x, _y, bulletSprite,0,8,8,GRRLIB_WHITE, _frame);
    }
}