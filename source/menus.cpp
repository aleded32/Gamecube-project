#include "menus.h"

menu::menu()
{
    menuTex = GRRLIB_LoadTexture(startMenu);
   
}

menu::~menu(){}

void menu::drawMenu(float width, float height, float x,float y)
{
    GRRLIB_InitTileSet(menuTex, width, height, 0);
	GRRLIB_DrawTile(x,y, menuTex, 0, 1,1, GRRLIB_WHITE, 0);
}

pause::pause(){}

pause::~pause(){}

void pause::displayText(float x,float y, GRRLIB_texImg* font)
{
    GRRLIB_Printf(x, y, font, GRRLIB_WHITE, 1, "PAUSE");
}

