#include <gccore.h>
#include <grrlib.h>
#include "BMfont4.h"
#include "font.h"
#include <ogc/pad.h>

class FontLoading
{
public:
	GRRLIB_texImg *fontImg1;
	GRRLIB_ttfFont *fontM;

	FontLoading();

	~FontLoading();

};