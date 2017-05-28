#include <iostream>
#include <map>
#include <string>
#include "ChessBoard.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"

using namespace std;

ChessBoard::ChessBoard()
{
  moveNum = 0;
  checkmate = staleMate = false;
  if (!setBoard())
    cerr << "Board incorrectly set" << endl;
  else 
    cout << "A new chess game is started!" << endl;
}

ChessBoard::~ChessBoard()
{
  clearBoard();
}

bool ChessBoard::clearBoard()
{
  //delete all pieces left on board
  for (auto &square : board)
  {
    if (square.second != NULL)
    {
      delete square.second;
      square.second = NULL;
    }
  }
  return true;
}
  
bool ChessBoard::setBoard()
{
  board["A1"] = new Rook("A1", "White", this);
  board["H1"] = new Rook("H1", "White", this);
  board["A8"] = new Rook("A8", "Black", this);
  board["H8"] = new Rook("H8", "Black", this);
 
  board["B1"] = new Knight("B1", "White", this);
  board["G1"] = new Knight("G1", "White", this);
  board["B8"] = new Knight("B8", "Black", this);
  board["G8"] = new Knight("G8", "Black", this);
  
  board["C1"] = new Bishop("C1", "White", this);
  board["F1"] = new Bishop("F1", "White", this);
  board["C8"] = new Bishop("C8", "Black", this);
  board["F8"] = new Bishop("F8", "Black", this);
  
  board["D1"] = new Queen("D1", "White", this);
  board["E1"] = new King("E1", "White", this);
  board["D8"] = new Queen("D8", "Black", this);
  board["E8"] = new King("E8", "Black", this);

  //set pawns
  for (int i = 0; i < 8; i++)
  {
    string position, position2;
    char pos0 = (char)(i + 'A');
    char pos1 = '2';
    position += pos0;
    position += pos1;
    board[position] = new Pawn(position, "White", this);
    pos1 = '7';
    position2 += pos0;
    position2 += pos1;
    board[position2] = new Pawn(position2, "Black", this);
  }

  //set middle of board with no pieces to NULL
  for (char pos0 = 'A'; pos0 <= 'H'; pos0++)
  {
    for (char pos1 = '3'; pos1 <= '6'; pos1++)
    {
      string position;
      position += pos0;
      position += pos1;
      board[position] = NULL;
    }
  }
  
  return true;
}

bool ChessBoard::resetBoard()
{
  moveNum = 0;
  checkmate = staleMate = false;
  clearBoard();
  setBoard();
  return true;
}

string ChessBoard::oppositeColour(string colour) const 
{
  if (colour == "White")
    return "Black";
  if (colour == "Black")
    return "White";
  
  cerr << "Input is not Black or White!" << endl;
  return "ERROR";
}

bool ChessBoard::onBoard(string pos) const
{
  if (pos[0] < 'A' || pos[0] > 'H' || pos[1] < '1' || pos[1] > '8')
    return false;

  return true;
}

