#include "Pawn.h"

bool Pawn::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos,std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;
    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;

    if(CheckPieceAt(newPos.first, newPos.second, pieces) == true) {
        if(this->team == "BLACK") {
            if(newPos.second == mapgrid[n-1][k].second && newPos.first == mapgrid[n][k].first)
                return true;
            else
            return false;
        } else {
            if(newPos.second == mapgrid[n+1][k].second && newPos.first == mapgrid[n][k].first)
                return true;
            else
                return false;
        }
    } else
        return false;
}

std::string Pawn::name() const {
    return "Pawn";
}