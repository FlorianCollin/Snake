/*
Ce code a pour but de me tester sur C++ et SDL. Je dois réussir à faire un snake des plus basiques,
mais je me rajoute la difficulté de n'avoir le droit de consulter que la documentation officielle de SDL ainsi que la documentation officielle de C++ mais surtout une limitation de temps de 2h.
De plus, le programme devra limiter les interfaces et aller droit au but. Le projet n'a pas pour but d'évoluer, mais d'être formateur.
*/
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "grid.h"
#include "entity.h"

void renderProcess(SDL_Renderer *renderer, Entity &snake, Grid &grid);
void inputGestion(SDL_Event &event, bool &quit,  Entity &snake);

int main() {
	float fps = 30;

	Grid grid;
	grid.newCandy();
	Entity snake(0, 0, 32, 32);

	// Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Erreur lors de l'initialisation de SDL : %s", SDL_GetError());
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        SDL_Log("Erreur lors de la création de la fenêtre : %s", SDL_GetError());
        return 1;
    }

    // Création du rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_Log("Erreur lors de la création du rendu : %s", SDL_GetError());
        return 1;
    }


	float currentTime = SDL_GetTicks();
    float previousTime, waitTime, deltaTime;

    SDL_Event event;
	bool quit = false;
	while (!quit){
		previousTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = currentTime - previousTime;
		waitTime = (1.0 / fps) * 1000 - deltaTime;

   		if (waitTime * 1000.0f > 0) {
        	SDL_Delay((int)(waitTime)); 
   		}

		while (SDL_PollEvent(&event)) {
			inputGestion(event, quit, snake);
		}
		renderProcess(renderer, snake, grid);
	}
    // Nettoyage de SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
	
}




void renderProcess(SDL_Renderer *renderer, Entity &snake, Grid &grid) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		grid.drawCandy(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		snake.moove();
		if (grid.checkCandy(snake)) {
			grid.newCandy();
			snake.speedUp();
		}
		snake.draw(renderer);
		SDL_RenderPresent(renderer);
	
}

void inputGestion(SDL_Event &event, bool &quit, Entity &snake) {
	switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_d:
					snake.setDirection(RIGHT);
					break;
				case SDLK_q:
					snake.setDirection(LEFT);
					break;
				case SDLK_z:
					snake.setDirection(UP);
					break;
				case SDLK_s:
					snake.setDirection(DOWN);
					break;
				default:
					break;
				}
				break;

			default:
				break;
			}
}