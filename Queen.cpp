#include <iostream>
#include <string>
#include "Queen.h"
#include "ChessBoard.h"

using namespace std;

Queen::Queen(string _pos, string _colour, ChessBoard *_cb)  : Piece(_pos, _colour, _cb)
{
  type = "Queen";
}

vector <string> Queen::checkMoves()
{
  string temp_pos(position);
  movelist.clear();

  //comments on implementation in Rook.cpp
  //test up and right till end of board, or a piece is hit
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

  //test up and left till end of board, or a piece is hit
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

  //test down and right till end of board, or a piece is hit
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

  //test down and left till end of board, or a piece is hit
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

  temp_pos = position;

  //test to the right till end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
    temp_pos[0]++;
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

  //test upwards till end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
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

  //test leftwards till end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
    temp_pos[0]--;
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

  //test legal moves downwards till end of board, or a piece is hit
  while (onBoard(temp_pos))
  {
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
