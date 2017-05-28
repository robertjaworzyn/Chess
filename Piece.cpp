#include <iostream>
#include <string>
#include "Piece.h"

using namespace std;

Piece::Piece(string _pos, string  _colour, ChessBoard *_cb) : position(_pos), colour(_colour), cb(_cb)
{
  firstMove = true;
}

bool Piece::onBoard(string pos) const
{
  if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8')
    return false;

  return true;
}

string Piece::getColour() const
{
  return colour;
}

string Piece::getType() const
{
  return type;
}

string Piece::getPosition() const
{
  return position;
}

void Piece::setPosition(string newPos)
{
  position = newPos;
}

void Piece::notFirstMove()
{
  firstMove = false;
}
