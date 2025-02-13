#include <stdio.h>
#include <stdlib.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter a number:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    if (errorState==0){
        printf("Your number is: %.2f \n", fnum1);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.

	int index = 0;
	char x = 'x';
	float number = 0;
	int multiplier = 10, result = 0, count = 0;
	
	while(index < SIZE && x != EOF){
		
		x = string[index];
    	    	
		if(x <= '9' && x >= '0' && result == 0){
    		if(x == 48)
    			number += 0;
    		else if(x == 49)
    			number += 1;
    		else if(x == 50)
    			number += 2;
    		else if(x == 51)
    			number += 3;
    		else if(x == 52)
    			number += 4;
    		else if(x == 53)
    			number += 5;
    		else if(x == 54)
    			number += 6;
    		else if(x == 55)
    			number += 7;
    		else if(x == 56)
    			number += 8;
    		else if(x == 57)
    			number += 9;
			number *= multiplier;	
		}
		else if(x == '.'){
			number /= 10;
			result = 1;
		}
		else if(x <= '9' && x >= '0' && result == 1){
			if(x == 48)
    			number += 0;
    		else if(x == 49)
    			number += 0.1;
    		else if(x == 50)
    			number += 0.2;
    		else if(x == 51)
    			number += 0.3;
    		else if(x == 52)
    			number += 0.4;
    		else if(x == 53)
    			number += 0.5;
    		else if(x == 54)
    			number += 0.6;
    		else if(x == 55)
    			number += 0.7;
    		else if(x == 56)
    			number += 0.8;
    		else if(x == 57)
    			number += 0.9;
    		number *= multiplier;
    		count++;
		}
		else if(x > '9' && x != '.' && x != 0 || x < '0' && x != '.' && x != 0){
			*error = 1;
			break;
		}
		else{
			break;
		}
		index++;
	}
    
    if(result == 0)
    	return number/multiplier;
	if(result == 1){
		int k = 0;
		while(k < count){
			result *= multiplier;	
			k++;
		}
		return number/result;	
	}   
}
