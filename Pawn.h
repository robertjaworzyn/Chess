#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

using namespace std;

class Pawn : public Piece
{
public:
  Pawn(string _pos, string _colour, ChessBoard *_cb);
  virtual vector <string> checkMoves();
};

#endif
