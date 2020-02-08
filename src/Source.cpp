#include "System.h"
#include <iostream>
#include <vector>

const int H = 1000, W = 1000;

int main() {
    System sys(1000,1000);
    sys.Startup();

    std::vector<Board> board;

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
            xpos += H/8;
        }
        xpos = 0;
        ypos += W/8;
    }

    while(sys.running == true)
    {
        sys.Render(board);
        SDL_UpdateWindowSurface(sys.window);
        sys.HandleInput();
    }

    sys.~System();
    return 0;
}