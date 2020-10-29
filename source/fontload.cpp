#include "fontload.h"

FontLoading::FontLoading()
{
	fontImg1 = GRRLIB_LoadTexture(BMfont4);
	GRRLIB_InitTileSet(fontImg1, 16,16,32);
}
	
FontLoading::~FontLoading()
{

}
