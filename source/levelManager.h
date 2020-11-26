#pragma once

#include <gccore.h>
#include <grrlib.h>
#include "menus.h"
#include "entity.h"
#include "score.h"
#include "bullet.h"
#include "entitySpawner.h"
#include "fontload.h"
#include <ogc/pad.h>

class levelManager
{
public:

    playerEnt* P;
    entitySpawn* S;
    FontLoading fonts;
    score* SC;
    menu M;
    pause PA;
    enum levels{start = 0, level1 = 1}currentLevel;

    levelManager();
    ~levelManager();

    void levelSelector();
    void startMenu();
    void level1Func();

    void freeTextures();
};