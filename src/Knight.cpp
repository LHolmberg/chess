#include "Knight.h"

bool Knight::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::array<Piece*, 32> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;

    int dx = abs((gridX - newPos.first) / (H/8));
    int dy = abs((gridY - newPos.second) / (H/8));
    if(dx == 1 && dy == 2 || dx == 2 && dy == 1) {
        if(CheckPieceAt(newPos.first, newPos.second, pieces) == true)
            return true;
    }
    return false;
}

std::string Knight::name() const {
    return "Knight";
}
