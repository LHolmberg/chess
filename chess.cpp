#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>


class Board {
public:
    SDL_Texture *sprite;
    SDL_Rect square;

    Board(int w, int h, int x, int y, SDL_Renderer *renderer) {
        this->square.w = w;
        this->square.h = h;
        this->square.x = x;
        this->square.y = y;
        this->sprite = IMG_LoadTexture(renderer, "brown.jpeg");
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

    void Render(Board b) {
        SDL_RenderClear(this->renderer);
        SDL_RenderCopy(this->renderer, b.sprite, NULL, &b.square);
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
    std::vector<Board> board;
    System sys(1000,1000);
    sys.Startup();
    Board b(40,40,0,0, sys.renderer);

    while(sys.running == true)
    {
        sys.Render(b);
        SDL_UpdateWindowSurface(sys.window);
        sys.HandleInput();
    }
    sys.~System();
    return 0;
}

