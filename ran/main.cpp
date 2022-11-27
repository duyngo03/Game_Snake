#include "BaseInit.h"
#include "LoadTexture.h"
#include "SnakeMove.h"
#include "Target.h"
#include "Menu.h"
#include "QuitMenu.h"

int main(int argc, char *argv[])
{
    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    // The window renderer
    SDL_Renderer *gRenderer = NULL;

    // The Texture
    SDL_Texture *gTexture = NULL;

    // Crete seed random
    srand(time(NULL));

    init(gWindow, gRenderer);

    if (MenuGame(gRenderer) == true)
    {
        bool restart = true;

        while (restart)
        {
            SnakeClass snake;
            Target target;

            bool quit = false;
            long long loop = 0;
            gTexture = loadTexture("image.png", gRenderer);

            while (!quit)
            {
                loop++;
                SDL_Event e;
                /*
                    for (int i = 0; i < SnakeClass().snakeBodyLength; i++)
                    {
                        if (SnakeClass().snakeHead.x == SnakeClass().snakeBody[i].x && SnakeClass().snakeHead.y == SnakeClass().snakeBody[i].y)
                        {
                            quit = true;
                            break;
                        }
                    }
                    */

                // Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    // User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    snake.handleMove(e);
                }

                if (loop % 5 == 0)
                {
                    snake.snakeMove(target.point);
                    if (snake.gameOver() == true)
                        {
                            SDL_SetTextureAlphaMod(gTexture, 100);
                            quit = true;
                        }
                }
                // Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                // The Image Background
                SDL_Rect desrect = {0, 0, 800, 800};
                SDL_RenderCopy(gRenderer, gTexture, NULL, &desrect);

                snake.renderSnake(gRenderer);
                target.renderTarget(gRenderer);

                // The Scores
                render_scores(gRenderer, snake.snakeBodyLength, snake.gameOver());

                SDL_RenderPresent(gRenderer);

                if (quit == true)
                {
                    restart = QuitGame(gRenderer);
                    // if(restart == 1)quit = false;
                }
            }
        }
    }

    QuitSDL(gWindow, gRenderer);
    return 0;
}
