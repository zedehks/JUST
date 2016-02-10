#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Block.h"


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
Block* blocks[32][32];
int x,y;

int init_all();

void new_map();

int main(int argc, char *argv[])
{
    int result = init_all();
    if(result != 0)
        return result;
    //init array
    new_map();

    //Main Loop
    while(true)
    {
        SDL_RenderClear(renderer);
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
                goto fin;
            if(Event.type == SDL_KEYDOWN)
            {
                switch(Event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    goto fin;
                    break;
                }
            }

        }
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j < 15; j++)
            {
                SDL_RenderCopy(renderer,blocks[i][j]->texture, NULL, &blocks[i][j]->rect_block);
            }
        }

         //SDL_RenderCopy(renderer,Cursor,NULL,&rect_Cursor);
        SDL_RenderPresent(renderer);
    }

    //Clear everything
    fin:
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            free(blocks[i][j]);
        }
    }
    SDL_Quit();
    //system("cls");
    printf("\nI seriously hope you remembered to save.");
    //printf("\nI also seriously hope we finish this shit by the deadline.\n\n");
    //printf("\nThank you for putting the \"dung\" in \"dungeon\"! \n\n\n\n\n");
    printf("\n\n\n\n\n\n\nJUST v0.0.1 - Copyup (c)1984 SOME AMOUNT OF RIGHTS RESERVED, BITCH\n\"Fuck FLOSS, Fuck Liberty, and especially, Fuck You :^)\"\n\n");
    //system("pause");
    return 0;

}

int init_all()
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("DungBuilder v1.0.0", 500, 20, 700/*WIDTH*/, 700/*HEIGHT*/, SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL_SetWindowIcon(window, IMG_Load("BJ_STAND.png"));

    printf("Renderer");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }
    SDL_RenderSetLogicalSize(renderer,512,512);
    //SDL_RenderSetScale(renderer,1.5,1.5);
    //selected_block = 0;
    //printSelection(selected_block);
    //bucket = false;
    //SDL_ShowCursor(0);

    return 0;
}

//Map I/O
void new_map()
{
    for(int i = 0;i<15;i++)
    {
        for(int j = 0;j<15;j++)
        {
            blocks[i][j] = NULL;
            if(i==7 && j==7)
            {
                blocks[i][j] = new Block(renderer,(i*32),(j*32),1,' ');
            }

            else if(i==0 && (j==0 || j==7 || j==14))
            {
                blocks[i][j] = new Block(renderer,(i*32),(j*32),2,' ');
            }
            else if(i==7 && (j==0 || j==14))
            {
                blocks[i][j] = new Block(renderer,(i*32),(j*32),2,' ');
            }
            else if(i==14 && (j==0 ||j==7|| j==14))
            {
                blocks[i][j] = new Block(renderer,(i*32),(j*32),2,' ');
            }

            else
            {
                blocks[i][j] = new Block(renderer,(i*32),(j*32),0,' ');
            }
        }
    }
}
