#include "System.h"
#include "Gameplay.h"
#include <iostream>
#include <vector>
#include <string>

System sys(W,H);

int main() {
    sys.Startup();
    Gameplay gp(&sys);
    bool myTurn = true;

    int mouseX, mouseY;
    SDL_Event event;
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    bool isSelected = false;
    while(sys.running == true)
    {
        sys.Render(gp.board, gp.pieces);
        SDL_PumpEvents();

        while(SDL_PollEvent(&event))
        {
            SDL_GetMouseState(&mouseX, &mouseY);
            switch(event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    isSelected = gp.PickedPiece(mouseX, mouseY);
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(isSelected == true) {
                        if(gp.pieces[gp.chosenPieceID]->PossibleMove(gp.mapgrid, 
                            gp.ChangePosTo(mouseX, mouseY),gp.pieces)) {
                            switch(myTurn) {
                                case true:
                                    if(gp.pieces[gp.chosenPieceID]->team == "WHITE") {
                                        gp.pieces[gp.chosenPieceID]->ChangePosition(gp.ChangePosTo(mouseX, mouseY).first, 
                                            gp.ChangePosTo(mouseX, mouseY).second);
                                        myTurn = !myTurn;
                                    }
                                    break;
                                default:
                                    if(gp.pieces[gp.chosenPieceID]->team == "BLACK") {
                                        gp.pieces[gp.chosenPieceID]->ChangePosition(gp.ChangePosTo(mouseX, mouseY).first, 
                                            gp.ChangePosTo(mouseX, mouseY).second);
                                        myTurn = !myTurn;
                                    }
                            }
                        }
                    }
                    break;
                case SDL_QUIT:
                    sys.running = false;
                    break;
            }
        }
        SDL_UpdateWindowSurface(sys.window);
    }

    sys.~System();

    for(auto p : gp.pieces) 
        delete p;
    // std::fill_n(gp.pieces, gp.pieces.size(), 0);

    return 0;
}