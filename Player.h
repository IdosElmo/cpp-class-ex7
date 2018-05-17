#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include "Board.h"
#include "Coordinate.h"

using namespace std;

class Board;

class Player {

    public:
    
        char myChar;
    
        virtual const string name() const;
        
        virtual const Coordinate play(const Board& board);
        
        char getChar() const;
        
        char setChar(char Char);
        
        
    protected:

    private:
    
    //char myChar;
    
};

#endif
