//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <utility>
#include <cmath>
#include "King.h"
#include <cstdlib>

using std::pair;
using std::abs;

bool King::legal_move_shape(pair<char, char> start, pair<char, char> end) const {
  //pair.first = column letter
  //pair.second = row number
  
  //King can move one space left or right
  if ((start.second == end.second) && (abs(start.first - end.first) == 1)) {
    return true;
  }
  //King can move one space up or down                                  
  else if ((start.first == end.first) && (abs(start.second - end.second) == 1)) {
    return true;
  }
    
  /* Can move one space diagonally
  difference between start and end column position must equal one
  and difference between start and end row position must equal one
  */
  else if ((abs(start.first - end.first) == 1) && (abs(start.second - end.second) == 1)) {
    return true;
  }
  else {
    return false;
  }
}
