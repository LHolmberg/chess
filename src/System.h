#include "Board.h"
#include "Pieces.h"
#include <vector>

class System {
public:
    int WIDTH, HEIGHT;
    bool running;
    int x, y;

    SDL_Surface* backbuffer;
    SDL_Window* window;
    SDL_Renderer* renderer;

    System(int WIDTH, int HEIGHT);
    ~System();

    void Startup();
    void Render(std::vector<Board> b, std::vector<Piece*> p);

};
