#ifndef CURSOR_H
#define CURSOR_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Cursor
{
    public:
        int block_x,block_y;
        SDL_Renderer* renderer;
        SDL_Rect rect;
        SDL_Texture* texture;

        Cursor(SDL_Renderer* renderer);
        virtual ~Cursor();
    protected:
    private:
};

#endif // CURSOR_H
