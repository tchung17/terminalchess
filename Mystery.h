//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

///////////////////////////////////
// IT IS OK TO MODIFY THIS FILE, //
// YOU WON'T HAND IT IN!!!!!     //
///////////////////////////////////
#ifndef MYSTERY_H
#define MYSTERY_H

#include "Piece.h"
#include <cmath>
#include <cstdlib>

class Mystery : public Piece {

public:
  bool legal_move_shape(std::pair<char, char> start, std::pair<char, char> end) const {
    int rise = end.second - start.second;
    int run = end.first - start.first;
    //The knight must move exactly 2 in the rise and 1 in the run or 2 in the
    //run and 1 in the rise.
    if (abs(rise) == 3) {
      if (abs(run) == 1) {
	return true;
      }
    } else if (abs(rise) == 1) {
      if (abs(run) == 3) {
	return true;
      }
    }
    return false;
  }
  
  char to_ascii() const {
    return is_white() ? 'M' : 'm';
  }

private:
	Mystery(bool is_white) : Piece(is_white) {}

	friend Piece* create_piece(char piece_designator);
};

#endif // MYSTERY_H
