#include "SnakeMove.h"

SnakeClass::SnakeClass()
{
     snakeHead.x = SCREEN_HEIGHT / 2;
     snakeHead.y = SCREEN_WIDTH / 2;
     snakeHead.w = 20;
     snakeHead.h = 20;

     direction = RIGHT;

     for (int i = 0; i < snakeMaxLength; i++)
     {
          snakeBody[i].w = 20;
          snakeBody[i].h = 20;
     }

     snakeBody[0].x = snakeHead.x - 20;
     snakeBody[0].y = snakeHead.y;
     snakeBody[1].x = snakeHead.x - 40;
     snakeBody[1].y = snakeHead.y;
}

SnakeClass::~SnakeClass()
{
}

void SnakeClass::renderSnake(SDL_Renderer *&gRenderer)
{
     SDL_SetRenderDrawColor(gRenderer, 102, 255, 51, 0xFF);
     for (int i = 0; i < snakeBodyLength; i++)
     {
          SDL_RenderFillRect(gRenderer, &snakeBody[i]);
     }
     SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, 255);
     SDL_RenderFillRect(gRenderer, &snakeHead);
}

void SnakeClass::handleMove(SDL_Event &e)
{
     if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
     {
          if (e.key.keysym.sym == SDLK_p)
               waitUntilEnterPressed();

          if (direction == RIGHT || direction == LEFT)
          {

               if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
               {
                    direction = DOWN;
               }
               if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
               {
                    direction = UP;
               }
          }

          if (direction == UP || direction == DOWN)
          {
               if (e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_a)
               {
                    direction = LEFT;
               }
               if (e.key.keysym.sym == SDLK_RIGHT || e.key.keysym.sym == SDLK_d)
               {
                    direction = RIGHT;
               }
          }
     }
}

void SnakeClass::snakeMove(SDL_Rect &point)
{
     // di chuyển phần thân
     for (int i = snakeBodyLength - 1; i > 0; i--)
     {
          snakeBody[i].x = snakeBody[i - 1].x;
          snakeBody[i].y = snakeBody[i - 1].y;
     }
     snakeBody[0].x = snakeHead.x;
     snakeBody[0].y = snakeHead.y;

     // Dat lai vi tri dau
     if (direction == LEFT)
     {
          snakeHead.x = (snakeHead.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
     }
     else if (direction == RIGHT)
     {
          snakeHead.x = (snakeHead.x + step) % SCREEN_WIDTH;
     }
     else if (direction == DOWN)
     {
          snakeHead.y = (snakeHead.y + step) % SCREEN_HEIGHT;
     }
     else if (direction == UP)
     {
          snakeHead.y = (snakeHead.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
     }

     if (CheckVaCham(snakeHead, point) == true)
     {
          Mix_Chunk *TargetChunk =  Mix_LoadWAV("target.mp3");
          Mix_PlayChannel(-1, TargetChunk, 0);
          TargetChunk = NULL;
          // chuyển point ra chỗ khác
          point.x = 20 + rand() % 37 * 20;
          point.y = 20 + rand() % 37 * 20;
          snakeBodyLength++;
          snakeBody[snakeBodyLength - 1].x = snakeBody[snakeBodyLength - 2].x;
          snakeBody[snakeBodyLength - 1].y = snakeBody[snakeBodyLength - 2].y;
     }
     SDL_Delay(50);
}

bool SnakeClass::gameOver()
{
     // Nếu đâm vào đuôi
     for (int i = 0; i < snakeBodyLength; i++)
     {
          if (snakeHead.x == snakeBody[i].x && snakeHead.y == snakeBody[i].y)
          {
               return true;
          }
     }
     return false;
}
