#include "Menu.h"

bool inside(int x, int y, SDL_Rect a)
{
    if (x < a.x || y < a.y || x > a.x + a.w || y > a.y + a.h)
        return false;
    return true;
}

bool MenuGame(SDL_Renderer *&gRenderer)
{
    SDL_Texture *Texture = loadTexture("start.png", gRenderer);
    while (true)
    {
        SDL_RenderClear(gRenderer);
        SDL_Rect desrect = {0, 0, 800, 800};
        SDL_RenderCopy(gRenderer, Texture, NULL, &desrect);
        SDL_Color gColor = {255, 255, 0};
        SDL_Rect playRect = renderTextTexture(gRenderer, "VeraMoBd.ttf", "PLAY", 60, gColor, 100, 500);
        SDL_Rect endRect = renderTextTexture(gRenderer, "VeraMoBd.ttf", "EXIT", 60, gColor, 600, 500);
        SDL_Rect TutorialRect = renderTextTexture(gRenderer, "VeraMoBd.ttf", "Tutorial?", 60, gColor, 50, 40);
        SDL_Event e;

        if (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                return 0;

            if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                if (inside(x, y, playRect) == true)
                {
                    switch (e.type)
                    {
                    case SDL_MOUSEMOTION:
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        return 1;
                    default:
                        break;
                    }
                }
                if (inside(x, y, endRect) == true)
                {
                    switch (e.type)
                    {
                    case SDL_MOUSEMOTION:
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        return 0;
                    default:
                        break;
                    }
                }
                if (inside(x, y, TutorialRect) == true)
                {
                    switch (e.type)
                    {
                    case SDL_MOUSEMOTION:
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                    {
                        bool tutorial = true;
                        SDL_Event e;
                        SDL_Texture *tTexture = loadTexture("tutorial.png", gRenderer);

                        while(tutorial == true)
                        {
                            if(SDL_WaitEvent(&e) != 0 && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                                break;
                            SDL_RenderClear(gRenderer);
                            SDL_RenderCopy(gRenderer, tTexture, NULL, &desrect);
                            SDL_RenderPresent(gRenderer);
                        }

                    }
                    break;
                    default:
                        break;
                    }
                }
            }
            SDL_RenderPresent(gRenderer);
        }
    }
}
