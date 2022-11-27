#include "LoadTexture.h"

SDL_Texture *loadTexture(std::string path, SDL_Renderer *&gRenderer)
{
     // The final texture
     SDL_Texture *newTexture = NULL;

     // Load image at specified path
     SDL_Surface *loadedSurface = IMG_Load(path.c_str());
     if (loadedSurface == NULL)
     {
          printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
     }
     else
     {
          // Create texture from surface pixels
          newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
          if (newTexture == NULL)
          {
               printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
          }

          // Get rid of old loaded surface
          SDL_FreeSurface(loadedSurface);
     }

     return newTexture;
}
SDL_Rect renderTextTexture(SDL_Renderer *&gRenderer, const std::string &fontName,
                           const std::string &content, const int &fontSize,
                           const SDL_Color &fcolor, const int &x, const int &y)
{
     TTF_Font *font = TTF_OpenFont(fontName.c_str(), fontSize);

     SDL_Surface *surface = TTF_RenderText_Solid(font, content.c_str(), fcolor);
     SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surface);
     SDL_FreeSurface(surface);
     surface = NULL;

     int w, h;
     SDL_QueryTexture(texture, NULL, NULL, &w, &h);

     SDL_Rect desRect = {x, y, w, h};
     SDL_RenderCopy(gRenderer, texture, NULL, &desRect);

     TTF_CloseFont(font);
     font = NULL;
     SDL_DestroyTexture(texture);
     texture = NULL;

     return desRect;
}
void render_scores(SDL_Renderer* &gRenderer, int BodyLength, bool gameOver)
{
     stringstream ss;
     ss.str("");
     ss << "SCORE: " << BodyLength - 1;
     SDL_Color gColor = {255, 255, 0};
     if(!gameOver)renderTextTexture(gRenderer, "VeraMoBd.ttf", ss.str().c_str(), 20, gColor, 20, 6);
     else
     {
         gColor = {255, 0, 0};
         renderTextTexture(gRenderer, "VeraMoBd.ttf", ss.str().c_str(), 50, gColor, 250, 300);
     }
}
