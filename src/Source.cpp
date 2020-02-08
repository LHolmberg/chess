#include "System.h"
#include <iostream>
#include <vector>

const int H = 1000, W = 1000;
std::pair<int,int> mapgrid[8][8];

int main() {
    System sys(1000,1000);
    sys.Startup();

    std::vector<Board> board;
    std::vector<Pawn> pawns;

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

    
    //Setup pawns
    for(int i = 0; i < 8; i++)
    {
        pawns.push_back(Pawn(W/8, H/8,mapgrid[i][i].first,mapgrid[1][1].second,"assets/pawn.png", sys.renderer));
        pawns.push_back(Pawn(W/8, H/8,mapgrid[i][i].first,mapgrid[6][6].second,"assets/pawn2.png", sys.renderer));
    }
    //SETUP TEAM 1
    pawns.push_back(Pawn(W/8, H/8,mapgrid[0][0].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[7][7].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[1][1].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[6][6].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[4][4].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[3][3].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[2][2].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[5][5].first,mapgrid[0][0].second,"assets/king.png", sys.renderer));

    
    //SETUP TEAM 2
    pawns.push_back(Pawn(W/8, H/8,mapgrid[0][0].first,mapgrid[7][7].second,"assets/rook2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[7][7].first,mapgrid[7][7].second,"assets/rook2.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[1][1].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[6][6].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[4][4].first,mapgrid[7][7].second,"assets/queen2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[3][3].first,mapgrid[7][7].second,"assets/king2.png", sys.renderer));

    pawns.push_back(Pawn(W/8, H/8,mapgrid[2][2].first,mapgrid[7][7].second,"assets/bishop2.png", sys.renderer));
    pawns.push_back(Pawn(W/8, H/8,mapgrid[5][5].first,mapgrid[7][7].second,"assets/bishop2.png", sys.renderer));



    while(sys.running == true)
    {
        sys.Render(board, pawns);
        SDL_UpdateWindowSurface(sys.window);
        sys.SelectPiece(pawns);
    }

    sys.~System();
    return 0;
}