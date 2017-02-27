#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
//#include "triangle1.c"
int blankspacer(int row){
int spacer=(2*row+1);

for(int i=9; i >= spacer; i--)
	printf(" ");
}
void allocateNumberTriangle(const int height, int ***triangle){
//printf("%d", height);
int numRows=height-1;
triangle = (int ***) malloc ( numRows * sizeof(int **) );



}
/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle){
int numRows=height-1;
int row=0;
int numelem=(2*row+1);
//blankspace(row);

for(int i=0; i <= numRows; i++){
	triangle[i]=(int*) malloc(8*sizeof(int));
	}

for(int i=0; i <= numRows; i++){
	for(int i=0; i < numelem; i++){
		triangle[row][i]=i;
	}
	row=row+1;
	numelem=(2*row+1);
}
}

/* Print a formatted triangle */
void printNumberTriangle(const int height, int **triangle){
//printf("print attempt %d", height);
int numRows=height-1;
int row=0;
int numelem=(2*row+1);
//blankspace(row);
for(int i=0; i <= numRows; i++){
	blankspacer(row);
	for(int i=0; i < numelem; i++){
		printf("%d ", triangle[row][i]);
	}
	printf("\n");
	row=row+1;
	numelem=(2*row+1);
}}


/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int height, int ***triangle){
	free(**triangle);

}

