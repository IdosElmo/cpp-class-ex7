#include <stdio.h>
#include <iostream>
#include <list>

#include "Player.h"

using namespace std;



    const string name() const { return "XYPlayer"; }
            
    const Coordinate Player::play(const Board& board) {
	for (uint y=0; y<board.size(); ++y) {
		for (uint x=0; x<board.size(); ++x) {
			Coordinate c = {x,y};
			if (board[c]=='.') {
				return c;
			}
		}
	}
	return {0,0};  // did not find an empty square - play on the top-left
    }
	char Player::getChar() const {
	    return myChar;
	}
	
	char Player::setChar(char Char){
	    if (Char != '.' && Char != 'X' && Char != 'O')
        throw IllegalCharException(Char);
        myChar = Char;
	}

