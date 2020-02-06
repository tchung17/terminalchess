//Kelvin Chen kchen90
//Timothy Chung tchung17
//Alexander Palacios apalaci4

#include <utility>
#include "Rook.h"
using std::pair;

bool Rook::legal_move_shape(pair<char, char> start, pair<char, char> end) const {
  int rise = end.second - start.second;
  int run = end.first - start.first;
  
  if (rise != 0 && run != 0){ //diagonal movement, illegal. 
      return false;
  }

  else if (rise == 0 && run == 0){ //no movement, illegal
    return false;
  }
  return true;

}
