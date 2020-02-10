#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>

const int W = 600, H = 600; //SCREEN

class Piece {
public:
    SDL_Texture *sprite;
    SDL_Rect square;
    std::string team;

    void ChangePosition(int x, int y);
    Piece(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team);
    
    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos,
            std::vector<Piece*> pieces) = 0;
    virtual std::string name() const = 0;
};

class King : public Piece {
public:
    King(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};

class Queen : public Piece {
public:
    Queen(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }
    
    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};

class Rook : public Piece {
public:
    Rook(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};

class Bishop : public Piece {
public:
    Bishop(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};

class Pawn : public Piece {
public:
    Pawn(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};

class Knight : public Piece {
public:
    Knight(int x, int y, const char* filename, SDL_Renderer *renderer, std::string team)
     : Piece(x,y,filename,renderer, team) { }

    virtual bool PossibleMove(std::pair<int,int> mapgrid[8][8], std::pair<int,int> newPos, std::vector<Piece*> pieces);
    virtual std::string name() const;
};
