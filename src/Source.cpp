#include "System.h"
#include <iostream>
#include <vector>
#include <string>

std::pair<int,int> mapgrid[8][8];
std::vector<Board> board;
std::vector<Piece*> pieces;

System sys(W,H);

std::pair<int,int> ChangePosTo(int x, int y);
void SetupMap();
void SetupPieces();
bool PickedPiece(int x,int y);

int TEMP_ID;

int main() {
    sys.Startup();
    SetupMap();
    SetupPieces();

    int mouseX, mouseY;

    SDL_Event event;
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    bool isSelected = false;

    while(sys.running == true)
    {
        sys.Render(board, pieces);
        
        SDL_PumpEvents();
        while(SDL_PollEvent(&event))
        {
            SDL_GetMouseState(&mouseX, &mouseY);

            if(event.type == SDL_MOUSEBUTTONDOWN)
                isSelected = PickedPiece(mouseX, mouseY);

            if(event.type == SDL_MOUSEBUTTONUP)
            {
                if(isSelected == true)
                {
                    if(pieces[TEMP_ID]->PossibleMove(mapgrid, ChangePosTo(mouseX, mouseY)))
                        pieces[TEMP_ID]->ChangePosition(ChangePosTo(mouseX, mouseY).first, ChangePosTo(mouseX, mouseY).second);
                    else
                        printf("wrong move");
                }
            }
            if(event.type == SDL_QUIT)
                sys.running = false;
        }
        SDL_UpdateWindowSurface(sys.window);
    }

    sys.~System();

    for(auto p : pieces) 
        delete p;
    pieces.clear();

    return 0;
}

// TODO: Get rid of ..

bool PickedPiece(int x, int y)
{
    for(int i = 0; i < pieces.size(); i++)
    {
        if(x >= pieces[i]->square.x && x <= pieces[i]->square.x + pieces[i]->square.w && y >= pieces[i]->square.y && y <= pieces[i]->square.y + pieces[i]->square.h)
        {
            TEMP_ID = i;
            return true;
        }
    }
    return false;
}

std::pair<int,int> ChangePosTo(int x, int y)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(x >= board[i].square.x && x <= board[i].square.x + board[i].square.w && y >= board[i].square.y && y <= board[i].square.y + board[i].square.h)
        {
            return std::make_pair(board[i].square.x,board[i].square.y);
        }
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
//TODO : fixa andra icons till team white
void SetupPieces() {
    //PAWNS
    for(int i = 0; i < 8; i++) { 
        pieces.push_back(new Pawn(mapgrid[i][i].first,mapgrid[1][1].second,"assets/pawn.png", sys.renderer, "WHITE"));
        pieces.push_back(new Pawn(mapgrid[i][i].first,mapgrid[6][6].second,"assets/pawn2.png", sys.renderer, "BLACK"));
    }
    
    //Setup rooks
    pieces.push_back(new Rook(mapgrid[0][0].first,mapgrid[7][7].second,"assets/rook2.png", sys.renderer, "BLACK"));
    pieces.push_back(new Rook(mapgrid[7][7].first,mapgrid[7][7].second,"assets/rook2.png", sys.renderer, "BLACK"));

    pieces.push_back(new Rook(mapgrid[0][0].first,mapgrid[0][0].second,"assets/rook2.png", sys.renderer, "WHITE"));
    pieces.push_back(new Rook(mapgrid[7][7].first,mapgrid[0][0].second,"assets/rook2.png", sys.renderer, "WHITE"));


    // Setup knights
    // Black
    // pieces.push_back(Piece(mapgrid[1][1].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));
    // pieces.push_back(Piece(mapgrid[6][6].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));
    
    //White
    // pieces.push_back(Piece(mapgrid[1][1].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));
    // pieces.push_back(Piece(mapgrid[6][6].first,mapgrid[7][7].second,"assets/knight2.png", sys.renderer));


    // Setup queens and kings
    pieces.push_back(new Queen(mapgrid[4][4].first,mapgrid[7][7].second,"assets/queen2.png", sys.renderer, "BLACK"));
    pieces.push_back(new King(mapgrid[3][3].first,mapgrid[7][7].second,"assets/king2.png", sys.renderer, "BLACK"));

    pieces.push_back(new Queen(mapgrid[4][4].first,mapgrid[0][0].second,"assets/queen2.png", sys.renderer, "WHITE"));
    pieces.push_back(new King(mapgrid[3][3].first,mapgrid[0][0].second,"assets/king2.png", sys.renderer, "WHITE"));

    // Setup bishops
    pieces.push_back(new Bishop(mapgrid[2][2].first,mapgrid[7][7].second,"assets/bishop2.png", sys.renderer, "BLACK"));
    pieces.push_back(new Bishop(mapgrid[5][5].first,mapgrid[7][7].second,"assets/bishop2.png", sys.renderer, "BLACK"));

    pieces.push_back(new Bishop(mapgrid[2][2].first,mapgrid[0][0].second,"assets/bishop2.png", sys.renderer, "WHITE"));
    pieces.push_back(new Bishop(mapgrid[5][5].first,mapgrid[0][0].second,"assets/bishop2.png", sys.renderer, "WHITE"));
}


