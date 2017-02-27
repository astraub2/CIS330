/*
 * reversi.h
 *
 *  Created on: Feb 7, 2017
 *      Author: Amber
 */
#ifndef REVERSI_H_
#define REVERSI_H_

enum color {X,O,N};
enum valid {T,F};

class Tile {
   public:
		Tile();
		enum color _color;
		enum valid _valid;
};

class Board{
public:
	Board(int size);
	void display();
	void reversivalid(enum color turn);
	void reversiupdate(enum color turn);
	void flip(int i, int j, enum color turn);
	bool checkforvalid();
	void clearvalid();
	void displayresults();
	~Board();
private:
	int _size;
	Tile **_tiles;

};

#endif /* REVERSI_H_ */




