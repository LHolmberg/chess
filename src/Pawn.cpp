#include "Pawn.h"

bool Pawn::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos,std::array<Piece*, 32> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;
    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;

    
    if(this->team == "BLACK") {
        if(newPos.second == mapgrid[n-1][k].second && newPos.first == mapgrid[n][k].first) {
            if(CheckPieceAt(newPos.first, newPos.second, pieces) == true) 
                return true;
        }
    } else {
        if(newPos.second == mapgrid[n+1][k].second && newPos.first == mapgrid[n][k].first) {
            if(CheckPieceAt(newPos.first, newPos.second, pieces) == true) 
                return true;
        }
    }
    
    return false;
}

std::string Pawn::name() const {
    return "Pawn";
}