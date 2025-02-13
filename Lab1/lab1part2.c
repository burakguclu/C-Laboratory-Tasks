#include <stdio.h>
#include <math.h>

void isInCircle(int *result, double *centerX, double *centerY)
{
	int x_circle, y_circle, radius;
    scanf("%d%d%d", &x_circle, &y_circle, &radius);
 
 	int x, y, sumx = 0, sumy = 0, points = 0;
	
	while(scanf("%d%d", &x, &y) != EOF){
    	sumx += x;
    	sumy += y;
    	points++;
	};
    
    *centerX = sumx / points;
    *centerY = sumy / points;
    
    double distance = pow(*centerX-x_circle,2) + pow(*centerY-y_circle,2);
    
    if(distance < pow(radius,2)) *result = 1;
    if(distance == pow(radius,2)) *result = 0;
    if(distance > pow(radius,2)) *result = -1;
}

int main()
{
    int result;
    double centerX, centerY;

    isInCircle(&result, &centerX, &centerY);

    if (result == 1)
        printf("center of points is inside circle, centerX: %.1f , centerY: %.1f",centerX,centerY );
    else if (result == 0)
        printf("center of points is on circle, centerX: %.1f , centerY: %.1f",centerX,centerY );
    else
        printf("center of points is outside circle, centerX: %.1f , centerY: %.1f",centerX,centerY);
    return 0;
}
