#include <stdio.h>
#include <math.h>

#define MAX_SHAPES 50

/* type definitions come here */
typedef struct{
    double x, y;
}point_t;

typedef struct{
    point_t center;
    double radius, perimeter, area;
}circle_t;

/* function prototypes*/
int scanShape(FILE *filep, circle_t *objp);
int loadCircles(circle_t shapes[]);
void printShape(const circle_t *objp);
void shortestDistance(circle_t *objp, point_t p);

int main()
{
    circle_t shapes[MAX_SHAPES];
    int numOfShapes = loadCircles(shapes);

    printf("\nCircles:\n");
    for (int i = 0; i < numOfShapes; i++) {
        printf("Circle %d: ", i+1);
        printShape(&shapes[i]);
    }

    point_t temp_point;
    printf("\nEnter the point coordinate: ");
    scanf("%lf %lf",&temp_point.x,&temp_point.y);
    printf("Shortest distances are:\n");
    for (int i = 0; i < numOfShapes; i++) {
        printf("Circle %d: ", i+1);
        shortestDistance(&shapes[i],temp_point);
    }

    return 0;
}

int scanShape(FILE *filep, circle_t *objp) {

    char shape_data [30];

    if(fscanf(filep, "%s ", shape_data) !=EOF){

        fscanf(filep, "%lf%lf%lf", &objp->center.x, &objp->center.y, &objp->radius);
        objp->radius /= 2;
        return 1;
    }
    else{
        return 0;
    }

}

int loadCircles(circle_t shapes[]) {

    char filename[30];
    int count = 0;

    printf("Enter the file name to read: ");
    scanf("%s", filename);

    FILE *myFile = fopen(filename, "r");

    printf("Opening %s\n", filename);

    while (scanShape(myFile, &shapes[count]) != 0) {
        count++;
    }

    printf("Loading complete.\n");

    fclose(myFile);
    printf("Closing %s.\n", filename);

    return count;
}

void printShape(const circle_t *objp) {
    double pi = 3.14159265358979323846;
    double x_coordinate = objp->center.x;
    double y_coordinate = objp->center.y;
    double radius = objp->radius;
    double perimeter = 2 * pi * objp->radius;
    double area = pi * pow(objp->radius, 2);

    printf("<%.2lf %.2lf> <%.2lf> <%.2lf> <%.2lf>\n", x_coordinate, y_coordinate, radius, perimeter, area);
}

void shortestDistance(circle_t *objp, point_t p){

    double x_1 = p.x;
    double h = objp->center.x;
    double y_1 = p.y;
    double k = objp->center.y;
    double r = objp->radius;

    double result = sqrt(pow(x_1 - h, 2) + pow(y_1 - k, 2)) - r;
    printf("%.2lf\n", result);

}
