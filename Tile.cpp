#include "Tile.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Tile::Tile(SDL_Renderer* renderer, char l,int points)
{
    this->renderer = renderer;
    this->letter = l;
    this->points = points;



    this->rect_tile.x = 32; this->rect_tile.y = 32;
   // SDL_QueryTexture(this->texture,NULL,NULL,&rect_tile.w,&rect_tile.h);
}

Tile::~Tile()
{
    //dtor
}
