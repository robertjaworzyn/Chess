#include <iostream>
#include <string>
#include <cmath>
#include "Knight.h"
#include "ChessBoard.h"

using namespace std;

Knight::Knight(string _pos, string _colour, ChessBoard *_cb)  : Piece(_pos, _colour, _cb)
{
  type = "Knight";
}

vector <string> Knight::checkMoves()
{
  //clear move list from previous move
  movelist.clear();
  string tempPos;

  //check the 8 moves a knight can make, looping through the 16 surrounding squares
  for (char file = position[0] - 2; file <= position[0] + 2; file++)
  {
    for (char rank = position[1] - 2; rank <= position[1] + 2; rank++)
    {
      tempPos += file;
      tempPos += rank;
      int ifile = abs(file - position[0]);
      int irank = abs(rank - position[1]);

      //check that destination square is 1 away in one direction and 2 away in the other  
      if (irank != ifile && irank != 0 && ifile != 0 && onBoard(tempPos))
      {
	Piece *square = cb->returnSquare(tempPos);
	if (square == NULL)
	  movelist.push_back(tempPos);
	else if (square->getColour() != colour)
	  movelist.push_back(tempPos);
      }
      tempPos = "";
    }
  }
  
  return movelist;
}
