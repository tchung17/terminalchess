//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <utility>
#include <cmath>
#include "Knight.h"
#include <cstdlib>

using std::pair;
using std::abs;

bool Knight::legal_move_shape(pair<char, char> start, pair<char, char> end) const {
  int rise = end.second - start.second;
  int run = end.first - start.first;
  
  //The knight must move exactly 2 in the rise and 1 in the run or 2 in the
  //run and 1 in the rise.
  if (abs(rise) == 2) {
    if (abs(run) == 1) {
      return true;
    }
  } else if (abs(rise) == 1) {
    if (abs(run) == 2) {
      return true;
    }
  }
  return false;
}
