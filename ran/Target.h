#ifndef Target_h_
#define Target_h_

#include "BaseInit.h"

class Target
{
public:
     SDL_Rect point;
     Target();
     ~Target();

     void renderTarget(SDL_Renderer *&gRenderer);
};

#endif