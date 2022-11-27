#ifndef quitmenu_h_
#define quitmenu_h_

#include "BaseInit.h"
#include "LoadTexture.h"

bool outside(int x, int y, SDL_Rect a);
bool QuitGame(SDL_Renderer *&gRenderer);

#endif