#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Piece {
public:
    SDL_Texture *sprite;
    SDL_Rect square;

    void ChangePosition(int x, int y);
    Piece(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer);
    
    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos) = 0;
    virtual std::string name() const = 0;
};

class King : public Piece {
public:
    King(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer)
     : Piece(w,h,x,y,filename,renderer) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos);
    virtual std::string name() const;
};

class Queen : public Piece {
public:
    Queen(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer)
     : Piece(w,h,x,y,filename,renderer) { }
    
    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos);
    virtual std::string name() const;
};

class Rook : public Piece {
public:
    Rook(int w, int h, int x, int y, const char* filename, SDL_Renderer *renderer)
     : Piece(w,h,x,y,filename,renderer) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos);
    virtual std::string name() const;
};


