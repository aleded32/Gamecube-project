#pragma once

#include "laserbolts.h"
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>


#define GRRLIB_WHITE     0xFFFFFFFF

class bullet
{
    public:

        float x,y, width, height;
        GRRLIB_texImg* bulletSprite;
        int bulletSpeed;
        float bulletSpawnTime;
        int frame;



        bullet();
        ~bullet();

        


};

class firstBullet : public bullet
{
    public:
    firstBullet();
    ~firstBullet();

    void draw(int _x, int _y, int _frame, GRRLIB_texImg* _bulletSprite);
};