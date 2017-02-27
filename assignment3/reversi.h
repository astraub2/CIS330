#ifndef REVERSI_H_
#define REVERSI_H_

enum color {X,O,N};
enum valid {T,F};


typedef struct 
{
	enum color Color;
	enum valid Valid;

	
}Board;


Board ** reversibuild(Board **board, int size);

Board ** reversivalid(int turn, Board **board, int size);
Board ** reversiupdate(Board **board, int size, int turn);
int checkforvalid(Board **board, int size);
Board ** flip(Board **board, int x, int y, int size, int turn);
Board ** clearvalid(Board **board, int size);
// void chechforflips(Struct board, bool finish);

// void displayboard(Struct board);

#endif /* TRIANGLE_H_ */



