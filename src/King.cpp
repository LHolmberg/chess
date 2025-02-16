#include "King.h"

bool King::PossibleMove(std::pair<int, int> mapgrid[8][8], std::pair<int, int> newPos, std::array<Piece *, 32> pieces)
{
    int x = square.x;
    int y = square.y;

    std::pair<int, int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;
    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;

    if (DidMeet(GetTravelpath(std::make_pair(gridX, gridY), newPos), pieces) == false)
    {
        if (newPos.second == mapgrid[n + 1][k].second || newPos.second == mapgrid[n - 1][k].second || newPos.first == mapgrid[n][k + 1].first || newPos.first == mapgrid[n][k - 1].first)
        {
            if (CheckPieceAt(newPos.first, newPos.second, pieces) == true)
            {
                return true;
            }
        }
    }
    return false;
}

std::string King::name() const
{
    return "King";
}