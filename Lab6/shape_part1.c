#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SHAPES 50

/* type definitions come here */
typedef struct
{
    double x, y, z;
} point_t;

typedef struct
{
    point_t center;
    double radius;
} sphere_t;

typedef struct
{
    point_t center;
    double side;
} cube_t;

typedef struct
{
    point_t center;
    double base_side_length;
    double height;
} square_prism_t;

typedef union
{
    cube_t cube;
    square_prism_t square_prism;
    sphere_t sphere;
} shape3d_data_t;

typedef enum
{
    CUBE,SQUARE_PRISM, SPHERE
} class_t;

typedef struct
{
    class_t type;
    shape3d_data_t shape;
} shape_t;

/* function prototypes*/
int scanShape(FILE *filep, shape_t *objp);
int loadShapes(shape_t shapes[]);
void printShape(const shape_t *objp);

int main()
{
    shape_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nShapes 3D:\n");
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);

    return 0;
}

int scanShape(FILE *filep, shape_t *objp)
{
    char shape_data [500], shapename[30];

    if(fscanf(filep, "%s", shapename) != EOF)
    {
        fgets(shape_data, 500, filep);

        if(strcmp(shapename, "cube") == 0)
        {
            objp->type = CUBE;
            objp->shape.cube;

            double x_coor = atof(strtok(shape_data, " "));
            double y_coor = atof(strtok(NULL, " "));
            double z_coor = atof(strtok(NULL, " "));
            double side_length = atof(strtok(NULL, " "));

            objp->shape.cube.center.x = x_coor;
            objp->shape.cube.center.y = y_coor;
            objp->shape.cube.center.z = z_coor;
            objp->shape.cube.side = side_length;
        }
        else if(strcmp(shapename, "square_prism") == 0)
        {
            objp->type = SQUARE_PRISM;
            objp->shape.square_prism;

            double x_coor = atof(strtok(shape_data, " "));
            double y_coor = atof(strtok(NULL, " "));
            double z_coor = atof(strtok(NULL, " "));
            double b_s_length = atof(strtok(NULL, " "));
            double height = atof(strtok(NULL, " "));

            objp->shape.square_prism.center.x = x_coor;
            objp->shape.square_prism.center.y = y_coor;
            objp->shape.square_prism.center.z = z_coor;
            objp->shape.square_prism.base_side_length = b_s_length;
            objp->shape.square_prism.height = height;
        }
        else if(strcmp(shapename, "sphere") == 0)
        {
            objp->type = SPHERE;
            objp->shape.sphere;

            double x_coor = atof(strtok(shape_data, " "));
            double y_coor = atof(strtok(NULL, " "));
            double z_coor = atof(strtok(NULL, " "));
            double radius = atof(strtok(NULL, " "));

            objp->shape.sphere.center.x = x_coor;
            objp->shape.sphere.center.y = y_coor;
            objp->shape.sphere.center.z = z_coor;
            objp->shape.sphere.radius = radius;
        }

        return 1;
    }
    else
    {
        return 0;
    }

}

int loadShapes(shape_t shapes[])
{
    char filename[30];
    int count = 0;

    printf("Enter the file name to read: ");
    scanf("%s", filename);

    FILE *txtFile = fopen(filename, "r");

    printf("\nOpening %s", filename);

    while (scanShape(txtFile, &shapes[count]) != 0)
    {
        count++;
    }

    printf("\nLoading complete");
    fclose(txtFile);
    printf("\nClosing %s\n", filename);

    return count;
}

void printShape(const shape_t *objp)
{
    if(objp->type == 0)
    {
        double volume = pow(objp->shape.cube.side, 3);
        double area = 6*pow(objp->shape.cube.side, 2);
        printf("Cube: <%.2lf %.2lf %.2lf> <%.2lf> <%.2lf>\n",
               objp->shape.cube.center.x,
               objp->shape.cube.center.y,
               objp->shape.cube.center.z,
               objp->shape.cube.side,
               volume);
    }
    else if(objp->type == 1)
    {
        double volume = objp->shape.square_prism.height*pow(objp->shape.square_prism.base_side_length, 2);
        double area = 4*objp->shape.square_prism.base_side_length*objp->shape.square_prism.height;
        printf("Square_prism: <%.2lf %.2lf %.2lf> <%.2lf %.2lf> <%.2lf>\n",
               objp->shape.square_prism.center.x,
               objp->shape.square_prism.center.y,
               objp->shape.square_prism.center.z,
               objp->shape.square_prism.base_side_length,
               objp->shape.square_prism.height,
               volume);
    }
    else if(objp->type == 2)
    {
        double volume = 4*3.14159*pow(objp->shape.sphere.radius, 3)/3;
        double area = 4*3.14159*pow(objp->shape.sphere.radius, 2);
        printf("Sphere: <%.2lf %.2lf %.2lf> <%.2lf> <%.2lf>\n",
               objp->shape.sphere.center.x,
               objp->shape.sphere.center.y,
               objp->shape.sphere.center.z,
               objp->shape.sphere.radius,
               volume);
    }
}
