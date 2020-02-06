CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

chess: King.o Queen.o Rook.o Knight.o Bishop.o Pawn.o Board.o Chess.o main.o CreatePiece.o
	$(CC) -o chess King.o Queen.o Rook.o Knight.o Bishop.o Pawn.o Board.o Chess.o main.o CreatePiece.o

test_piece: CreatePiece.o King.o Queen.o Rook.o Knight.o Bishop.o Pawn.o test_piece.o
	$(CC) -o test_piece CreatePiece.o King.o Queen.o Rook.o Knight.o Bishop.o Pawn.o test_piece.o

test_piece.o: test_piece.cpp Piece.h King.h Queen.h Knight.h Bishop.h Rook.h Pawn.h CreatePiece.h
	$(CC) $(CFLAGS) -c test_piece.cpp

King.o: King.cpp King.h Piece.h
	$(CC) $(CFLAGS) -c King.cpp

Queen.o: Queen.cpp Queen.h Piece.h
	$(CC) $(CFLAGS) -c Queen.cpp

Rook.o: Rook.cpp Rook.h Piece.h
	$(CC) $(CFLAGS) -c Rook.cpp

Knight.o: Knight.cpp Knight.h Piece.h
	$(CC) $(CFLAGS) -c Knight.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h
	$(CC) $(CFLAGS) -c Bishop.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h
	$(CC) $(CFLAGS) -c Pawn.cpp

Board.o: Board.cpp Board.h CreatePiece.h
	$(CC) $(CFLAGS) -c Board.cpp

Chess.o: Chess.cpp Chess.h
	$(CC) $(CFLAGS) -c Chess.cpp

main.o: main.cpp Chess.h
	$(CC) $(CFLAGS) -c main.cpp

CreatePiece.o: CreatePiece.cpp CreatePiece.h Pawn.h Rook.h Knight.h Bishop.h Queen.h King.h Mystery.h
	$(CC) $(CFLAGS) -c CreatePiece.cpp

clean:
	rm -f *.o chess test_piece
