#include "System.h"
#include <iostream>

System::System(int WIDTH, int HEIGHT) {
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
}

System::~System() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void System::Startup() {
    this->running = true;
    this->window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    this->backbuffer = SDL_GetWindowSurface(this->window);
}

void System::Render(std::vector<Board> b, std::vector<Pawn> p) {
    SDL_RenderClear(this->renderer);
    for(int i = 0; i < b.size(); i++)
        SDL_RenderCopy(this->renderer, b[i].sprite, NULL, &b[i].square);
    for(int i = 0; i < p.size(); i++)
        SDL_RenderCopy(this->renderer, p[i].sprite, NULL, &p[i].square);
    SDL_RenderPresent(this->renderer);
}

void System::SelectPiece(std::vector<Pawn> p) {
    SDL_PumpEvents();
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    int x, y;
    while(SDL_PollEvent(&this->event))
    {
        SDL_GetMouseState(&x,&y);
        if(this->event.type == SDL_MOUSEBUTTONDOWN)
        {
            for(int i = 0; i < p.size(); i++)
            {
                if(x >= p[i].square.x && x <= p[i].square.x + p[i].square.w && y >= p[i].square.y && y <= p[i].square.y + p[i].square.h)
                {
                    SDL_DestroyTexture(p[i].sprite); // select piece
                }
            }
        }
        if(this->event.type == SDL_QUIT)
        {
            this->running = false;
        }
    }
}