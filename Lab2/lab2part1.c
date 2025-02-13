#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr);
void printNumbers(const int arr[], int n);

int main(){
	
	int arr[SIZE];
    int n;
    
    readInput(arr, &n);
    printNumbers(arr, n);
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
