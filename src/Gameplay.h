#pragma once
#include "System.h"
#include "Pieces.h"
#include "Bishop.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Board.h"
#include <vector>

class Gameplay {
public:
    std::pair<int,int> mapgrid[8][8];
    std::array<Board, 64> board;
    std::array<Piece*, 32> pieces;

    Gameplay(System* sys);
    
    std::pair<int,int> ChangePosTo(int x, int y);
    void SetupMap(SDL_Renderer* renderer);
    void SetupPieces(SDL_Renderer* renderer);
    bool PickedPiece(int x, int y);

    int chosenPieceID;
};