bool ChessBoard::submitMove(string startPos, string endPos)
{
  //players should not be allowed to make a move if in checkmate or stalemate- game has ended
  if (checkmate || staleMate)
  {
    cerr << "The game has ended, stop trying to make moves!" << endl;
    return false;
  }

  //illegal starting position for submit move
  if (!onBoard(startPos))
  {
    cerr << "The start position you have specified is not a real chessboard position!" << endl;
    return false;
  }

  //illegal end position for submit move
  if (!onBoard(endPos))
  {
    cerr << "The end position you have specified is not a real chessboard position!" << endl;
    return false;
  }

  //no piece at specified starting position
  if (board[startPos] == NULL)
  {
    cerr << "There is no piece at position " << startPos << "!" << endl;
    return false;
  }

  /* calculate whose turn it should be, which colour piece has
     been selected and the colour of the opponent */
  string turnColour, pieceColour, opponentColour;
  if (moveNum % 2 == 0)
    turnColour = "White";
  else
    turnColour = "Black";

  opponentColour = oppositeColour(turnColour);
  pieceColour = board[startPos]->getColour();

  //check that the piece selected belongs to the player whose turn it is
  if (pieceColour != turnColour)
  {
    cerr << "It is not " << pieceColour << "'s turn to move!" << endl;  
    return false;
  }

  /* calculate list of legal moves for the piece at the source square and check
     the destination square is in it */
  vector <string> possible_moves = board[startPos]->checkMoves();
  for (unsigned int i = 0; i < possible_moves.size(); i++)
  {
    if (possible_moves[i] == endPos)
    {
      Piece *temp = NULL;
      // make the move, keeping the piece at the destination square in temp
      temp = board[endPos];
      board[endPos] = board[startPos];
      board[startPos] = NULL;

      //check if the move leaves the players king in check - if so it's illegal and is taken back
      if (inCheck(turnColour))
      {
	cerr << "That move puts your king in check- illegal!" << endl;
	board[startPos] = board[endPos];
	board[endPos] = temp;
	return false;
      }

      cout << pieceColour << "'s " << board[endPos]->getType();
      cout << " moves from " << startPos << " to " << endPos;
      
      if (temp != NULL)
      {
	cout << " taking " << temp->getColour() << "'s " << temp->getType();
	cout << endl;
      }
      else
	cout << endl;
      
      delete temp;
      temp = NULL;
      board[endPos]->setPosition(endPos);
      board[endPos]->notFirstMove();
      moveNum++;

      //check for check, stalemate, and checkmate (combination of check and stalemate) 
      bool check = inCheck(opponentColour);
      staleMate = stalemate(opponentColour);

      if (check)
      {
	if (staleMate)
        {
	  cout << opponentColour << " is in checkmate" << endl;
	  checkmate = true;
	  return true;
	}
	cout << opponentColour << " is in check" << endl;
	return true;
      }
      
      if (staleMate)
      {
	cout << opponentColour << " is in stalemate" << endl;
	staleMate = true;
      }
      
      return true;
    }
  }

  cerr << pieceColour << "'s " << board[startPos]->getType();
  cerr << " cannot move to " << endPos << "!" << endl;
  
  return false;
}

Piece *ChessBoard::returnSquare(string pos)
{
  Piece *piece;
  piece = board[pos];
  return piece;
}

string ChessBoard::findKing(string colour) const
{
  string kingPosition;
  for (auto const& square : board)
  {
    if (square.second != NULL)
    {
      if (square.second->getType() == "King" && square.second->getColour() == colour)
      {
	kingPosition = square.first;
	break;
      }
    }
  }

  return kingPosition;
}


bool ChessBoard::inCheck(string colour)
{
  string kingPosition = findKing(colour);
  for (auto const& square : board)
  {
    if (square.second != NULL && square.second->getColour() != colour)
    {
      //check every possible move by pieces of opposite colour and if the king's position is in there,
      //king is in check
      vector <string> moves = square.second->checkMoves();
      for (unsigned int i = 0; i < moves.size(); i++)
      {
	if (moves[i] == kingPosition)
	  return true;
	
      }
    }
  }
  
  return false;
}

bool ChessBoard::stalemate(string colour)
{
  for (auto const& square : board)
  {
    // look through every possible move by the colour that may be in stalemate
    if (square.second != NULL && square.second->getColour() == colour)
    {
      vector <string> moves = square.second->checkMoves();
      Piece *temp;
      for (unsigned int i = 0; i < moves.size(); i++)
      {
	//temporarily make move
	temp = NULL;
	if (board[moves[i]] != NULL)
	  temp = board[moves[i]];

	board[moves[i]] = board[square.first];
	board[square.first] = NULL;
	string kingPosition = findKing(colour);

	//if not in check, there is a legal move to make, therefore colour is not in stalemate
	if (!inCheck(colour))
	{
	  board[square.first] = board[moves[i]];
	  board[moves[i]] = temp;
	  return false;
	}

	//undo tested move
        board[square.first] = board[moves[i]];
	board[moves[i]] = temp;
      }
    }
  }
  //if no legal move, colour is in stalemate
  return true;
}
  

