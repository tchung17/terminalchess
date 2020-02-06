//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <utility>
#include <cmath>
#include <cstdlib>
#include "Pawn.h"
using std::pair;

bool Pawn::legal_move_shape(pair<char, char> start, pair<char, char> end) const {
  int rise = end.second - start.second;
  int run = end.first - start.first;
  
  if (rise != 0 && run != 0) { //diagonal movement, illegal.
    return false;
  }

  if (rise == 0 && run == 0){ //no movement, illegal. 
    return false;
  }
  if (is_white()){ //white piece
    if (start.second == '1' + 1){
      if (run != 0 || (rise != 1 && rise != 2)){ //double movement allowed only in start position
	return false;
      }
    }
    else {
      if(run != 0 || rise != 1) {
	return false;
      }
    }
  }
  else if(!is_white()) { //black piece
    if (start.second == '1' + 6){
      if (run != 0 || (rise != -1 && rise != -2)){ //double movement allowed only in start position
	return false;
      }
    }
    else {
      if (run != 0 || rise != -1){ //backwards movement is illegal
	return false;
      }
    }
  }
  return true;
}

bool Pawn::legal_capture_shape(pair<char, char> start, pair<char, char> end) const {
  int rise = end.second - start.second;
  int run = end.first - start.first;
  if (is_white()) { //white piece
    if (rise == 1 && abs(run) == 1) { //diagonal capture
      return true;
    }
  }
  else { //black piece
    if (rise == -1 && abs(run) == 1) { //diagonal capture
      return true;
    }
  }
  return false;
}
