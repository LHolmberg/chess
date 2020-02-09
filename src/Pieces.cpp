#include "Pieces.h"

Piece::Piece(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer) {
        this->square.w = w;
        this->square.h = h;
        this->square.x = x;
        this->square.y = y;
        this->sprite = IMG_LoadTexture(renderer, filename); 
}

void Piece::ChangePosition(int x, int y) {
        this->square.x = x;
        this->square.y = y;
}

bool King::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos) {
    int x = square.x;
    int y = square.y;
    int k, n;
    
    //get grid pos:
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8;j++)
        {
            if(mapgrid[i][j].first == x && mapgrid[i][j].second == y)
            {
                n = i;
                k = j;
            }
        }
    }

    if(newPos.second == mapgrid[n + 1][k].second || newPos.second == mapgrid[n - 1][k].second
    || newPos.first == mapgrid[n][k+1].first || newPos.first == mapgrid[n][k-1].first)
        return true;
    else
        return false;
}

std::string King::name() const {
    return "King";
}

bool Rook::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos) {
    int x = square.x;
    int y = square.y;
    int k, n;
    
    //get grid pos:
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8;j++)
        {
            if(mapgrid[i][j].first == x && mapgrid[i][j].second == y)
            {
                n = i;
                k = j;
            }
        }
    }
    if(newPos.second == mapgrid[n][k].second || newPos.first == mapgrid[n][k].first)
        return true;
    else
        return false;
}

std::string Rook::name() const {
    return "Rook";
}