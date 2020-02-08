#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

const int h = 1000, w = 1000;

class Board {
public:
    SDL_Texture *sprite;
    SDL_Rect square;

    Board(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer) {
        this->square.w = w;
        this->square.h = h;
        this->square.x = x;
        this->square.y = y;
        this->sprite = IMG_LoadTexture(renderer, filename);
    }
};

class System {
public:
    int WIDTH, HEIGHT;
    bool running;

    SDL_Surface* backbuffer;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    System(int WIDTH, int HEIGHT) {
        this->WIDTH = WIDTH;
        this->HEIGHT = HEIGHT;
    }
    
    ~System() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Startup() {
        this->running = true;
        this->window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
        this->backbuffer = SDL_GetWindowSurface(this->window);
    }

    void Render(std::vector<Board> b) {
        SDL_RenderClear(this->renderer);
        for(int i = 0; i < b.size(); i++)
            SDL_RenderCopy(this->renderer, b[i].sprite, NULL, &b[i].square);
        SDL_RenderPresent(this->renderer);
    }
   
    void HandleInput() {
        SDL_PumpEvents();
        const Uint8* keystate = SDL_GetKeyboardState(NULL);

        while(SDL_PollEvent(&this->event))
        {
            if(keystate[SDL_SCANCODE_ESCAPE]) {
                this->running = false;
            }
            if(this->event.type == SDL_QUIT)
            {
                this->running = false;
            }
        }
    }
};

int main(void) {

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
                    board.push_back(Board(w/8,h/8,xpos,ypos,"assets/beige.png", sys.renderer));
                else
                    board.push_back(Board(w/8,h/8,xpos,ypos,"assets/brown.jpeg", sys.renderer));
            }
            else {
                if(i % 2 != 0)
                    board.push_back(Board(w/8,h/8,xpos,ypos,"assets/beige.png", sys.renderer));
                else
                    board.push_back(Board(w/8,h/8,xpos,ypos,"assets/brown.jpeg", sys.renderer));
            }
            xpos += h/8;
        }
        xpos = 0;
        ypos += h/8;
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

