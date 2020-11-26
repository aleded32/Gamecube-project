#pragma once

#include "startMenu.h"
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

#define GRRLIB_WHITE     0xFFFFFFFF

class menus
{
public:
    menus(){}
    ~menus(){}
    
};

class menu : public menus
{
public:

    GRRLIB_texImg* menuTex;
    
    menu();
    ~menu();

    void drawMenu(float width, float height, float x,float y);
    
};

class pause : public menus
{
public:

    pause();
    ~pause();

    bool isPaused; 

    void displayText(float x,float y, GRRLIB_texImg* font);


};