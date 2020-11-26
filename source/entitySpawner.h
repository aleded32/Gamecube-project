#pragma once

#include <cstdlib>
#include <chrono>
#include <math.h>
#include "entity.h"
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>



class entitySpawn
{
    public:

        std::vector<enemyEnt> enemies;
        enemyEnt* enemy;
        float spawnPointX;
        float spawnPointY[3];
        int spawnTime;
        int randY;

        entitySpawn();
        ~entitySpawn();

        void spawnEnemy();
        void draw();
        

};