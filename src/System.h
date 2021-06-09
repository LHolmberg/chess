#pragma once
#include "Board.h"
#include "Pieces.h"
#include <vector>

class System
{
public:
    int WIDTH, HEIGHT;
    bool running;
    int x, y;

    SDL_Surface *backbuffer;
    SDL_Window *window;
    SDL_Renderer *renderer;

    System(int WIDTH, int HEIGHT);
    ~System();

    void Startup();
    void Render(std::array<Board, 64> b, std::array<Piece *, 32> p);
    void UpdateTurnStatus(std::array<Piece *, 32> pieces, bool turn);
};
