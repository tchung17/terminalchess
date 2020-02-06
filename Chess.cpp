//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include "Chess.h"
#include <iostream>
#include <string>

/////////////////////////////////////
// DO NOT MODIFY THIS FUNCTION!!!! //
/////////////////////////////////////
Chess::Chess() : is_white_turn(true) {
	// Add the pawns
	for (int i = 0; i < 8; i++) {
		board.add_piece(std::pair<char, char>('A' + i, '1' + 1), 'P');
		board.add_piece(std::pair<char, char>('A' + i, '1' + 6), 'p');
	}

	// Add the rooks
	board.add_piece(std::pair<char, char>( 'A'+0 , '1'+0 ) , 'R' );
	board.add_piece(std::pair<char, char>( 'A'+7 , '1'+0 ) , 'R' );
	board.add_piece(std::pair<char, char>( 'A'+0 , '1'+7 ) , 'r' );
	board.add_piece(std::pair<char, char>( 'A'+7 , '1'+7 ) , 'r' );

	// Add the knights
	board.add_piece(std::pair<char, char>( 'A'+1 , '1'+0 ) , 'N' );
	board.add_piece(std::pair<char, char>( 'A'+6 , '1'+0 ) , 'N' );
	board.add_piece(std::pair<char, char>( 'A'+1 , '1'+7 ) , 'n' );
	board.add_piece(std::pair<char, char>( 'A'+6 , '1'+7 ) , 'n' );

	// Add the bishops
	board.add_piece(std::pair<char, char>( 'A'+2 , '1'+0 ) , 'B' );
	board.add_piece(std::pair<char, char>( 'A'+5 , '1'+0 ) , 'B' );
	board.add_piece(std::pair<char, char>( 'A'+2 , '1'+7 ) , 'b' );
	board.add_piece(std::pair<char, char>( 'A'+5 , '1'+7 ) , 'b' );

	// Add the kings and queens
	board.add_piece(std::pair<char, char>( 'A'+3 , '1'+0 ) , 'Q' );
	board.add_piece(std::pair<char, char>( 'A'+4 , '1'+0 ) , 'K' );
	board.add_piece(std::pair<char, char>( 'A'+3 , '1'+7 ) , 'q' );
	board.add_piece(std::pair<char, char>( 'A'+4 , '1'+7 ) , 'k' );
}

bool Chess::try_move(std::pair<char, char> start, std::pair<char, char> end, bool white) const{
  char start_column = start.first;
  char start_row = start.second;
  char end_column = end.first;
  char end_row = end.second;
  
  //Check if start column is out of bounds                                        
  if ((start_column < 'A') || (start_column > 'H')) {
    //Return false and do not switch the turn                                     
    return false;
  }
  //Check if start row is out of bounds                                           
  if ((start_row < '1') || (start_row > '8')) {
    return false;
  }
  //Check if end column is out of bounds                                          
  if ((end_column < 'A') || (end_column > 'H')) {
    return false;
  }
  //Check if end row is out of bounds                                             
  if ((end_row < '1') || (end_row > '8')) {
    return false;
  }
  
  //Check if trying to move an empty space
  if (board(start) == board(end)){
	  return false;
  }
  if (board(start) == nullptr){
	  return false;
  }
  if(board(start)->is_white() != white){
    return false;
  }
  //Check if end is an empty space                                                       
  if (board(end) == nullptr) {
    //If move shape is not legal, return false                                    
    if (!board(start)->legal_move_shape(start, end)) {
      return false;
    }
  }
  //Illegal to move to a space with same color piece                              
  else if (board(end)->is_white() == white) {
    return false;
  }
  //If move to a space with another color piece                                   
  else if (board(end)->is_white() != white) {
    //If not a legal capture shape return false                                   
    if (!board(start)->legal_capture_shape(start, end)) {
      return false;
    }
  }

  //Function to check is unallowed piece crossing has occured
  if (crossing_violation(start, end)) {
    return false;
  }
  
  return true;
}

