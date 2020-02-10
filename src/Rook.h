#pragma once
#include "Pieces.h"

class Rook : public Piece {
public:
    Rook(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};