#include "grid.h"


// Cette class s'appelle grid car on peut imaginer ajouter des nouveaux item autre que Candy

Grid::Grid() {
    candy.w = 16;
    candy.h = 16;  
}

int Grid::checkCandy(Entity &entity){
    SDL_Rect entityRect = entity.getRect();
    return SDL_HasIntersection(&candy, &entityRect);
}

void Grid::newCandy() {
    // Créer un générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 gen(rd());

    // Définir les plages de valeurs aléatoires
    std::uniform_int_distribution<> dis1(0, 19);
    std::uniform_int_distribution<> dis2(0, 14);

    // Générer les nombres aléatoires
    int new_j = dis1(gen);
    int new_i = dis2(gen);

    candy.x = new_j * 32;
    candy.y = new_i * 32;
}

void Grid::drawCandy(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
    SDL_RenderFillRect(renderer, &candy);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}