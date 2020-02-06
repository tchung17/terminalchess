//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {

public:
  //Can move forward once space towards opponent's side of the board. On first
  //move of the game, can move either one or two spaces forward. Cannot move
  //onto spaces occupied by pieces owned by any player.
  bool legal_move_shape(std::pair<char, char> start, std::pair<char, char> end) const;
  //This function overrides the legal_capture_shape in Piece.h. Instead of
  //using it's legal move shape to capture pieces, the pawn instead captures
  //pieces by moving one space diagonally
  bool legal_capture_shape(std::pair<char, char> start, std::pair<char, char> end) const;
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  char to_ascii() const {
    return is_white() ? 'P' : 'p';
  }
  
  ~Pawn () {}
  
private:
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  Pawn(bool is_white) : Piece(is_white) {}
  
  friend Piece* create_piece(char piece_designator);
};

#endif // PAWN_H
