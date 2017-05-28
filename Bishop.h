#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

using namespace std;

class Bishop : public Piece
{
public:
  Bishop(string _pos, string _colour, ChessBoard *_cb);
  virtual vector <string> checkMoves();
};

#endif
