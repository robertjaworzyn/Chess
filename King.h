#ifndef KING_H
#define KING_H
#include "Piece.h"

using namespace std;

class King : public Piece
{
public:
  King(string _pos, string _colour, ChessBoard *_cb);
  virtual vector <string> checkMoves();
};

#endif
