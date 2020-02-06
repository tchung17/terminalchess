//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {

public:
  //May move any number of spaces horizontally, vertically, or diagonally
  bool legal_move_shape(std::pair<char, char> start, std::pair<char, char> end) const;
	
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  char to_ascii() const {
    return is_white() ? 'Q' : 'q';
  }
  
  ~Queen() {}
  
private:
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  Queen(bool is_white) : Piece(is_white) {}
  
  friend Piece* create_piece(char piece_designator);
};

#endif // QUEEN_H
