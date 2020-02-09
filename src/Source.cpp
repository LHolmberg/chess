#include "System.h"
#include <iostream>
#include <vector>

const int H = 600, W = 600;
std::pair<int,int> mapgrid[8][8];

std::vector<Board> board;
std::vector<Pawn> pawns;
System sys(600,600);

std::pair<int,int> ChangePosTo(int x, int y);
void SetupMap();
void SetupPieces();
bool PickedPiece(int x,int y);
int TEMP_ID;

int main() {
    sys.Startup();
    SetupMap();
    SetupPieces();

    int x, y; //mousepos

    SDL_Event event;
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    bool isSelected = false;

    while(sys.running == true)
    {
        sys.Render(board, pawns);
        SDL_PumpEvents();
        
        while(SDL_PollEvent(&event))
        {
            SDL_GetMouseState(&x,&y);
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                isSelected = PickedPiece(x,y);
            }
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if(isSelected == true)
                    pawns[TEMP_ID].ChangePosition(ChangePosTo(x,y).first, ChangePosTo(x,y).second);
            }
            if(event.type == SDL_QUIT)
            {
                sys.running = false;
            }
        }
        SDL_UpdateWindowSurface(sys.window);
    }

    sys.~System();
    return 0;
}

std::pair<int,int> ChangePosTo(int x, int y)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(x >= board[i].square.x && x <= board[i].square.x + board[i].square.w && y >= board[i].square.y && y <= board[i].square.y + board[i].square.h)
            return std::make_pair(board[i].square.x,board[i].square.y);
    }
}

void SetupMap() {
    int xpos = 0, ypos = 0;
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            if(j % 2 != 0)
            {
                if(i % 2 == 0)
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/beige.png", sys.renderer));
                else
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/brown.jpeg", sys.renderer));
            }
            else {
                if(i % 2 != 0)
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/beige.png", sys.renderer));
                else
                    board.push_back(Board(W/8,H/8,xpos,ypos,"assets/brown.jpeg", sys.renderer));
            }
            mapgrid[j][i] = std::make_pair(xpos,ypos);
            xpos += H/8;
        }
        xpos = 0;
        ypos += W/8;
    }
}

void SetupPieces() {
    //Setup pawns
    for(int i = 0; i < 8; i++)
    {
        //white
        pawns.push_back(Pawn(W/8, H/8,mapgrid[i][i].first,mapgrid[1][1].second,"assets/pawn.png", sys.renderer));
        
        //black
        pawns.push_back(Pawn(W/8, H/8,mapgrid[i][i].first,mapgrid[6][6].second,"assets/pawn2.png", sys.renderer));
    }

    //Setup : fixa andra icons
    pawns.push_back(Pawn(W/8, H/8,mapgrid[0][0].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[7][7].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[1][1].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[6][6].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[4][4].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[3][3].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[2][2].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[5][5].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    
    //Setup rooks
    pawns.push_back(Pawn(W/8, H/8,mapgrid[0][0].first,mapgrid[7][7].second,"assets/rook2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[7][7].first,mapgrid[7][7].second,"assets/rook2.png", sys.renderer));

    //Setup knights
    pawns.push_back(Pawn(W/8, H/8,mapgrid[1][1].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[6][6].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));

    //Setup queens and kings
    pawns.push_back(Pawn(W/8, H/8,mapgrid[4][4].first,mapgrid[7][7].second,"assets/queen2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[3][3].first,mapgrid[7][7].second,"assets/king2.png", sys.renderer));

    //Setup bishops
    pawns.push_back(Pawn(W/8, H/8,mapgrid[2][2].first,mapgrid[7][7].second,"assets/bishop2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[5][5].first,mapgrid[7][7].second,"assets/bishop2.png", sys.renderer));
}

bool PickedPiece(int x, int y)
{
    for(int i = 0; i < pawns.size(); i++)
    {
        if(x >= pawns[i].square.x && x <= pawns[i].square.x + pawns[i].square.w && y >= pawns[i].square.y && y <= pawns[i].square.y + pawns[i].square.h)
        {
            TEMP_ID = i;
            return true;
        }
    }
    return false;
}