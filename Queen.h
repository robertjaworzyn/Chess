#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

using namespace std;

class Queen : public Piece
{
public:
  Queen(string _pos, string _colour, ChessBoard *_cb);
  virtual vector <string> checkMoves();
};

#endif
