#include <stdio.h>
#include <math.h>

double calculate(int num, double b, double num2){
	
	if(num == 0)
		return 10;
	
	return calculate(num-1, b, num2)*b + num2;
}

int main(){
	
	double result;
	int min, max, a, b, c;
	
	printf("Enter value of a:\n");
	scanf("%d",&a);
	
	printf("Enter value of b:\n");
	scanf("%d",&b);
	
	printf("Enter value of c:\n");
	scanf("%d",&c);
	
	printf("Enter minimum value of x_n:\n");
	scanf("%d",&min);
	
	printf("Enter maximum value of x_n:\n");
	scanf("%d",&max);
		
	double rightpart = (-b + sqrt( b*b - 4*a*c)) / (2*a);

	int temp = min;
	
	for(int i = 0; i < max-min+1; i++){
		result = calculate(temp, b, rightpart);
		printf("\nx_%d: %0.2f", temp, result);
		temp++;
	}	
	
	return 0;
}
