#include "Gameplay.h"

Gameplay::Gameplay(System* sys) {
    SetupMap(sys->renderer);
    SetupPieces(sys->renderer);
}

bool Gameplay::PickedPiece(int x, int y)
{
    for(int i = 0; i < pieces.size(); i++)
    {
        if(x >= pieces[i]->square.x && x <= pieces[i]->square.x + pieces[i]->square.w && y >= pieces[i]->square.y && y <= pieces[i]->square.y + pieces[i]->square.h)
        {
            chosenPieceID = i;
            return true;
        }
    }
    return false;
}

std::pair<int,int> Gameplay::ChangePosTo(int x, int y)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(x >= board[i].square.x && x <= board[i].square.x + board[i].square.w && y >= board[i].square.y && y <= board[i].square.y + board[i].square.h)
        {
            return std::make_pair(board[i].square.x,board[i].square.y);
        }
    }
}

void Gameplay::SetupMap(SDL_Renderer* renderer) {
    int xpos = 0, ypos = 0;
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            if(j % 2 != 0)
            {
                if(i % 2 == 0)
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/beige.png", renderer));
                else
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/brown.jpeg", renderer));
            }
            else {
                if(i % 2 != 0)
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/beige.png", renderer));
                else
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/brown.jpeg", renderer));
            }
            mapgrid[j][i] = std::make_pair(xpos,ypos);
            xpos += H/8;
        }
        xpos = 0;
        ypos += W/8;
    }
}
//TODO : fixa andra icons till team white
void Gameplay::SetupPieces(SDL_Renderer* renderer) {
        //PAWNS
    for(int i = 0; i < 8; i++) { 
        pieces.push_back(new Pawn(mapgrid[i][i].first,mapgrid[1][1].second,"assets/pawn.png", renderer, "WHITE"));
        pieces.push_back(new Pawn(mapgrid[i][i].first,mapgrid[6][6].second,"assets/pawn2.png", renderer, "BLACK"));
    }
    
    //Setup rooks
    pieces.push_back(new Rook(mapgrid[0][0].first,mapgrid[7][7].second,"assets/rook2.png", renderer, "BLACK"));
    pieces.push_back(new Rook(mapgrid[7][7].first,mapgrid[7][7].second,"assets/rook2.png", renderer, "BLACK"));

    pieces.push_back(new Rook(mapgrid[0][0].first,mapgrid[0][0].second,"assets/rook2.png", renderer, "WHITE"));
    pieces.push_back(new Rook(mapgrid[7][7].first,mapgrid[0][0].second,"assets/rook2.png", renderer, "WHITE"));


    // Setup knights
    pieces.push_back(new Knight(mapgrid[1][1].first,mapgrid[7][7].second,"assets/knight2.png", renderer, "BLACK"));
    pieces.push_back(new Knight(mapgrid[6][6].first,mapgrid[7][7].second,"assets/knight2.png", renderer, "BLACK"));
    
    pieces.push_back(new Knight(mapgrid[1][1].first,mapgrid[0][0].second,"assets/knight2.png", renderer, "WHITE"));
    pieces.push_back(new Knight(mapgrid[6][6].first,mapgrid[0][0].second,"assets/knight2.png", renderer, "WHITE"));

    // Setup queens and kings
    pieces.push_back(new Queen(mapgrid[4][4].first,mapgrid[7][7].second,"assets/queen2.png", renderer, "BLACK"));
    pieces.push_back(new King(mapgrid[3][3].first,mapgrid[7][7].second,"assets/king2.png", renderer, "BLACK"));

    pieces.push_back(new Queen(mapgrid[4][4].first,mapgrid[0][0].second,"assets/queen2.png", renderer, "WHITE"));
    pieces.push_back(new King(mapgrid[3][3].first,mapgrid[0][0].second,"assets/king2.png", renderer, "WHITE"));

    // Setup bishops
    pieces.push_back(new Bishop(mapgrid[2][2].first,mapgrid[7][7].second,"assets/bishop2.png", renderer, "BLACK"));
    pieces.push_back(new Bishop(mapgrid[5][5].first,mapgrid[7][7].second,"assets/bishop2.png", renderer, "BLACK"));

    pieces.push_back(new Bishop(mapgrid[2][2].first,mapgrid[0][0].second,"assets/bishop2.png", renderer, "WHITE"));
    pieces.push_back(new Bishop(mapgrid[5][5].first,mapgrid[0][0].second,"assets/bishop2.png", renderer, "WHITE"));
}