#include <stdio.h>
#include <math.h>
#include "power.h"

int power(double a, double b){

	double calc=pow(a,b);
	printf("%d",calc);
	return calc;

}

int main(){
	double x=2;
	double y=3;
	power(x,y);

}