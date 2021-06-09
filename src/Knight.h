#pragma once
#include "Pieces.h"

class Knight : public Piece
{
public:
    Knight(int x, int y, const char *filename, SDL_Renderer *renderer, std::string team)
        : Piece(x, y, filename, renderer, team) {}

    virtual bool PossibleMove(std::pair<int, int> mapgrid[8][8], std::pair<int, int> newPos, std::array<Piece *, 32> pieces);
    virtual std::string name() const;
};
