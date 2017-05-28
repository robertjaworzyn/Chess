#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <map>
#include <string>
#include "Piece.h"

using namespace std;

class ChessBoard
{
private:
  map <string, Piece *> board; //map of pieces on board
  int moveNum;
  bool checkmate;
  bool staleMate;
  bool onBoard (string pos) const; //test whether specified position is a correct input
  string oppositeColour(string Colour) const; //returns opposite colour to the one input
  string findKing(string colour) const; //find the position of the king of the colour specified
  bool inCheck(string colour); //test whether colour specified is in check
  bool stalemate(string colour); //test whether colour specified is in stalemate

  /* Note about stalemate: the definition of the stalemate function does not take into 
     account whether the piece is in check. This is so checkmate can be implemented in 
     submit_move as a combination of check and stalemate (so as to minimise reuse of code).
     However, the program will only say that stalemate has been achieved if neither player is
     in check, as required */
      
public:
  ChessBoard();
  ~ChessBoard();
  bool clearBoard(); //delete all existing piece in the board map.
  bool setBoard(); //place all pieces on the board
  bool resetBoard(); //delete and replace all pieces, reset checkmate and number of moves
  bool submitMove(string startPos, string endPos); /*sumbit a move, test for legality , check,
						     stalemate, and checkmate */
  Piece *returnSquare(string pos); //return the piece located at position pos
  
};

#endif
