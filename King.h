//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {

public:
  //May move one space horizontally, vertically, or diagonally
  bool legal_move_shape(std::pair<char, char> start, std::pair<char, char> end) const;

  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  char to_ascii() const {
    return is_white() ? 'K' : 'k';
  }
  
  ~King() {}

private:
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  King(bool is_white) : Piece(is_white) {}
  
  friend Piece* create_piece(char piece_designator);
};

#endif // KING_H
