#include <stdio.h>

int main(){
		
	char filename[9];
	int point = 0, count = 1, k;
	char a, b;
	
	printf("Enter txt file name:\n");
	scanf("%s", filename);
	
	FILE *file_traversal;
	file_traversal = fopen(filename,"r");
	
	FILE *temp_traversal;
	temp_traversal = fopen(filename,"r");
	
	while((b = fgetc(temp_traversal)) != EOF) {
   		if(b == '\n')
			count++;
	}
		
	printf("There are %d teams in total.\n", count);
	
	for(int i = 0; i < count; i++) {
		
		fscanf(file_traversal, "%d", &k);
		
		a = fgetc(file_traversal);
		a = fgetc(file_traversal);
		
    	while(a <= 'Z' && a >= 'A'){
    		if(a == 'W')
    			point = point + 3;
    		else if(a == 'D')
    			point = point + 1;
    		a = fgetc(file_traversal);
		}
		
		printf("Team %d: %d\n", k, point);
		
		point = 0;

    }
			
	return 0;
}
