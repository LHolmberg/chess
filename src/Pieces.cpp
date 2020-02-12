#include "Pieces.h"


std::vector< std::pair<int,int> > Piece::GetTravelpath(std::pair<int,int> curpos, std::pair<int,int> newpos)
{
    std::vector< std::pair<int,int> > retval;

    int cX = curpos.first, cY = curpos.second;
    int nX = newpos.first, nY = newpos.second;
    int boardsMovedX = 0, boardsMovedY = 0, boardsMovedDiagonal = 0;
    
    if(cY == nY)
        boardsMovedX = (cX - nX) / (H/8);//dx
    if(cX == nX)
        boardsMovedY = (cY - nY) / (H/8);//dy
    if(cX != nX && cY != nY)
        boardsMovedDiagonal = abs((cY - nY) / (H/8));

    int xTravel = cX;
    if(boardsMovedX != 0) {
        for(int i = 0; i < abs(boardsMovedX);i++) {
            if(boardsMovedX < 0) {
                xTravel += H/8; //one board piece
                retval.push_back(std::make_pair(xTravel, cY));
            }
            else{
                xTravel -= H/8;
                retval.push_back(std::make_pair(xTravel, cY));
            } 
        } 
    }

    int yTravel = cY;
    if(boardsMovedY != 0) {
        for(int i = 0; i < abs(boardsMovedY);i++) {
            if(boardsMovedY < 0) {
                yTravel += H/8;
                retval.push_back(std::make_pair(cY, yTravel)); 
            }
            else {
                yTravel -= H/8;
                retval.push_back(std::make_pair(cY, yTravel));
            }
        }
    }
    
    int diaTravelX = cX, diaTravelY = cY;
    if(boardsMovedDiagonal != 0) {
        for(int i = 0; i < boardsMovedDiagonal; i++) {
            if((cY - nY) / (H/8) > 0 && (cX - nX) / (H/8) > 0) {
                diaTravelX -= H/8;
                diaTravelY -= H/8;
                retval.push_back(std::make_pair(diaTravelX, diaTravelY));
            }
            if((cY - nY) / (H/8) < 0 && (cX - nX) / (H/8) < 0) {
                diaTravelX += H/8;
                diaTravelY += H/8;
                retval.push_back(std::make_pair(diaTravelX, diaTravelY));
            }
            if((cY - nY) / (H/8) > 0 && (cX - nX) / (H/8) < 0) {
                diaTravelX += H/8;
                diaTravelY -= H/8;
                retval.push_back(std::make_pair(diaTravelX, diaTravelY));
            }
            if((cY - nY) / (H/8) < 0 && (cX - nX) / (H/8) > 0) {
                diaTravelX -= H/8;
                diaTravelY += H/8;
                retval.push_back(std::make_pair(diaTravelX,diaTravelY));
            }
        }
    }
    return retval;
}

std::pair<int,int> Piece::GetCurrentPosition(std::pair<int,int> mapgrid[8][8], int x, int y) {
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8;j++)
        {
            if(mapgrid[i][j].first == x && mapgrid[i][j].second == y)
                return std::make_pair(i,j);
        }
    }
}

bool Piece::DidMeet(std::vector<std::pair<int,int> > tpath, std::vector<Piece*> pieces)
{
    if(tpath.size() == 0)
        return true;
    
    for(auto p : pieces)
    {
        if(std::find(tpath.begin(), tpath.end(), std::make_pair(p->square.x, p->square.y)) != tpath.end())
            return true; 
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