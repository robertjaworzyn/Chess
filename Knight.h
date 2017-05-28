#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

using namespace std;

class Knight : public Piece
{
public:
  Knight(string _pos, string _colour, ChessBoard *_cb);
  virtual vector <string> checkMoves();
};

#endif
