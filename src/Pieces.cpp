#include "Pieces.h"

std::vector< std::pair<int,int> > GetTravelpath(std::pair<int,int> curpos, std::pair<int,int> newpos)
{
    std::vector< std::pair<int,int> > retval;

    int cX = curpos.first, cY = curpos.second;
    int nX = newpos.first, nY = newpos.second;
    int boardsMovedX = abs(cX - nX) / (H/8);//dx
    
    for(int i = 0; i < boardsMovedX;i++)
    {
        retval.push_back(std::make_pair(curpos.first + H/8, curpos.second));
    }
    return retval;
}

std::pair<int,int> GetCurrentPosition(std::pair<int,int> mapgrid[8][8], int x, int y) {
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8;j++)
        {
            if(mapgrid[i][j].first == x && mapgrid[i][j].second == y)
                return std::make_pair(i,j);
        }
    }
}

bool DidMeet(std::vector<std::pair<int,int> > tpath, std::vector<Piece*> pieces)
{
    if(tpath.size() == 0)
        return true;
    for(auto p : pieces)
    {
        for(int i = 0; i < tpath.size(); i++)
        {
            if(p->square.x == tpath[i].first && p->square.y == tpath[i].second) {
                std::cout << "IN THE WAY";
                return true;
            }
        }
    }
    return false;
}

Piece::Piece(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team) {
        this->square.w = W/8;
        this->square.h = H/8;
        this->square.x = x;
        this->square.y = y;
        this->sprite = IMG_LoadTexture(renderer, filename); 
        this->team = team;
}

void Piece::ChangePosition(int x, int y) {
        this->square.x = x;
        this->square.y = y;
}

bool King::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
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

bool Queen::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    int dy = abs(newPos.second - mapgrid[n][k].second);
    int dx = abs(newPos.first - mapgrid[n][k].first);

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

bool Rook::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;
    int gridX = mapgrid[n][k].first, gridY = mapgrid[n][k].second;
    
    if(DidMeet(GetTravelpath(std::make_pair(gridX,gridY), newPos), pieces) == false)
    {
        if(newPos.second == mapgrid[n][k].second || newPos.first == mapgrid[n][k].first)
            return true;
        else    
            return false;
    } else
        return false;
}

std::string Rook::name() const {
    return "Rook";
}

bool Bishop::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    int dy = abs(newPos.second - mapgrid[n][k].second);
    int dx = abs(newPos.first - mapgrid[n][k].first);
    
    for(int i = 0; i < 8; i++) {
    if(newPos.second == mapgrid[i][k].second && dx == dy 
        || newPos.second == mapgrid[i][k].second && dx == dy
            || newPos.first == mapgrid[n][i].first && dx == dy
                || newPos.first == mapgrid[n][i].first && dx == dy)
        return true;
    }
    
    return false;
}

std::string Bishop::name() const {
    return "Bishop";
}

bool Pawn::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos,std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    if(this->team == "BLACK") {
        if(newPos.second == mapgrid[n-1][k].second)
            return true;
        else
           return false;
    } else {
        if(newPos.second == mapgrid[n+1][k].second)
            return true;
        else
           return false;
    }
}

std::string Pawn::name() const {
    return "Pawn";
}

bool Knight::PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces) {
    int x = square.x;
    int y = square.y;

    std::pair<int,int> curPos = GetCurrentPosition(mapgrid, x, y);
    int n = curPos.first, k = curPos.second;

    if(newPos.first == mapgrid[n][k+1].first || newPos.first == mapgrid[n][k-1].first)
        return true;
    else
        return false;
}

std::string Knight::name() const {
    return "Knight";
}
