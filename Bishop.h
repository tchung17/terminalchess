//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {

public:
  //May move diagonally any number of spaces
  bool legal_move_shape(std::pair<char, char> start, std::pair<char, char> end) const;

  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  char to_ascii() const {
    return is_white() ? 'B' : 'b';
  }

  ~Bishop() {}
  
private:
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  Bishop(bool is_white) : Piece(is_white) {}
  
  friend Piece* create_piece(char piece_designator);
};

#endif // BISHOP_H
