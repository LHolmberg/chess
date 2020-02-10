#include "Knight.h"

bool Knight::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;

    if(newPos.first == mapgrid[n][k+1].first || newPos.first == mapgrid[n][k-1].first)
        return true;
    else
        return false;
}

std::string Knight::name() const {
    return "Knight";
}
