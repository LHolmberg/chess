#include "Board.h"

Board::Board(int w, int h, int x, int y, const char *filename, SDL_Renderer *renderer)
{
        this->square.w = w;
        this->square.h = h;
        this->square.x = x;
        this->square.y = y;
        this->sprite = IMG_LoadTexture(renderer, filename);
}