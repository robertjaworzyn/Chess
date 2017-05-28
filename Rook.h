#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

using namespace std;

class Rook : public Piece
{
public:
  Rook(string _pos, string  _colour, ChessBoard *_cb);
  virtual vector <string> checkMoves();
};

#endif
