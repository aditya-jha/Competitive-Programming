#include <stdio.h>
#include <math.h>
#define DEPTH 16

double xroot(double n, double x)
{    
	double xn = x;    
	int i;    
	for(i = 0; i < DEPTH; i++)        
	xn = xn - ( (pow(xn,n) - x) / (n * pow(xn, n-1)) );    
	return xn;
}

int main(int argc, char **argv)
{    
	double x = 72;    
	double root = 3.14159265;    
	printf("%f root %f = %f\n", root, x, pow(4, 1/2.0));   
 getch(); 
	return 0;
}
