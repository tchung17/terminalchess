#include <utility>
#include <cassert>
#include <iostream>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"
#include "CreatePiece.h"

using std::pair;

int main() {
  pair<char, char> start;
  pair<char, char> end;
  bool legal;
  Piece* k = create_piece('k');
  Piece* B = create_piece('B');
  Piece* p = create_piece('p');
  Piece* P = create_piece('P');
  Piece* Q = create_piece('Q');
  Piece* r = create_piece('r');
  Piece* N = create_piece('N');

  //tests if pieces can move 1 space diagonally (A1->B2)
  start.first='A';
  start.second='1';
  end.first='B';
  end.second='2';
  legal = B->legal_move_shape(start, end);
  assert(legal);
  legal = k->legal_move_shape(start, end);
  assert(legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //A1->B2 capture legality test
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(legal);
  legal = B->legal_capture_shape(start, end);
  assert(legal);
  legal = k->legal_capture_shape(start, end);
  assert(legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 1 space diagonally (C3->B2)
  start.first='C';
  start.second='3';
  end.first='B';
  end.second='2';
  legal = B->legal_move_shape(start, end);
  assert(legal);
  legal = k->legal_move_shape(start, end);
  assert(legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = P->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //C3->B2 capture legality test
  legal = p->legal_capture_shape(start, end);
  assert(legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = B->legal_capture_shape(start, end);
  assert(legal);
  legal = k->legal_capture_shape(start, end);
  assert(legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 6 spaces diagonally (G1->A7)
  start.first = 'G';
  start.second = '1';
  end.first = 'A';
  end.second = '7';
  legal = B->legal_move_shape(start, end);
  assert(legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //G1->A7 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 1 space vertically down (C5->C4)
  start.first = 'C';
  start.second = '5';
  end.first = 'C';
  end.second = '4';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(legal);
  legal = p->legal_move_shape(start, end);
  assert(legal);
  legal = P->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //C5->C4 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 1 space vertically up (C4->C5)
  start.first = 'C';
  start.second = '4';
  end.first = 'C';
  end.second = '5';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = P->legal_move_shape(start, end);
  assert(legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //C4->C5 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 3 spaces vertically up (G2->G5)
  start.first = 'G';
  start.second = '2';
  end.first = 'G';
  end.second = '5';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //G2->G5 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);
  
  //tests if pieces can move 1 space horizontally (D6->C6)
  start.first = 'D';
  start.second = '6';
  end.first = 'C';
  end.second = '6';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = P->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //D6->C6 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 5 spaces horizontally (A8->F8)
  start.first = 'A';
  start.second = '8';
  end.first = 'F';
  end.second = '8';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = P->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(legal);
  legal = r->legal_move_shape(start, end);
  assert(legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //A8->F8 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(legal);
  legal = r->legal_capture_shape(start, end);
  assert(legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 2 spaces horizontally and 1 space vertically (H2->F1)
  start.first = 'H';
  start.second = '2';
  end.first = 'F';
  end.second = '1';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(!legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(legal);
  //H2->F1 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(!legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(legal);

  //tests if pieces can move 2 spaces vertically and 1 space horizontally (A1->B3)
  start.first = 'A';
  start.second = '1';
  end.first = 'B';
  end.second = '3';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(!legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(legal);
  //A1->B3 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(!legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(legal);

  //tests if pieces can move 4 spaces horizontally and 2 spaces vertically (A8->E6)
  start.first = 'A';
  start.second = '8';
  end.first = 'E';
  end.second = '6';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(!legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //A8->E6 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(!legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if pieces can move 0 spaces (D5->D5)
  start.first = 'D';
  start.second = '5';
  end.first = 'D';
  end.second = '5';
  legal = B->legal_move_shape(start, end);
  assert(!legal);
  legal = k->legal_move_shape(start, end);
  assert(!legal);
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = Q->legal_move_shape(start, end);
  assert(!legal);
  legal = r->legal_move_shape(start, end);
  assert(!legal);
  legal = N->legal_move_shape(start, end);
  assert(!legal);
  //D5->D5 capture legality test
  legal = B->legal_capture_shape(start, end);
  assert(!legal);
  legal = k->legal_capture_shape(start, end);
  assert(!legal);
  legal = p->legal_capture_shape(start, end);
  assert(!legal);
  legal = P->legal_capture_shape(start, end);
  assert(!legal);
  legal = Q->legal_capture_shape(start, end);
  assert(!legal);
  legal = r->legal_capture_shape(start, end);
  assert(!legal);
  legal = N->legal_capture_shape(start, end);
  assert(!legal);

  //tests if unmoved pawns can advance 2 spaces
  start.first = 'B';
  start.second = '2';
  end.first = 'B';
  end.second = '4';
  legal = p->legal_move_shape(start, end);
  assert(!legal);
  legal = P->legal_move_shape(start, end);
  assert(legal);
  start.first = 'C';
  start.second = '7';
  end.first = 'C';
  end.second = '5';
  legal = p->legal_move_shape(start, end);
  assert(legal);
  legal = P->legal_move_shape(start, end);
  assert(!legal);
  
  std::cout << "All tests successful!" << std::endl;
  return 0;
}
