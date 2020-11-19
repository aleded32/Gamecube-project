#include "score.h"

score::score(GRRLIB_ttfFont* _font)
{

    font = _font;
    pScore = 0;
    pHighScore = 0;

}

score::~score(){}

int score::updateScore()
{
    pScore++;

    return pScore;
}

void score::setText()
{
    char strScore[32];
    char strHighScore[32];
	sprintf(strScore, "%d" ,  pScore);
    sprintf(strHighScore, "%d" ,  pHighScore);
	GRRLIB_PrintfTTF(5,50, font,  "SCORE:" ,32,0xFFFFFFFF);
	GRRLIB_PrintfTTF(110,50, font,  strScore ,32,0xFFFFFFFF);

    GRRLIB_PrintfTTF(5,100, font,  "HIGH SCORE:" ,32,0xFFFFFFFF);
	GRRLIB_PrintfTTF(160,100, font,  strHighScore ,32,0xFFFFFFFF);

}

void score::setHighScore()
{

    if(pScore > pHighScore)
    {
        pHighScore = pScore;
        
    }
   

}
