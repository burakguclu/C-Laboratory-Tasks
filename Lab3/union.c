#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 20
#define MAX_ELEM 10

void findUnion(char *group1[], char *group2[], int n1, int n2, char *unionSet[], int *unionCountPtr)
{
	int i, j, k, count, num = 0;
	
	for(i = 0; i < n1; i++){
		unionSet[i] = group1[i];
		num++;
	}
	
	for(j = 0; j < n2; j++){
		count = 0;
		for(k = 0; k < n1; k++){
			if(strcmp(group2[j], group1[k]) == 0){
				count++;
			}
		}
		if(count == 0){
			unionSet[i] = group2[j];
			num++;
			i++;
		}
	}
	
	*unionCountPtr = num;

}

void printCarInfo(char *unionSet[], int unionCount)
{
	int i,j;
	
    for (i = 0; i < unionCount; i++){
    	
		char tempSet[STR_LEN];
		
		strcpy(tempSet, unionSet[i]);
		  	
    	for(j = 0; j < STR_LEN; j++){
    		tempSet[j] = toupper(tempSet[j]);
		}
    	
        printf("%s ", strtok(tempSet, "_"));
        printf("%s ", strtok(NULL, "_"));
        printf("%d", (2023-atoi(strtok(NULL, "_"))));
        printf("\n");
	}
}

int main()
{
    char list[MAX_ELEM][STR_LEN] = {"", "citroen_250_2010", "honda_200_2005",
    "mercedes_300_2020", "nissan_190_2014", "peugeot_210_2000",
    "opel_210_2011", "volkswagen_200_2003", "suzuki_240_2022", "bmw_260_2021"};

    char *group1[MAX_ELEM];
    int n1;

    char *group2[MAX_ELEM];
    int n2;

    int i;
    int ind;

    printf("Number of elements in car group1: ");
    scanf("%d", &n1);
    printf("Entries in car group1: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &ind);
        group1[i] = list[ind];
    }

    printf("\nNumber of elements in car group2: ");
    scanf("%d",&n2);
    printf("Entries in car group2: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &ind);
        group2[i] = list[ind];
    }

    char *unionSet[2*MAX_ELEM];
    int unionCount;

    findUnion(group1, group2, n1, n2, unionSet, &unionCount);

    printf("\ngroup1:\n");
    for (i = 0; i < n1; i++)
    {
        printf("%s\n",group1[i]);
    }

    printf("\ngroup2:\n");
    for (i = 0; i < n2; i++)
    {
        printf("%s\n",group2[i]);
    }

    printf("\nunion of group1 and group2:\n");
    for (i = 0; i < unionCount; i++)
    {
        printf("%s\n",unionSet[i]);
    }

    printf("\nDo you want to print the union set in NAME, max speed and age format (1/0)? ");
    int response;

    scanf("%d", &response);

    if (response == 1)
    {
        printf("\nunion of group1 and group2 in NAME, max speed and age format:\n");
        printCarInfo(unionSet, unionCount);

        printf("\nunion of group1 and group2:\n");
        for (i = 0; i < unionCount; i++)
        {
            printf("%s\n",unionSet[i]);
        }
    }

    return 0;
}
