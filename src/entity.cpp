#include "entity.h"

Entity::Entity(int x, int y, int w, int h) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    speed = 30 * 4; // Ce qui revient à avancer de 4 pixel par frame ca on fixe le jeu à 30 fps
}
void Entity::moove() {
    switch (dir)
    {
    case RIGHT:
        rect.x += (int)(speed * (1.0/30.0));
        break;
    case LEFT:
        rect.x -= (int)(speed * (1.0/30.0));
        break;
    case UP:
        rect.y -= (int)(speed * (1.0/30.0));
        break;
    case DOWN:
        rect.y += (int)(speed * (1.0/30.0));
        break; 
    default:
        break;
    }

    if (rect.x < 0) {
        rect.x = 640 - 32;
    } else if (rect.x > 640 - 32) {
        rect.x = 0;
    }

    if (rect.y < 0) {
        rect.y = 480 - 32;
    } else if (rect.y > 480 - 32) {
        rect.y = 0;
    }

}

void Entity::draw(SDL_Renderer* renderer) {
    SDL_RenderFillRect(renderer, &rect);
    
    
}


void Entity::setDirection(Direction new_direction) {
    dir = new_direction;
}

SDL_Rect Entity::getRect() {
    return rect;
}

void Entity::speedUp() {
    speed += 5;
}