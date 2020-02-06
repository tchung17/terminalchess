//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {

public:
  //May move either two spaces horizontally and one space vertically or
  //one space horizontally and two spaces vertically. May pass through
  //other pieces
  bool legal_move_shape(std::pair<char, char> start, std::pair<char, char> end) const;
  
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  char to_ascii() const {
    return is_white() ? 'N' : 'n';
  }

  ~Knight() {}

private:
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  Knight(bool is_white) : Piece(is_white) {}
  
  friend Piece* create_piece(char piece_designator);
};

#endif // KNIGHT_H
