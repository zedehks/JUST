#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Tile
{
    public:
        SDL_Renderer* renderer;
        SDL_Rect rect_tile;
        SDL_Texture* texture;
        char letter;
        int points;
        Tile(SDL_Renderer* renderer, char l,int points);
        virtual ~Tile();
    protected:
    private:
};

#endif // TILE_H
