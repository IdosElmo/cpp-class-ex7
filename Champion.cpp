#include "Champion.h"

using namespace std;


    const Coordinate Champion::play(const Board& board) {
/*	for (int y=0; y<board.size(); ++y) {
		for (int x=0; x<board.size(); ++x) {
			Coordinate c = {x,y};
			if (board[c]=='.') {
				return c;
			}
		}
	}   */
	return {0,0};  // did not find an empty square - play on the top-left
}
