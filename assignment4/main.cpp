/*
 * main.cpp

 *
 *  Created on: Feb 9, 2017
 *      Author: Amber
 */
#include "reversi.h"

#include <iostream>
using namespace std;
int  main(){
		cout << "  ";

	cout << "Enter even board dimensions (between 8 and 20)\n" << endl;
	int size;
	cin  >> size;

	if(size<3 || size>20){
			cout << "Not a valid size\n"<<endl;
			main();
		}
	else{

	Board game(size);
	enum color turn=X;
	bool finish=false;

	while(finish==false){
		game.reversivalid(turn);
		game.display();
		cout << "Player "<< turn+1<<endl;
		finish=game.checkforvalid();

		if(finish==false){
			game.reversiupdate(turn);
			game.clearvalid();
			if(turn==X)
				turn=O;
			else
				turn=X;
		}
	}
	game.displayresults();
	}
}



