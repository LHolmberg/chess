#include "Board.h"
#include <vector>

class System {
public:
    int WIDTH, HEIGHT;
    bool running;
    int x, y;

    SDL_Surface* backbuffer;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    System(int WIDTH, int HEIGHT);
    ~System();

    void Startup();
    void Render(std::vector<Board> b, std::vector<Pawn> p);
    void SelectPiece(std::vector<Pawn> p);

};
