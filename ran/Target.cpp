#include "Target.h"

Target::Target()
{
     // tạo điểm ngẫu nhiên để ăn
     point.x = 20 + rand() % 37 * 20;
     point.y = 20 + rand() % 37 * 20;
     point.w = 20;
     point.h = 20;
}

Target::~Target()
{
}

void Target::renderTarget(SDL_Renderer *&gRenderer)
{
     SDL_SetRenderDrawColor(gRenderer, 255, 50, 0, 0xFF);
     SDL_RenderFillRect(gRenderer, &point);
}
