//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <utility>
#include <cmath>
#include "Queen.h"
#include <cstdlib>

using std::pair;
using std::abs;

bool Queen::legal_move_shape(pair<char, char> start, pair<char, char> end) const {
  //Values for checking diagonal movement
  int rise = end.second - start.second;
  int run = end.first - start.first;

  //No movement is illegal
  if (rise == 0 && run == 0) {
    return false;
  }
  
  //Queen can move as far as it wants in either direction horizontally
  if ((start.second == end.second) && (start.first != end.first)) {
    return true;
  }
  //Queen can move as far as it wants up or down
  else if ((start.first == end.first) && (start.second != end.second)) {
    return true;
  }
  //Can move as far as it wants diagonally
  //rise must equal run or be the opposite of run
  else if (abs(rise) == abs(run)) {
    return true;
  }
  else {
    return false;
  }
}
