#ifndef CHAMPION_H
#define CHAMPION_H

#include <iostream>
#include <string>

#include "Board.h"
#include "Coordinate.h"

using namespace std;

class Champion : public Player {

    public:
    
        const string name();
        
        const Coordinate play(const Board& board);
        
    protected:

    private:
    
};

#endif
