#ifndef ENTITY_H 
#define ENTITY_H
#include <SDL2/SDL.h>
#include "direction.h"
class Entity{
private :
    SDL_Rect rect;
    Direction dir;
    float speed;
public :
    Entity(int x, int y, int w, int h);
    void moove();
    void draw(SDL_Renderer*);
    void setDirection(Direction);
    SDL_Rect getRect();
    void speedUp();
};
#endif