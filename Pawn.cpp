#include <iostream>
#include <string>
#include "Pawn.h"
#include "ChessBoard.h"

using namespace std;

Pawn::Pawn(string _pos, string _colour, ChessBoard *_cb)  : Piece(_pos, _colour, _cb)
{
  type = "Pawn";
}

vector <string> Pawn::checkMoves()
{
  // white pawns move up, black moves down
  int move;
  if (colour == "White")
    move = 1;
  else
    move = -1;

  //clear list of legal moves from previous moves
  movelist.clear();
  string tempPos = position;

  //if it's the pawn's first move, can move 2 places
  if (firstMove)
  {
    for (int i = 0; i < 2; i++)
    {
      tempPos[1] += move;
      Piece *square = cb->returnSquare(tempPos);
      //can only move if there is no piece in the destination square
      if (onBoard(tempPos) && square == NULL)
	movelist.push_back(tempPos);
      else
	break;
    }
  }

  else 
  {
    tempPos[1] += move;
    Piece *square = cb->returnSquare(tempPos);
    if (onBoard(tempPos) && square == NULL)
      movelist.push_back(tempPos);
  }

  //check diagonals for pieces, and if there are, add to list of legal moves
  tempPos = position;
  tempPos[0]--;
  tempPos[1] += move;
  Piece *square = cb->returnSquare(tempPos);
  if (onBoard(tempPos) && square != NULL && square->getColour() != colour)
    movelist.push_back(tempPos);

  tempPos[0] += 2;
  square = cb->returnSquare(tempPos);
  if (onBoard(tempPos) && square != NULL && square->getColour() != colour)
    movelist.push_back(tempPos);

  return movelist;
}

