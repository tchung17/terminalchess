//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <iostream>
#include <utility>
#include <map>
#include <string>
#include "Board.h"
#include "CreatePiece.h"
#include "Terminal.h"

/////////////////////////////////////
// DO NOT MODIFY THIS FUNCTION!!!! //
/////////////////////////////////////
Board::Board(){}

const Piece* Board::operator()(std::pair<char, char> position) const {
  if (occ.count(position) > 0) {
    return occ.at(position);
  }
  else {
    return nullptr;
  }
}

// Attempts to add a new piece with the specified designator, at the given location.
	// Returns false if:
	// -- the designator is invalid,
	// -- the specified location is not on the board, or
	// -- if the specified location is occupied
bool Board::add_piece(std::pair<char, char> position, char piece_designator){
  
  //Checks for valid designator
  if (piece_designator != 'K' && piece_designator != 'k'
      && piece_designator != 'Q' && piece_designator != 'q' 
      && piece_designator != 'B' && piece_designator != 'b'
      && piece_designator != 'N' && piece_designator != 'n'
      && piece_designator != 'R' && piece_designator != 'r'
      && piece_designator != 'P' && piece_designator != 'p'
      && piece_designator != 'M' && piece_designator != 'm') {
    return false;
  }

  //Checks for valid board position
  if (position.first != 'A' + 0 && position.first != 'A' + 1
      && position.first != 'A' + 2 && position.first != 'A' + 3
      && position.first != 'A' + 4 && position.first != 'A' + 5
      && position.first != 'A' + 6 && position.first != 'A' + 7){
    return false;
  }

  if (position.second != '1' + 0 && position.second != '1' + 1
      && position.second != '1' + 2 && position.second != '1' + 3
      && position.second != '1' + 4 && position.second != '1' + 5
      && position.second != '1' + 6 && position.second != '1' + 7){
    return false;
  }

  //Checks if position is occupied
  if (occ.count(position) > 0) {
    return false;
  }

  //Adds the piece to the board
  occ[position] = create_piece(piece_designator);
  return true;
}

Board::~Board(){
  clear_board();
}

void Board::dele(std::pair<char, char> position){
  delete occ[position];
  occ.erase(position);
}
void Board::board_move(std::pair<char, char> start, std::pair<char, char> end) {
  //If capturing a piece, must delete captured piece first
  if (occ.count(end) > 0) {
    delete occ[end];
  }
  
  //Now make end contain pointer to the piece, and erase the element containing now empty start position
  occ[end] = occ[start];
  occ.erase(start);
}

void Board::clear_board(){
  for (std::map<std::pair<char, char>, Piece*>::iterator it = occ.begin(); it != occ.end(); ++it) {
    delete it->second;
  }
  occ.clear();
  
}

bool Board::has_valid_kings() const{
  if (king_location(true).first != 'z' && king_location(false).first != 'z'){
    return true;
  }
  return false;
}

std::pair<char, char> Board::king_location(bool white) const {
  //Iterate through every space on the board
  for (std::map<std::pair<char, char>, Piece*>::const_iterator it = occ.cbegin(); it != occ.cend(); ++it) {
    //Searching for white king location
    if (white) {
      //If the space contains a white king
      if (it->second->to_ascii() == 'K') {
	return (it->first);
      }
    }
    //Searching for black king location
    else {
      //If the space contains a black king
      if (it->second->to_ascii() == 'k') {
	return (it->first);
      }
    }
  }
  
  return std::pair<char, char> ('z', 'z'); //Failed
}

void Board::display() const {
  // Colors from Terminal.h
  Terminal::Color blue = Terminal::Color::BLUE; //border background
  Terminal::Color cyan = Terminal::Color::CYAN; //border text
  Terminal::Color yellow = Terminal::Color::YELLOW; //checkerboard color 1
  Terminal::Color green = Terminal::Color::GREEN; //checkerboard color 2
  Terminal::Color black = Terminal::Color::BLACK; //black pieces
  Terminal::Color white = Terminal::Color::WHITE; //white pieces
  /*
   * Unused colors
   *
   * Terminal::Color default_color = Terminal::Color::DEFAULT_COLOR;
   * Terminal::Color red = Terminal::Color::RED;
   * Terminal::Color magenta = Terminal::Color::MAGENTA;
   */
  
  int count=0;

  //Style for top of board
  std::cout << std::endl;
  Terminal::color_all(0, cyan, blue);
  std::cout << "  ABCDEFGH  "; //Column designators
  Terminal::set_default();
  std::cout << std::endl;

  //Style for middle of board
  for(char r = '8'; r >= '1'; r--) {
    Terminal::color_all(0, cyan, blue);
    std::cout << " " << r; //Row designators
    for(char c = 'A'; c <= 'H'; c++) {
      count++;
      //Checkerboard pattern for the background of the board
      if ((count + r) % 2 == 0) {
	Terminal::color_all(1, green, green);
      } else {
	Terminal::color_all(1, yellow, yellow);
      }
      const Piece* piece = ((const Board&) *this)(std::pair<char, char>(c, r));
      if (piece) {
	if (piece->to_ascii() < 'z' && piece->to_ascii() > 'a') {
	  Terminal::color_fg(0, black); //Black pieces are colored black
	} else if (piece->to_ascii() < 'Z' && piece->to_ascii() > 'A') {
	  Terminal::color_fg(1, white); //White pieces are colored white
	}
	std::cout << piece->to_ascii(); //Prints the respective piece
      } else {
	std::cout << '-'; //Prints an empty space
      }
    }
    Terminal::color_all(0, cyan, blue);
    std::cout << r << " "; //Row designators
    Terminal::set_default();
    std::cout << std::endl;
  }

  //Style for bottom of board
  Terminal::color_all(0, cyan, blue);
  std::cout << "  ABCDEFGH  "; //Column designators
  Terminal::set_default();
  std::cout << std::endl;
}

/////////////////////////////////////
// DO NOT MODIFY THIS FUNCTION!!!! //
/////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Board& board) {
	for(char r = '8'; r >= '1'; r--) {
		for(char c = 'A'; c <= 'H'; c++) {
			const Piece* piece = board(std::pair<char, char>(c, r));
			if (piece) {
				os << piece->to_ascii();
			} else {
			  os << '-';
			}
		}
		os << std::endl;
	}
	return os;
}

