#include <stdio.h>

int takePow(int numArg, int dArg, int returnVal)
{
	if(dArg == 0)
		return returnVal;
		
    return numArg * takePow(numArg, dArg-1, returnVal);
}

int main()
{
    int num;
    int d;
    int p;

    printf("Enter number> ");
    scanf("%d", &num);
    printf("Enter divisor> ");
    scanf("%d", &d);
    int ans = takePow(num, d,1);
    printf("%d Power of: %d is %d",d, num,ans);
    return 0;
}
