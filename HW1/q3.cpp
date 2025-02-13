#include <stdio.h>
#include <math.h>

int function(int x, int c, int d){
	return pow(x,c)+2*d;
}

int main(){
	
	int a, b, n, c, d;
	double result, h, mySum = 0;
	
	printf("Enter value of a:\n");
	scanf("%d",&a);
	
	printf("Enter value of b:\n");
	scanf("%d",&b);
	
	printf("Enter value of n:\n");
	scanf("%d",&n);
	
	printf("Enter value of c:\n");
	scanf("%d",&c);
	
	printf("Enter value of d:\n");
	scanf("%d",&d);
	
	h = (b-a)/n;
	
	for(int i = 1; i < n; i++){
		mySum = mySum + function(a+i*h, c, d);
	}
	
	result = (h/2)*(function(a,c,d) + function(b,c,d) + 2*mySum);
	
	printf("T: %0.2f", result);
	
	return 0;
}
