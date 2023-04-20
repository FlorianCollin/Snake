#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <SDL2/SDL.h>
#include <random>
#include "entity.h"
class Grid{
private :
    SDL_Rect candy;
public :
    Grid();
    int checkCandy(Entity &entity); // Retourne 1 si l'entity est en collision avec le "candy"
    void newCandy();
    void drawCandy(SDL_Renderer* renderer);
};

#endif