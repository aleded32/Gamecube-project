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