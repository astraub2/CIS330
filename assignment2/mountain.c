#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
#include "mountain.h"


void printNumberMountain(const int numPeaks, int *heights, int ***triangles){


	//max 
	int max=0;
	for(int i=0; i<=numPeaks;i++){
		if(heights[i]>max)
			max=heights[i];

	}
	int offset=0;
	for(int i=0; i<numPeaks;i++){
		//i is the little triangles(1-5 times)
		//printf("offset: %d\n", offset);
		int move=0;
		if (heights[i]!=max){
			move=max-heights[i];
		}
		//populate the rest 
		int barf=0;

		for(int row=0; row<heights[i]; row++){
		//rows in the triangle(up to 5 times each run)
			int numelem=(2*barf+1);
			int space=((9-numelem)/2)-move;
			//printf("space: %d\n", space);
			
			for(int y=0; y < numelem; y++){
				(*triangles)[row+move][y+offset+space]=y;
				//printf("!%d!", (*triangles)[row][y+offset]);
			}		
			barf+=1;
		}
		offset+=2*(heights[i])-1;
	}
		int numRows=max;

		int thestuff=8*numPeaks;

		for(int i=0; i < max; i++){
			//printf("pass\n");
			for(int j=0; j < thestuff; j++){
				if((*triangles)[i][j]>-1){
					printf("%d ", (*triangles)[i][j]);
				}
				else
					printf("  ");
				//printf("\n");
			}
			printf("\n");
		}
		free(**triangles);




}

int main(){
	int x;
	int c;
	do{
	printf("Problem 3, #of peaks (a value between 1 and 5)\n");
	c=getc(stdin);
	x=c-'0';
	//printf("%d", x);
	}while(x<0 || x>5);
	const int numPeaks=x;

	printf("Please enter the heights of the peaks [each should be between 1 and 5]:\n");
	
	int *heights;
	heights=(int*) malloc(numPeaks*sizeof(int));

	for(int i=0; i<numPeaks;i++){
		//printf("Height of peak %d", i);
		int x;
		scanf("%d", &x);
		const int y=x;
		heights[i]=y;
	}
	
	int **triangles=(int **) malloc (5*sizeof(int **));

	for(int i=0; i<6; i++){
	 	triangles[i]=(int *) malloc ( (9*numPeaks)*sizeof(int));
	 	}

	for(int i=0; i<6; i++){
		for(int j=0; j<(12*numPeaks); j++)
			triangles[i][j]=-9;
	}


	 printNumberMountain(numPeaks, heights, &triangles);


}
