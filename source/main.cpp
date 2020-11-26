
#include <gccore.h>

#include <grrlib.h>
#include "levelManager.h"
#include <ogc/pad.h>
#include <asndlib.h>
#include <mp3player.h>
#include "gameSound.h"



#define GRRLIB_BLACK     0x000000FF
#define GRRLIB_RED		 0xFF0000FF
#define GRRLIB_WHITE     0xFFFFFFFF



//#define click() PAD_ButtonsDown(0) & PAD_BUTTON_RIGHT
//#define release() PAD_ButtonsUp(0) & PAD_BUTTON_RIGHT






int main()
{
	PAD_Init();
	GRRLIB_Init();

	//intiallise audio
	ASND_Init();
	MP3Player_Init();


	levelManager* LM = new levelManager();
	LM->currentLevel = LM->start;

	//MP3Player_PlayBuffer(gameSound, gameSound_size, NULL);

	while(1)
	{

		
		GRRLIB_FillScreen(GRRLIB_BLACK);
		PAD_ScanPads();

		LM->levelSelector();
			
		//place every in here to output to screen
		GRRLIB_Render();
	}

	LM->freeTextures();
	
	GRRLIB_Exit();

	delete LM;
	
	return 0;
}