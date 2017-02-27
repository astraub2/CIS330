#include <stdio.h>
#include "reversi.h"
#include <stdlib.h>

Board ** reversibuild(Board **board, int size){

	board=(Board **) malloc ((size+1)*sizeof(Board *));

	for(int i=0; i<size+1; i++){
	 	board[i]=(Board *) malloc ( (size+1)*sizeof(Board));
	 	}
	for(int i=0; i<size+1; i++){
		for(int j=0; j<size+1; j++){
			Board y;
			y=(Board){.Valid=F, .Color=N};
			//char x=Board.Color;
			board[i][j]=y;
		}
	}
	board[size/2][size/2]=(Board){.Valid=F, .Color=O};
	board[size/2-1][size/2]=(Board){.Valid=F, .Color=X};
	board[size/2][size/2-1]=(Board){.Valid=F, .Color=X};
	board[size/2-1][size/2-1]=(Board){.Valid=F, .Color=O};



	return board;

}
Board ** displayboard(Board **board, int size){
	printf("  ");
	for(int i=0; i<size; i++){
		printf(" %d", i);
	}
	printf("\n");
	for(int i=0; i<size; i++){
		printf(" %d", i);
		for(int j=0; j<size; j++){
			Board y;
			y=board[i][j];
			char c=y.Color;
			char v=y.Valid;
			if(c==N && v!=T)
				printf(" -");
			else if (v==T && c==N)
				printf(" *");	
			else
				printf(" %d", c);

		}
		printf("\n");


}
}
Board ** reversivalid(int turn, Board **board, int size){

	int opponent;
	if(turn==0)
		opponent=1;
	else
		opponent=0;
	//board[2][2].Valid=T;

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			Board y;
			y=board[i][j];
			char c=y.Color;
			char v=y.Valid;
			if(c==turn){
				//down
				if((i+1)<size){
					Board down=board[i+1][j];
					char c=down.Color;
					char v=down.Valid;
					//printf("%c", c);
					if(c==opponent){
						//iterate to find next blank
						int counter=2;
						
						for(counter; (i+counter)<size; counter++){
							//printf("%d %d", i+counter, size);
							Board downturn=board[i+counter][j];
							char downc=downturn.Color;
							char downv=downturn.Valid;
							if(downc==2){

								board[i+counter][j].Valid=T;
								board[i+(counter-1)][j].Valid=T;
								break;
							}
							board[i+counter][j].Valid=T;
							
						}

					
				}
				}

			

				if(i>0){
					//up
					Board up=board[i-1][j];
					char c=up.Color;
					char v=up.Valid;
					if(c==opponent){

						int counter=2;
						
						for(counter; (i-counter)>=0; counter++){
							
							Board downturn=board[i-counter][j];
							char downc=downturn.Color;
							char downv=downturn.Valid;
							if(downc=2){
								//printf("working\n%d %d",i,j);
								board[i-counter][j].Valid=T;
								board[i-(counter)+1][j].Valid=T;
								break;
							}
							board[i-counter][j].Valid=T;
							
						}

					
					}
				 }

				if(j+1<size){

					//right
					Board right=board[i][j+1];
					char c=right.Color;
					char v=right.Valid;
					if(c==opponent){

						int counter=2;

						for(counter; (j+counter)<size; counter++){
							Board rightturn=board[i][j+counter];
							char rightc=rightturn.Color;
							char rightv=rightturn.Valid;
							if(rightc==2){
								board[i][j+counter].Valid=T;
								board[i][j+(counter-1)].Valid=T;
								break;
							}
							board[i][j+counter].Valid=T;
					}
					}
				}

				if(j>0){
					//left
					Board left=board[i][j-1];
					char c=left.Color;
					char v=left.Valid;
					//printf("working%d %d\n",i,j);
					if(c==opponent){
						//printf("working%d %d\n",i,j);
						int counter=2;
							for(counter; (j-counter)>=0; counter++){
							//printf("working\n%d %d",i,j);
							Board leftturn=board[i][j-counter];
							char leftc=leftturn.Color;
							char leftv=leftturn.Valid;
							if(leftc=2){
								//printf("working\n%d %d",i,j);
								board[i][j-counter].Valid=T;
								board[i][j-(counter)+1].Valid=T;
								break;
							}
							board[i][j-counter].Valid=T;
							
						}
					}
				}

		}
	}
	}
	return board;
}

