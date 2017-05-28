#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>

using namespace std;

class ChessBoard;
class Piece
{
protected:
  string position;
  string colour;
  string type;
  ChessBoard *cb; //pointer to chessboard the piece is on
  vector <string> movelist; //list of legal moves
  bool firstMove; //bool to see whether it's the first time piece has moved (only used for pawns)
  
public:
  Piece(string _pos, string  _colour, ChessBoard *_cb);
  virtual ~Piece() {}
  virtual vector <string> checkMoves() =0; //construct list of legal moves
  virtual bool onBoard(string pos) const; //check whether position is on the board or not
  virtual string getColour() const; //return colour of piece
  virtual string getType() const; //return type of piece
  virtual string getPosition() const; //return position of piece
  virtual void setPosition(string newPos); //set position of piece to newPos
  virtual void notFirstMove(); //set first move to false

};

#endif
