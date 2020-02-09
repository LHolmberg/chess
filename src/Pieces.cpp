#include "Pieces.h"

std::pair<int,int> GetCurrentPosition(std::pair<int,int> mapgrid[8][8], int x, int y) {
    int k, n;

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
    return std::make_pair(n,k);
}

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

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    if(newPos.second == mapgrid[n + 1][k].second || newPos.second == mapgrid[n - 1][k].second
    || newPos.first == mapgrid[n][k+1].first || newPos.first == mapgrid[n][k-1].first)
        return true;
    else
        return false;
}

std::string King::name() const {
    return "King";
}

bool Queen::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    int dx,dy;
    dy = abs(newPos.second - mapgrid[n][k].second);
    dx = abs(newPos.first - mapgrid[n][k].first);

    //any diagonal and straight up/down/sidetoside = OK
    for(int i = 0; i < 8; i++) {
        if(newPos.second == mapgrid[n][k].second || newPos.first == mapgrid[n][k].first
        || newPos.second == mapgrid[i][k].second && dx == dy
        || newPos.second == mapgrid[i][k].second && dx == dy
        || newPos.first == mapgrid[n][i].first && dx == dy
        || newPos.first == mapgrid[n][i].first && dx == dy)
            return true;

    }
    return false;
}

std::string Queen::name() const {
    return "Queen";
}

bool Rook::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    if(newPos.second == mapgrid[n][k].second || newPos.first == mapgrid[n][k].first)
        return true;
    else
        return false;
}

std::string Rook::name() const {
    return "Rook";
}