#include "Block.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Block::Block(SDL_Renderer* renderer, int x, int y, int texture,char val)
{
    this->renderer = renderer;
    this->x = x; this->y = y;
    this->tipo = texture;

    this->value = val;

    switch(tipo)
    {
    case 0:
        this->texture = IMG_LoadTexture(renderer, "TILE.png");
        break;
    case 1:
        this->texture = IMG_LoadTexture(renderer, "TILE_ALT.png");
        break;
    case 2:
        this->texture = IMG_LoadTexture(renderer, "TILE_2C.png");
        break;
    case 3:
        this->texture = IMG_LoadTexture(renderer, "TILE_2W.png");
        break;
    case 4:
        this->texture = IMG_LoadTexture(renderer, "TILE_3W.png");
        break;
    case 5:
        this->texture = IMG_LoadTexture(renderer, "TILE_3C.png");
        break;
    case 6:
        this->texture = IMG_LoadTexture(renderer, "TILE_STAR.png");
        break;
    case 7:
        this->texture = IMG_LoadTexture(renderer, "TILE_LETTER.png");
        break;
    case 8:
        this->texture = IMG_LoadTexture(renderer, "TILE_WORD.png");
        break;
    }

    this->rect_block.x = x; this->rect_block.y = y;
    SDL_QueryTexture(this->texture,NULL,NULL,&rect_block.w,&rect_block.h);
}

Block::~Block()
{
    //dtor
}

bool Block::check_selected(int x, int y)
{
    if(x>= this->rect_block.x && x< this->rect_block.x+16)
    {
       if(y>= this->rect_block.y && y< this->rect_block.y+16)
        {
            return true;
        }
    }
    return false;
}

void Block::change_type(int tipo)
{
    SDL_DestroyTexture(this->texture);
    this->tipo = tipo;

    switch(this->tipo)
    {
    case 0:
        this->texture = IMG_LoadTexture(renderer, "TILE.png");
        break;
    case 1:
        this->texture = IMG_LoadTexture(renderer, "TILE_ALT.png");
        break;
    case 2:
        this->texture = IMG_LoadTexture(renderer, "TILE_2C.png");
        break;
    case 3:
        this->texture = IMG_LoadTexture(renderer, "TILE_2W.png");
        break;
    case 4:
        this->texture = IMG_LoadTexture(renderer, "TILE_3W.png");
        break;
    case 5:
        this->texture = IMG_LoadTexture(renderer, "TILE_3C.png");
        break;
    case 6:
        this->texture = IMG_LoadTexture(renderer, "TILE_STAR.png");
        break;
    case 7:
        this->texture = IMG_LoadTexture(renderer, "TILE_LETTER.png");
        break;
    case 8:
        this->texture = IMG_LoadTexture(renderer, "TILE_WORD.png");
        break;
    }
    SDL_QueryTexture(this->texture,NULL,NULL,&rect_block.w,&rect_block.h);
}
