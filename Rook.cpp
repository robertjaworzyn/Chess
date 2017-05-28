#include <iostream>
#include <string>
#include "Rook.h"
#include "ChessBoard.h"

using namespace std;

Rook::Rook(string _pos, string _colour, ChessBoard *_cb)  : Piece(_pos, _colour, _cb)
{
  type = "Rook";
}

vector <string> Rook::checkMoves()
{
  //clear movelist from previous moves
  string tempPos(position);
  movelist.clear();
  
  while (onBoard(tempPos))
  {
    //test all moves to the right until end of board, add to list if there is an opposite colour
    //piece in the way and then break, if piece is the same colour break before adding to list
    tempPos[0]++;
    Piece *square = cb->returnSquare(tempPos);
    if (onBoard(tempPos) && square == NULL)
      movelist.push_back(tempPos);

    if (onBoard(tempPos) && square != NULL)
    {
      if (square->getColour() != colour)
      {
	movelist.push_back(tempPos);
	break;
      }
      break;
    }
  }

  //reset temp position, 
  tempPos = position;

  //test all squares upwards until end of board, or a piece is hit
  while (onBoard(tempPos))
  {
    tempPos[1]++;
    Piece *square = cb->returnSquare(tempPos);
    if (onBoard(tempPos) && square == NULL)
      movelist.push_back(tempPos);

    if (onBoard(tempPos) && square != NULL) 
    {
      if (square->getColour() != colour)
      {
	movelist.push_back(tempPos);
	break;
      }
      break;
    }
  }

  //reset test position
  tempPos = position;

  //test all moves to the left until end of board, or a piece is hit
  while (onBoard(tempPos))
  {
    tempPos[0]--;
    Piece *square = cb->returnSquare(tempPos);
    if (onBoard(tempPos) && square == NULL)
      movelist.push_back(tempPos);

    if (onBoard(tempPos) && square != NULL)
    {
      if (square->getColour() != colour)
      {
	movelist.push_back(tempPos);
	break;
      }
      break;
    }
  }

  //reset test position
  tempPos = position;
  
  //test all squares downwards till end of board, or a piece is hit
  while (onBoard(tempPos))
  {
    tempPos[1]--;
    Piece *square = cb->returnSquare(tempPos);
    if (onBoard(tempPos) && square == NULL)
      movelist.push_back(tempPos);

    if (onBoard(tempPos) && square != NULL)
    {
      if (square->getColour() != colour)
      {
	  movelist.push_back(tempPos);
	  break;
      }
      break;
    }
  }
  
  return movelist;
}

