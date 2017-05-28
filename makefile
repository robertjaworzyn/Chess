chess: ChessMain.o ChessBoard.o Piece.o Pawn.o Rook.o Bishop.o Queen.o King.o Knight.o 
	g++ -g -std=c++11 ChessMain.o ChessBoard.o Piece.o Pawn.o Rook.o Bishop.o Queen.o King.o Knight.o -o chess

%.o: %.cpp
	g++ -Wall -std=c++11 -g -c $<

ChessMain.o: ChessBoard.h

ChessBoard.o: ChessBoard.h Piece.h Pawn.h Rook.h Bishop.h Queen.h King.h Knight.h

Piece.o: Piece.h

Pawn.o: Pawn.h Piece.h

Rook.o: Rook.h Piece.h

Bishop.o: Bishop.h Piece.h

Queen.o: Queen.h Piece.h

King.o: King.h Piece.h

Knight.o: Knight.h Piece.h

clean:
	rm -f *.o chess

.PHONY: clean