Board ** reversiupdate(Board **board, int size, int turn){
	printf("Enter the x and y coordinated of your move\n");
	int x;
	int y;
	scanf("%d",&x);
	fflush(stdout);	
	scanf("%d",&y);
	fflush(stdout);
	Board b=board[x][y];
	char v=b.Valid;
	if(v==1){
		printf("Not a valid move\n");
		reversiupdate(board, size, turn);
	}
	Board q=(Board){.Valid=F, .Color=turn};
	board[x][y]=q;
	board=flip(board, x, y, size, turn);

	return board;
}
Board ** flip(Board **board, int i, int j, int size, int turn){
	int opponent;
	if(turn==0)
		opponent=1;
	else
		opponent=0;
			Board y;
			y=board[i][j];
			char c=y.Color;
			char v=y.Valid;
			if(c==turn){
				//down
				if((i+1)<size){
					Board down=board[i+1][j];
					char c=down.Color;
					char v=down.Valid;
					//printf("%c", c);
					if(c==opponent){
						//iterate to find next blank
						int counter=2;
						
						for(counter; (i+counter)<size; counter++){
							//printf("%d %d", i+counter, size);
							Board downturn=board[i+counter][j];
							char downc=downturn.Color;
							char downv=downturn.Valid;
							if(downc==turn){
								board[i+counter][j].Color=turn;
								board[i+(counter-1)][j].Color=turn;
								break;
							}
							board[i+counter][j].Color=turn;
							
						}

					
				}
				}

			

				if(i>0){
					//up
					Board up=board[i-1][j];
					char c=up.Color;
					char v=up.Valid;
					if(c==opponent){

						int counter=2;
						
						for(counter; (i-counter)>=0; counter++){
							
							Board upturn=board[i-counter][j];
							char upc=upturn.Color;
							char upv=upturn.Valid;
							if(upc==turn){
								board[i-counter][j].Color=turn;
								board[i-(counter)+1][j].Color=turn;
								break;
							}
							board[i-counter][j].Color=turn;
							
						}

					
					}
				 }

				if(j+1<size){
					Board right=board[i][j+1];
					char c=right.Color;
					char v=right.Valid;
					if(c==opponent){

						int counter=2;

						for(counter; (j+counter)<size; counter++){
							Board rightturn=board[i][j+counter];
							char rightc=rightturn.Color;
							char rightv=rightturn.Valid;
							if(rightc==turn){
								board[i][j+counter].Color=turn;
								board[i][j+(counter-1)].Color=turn;
								break;
							}
							board[i][j+counter].Color=turn;
					}
					}
				}

				if(j>0){
					Board left=board[i][j-1];
					char c=left.Color;
					char v=left.Valid;
					if(c==opponent){
						int counter=2;
							for(counter; (j-counter)>=0; counter++){
							
							Board leftturn=board[i][j-counter];
							char leftc=leftturn.Color;
							char leftv=leftturn.Valid;
							if(leftc==turn){
								board[i][j-counter].Color=turn;
								board[i][j-(counter)+1].Color=turn;
								break;
							}
							board[i][j-counter].Color=turn;
							
						}
					}
				}

		
	
	}

	return board;
}


 int checkforvalid(Board **board, int size){
	int count=0;
	for(int i=0; i<size+1; i++){
		for(int j=0; j<size+1; j++){
		
			Board y=board[i][j];
			char v=y.Valid;
			if(v=0)
				count+=1;
		}
	}
	if(count>0)
		return 1;
	return 0;
}

Board ** clearvalid(Board **board, int size){
	for(int i=0; i<size+1; i++){
		for(int j=0; j<size+1; j++){
			
			board[i][j].Valid=F;
		}
}
	return board;
}




int  main(){

printf("Enter even board dimentions (between 8 and 20)\n");
int size;
scanf("%d",&size);	
fflush(stdout);
if(size<3 || size>20){
		printf("Not a valid size\n");
		main();
	}

//int size=8;
Board **board;

board=reversibuild(board, size);

int turn=0;
int finish=0;
int count=0;
while(count<5){
	board=reversivalid(turn, board, size);
	displayboard(board, size);
	finish=checkforvalid(board, size);
	if(finish!=1){
		printf("Player %d ", turn);
		board=reversiupdate(board, size, turn);
		board=clearvalid(board, size);

		if(turn==0)
			turn=1;
		else
			turn=0;
	count+=1;
	}
}
}



