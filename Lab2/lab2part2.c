#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); // You can use same from Part I

void printNumbers(const int arr[], int n); // You can use same from Part I

void findMeanVar(const int arr[], int n, double *meanPtr, double *varPtr)
{
	printf("\n");
	int index = 0;
	double sum = 0;
	
	while(index < n){

		sum += arr[index];
		index++;
	}
	
	*meanPtr = sum / n;
	
	index = 0, sum = 0;
	
	while(index < n){
		sum += pow(arr[index] - *meanPtr, 2);
		index++;
	}
	
	*varPtr = sum / n;	
}

int main() {
        int arr[SIZE];
        int n;
        double mean, var;

        readInput(arr, &n);
        printNumbers(arr, n);
		findMeanVar(arr, n, &mean, &var);
		printf("Mean of all elements = %.2lf\n", mean);
		printf("Variance of all elements = %.2lf\n", var);

        return 0;
}

void readInput(int arr[], int *nPtr){
	
	int count = 0, num, temp;
	
	printf("Enter the number of elements:\n");
	scanf("%d", &temp);
	
	printf("Enter %d elements:\n", temp);
	do{
		scanf("%d", &num);
		arr[count] = num;
		count++;
	}while(count < temp);
	
	*nPtr = temp;
}

void printNumbers(const int arr[], int n){
	
	int index = 0;
	printf("Array elements:");
	
	while(index < n){
		printf(" %d", arr[index]);
		index++;
	}
			
}
