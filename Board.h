#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <list>

#include "CheckBoard.h"
#include "Coordinate.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"
#include "TicTacToe.h"
#include "Player.h"

using namespace std;


class Board {
    public:
    
        //friend class CheckBoard;
        
        //Coordinate& operator[] (Coordinate& point);
        
        Board(const int squer);
        
        Board(const Board& board); 
        
        ~Board();
        
        Board& operator= (char Char);
        
        Board& operator= (const Board& board);

        CheckBoard& operator [](vector<int> point);
        
        CheckBoard& operator [](const Coordinate& point);
     
        friend ostream& operator<< (ostream& os, const Board& board);
        
        void printBoard();
        
        int size() const;
        
    private:
    
        CheckBoard** board;
        int squer;

};

#endif

