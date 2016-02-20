#include "Cursor.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Cursor::Cursor(SDL_Renderer* renderer)
{
    this->renderer = renderer;
    this->texture = IMG_LoadTexture(renderer, "CURSOR.png");
    this->rect.x = 32; this->rect.y = 32;
    SDL_QueryTexture(this->texture,NULL,NULL,&rect.w,&rect.h);
}

Cursor::~Cursor()
{
    //dtor
}