bool Chess::crossing_violation(std::pair<char, char> start, std::pair<char, char> end) const {
  char start_column = start.first;
  char start_row = start.second;
  char end_column = end.first;
  char end_row = end.second;

  //up (u), down (d), right (r), left (l), northeast (1), northwest (2), southwest (3), southeast (4))
  //Otherwise move is nonlinear ('n')
  char move_type;
  
  //Check if the piece moves in a straight line
  if ((start_column == end_column) && (start_row < end_row)) {
    //up
    move_type = 'u';
  }
  else if ((start_column == end_column) && (start_row > end_row)) {
    //down                                                
    move_type = 'd';
  }
  else if ((start_row == end_row) && (start_column < end_column)) {
    //right
    move_type = 'r';
  }
  else if ((start_row == end_row) && (start_column > end_column)) {
    //left                                          
    move_type = 'l';
  }
  else if (end_row - start_row == end_column - start_column && end_row > start_row) {
    //northeast
    move_type = '1';
  }
  else if (end_row - start_row == -(end_column - start_column) && end_column < start_column) {
    //northwest                                           
    move_type = '2';
  }
  else if (end_row - start_row == end_column - start_column && end_row < start_row) {
    //southwest                                                
    move_type = '3';
  }
  else if (end_row - start_row == -(end_column - start_column) && end_column > start_column) {
    //southeast      
    move_type = '4';
  }
  else {
    //non linear
    move_type = 'n';
  }

  std::pair<char, char> position;
  
  //Pieces that move in a straight line are not allowed to cross pieces                         
  //Pieces that do not move in a straight line (Knights and potentially a mystery piece) are allowed to cross pieces)   
  switch (move_type) {
  case 'u':
    position.first = start_column;
    for (int i = start_row + 1; i < end_row; i++) {
      position.second = i;

      //If there is a key for this position
      if (board(position) != nullptr) {
	//there is a piece crossed so return true
	return true;
      }
    }
    break;
  case 'd':
    position.first = start_column;
    for (int i = end_row + 1; i < start_row; i++) {
      position.second = i;
      //If there is a key for this position                                                                    
      if (board(position) != nullptr) {
        //there is a piece crossed so return true                                                            
        return true;
      }
    }
    break;
  case 'r':
    position.second = start_row;
    for (int i = start_column + 1; i < end_column; i++) {
      position.first = i;

      //If there is a key for this position                                                                       
      if (board(position) != nullptr) {
        //there is a piece crossed so return true                                                                 
        return true;
      }
    }
    break;
  case 'l':
    position.second = start_row;
    for (int i = end_column + 1; i < start_column; i++) {
      position.first = i;

      //If there is a key for this position                                                                    
      if (board(position) != nullptr) {
        //there is a piece crossed so return true                                    
        return true;
      }
    }
    break;
  case '1':
    position = start;
    for (int i = 1; i < (end_row - start_row); i++) {
      position.first++;
      position.second++;

      //If there is a key for this position
      if (board(position) != nullptr) {
	return true;
      }
    }
    break;
  case '2':
    position = start;
    for	(int i = 1; i < (end_row - start_row); i++) {
      position.first--;
      position.second++;

      //If there is a key for this position                                          
      if (board(position) != nullptr) {
	return true;
      }
    }
    break;
  case '3':
    position = start;
    for (int i = 1; i < (start_row - end_row); i++) {
      position.first--;
      position.second--;
      //If there is a key for this position
      if (board(position) != nullptr) {
        return true;
      }
    }
    break;
  case '4':
    position = start;
    for (int i = 1; i < (start_row - end_row); i++) {
      position.first++;
      position.second--;
      //If there is a key for this position                                                                   
      if (board(position) != nullptr) {
        return true;
      }
    }
    break;
  case 'n':
    break;
  default:
    std::cerr << "Unexpected move type" << std::endl;
  }

  return false;
}

bool Chess::make_move(std::pair<char, char> start, std::pair<char, char> end){
  //Make positions uppercase                                                  
  start.first = toupper(start.first);
  end.first = toupper(end.first);

  char startchar = '-';
  char endchar = '-';

  if (try_move(start, end, is_white_turn)){
    //Save ascii values in case move needs to be undone
    startchar = board(start)->to_ascii();
    if(board(end)){
      endchar = board(end)->to_ascii();
    } 

    board.board_move(start, end);
    
    //If the piece just moved is a pawn to the otherside of the board
    if (board(end)->to_ascii() == 'P' && end.second == '8') {
      //Promote a white pawn that reached row 8
      promote_pawn(end, true);
    }
    if (board(end)->to_ascii() == 'p' && end.second == '1') {
      //Promote a black pawn that reached row 1
      promote_pawn(end, false);
    }

    //Added check disallows making a move that would put you in check
    if (in_check(is_white_turn)){
      //Undoes the move
      if (endchar != '-') {
	board.dele(end);
	board.add_piece(start, startchar);
	board.add_piece(end, endchar);
      }
      else {
	board.dele(end);
	board.add_piece(start, startchar);
      }
      return false;
    }
    
    //Change the turn
    is_white_turn = !is_white_turn;

    return true;
  }
  
  //Is reached if try_move is not successful
  return false;
}

