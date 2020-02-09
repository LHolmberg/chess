#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Pawn {
public:
    SDL_Texture *sprite;
    SDL_Rect square;
    int pawnID;

    void ChangePosition(int x, int y);
    Pawn(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer);
};