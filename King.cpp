#include <iostream>
#include <string>
#include "King.h"
#include "ChessBoard.h"

using namespace std;

King::King(string _pos, string _colour, ChessBoard *_cb)  : Piece(_pos, _colour, _cb)
{
  type = "King";
}

vector <string> King::checkMoves()
{
  //clear movelist from previous moves
  movelist.clear();
  string tempPos;

  //check the 8 squares surrounding the king, add to movelist if square if free or if
  //it has a piece of opposite colour
  for (char file = position[0] -1; file <= position[0] + 1; file++)
  {
    for (char rank = position[1] -1; rank <= position[1] + 1; rank++)
    {
      tempPos += file;
      tempPos += rank;
      
      if (onBoard(tempPos) && tempPos != position)
      {
	Piece *square = cb->returnSquare(tempPos);
	if (square == NULL)
	  movelist.push_back(tempPos);

	else
	{
	  if (square->getColour() != colour)
	    movelist.push_back(tempPos);
	}
      }
      tempPos = "";
    }
  }
  
  return movelist;
}
