#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>


#include "Board.h"
#include "Player.h"

using namespace std;

class Board;
class Player;

class TicTacToe {

    public:

        //Constructor.
        
        TicTacToe(const int board_size);

        void play(Player& player1, Player& player2);

        char&  board() const;
        
        Player&  winner() const;
        
        int checkForWin( Board& board);
        
        int checkColVictory( Board& board);
        
        int checkDiagVictory( Board& board);
        
        int checkRowVictory( Board& board);
        
    protected:

    private:

        //Variables of the object.
        
        int gameSize;
        
        Board& gameBoard;
        
        Player& win;
        
        friend ostream& operator<< (ostream& os, const CheckBoard& piece);
};

#endif
