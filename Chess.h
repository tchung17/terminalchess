//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include "Piece.h"
#include "Board.h"
#include <string>

class Chess {

public:
  // This default constructor initializes a board with the standard
  // piece positions, and sets the state to white's turn
  Chess();
  
  // Returns a constant reference to the board 
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  const Board& get_board() const { return board; }
  
  // Returns true if it is white's turn
  /////////////////////////////////////
  // DO NOT MODIFY THIS FUNCTION!!!! //
  /////////////////////////////////////
  bool turn_white() const { return is_white_turn; }
  
  // Attempts to make a move. If successful, the move is made and
  // the turn is switched white <-> black
  // Will return false if move ends with player in check
  bool make_move(std::pair<char, char> start, std::pair<char, char> end);
  
  // Returns true if the designated player is in check
  bool in_check(bool white) const;

  // Returns true if the designated player is in mate
  bool in_mate(bool white);

  // Returns true if the designated player is in mate
  bool in_stalemate(bool white);

  // allows function to access private board
  friend std::istream& operator>> (std::istream& is, Chess& chess);

private:
  // The board
  Board board;

  // Is it white's turn?
  bool is_white_turn;

  //Changes pawn to queen if the pawn reaches the last row of the board
  void promote_pawn(std::pair<char, char> position, bool is_white); //private
  
  //Sees if move is legal without attempt; does not account for check
  bool try_move(std::pair<char, char> start, std::pair<char, char> end, bool white) const;

  //Returns true if a piece crossing violation has occured; if a piece
  //moves in a straight line, then it is not allowed to pass through
  //other pieces
  bool crossing_violation(std::pair<char, char> start, std::pair<char, char> end) const;
  
  //for a given piece, check any and all possible moves that change the
  //check status
  bool check_changed(std::pair<char, char> position, bool white); 

};

// Writes the board out to a stream
std::ostream& operator<< (std::ostream& os, const Chess& chess);

// Reads the board in from a stream
std::istream& operator>> (std::istream& is, Chess& chess);


#endif // CHESS_H
