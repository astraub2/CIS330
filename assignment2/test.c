//implement the main function, which should include the 
//triangle.h header file and call the print5Triangle() function.
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
#include "triangle1.c"
#include "triangle2.c"



int main(){
	printf("Problem 1 (a triangle of height 5)\n");

	print5Triangle();
	//now do the triangle 2
	int c;
	int x;
	do{
	printf("Problem 2, enter a value between 1 and 5\n");
	c=getc(stdin);
	x=c-'0';
	//printf("%d", x);
	}while(x<0 || x>5);


	//int x=c-'0';
	//printf("You entered:  %d\n", x);

	const int z=x;
	


	int **triangle;

	allocateNumberTriangle(z, &triangle);
	initializeNumberTriangle(z, triangle);
	printNumberTriangle(z, triangle);
	deallocateNumberTriangle(z, &triangle);



}
