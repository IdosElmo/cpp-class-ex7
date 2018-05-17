#include "TicTacToe.h"

using namespace std;

 TicTacToe::TicTacToe(const int board_size){
     
        this->gameSize = board_size;
      	Board gameBoard(gameSize);
 }
 
 void TicTacToe::play(Player& player1, Player& player2){
 	

     
     bool gameIsRunning = true;
     player1.setChar('X');
     player2.setChar('O');
     
     while(gameIsRunning){
         
         //player1's turn
         gameBoard[player1.play(gameBoard)] = 'X';
         
         if(checkForWin(gameBoard) == 1){
            win = player1; 
            gameIsRunning = false;
            break;
         }
         
         //player2's turn
         gameBoard[player2.play(gameBoard)] = 'O';
         
         if(checkForWin(gameBoard) == 2){
            win = player2;
            gameIsRunning = false;
         }
     }
     
     cout << "The final board is\n" << board() << endl;
 }


//1 for 'X' - player1
//2 for 'O' - player2
//0 for none -  
int TicTacToe::checkForWin(Board& board){
    
    if(checkRowVictory(board) == 1 || checkColVictory(board) == 1 || checkDiagVictory(board) == 1){
        //player 1 win
        return 1;
    }
    else if(checkRowVictory(board) == 2 || checkColVictory(board) == 2 || checkDiagVictory(board) == 2){
        //player 2 win
        return 2;
    }
    else
    return 0;
}


//1 for 'X' -
//2 for 'O' -
//0 for none -  
int TicTacToe::checkRowVictory(Board& board){
    int rowCountX = 0, rowCountO = 0;
    
    for (uint x=0; x<board.size(); ++x) {
		for (uint y=0; y<board.size(); ++y) {
		    Coordinate c{x,y};
		    if(board[c] == 'X')
		    {
		        rowCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        rowCountO++;
		    }
		}
		
		if(rowCountX == board.size()){
		    return 1;
		}
		else if(rowCountO == board.size()){
		    return 2;
		}
		rowCountO = 0;
		rowCountX = 0;
	}
	
	return 0;
}

//1 for 'X' -
//2 for 'O' -
//0 for none - 
int TicTacToe::checkColVictory(Board& board){
    int colCountX = 0, colCountO = 0;
    
    for (uint y=0; y<board.size(); ++y) {
		for (uint x=0; x<board.size(); ++x) {
            Coordinate c{x,y};
		    if(board[c] == 'X')
		    {
		        colCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        colCountO++;
		    }
		}
	}
	
	if(colCountX == board.size()){
		return 1;
	}
	else if(colCountO == board.size()){
	    return 2;
	}
	
	colCountO = 0;
	colCountX = 0;
	
	return 0;
}

//1 for 'X' -
//2 for 'O' -
//0 for none - 
int TicTacToe::checkDiagVictory(Board& board){
    int diagCountX = 0, diagCountO = 0;
    
    for (uint y=0; y<board.size(); ++y) {
		for (uint x=0; x<board.size(); ++x) {
            if(x == y)
            {
            Coordinate c{x,y};
		    if(board[c] == 'X')
		    {
		        diagCountX++;
		    }
		    else if(board[c] == 'O')
		    {
		        diagCountO++;
		    }
            }
		}
	}
	
	if(diagCountX == board.size()){
		return 1;
	}
	else if(diagCountO == board.size()){
	    return 2;
	}
	
	return 0;
}
 
 
Player& TicTacToe::winner() const{
    return win;
}

char& TicTacToe::board() const{
    for(int i=0; i < gameBoard.size(); i++){
        for(int j=0; j < gameBoard.size(); j++){
            cout << gameBoard[i][j];
            }
            
       cout << endl;
    }
}