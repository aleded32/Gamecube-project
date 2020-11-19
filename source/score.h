#pragma once

#include <iostream>
#include <fstream>
#include <gccore.h>
#include <grrlib.h>
#include <ogc/pad.h>

class score
{
    public:

        int pScore, pHighScore;

        GRRLIB_ttfFont* font;

        score(GRRLIB_ttfFont* _font);
        ~score();

        int updateScore();

        void setText();
        void setHighScore();

};