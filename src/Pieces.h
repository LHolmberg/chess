#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
#include "Board.h"

const int W = 600, H = 600; //SCREEN

class Piece {
public:
    SDL_Texture *sprite;
    SDL_Rect square;
    std::string team;

    void ChangePosition(int x, int y);

    Piece(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team);
    
    bool CheckPieceAt(int x, int y, std::vector<Piece*> pieces);
    std::vector< std::pair<int,int> > GetTravelpath(std::pair<int,int> curpos, std::pair<int,int> newpos);
    std::pair<int,int> GetCurrentPosition(std::pair<int,int> mapgrid[8][8], int x, int y);
    bool DidMeet(std::vector<std::pair<int,int> > tpath, std::vector<Piece*> pieces);

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos,
            std::vector<Piece*> pieces) = 0;
    virtual std::string name() const = 0;
};