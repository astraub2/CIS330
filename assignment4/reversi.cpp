/*
 * reversi.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: Amber
 */
#include "reversi.h"
#include <iostream>
using namespace std;

Tile::Tile(){
	_color=N;
	_valid=F;
}

Board::Board(int size){
	_size=size;
	_tiles= new Tile*[size];
	for(int i=0; i<size; i++){
		_tiles[i]= new Tile[size];
	}
	_tiles[size/2][size/2]._color=O;
	_tiles[size/2-1][size/2]._color=X;
	_tiles[size/2][size/2-1]._color=X;
	_tiles[size/2-1][size/2-1]._color=O;

}
Board::~Board()
{
	cout <<" Inside ~Board" << endl;
	if(_tiles!=NULL)
	{
	//delete [] _tiles[0];
	for(int i = 0; i < _size ; ++i)
	{
		//cout << " " << _tiles[i];
	    delete [] _tiles[i];
	}
	delete [] _tiles;
	}
}

void Board::display(){
	cout <<"  ";
		for(int i=0; i<_size; i++){
			cout << " " << i;
		}
		cout << "\n";

		for(int i=0; i<_size; i++){
			cout << " " << i;
			for(int j=0; j<_size; j++){
				Tile y=_tiles[i][j];
				char c=y._color;
				char v=y._valid;
				if(c==N && v!=T)
					cout << " -";
				else if (v==T && c==N)
					cout << " *";
				else if (c==X)
					cout << " X";
				else if (c==O)
					cout<<" O";

			}
			cout << "\n";
		}
		cout << "\n"<< endl;
}
void Board::reversivalid(enum color turn){
	enum color opponent;
		if(turn==X)
			opponent=O;
		else
			opponent=X;
		for(int i=0; i<_size; i++){
				for(int j=0; j<_size; j++){
					Tile y=_tiles[i][j];
					char c=y._color;
					//char v=y._valid;
					if(c==turn){
						//down
						if((i+1)<_size){
							Tile down=_tiles[i+1][j];
							char c=down._color;
							//char v=down._valid;
							//printf("%c", c);
							if(c==opponent){
								//iterate to find next blank
								int counter=2;

								for(counter; (i+counter)<_size; counter++){
									//printf("%d %d", i+counter, size);
									Tile downturn=_tiles[i+counter][j];
									char downc=downturn._color;
									//char downv=downturn._valid;
									if(downc==turn)
										break;
									if(downc==N){

										_tiles[i+counter][j]._valid=T;
										_tiles[i+(counter-1)][j]._valid=T;
										break;
									}
									else if(downc==opponent){
										_tiles[i+counter][j]._valid=T;
										_tiles[i+(counter-1)][j]._valid=T;
									}

								}


						}
						}
						if((i-1)>=0){
							//up
							Tile up=_tiles[i-1][j];
							char c=up._color;
							//char v=up._valid;
							if(c==opponent){
								int counter=2;
								for(counter; (i-counter)>=0; counter++){
									Tile upturn=_tiles[i-counter][j];
									char upc=upturn._color;
									//char downv=downturn._valid;
									if(upc==turn)
										break;
									if(upc==N){
										//printf("working\n%d %d",i,j);
										_tiles[i-counter][j]._valid=T;
										_tiles[i-(counter)+1][j]._valid=T;
										break;
									}
									else if((upc==opponent)){
										_tiles[i-counter][j]._valid=T;
										_tiles[i-(counter)+1][j]._valid=T;
									}

								}


							}
						 }

						if(j+1<_size){

							//right
							Tile right=_tiles[i][j+1];
							char c=right._color;
							//char v=right._valid;
							if(c==opponent){

								int counter=2;

								for(counter; (j+counter)<_size; counter++){
									Tile rightturn=_tiles[i][j+counter];
									char rightc=rightturn._color;
									//char rightv=rightturn._valid;
									if(rightc==turn)
										break;
									if(rightc==2){
										_tiles[i][j+counter]._valid=T;
										_tiles[i][j+(counter-1)]._valid=T;
										break;
									}
									else if(rightc==opponent){
										_tiles[i][j+counter]._valid=T;
										_tiles[i][j+(counter-1)]._valid=T;
									}
							}
							}
						}

						if(j>0){
							//left
							Tile left=_tiles[i][j-1];
							char c=left._color;
							//char v=left._valid;
							//printf("working%d %d\n",i,j);
							if(c==opponent){
								//printf("working%d %d\n",i,j);
								int counter=2;
									for(counter; (j-counter)>=0; counter++){
									//printf("working\n%d %d",i,j);
									Tile leftturn=_tiles[i][j-counter];
									char leftc=leftturn._color;
									//char leftv=leftturn._valid;
									if(leftc==turn)
										break;
									if(leftc==N){
										//printf("working\n%d %d",i,j);
										_tiles[i][j-counter]._valid=T;
										_tiles[i][j-(counter)+1]._valid=T;
										break;
									}
									else if(leftc==opponent){
									_tiles[i][j-counter]._valid=T;
									_tiles[i][j-(counter)+1]._valid=T;
									}

								}
							}
						}
						if(j>0 && i>0){
						//left left
						Tile leftleft=_tiles[i-1][j-1];
						char c=leftleft._color;
						//char v=left._valid;
						//printf("working%d %d\n",i,j);
						if(c==opponent){
							//printf("working%d %d\n",i,j);
							int counter=2;
								for(counter; (j-counter)>=0; counter++){
								//printf("working\n%d %d",i,j);
								Tile leftleftturn=_tiles[i-counter][j-counter];
								char leftleftc=leftleftturn._color;
								//char leftv=leftturn._valid;
								if(leftleftc==turn)
									break;
								if(leftleftc==N){
									//printf("working\n%d %d",i,j);
									_tiles[i-counter][j-counter]._valid=T;
									_tiles[i-(counter)+1][j-(counter)+1]._valid=T;
									break;
								}
								else if(leftleftc==opponent){
									_tiles[i-counter][j-counter]._valid=T;
									_tiles[i-(counter)+1][j-(counter)+1]._valid=T;
								}

							}
						}

					}
					if(i+1<_size && j>0){
						//left right
						Tile leftright=_tiles[i+1][j-1];
						char c=leftright._color;
						//char v=left._valid;
						//printf("working%d %d\n",i,j);
						if(c==opponent){
							//printf("working%d %d\n",i,j);
							int counter=2;
								for(counter; (j-counter)>=0; counter++){
								//printf("working\n%d %d",i,j);
								Tile leftrightturn=_tiles[i+counter][j-counter];
								char leftrightc=leftrightturn._color;
								//char leftv=leftturn._valid;
								if(leftrightc==turn)
									break;
								if(leftrightc==N){
									//printf("working\n%d %d",i,j);
									_tiles[i+counter][j-counter]._valid=T;
									_tiles[i+(counter-1)][j-(counter)+1]._valid=T;
									break;
								}
								else if(leftrightc==opponent){
									_tiles[i+counter][j-counter]._valid=T;
									_tiles[i+(counter-1)][j-(counter)+1]._valid=T;
								}

							}
						}

					}
					if(i>0 && j+1<_size){
					//right left
					Tile rightleft=_tiles[i-1][j+1];
					char c=rightleft._color;
					//char v=left._valid;
					//printf("working%d %d\n",i,j);
					if(c==opponent){
						//printf("working%d %d\n",i,j);
						int counter=2;
							for(counter; (j-counter)>=0; counter++){
							//printf("working\n%d %d",i,j);
							Tile rightleftturn=_tiles[i-counter][j+counter];
							char rightleftc=rightleftturn._color;
							//char leftv=leftturn._valid;
							if(rightleftc==turn)
								break;
							if(rightleftc==N){
								//printf("working\n%d %d",i,j);
								_tiles[i-counter][j+counter]._valid=T;
								_tiles[i-(counter)+1][j+(counter-1)]._valid=T;
								break;
							}
							else if(rightleftc==opponent){
								_tiles[i-counter][j+counter]._valid=T;
								_tiles[i-(counter)+1][j+(counter-1)]._valid=T;
							}

						}
					}

				}

						if((j+1)<_size && (i+1)<_size){
							//right right
							Tile rightright=_tiles[i+1][j+1];
							char c=rightright._color;
							if(c==opponent){
								int counter=2;
									for(counter; (j-counter)<=_size; counter++){
									Tile rightrightturn=_tiles[i+counter][j+counter];
									char rightrightc=rightrightturn._color;
									if(rightrightc==turn)
										break;
									if(rightrightc==N){
										//printf("working\n%d %d",i,j);
										_tiles[i+counter][j+counter]._valid=T;
										_tiles[i+(counter)-1][j-(counter)+1]._valid=T;
										break;
									}
									else if(rightrightc==opponent){
										_tiles[i+counter][j+counter]._valid=T;
										_tiles[i+(counter-1)][j+(counter-1)]._valid=T;
									}

								}
							}
						}


				}
			}
			}

}
void Board::reversiupdate(enum color turn){
		cout << "Enter the x and y coordinated of your move\n" << endl;
		int x;
		int y;
		cin >> x;
		cin >> y;

		Tile b=_tiles[x][y];
		char v=b._valid;
		char c=b._color;
		if(v==1 || c!=N){
			cout <<"Not a valid move\n" << endl;
			reversiupdate(turn);
		}
		else{
		//cout << "hit"<< endl;
		Tile q=Tile();
		q._color=turn;
		_tiles[x][y]=q;
		flip(x, y, turn);
		}


}
void Board::flip(int i, int j, enum color turn){
	enum color opponent;
	if(turn==X)
		opponent=O;
	else
		opponent=X;
			Tile y=_tiles[i][j];
			char c=y._color;
			if(c==turn){

				if((i+1)<_size){
					Tile down=_tiles[i+1][j];
					char c=down._color;
					if(c==opponent){
						//iterate to find next blank
						int counter=2;

						for(counter; (i+counter)<_size; counter++){
							//printf("%d %d", i+counter, size);
							Tile downturn=_tiles[i+counter][j];
							char downc=downturn._color;
							char downv=downturn._valid;
							if(downc==turn){
								_tiles[i+counter][j]._color=turn;
								_tiles[i+(counter-1)][j]._color=turn;
								break;
							}
							else if (downc==opponent && downv==T){
								_tiles[i+counter][j]._color=turn;
								_tiles[i+(counter-1)][j]._color=turn;
						}}
				}
				}
				if(i>0){
					//up
					Tile up=_tiles[i-1][j];
					char c=up._color;
					//char v=up._valid;
					if(c==opponent){
						int counter=2;
						for(counter; (i-counter)>=0; counter++){
							Tile upturn=_tiles[i-counter][j];
							char upc=upturn._color;
							char upv=upturn._valid;
							if(upc==turn){
								_tiles[i-counter][j]._color=turn;
								_tiles[i-counter+1][j]._color=turn;
					
								break;
							}
							else if (upc==opponent && upv==T){

								_tiles[i-counter][j]._color=turn;
								_tiles[(i-(counter))+1][j]._color=turn;
							}
						}
					}
				 }
				if(j+1<_size){
					Tile right=_tiles[i][j+1];
					char c=right._color;
					//char v=right._valid;
					if(c==opponent){
						int counter=2;
						for(counter; (j+counter)<_size; counter++){
							Tile rightturn=_tiles[i][j+counter];
							char rightc=rightturn._color;
							char rightv=rightturn._valid;
							if(rightc==turn){
								_tiles[i][j+counter]._color=turn;
								_tiles[i][j+(counter-1)]._color=turn;
								break;
							}
							else if (rightc==opponent && rightv==T){
								_tiles[i][j+counter]._color=turn;
								_tiles[i][j+(counter-1)]._color=turn;
							}
					}
					}
				}
				if(j>0){
					Tile left=_tiles[i][j-1];
					char c=left._color;
					//char v=left._valid;
					if(c==opponent){
						int counter=2;
							for(counter; (j-counter)>0; counter++){

							Tile leftturn=_tiles[i][j-counter];
							char leftc=leftturn._color;
							char leftv=leftturn._valid;
							if(leftc==turn){
								_tiles[i][j-counter]._color=turn;
								_tiles[i][j-(counter)+1]._color=turn;
								break;
							}
							else if (leftc==opponent && leftv==T){
								_tiles[i][j-counter]._color=turn;
								_tiles[i][j-(counter)+1]._color=turn;
							}
						}
					}
				}
				if(j>0 && i>0){
				//left left
				Tile leftleft=_tiles[i-1][j-1];
				char c=leftleft._color;
				if(c==opponent){
					int counter=2;
						for(counter; (j-counter)>=0; counter++){
						Tile leftleftturn=_tiles[i-counter][j-counter];
						char leftleftc=leftleftturn._color;
						char leftleftv=leftleftturn._valid;

						if(leftleftc==turn){
							_tiles[i-counter][j-counter]._color=turn;
							_tiles[i-(counter)+1][j-(counter)+1]._color=turn;
							break;
						}
						else if(leftleftc==opponent && leftleftv==T){
							_tiles[i-counter][j-counter]._color=turn;
							_tiles[i-(counter)+1][j-(counter)+1]._color=turn;
						}

					}
				}

			}
			if(i+1<=_size && j>0){
				//left right
				Tile leftright=_tiles[i+1][j-1];
				char c=leftright._color;
				//char v=left._valid;
				//printf("working%d %d\n",i,j);
				if(c==opponent){
					//printf("working%d %d\n",i,j);
					int counter=2;
						for(counter; (j-counter)>=0; counter++){
						//printf("working\n%d %d",i,j);
						Tile leftrightturn=_tiles[i+counter][j-counter];
						char leftrightc=leftrightturn._color;
						char leftrightv=leftrightturn._valid;

						if(leftrightc==turn){
							//printf("working\n%d %d",i,j);
							_tiles[i+counter][j-counter]._color=turn;
							_tiles[i+(counter-1)][j-(counter)+1]._color=turn;
							break;
						}
						else if(leftrightc==opponent && leftrightv==T){
							_tiles[i+counter][j-counter]._color=turn;
							_tiles[i+(counter-1)][j-(counter)+1]._color=turn;
						}

					}
				}

			}
			if(i>0 && j+1<=_size){
			//right left
			Tile rightleft=_tiles[i-1][j+1];
			char c=rightleft._color;
			//char v=left._valid;
			//printf("working%d %d\n",i,j);
			if(c==opponent){
				//printf("working%d %d\n",i,j);
				int counter=2;
					for(counter; (j-counter)>=0; counter++){
					//printf("working\n%d %d",i,j);
					Tile rightleftturn=_tiles[i-counter][j+counter];
					char rightleftc=rightleftturn._color;
					char rightleftv=rightleftturn._valid;

					if(rightleftc==turn){
						//printf("working\n%d %d",i,j);
						_tiles[i-counter][j+counter]._color=turn;
						_tiles[i-(counter)+1][j+(counter-1)]._color=turn;
						break;
					}
					else if(rightleftc==opponent && rightleftv==T){
						_tiles[i-counter][j+counter]._color=turn;
						_tiles[i-(counter)+1][j+(counter-1)]._color=turn;
					}

				}
			}

		}

				if(j<_size && i<_size){
					//cout <<"right right"<< endl;
					Tile rightright=_tiles[i+1][j+1];
					char c=rightright._color;
					//char v=left._valid;
					//printf("working%d %d\n",i,j);
					if(c==opponent){
						//printf("working%d %d\n",i,j);
						int counter=2;
							for(counter; (j-counter)<=_size; counter++){
							//printf("working\n%d %d",i,j);
							Tile rightrightturn=_tiles[i+counter][j+counter];
							char rightrightc=rightrightturn._color;
							char rightrightv=rightrightturn._valid;

							if(rightrightc==turn){
								//printf("working\n%d %d",i,j);
								_tiles[i+counter][j+counter]._color=turn;
								_tiles[i+(counter)-1][j+(counter)-1]._color=turn;
								break;
							}
							else if(rightrightc==opponent && rightrightv==T){
								_tiles[i+counter][j+counter]._color=turn;
								_tiles[i+(counter)-1][j+(counter)-1]._color=turn;
							}

						}
					}
				}



	}


}
bool Board::checkforvalid(){
	int count=0;
		for(int i=0; i<_size; i++){
			for(int j=0; j<_size; j++){
				Tile y=_tiles[i][j];
				char v=y._valid;
				char c=y._color;
				if(v==T && c==N)
					count+=1;
			}
		}
		if(count>0)
			return false;
		return true;
}
void Board::clearvalid(){
	for(int i=0; i<_size; i++){
			for(int j=0; j<_size; j++){

				_tiles[i][j]._valid=F;
			}
	}

}
void Board::displayresults(){
	int x=0;
	int o=0;
	for(int i=0; i<_size; i++){
				for(int j=0; j<_size; j++){

					if(_tiles[i][j]._color==X)
						x+=1;
					else if(_tiles[i][j]._color==O)
											o+=1;

				}
		}
	if(x>o)
		cout << "PLayer 1 wins!"<<endl;
	else if(o>x)
		cout << "Player 2 wins!"<<endl;
	else
		cout << "It's a tie!"<<endl;

}





