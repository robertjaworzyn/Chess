#include <iostream>
#include <string>
#include "Bishop.h"
#include "ChessBoard.h"

using namespace std;

Bishop::Bishop(string _pos, string _colour, ChessBoard *_cb)  : Piece(_pos, _colour, _cb)
{
  type = "Bishop";
}

vector <string> Bishop::checkMoves()
{
  //clear movelist of legal moves from previous move
  string temp_pos(position);
  movelist.clear();

  //implementation detailed in Rook.cpp.
  //test up and to the right until end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
    temp_pos[0]++;
    temp_pos[1]++;
    Piece *square = cb->returnSquare(temp_pos);
    if (onBoard(temp_pos) && square == NULL)
      movelist.push_back(temp_pos);

    if (onBoard(temp_pos) && square != NULL)
    {
      if (square->getColour() != colour)
      {
	movelist.push_back(temp_pos);
	break;
      }
      break;
    }
  }

  temp_pos = position;

  //test all moves up and to the left until end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
    temp_pos[0]--;
    temp_pos[1]++;
    Piece *square = cb->returnSquare(temp_pos);
    if (onBoard(temp_pos) && square == NULL)
      movelist.push_back(temp_pos);

    if (onBoard(temp_pos) && square != NULL) 
    {
      if (square->getColour() != colour)
      {
	movelist.push_back(temp_pos);
	break;
      }
      break;
    }
  }

  temp_pos = position;

  //test all squares down and to the right until end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
    temp_pos[0]++;
    temp_pos[1]--;
    Piece *square = cb->returnSquare(temp_pos);
    if (onBoard(temp_pos) && square == NULL)
      movelist.push_back(temp_pos);

    if (onBoard(temp_pos) && square != NULL)
    {
      if (square->getColour() != colour)
      {
	movelist.push_back(temp_pos);
	break;
      }
      break;
    }
  }

  temp_pos = position;

  //test all squares down and to the left until end of board, or a piece is hit 
  while (onBoard(temp_pos))
  {
    temp_pos[0]--;
    temp_pos[1]--;
    Piece *square = cb->returnSquare(temp_pos);
    if (onBoard(temp_pos) && square == NULL)
      movelist.push_back(temp_pos);

    if (onBoard(temp_pos) && square != NULL)
    {
      if (square->getColour() != colour)
      {
	  movelist.push_back(temp_pos);
	  break;
      }
      break;
    }
  }
  
  return movelist;
}
