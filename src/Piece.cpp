#include "Piece.h"

Pawn::Pawn(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer) {
        this->square.w = w;
        this->square.h = h;
        this->square.x = x;
        this->square.y = y;
        this->pawnID = rand() % 100 + 1;
        this->sprite = IMG_LoadTexture(renderer, filename); 
}

void Pawn::ChangePosition(int x, int y) {
        this->square.x = x;
        this->square.y = y;
}