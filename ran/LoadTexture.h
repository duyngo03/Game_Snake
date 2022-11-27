#ifndef Load_Texture_h_
#define Load_Texture_h_

#include "BaseInit.h"

SDL_Texture *loadTexture(std::string path, SDL_Renderer *&gRenderer);
SDL_Rect renderTextTexture(SDL_Renderer *&gRenderer, const std::string &fontName,
                           const std::string &content, const int &fontSize,
                           const SDL_Color &fcolor, const int &x, const int &y);
void render_scores(SDL_Renderer *&gRenderer, int BodyLength, bool gameOver);
#endif
