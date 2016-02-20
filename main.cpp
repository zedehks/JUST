#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Block.h"
#include "Cursor.h"
#include "Tile.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
Block* blocks[32][32];
std::vector<Tile*> tiles;
int x,y;
int cursor_x = 0,cursor_y = 0;

int init_all();

void new_map();
void seed_special_blocks();
void summon_tiles();

int main(int argc, char *argv[])
{
    int result = init_all();
    if(result != 0)
        return result;
    //init array
    new_map();
    //init cursor
    Cursor* cursor = new Cursor(renderer);
    //init tiles
    summon_tiles();

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
                case SDLK_LEFT:
                    if(cursor_x == 0)
                        cursor_x = 14;
                    else
                        --cursor_x;
                    break;
                case SDLK_RIGHT:
                    if(cursor_x == 14)
                        cursor_x = 0;
                    else
                        ++cursor_x;
                    break;
                case SDLK_UP:
                    if(cursor_y == 0)
                        cursor_y = 14;
                    else
                        --cursor_y;
                    break;
                case SDLK_DOWN:
                    if(cursor_y == 14)
                        cursor_y = 0;
                    else
                        ++cursor_y;
                    break;
                case SDLK_RETURN:

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

        cursor->rect.x = cursor_x*32;
        cursor->rect.y = cursor_y*32;
        SDL_RenderCopy(renderer,cursor->texture,NULL,&cursor->rect);
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
    //printf("\nI seriously hope you remembered to save.");
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
    if((window = SDL_CreateWindow("DungBuilder v1.0.0", 500, 20, 640/*WIDTH*/, 640/*HEIGHT*/, SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL_SetWindowIcon(window, IMG_Load("BJ_STAND.png"));


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }
    //SDL_RenderSetLogicalSize(renderer,320,240);
    //SDL_RenderSetScale(renderer,1.2,1.2);
    //selected_block = 0;
    //printSelection(selected_block);
    //bucket = false;
    //SDL_ShowCursor(0);
    srand(time(NULL));

    return 0;
}

//Map I/O
void new_map()
{
    int theme = rand()%2;
    for(int i = 0;i<15;i++)
    {
        for(int j = 0;j<15;j++)
        {
            blocks[i][j] = NULL;
            blocks[i][j] = new Block(renderer,(i*32),(j*32),theme,' ');
        }
    }
    seed_special_blocks();
}

void seed_special_blocks()
{
    blocks[7][7]->change_type(6);//star tile

    int word_2 = 8;
    while(word_2 != 0)
    {
        int x = rand()%15;
        int y = rand()%15;
        if(blocks[x][y]->tipo < 2)
        {
           blocks[x][y]->change_type(3);
           word_2--;
        }
    }

    int letter_2 = 12;
    while(letter_2 != 0)
    {
        int x = rand()%15;
        int y = rand()%15;
        if(blocks[x][y]->tipo < 2)
        {
           blocks[x][y]->change_type(2);
           letter_2--;
        }
    }

    int letter_3 = 12;
    while(letter_3 != 0)
    {
        int x = rand()%15;
        int y = rand()%15;
        if(blocks[x][y]->tipo < 2)
        {
           blocks[x][y]->change_type(5);
           letter_3--;
        }
    }

    int word_3 = 4;
    while(word_3 != 0)
    {
        int x = rand()%15;
        int y = rand()%15;
        if(blocks[x][y]->tipo < 2)
        {
           blocks[x][y]->change_type(4);
           word_3--;
        }
    }

    int word_minus = 4;
    while(word_minus != 0)
    {
        int x = rand()%15;
        int y = rand()%15;
        if(blocks[x][y]->tipo < 2)
        {
           blocks[x][y]->change_type(8);
           word_minus--;
        }
    }

    int letter_minus = 4;
    while(letter_minus != 0)
    {
        int x = rand()%15;
        int y = rand()%15;
        if(blocks[x][y]->tipo < 2)
        {
           blocks[x][y]->change_type(7);
           letter_minus--;
        }
    }

}

void summon_tiles()
{

    tiles.push_back(new Tile(renderer,'k',rand()%11));
    tiles.push_back(new Tile(renderer,'j',rand()%11));
    tiles.push_back(new Tile(renderer,'q',rand()%11));
    tiles.push_back(new Tile(renderer,'x',rand()%11));
    tiles.push_back(new Tile(renderer,'z',rand()%11));

    tiles.push_back(new Tile(renderer,' ',0));
    tiles.push_back(new Tile(renderer,'@',0));
    tiles.push_back(new Tile(renderer,'*',0));

    for(int i = 0;i<12;i++)
    {
        tiles.push_back(new Tile(renderer,'e',rand()%11));
    }
    for(int i = 0;i<9;i++)
    {
        tiles.push_back(new Tile(renderer,'a',rand()%11));
        tiles.push_back(new Tile(renderer,'i',rand()%11));
    }
    for(int i = 0;i<8;i++)
    {
        tiles.push_back(new Tile(renderer,'o',rand()%11));
    }
    for(int i = 0;i<6;i++)
    {
        tiles.push_back(new Tile(renderer,'n',rand()%11));
        tiles.push_back(new Tile(renderer,'r',rand()%11));
        tiles.push_back(new Tile(renderer,'t',rand()%11));
    }
    for(int i = 0;i<4;i++)
    {
        tiles.push_back(new Tile(renderer,'l',rand()%11));
        tiles.push_back(new Tile(renderer,'s',rand()%11));
        tiles.push_back(new Tile(renderer,'u',rand()%11));
        tiles.push_back(new Tile(renderer,'d',rand()%11));
    }
    for(int i = 0;i<3;i++)
    {
        tiles.push_back(new Tile(renderer,'g',rand()%11));
    }
    for(int i = 0;i<2;i++)
    {
        tiles.push_back(new Tile(renderer,'b',rand()%11));
        tiles.push_back(new Tile(renderer,'m',rand()%11));
        tiles.push_back(new Tile(renderer,'c',rand()%11));
        tiles.push_back(new Tile(renderer,'p',rand()%11));
        tiles.push_back(new Tile(renderer,'f',rand()%11));
        tiles.push_back(new Tile(renderer,'h',rand()%11));
        tiles.push_back(new Tile(renderer,'v',rand()%11));
        tiles.push_back(new Tile(renderer,'w',rand()%11));
        tiles.push_back(new Tile(renderer,'y',rand()%11));
    }
}