void Chess::promote_pawn(std::pair<char, char> position, bool is_white) {
  if (is_white) {
    board.dele(position);
    board.add_piece(position, 'Q');
  }
  else {
    board.dele(position);
    board.add_piece(position, 'q');
  }
}

bool Chess::in_check(bool white) const {
  std::pair<char, char> king = board.king_location(white);
  bool test = false;
  king.first = toupper(king.first);

  //For every position on the board
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      std::pair<char, char> position;
      position.first = 'A' + i;
      position.second = '1' + j;

      //If there is a piece at that position that could take the king
      if(try_move(position, king, !white)){
	test = true;
      }	
    }
  }
  return test;
}

bool Chess::check_changed(std::pair<char, char> position, bool white) {
  bool check = in_check(white);
  bool test = false;

  //For every location on the board
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      std::pair<char, char> attempt;
      attempt.first = 'A' + i;
      attempt.second = '1' + j;
      char positionchar = '-';
      char attemptchar = '-';

      //If the piece at the start position could not move to attempt
      //then try next attempt
      if (!try_move(position, attempt, white)){
	continue;
      }

      //Store the original positions to undo the move made later
      if(board(position)){
	positionchar = board(position)->to_ascii();
      }
      if(board(attempt)){
	attemptchar = board(attempt)->to_ascii();
      }

      //If the piece can move to attempt, then make the move
      board.board_move(position, attempt);

      //Check if this move puts you in check
      if (in_check(white) != check){
	test = true;
      }

      //Undo the move
      board.dele(attempt);
      board.add_piece(position, positionchar);
      board.add_piece(attempt, attemptchar);
    }
  }
  return test;
}

bool Chess::in_mate(bool white){

  //Must be in check
  if (!in_check(white)){
    return false;
  }

  //For every location on the board
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      std::pair<char, char> position;
      position.first = 'A' + i;
      position.second = '1' + j;

      //If the piece at that location could make a move that takes you out of check
      if (check_changed(position, white)){
	return false;
      }
    }
  }
  return true;
}


bool Chess::in_stalemate(bool white) {
  //Must not be in check to be in stalemate
  if (in_check(white)) {
    return false;
  }
  
  std::pair<char, char> attempted_position;
  std::pair<char, char> start;
  
  //For every piece in play
  for (char i = 'A'; i < 'I'; i++) {
    for (char j = '1'; j < '9'; j++) {
      start.first = i;
      start.second = j;

      //If there is a piece there
      if (board(start) != nullptr) {
	//If it is the color's turn
	if (board(start)->is_white() == white) {
	  //Make every possible move
	  for (char i = 'A'; i < 'I'; i++) {
	    for (char j = '1'; j < '9'; j++) {
	      attempted_position.first = i;
	      attempted_position.second = j;
	      
	      //Save ascii values in case move needs to be undone   
	      char startchar = '-';
	      char endchar = '-';
	      startchar = board(start)->to_ascii();   
	      if(board(attempted_position)){
		endchar = board(attempted_position)->to_ascii();
	      }
	      
	      //If the move is possible
	      if (make_move(start, attempted_position)) {	
		//undo the move and the turn change
		is_white_turn = !is_white_turn;
		if (endchar != '-') {
		  board.dele(attempted_position);
		  board.add_piece(start, startchar);
		  board.add_piece(attempted_position, endchar);
		}
		else {
		  board.dele(attempted_position);
		  board.add_piece(start, startchar);
		}

		//Not in stalemate
		return false;
	      }		    
	    }
	  }
	}
      }
    }
  }

  return true;

}

/////////////////////////////////////
// DO NOT MODIFY THIS FUNCTION!!!! //
/////////////////////////////////////
std::ostream& operator<< (std::ostream& os, const Chess& chess) {
	// Write the board out and then either the character 'w' or the character 'b',
	// depending on whose turn it is 
	return os << chess.get_board() << (chess.turn_white() ? 'w' : 'b');
}

std::istream& operator>> (std::istream& is, Chess& chess) {
  char piece_designator;
  char turn;

  //Clear the board to make room for new setup
  chess.board.clear_board();

  // For every location on the board
  for (char i = '8'; i > '0'; i--){
    for (char j = 'A'; j < 'I'; j++){
      std::pair<char, char> position;
      position.first = j;
      position.second = i;
      is >> piece_designator;

      //Add the piece designated by input file to the board
      chess.board.add_piece(position, piece_designator);	
    }
  }

  //final character in input file designates player turn
  is >> turn;
  if (turn == 'w'){
    chess.is_white_turn = true;
  }
  else {
    chess.is_white_turn = false;
  }
  return is;
}
