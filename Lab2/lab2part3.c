#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000


void readInput(int arr[], int *nPtr); // You can use same from Part I

void printNumbers(const int arr[], int n); // You can use same from Part I


void countSmallerArray(const int arr[], int n, int csmallerArr[])
{
	printf("\n");
	int count = 0;
	int i, j;
	for(i = 0; i < n; i++){
		for(j = i + 1 ; j < n ; j++){
			if(arr[i] > arr[j])
				count++;
		}
		csmallerArr[i] = count;
		count = 0;
	}
}

int main() {
        int arr[SIZE];
        int n;
        int csmallerArr[SIZE];
        readInput(arr, &n);
        printNumbers(arr, n);
		countSmallerArray(arr, n, csmallerArr);
		printf("Count Smaller ");
		printNumbers(csmallerArr, n);

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
