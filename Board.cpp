#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

#include "Board.h"


        Board::Board(const int squer){
            this->squer = squer;
            board = new CheckBoard*[squer];
            for(int i = 0; i < squer; ++i){
                board[i] = new CheckBoard[squer];
            }
            for (int i = 0; i < squer; i++) {
                for (int  j = 0; j <  squer; j++) {
                    board[i][j] = '.';
                }
            }
        }
        
        Board::Board(const Board& _board) {
          squer = _board.squer;
          board = new CheckBoard*[squer];
          for(int i = 0; i < squer; i++)
                board[i] = new CheckBoard[squer];
                
              for (int i = 0; i < squer; i++) {
               for (int j = 0; j < squer; j++) {
            board[i][j] = _board.board[i][j];
        }
    }
}

Board::~Board(){
    for (int i = 0; i <squer ; ++i) {
            delete[] board[i];
    }delete[] board;

}

    
        CheckBoard& Board::operator[] (vector<int> point) {
            if (point.at(0) < 0 || point.at(0) >= squer || point.at(1) < 0 || point.at(1) >= squer)
            throw IllegalCoordinateException(point.at(0), point.at(1));
            return board[point.at(0)][point.at(1)];
}   

        CheckBoard& Board::operator[] (const Coordinate& point) {
            if (point.x < 0 || point.x >= squer || point.y < 0 || point.y >= squer)
            throw IllegalCoordinateException(point.x, point.y);
            return &board[point.x][point.y];
} 


    Board& Board::operator= (char Char){
        if(Char != '.' && Char != 'X' && Char != 'O')
        throw IllegalCharException(Char);
       
    for (int i = 0; i < squer; i++) {
        for (int j = 0; j < squer; j++) {
            board[i][j] = Char;
        }
    }
 
    return *this;
}

Board& Board::operator= (const Board& _board) {
         this->~Board();
        squer = _board.squer;
        board = new CheckBoard*[squer];
        
        for(int i = 0; i < squer; i++)
        board[i] = new CheckBoard[squer];
        
        for(int i = 0; i < squer; i++) {
                for(int j = 0; j < squer; j++) {
                  board[i][j].setP(_board.board[i][j].getP());
        }
    }
    return *this;
}

   ostream& operator<<(ostream& os , const Board& board) {
           for(int i=0; i < board.squer; i++){
               for(int j=0; j < board.squer; j++){
                   os << board.board[i][j];
               }
               os<< endl;
           }
    return os;
    }
    
int Board::size() const{
    return squer;
}

    