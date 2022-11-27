#ifndef Base_Init_h_
#define Base_Init_h_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>

using namespace std;

// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

const int step = 20;

enum
{
     RIGHT,
     LEFT,
     UP,
     DOWN
};

bool CheckVaCham(SDL_Rect &a, SDL_Rect &b);

bool init(SDL_Window *&gWindow, SDL_Renderer *&gRenderer);

void QuitSDL(SDL_Window *&gWindow, SDL_Renderer *&gRenderer);

void waitUntilEnterPressed();

#endif
