//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <utility>
#include "Bishop.h"

using std::pair;

bool Bishop::legal_move_shape(pair<char, char> start, pair<char, char> end) const {
  int rise = end.second - start.second;
  int run = end.first - start.first;
  
  //No movement is illegal
  if (rise == 0 && run == 0) {
    return false;
  }
  
  //The bishop can move diagonally as far as it wants
  //Rise must equal run or be the opposite of run
  if (rise == run || rise == -1 * run) {
    return true;
  }
  else {
    return false;
  }
}
