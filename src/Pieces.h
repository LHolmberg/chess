#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Piece {
public:
    SDL_Texture *sprite;
    SDL_Rect square;
    std::string type;

    void ChangePosition(int x, int y);
    Piece(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer);
    
    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos) = 0;
    virtual std::string name() const = 0;
};

class Rook : public Piece {
public:
    Rook(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer)
     : Piece(w,h,x,y,filename,renderer) {
        this->type = typeid(this).name();
    }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos);
    virtual std::string name() const;
};
