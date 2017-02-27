//implement the print5Triangle function. In the function, declare a static 2-D array of 
//integers and initialize its contents to be 
//as shown in the example output below (for Problem 1), then print them to standard output.
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

int blankspace(int row){
int spacer=(2*row+1);

for(int i=9; i >= spacer; i--)
	printf(" ");
}
void print5Triangle(){
printf("Problem 1 (a triangle of height 5)\n");

int numRows=4;
int row=0;
int numelem=(2*row+1);

int a[5][9];
for(int i=0; i <= numRows; i++){
	blankspace(row);
	for(int i=0; i < numelem; i++){

		a[row][i]=i;
		printf("%d ", a[row][i]);

	}
	//printf("%d", row);
	printf("\n");
	row=row+1;
	numelem=(2*row+1);


}

}

