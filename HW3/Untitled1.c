#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[30];
    char surname[30];
    double duration;
}student;

int loadData(student students[]);
int scanStudent(FILE *filep, student *objp, int count);
int checkForDuplicate(student students[], student temp_students[], int length);
int allocate_surname(student *students, int length);
void sortTheList(student students[], int length);
void printStudent(const student *objp);

int main(){

    int count = 0;
    char answer[5];
    student students[500], temp_students[500], results_students[500];
    int numOfStudents = loadData(students);
    int checking = checkForDuplicate(students, temp_students, numOfStudents);

    printf("\nSort the results? (yes/no): ");
	scanf("%s", answer);

    for (int i = 1; i < numOfStudents; i++) {
            if(temp_students[i].duration == 0){
                continue;
            }
        results_students[count] = temp_students[i];
        count++;
    }

	 if(strcmp(answer, "yes") == 0){
        sortTheList(results_students, count);
    }

    for(int j = 0; j < count; j++){
        printStudent(&results_students[j]);
    }

}

int loadData(student students[]) {

    char filename[30];
    int count = 0;

    printf("Enter the input file name: ");
    scanf("%s", filename);

    FILE *txtFile = fopen(filename, "r");

    while (scanStudent(txtFile, &students[count], count) != 0) {
        count++;
    }

    fclose(txtFile);

    return count;
}

int scanStudent(FILE *filep, student *objp, int count) {

    char student_data [500], temp_string [500], student_name[100];
    double temp_duration = 0;

    if(fscanf(filep, "%s", student_data) != EOF){

        fgets(student_data, 500, filep);

        if(count != 0){

        strcpy(temp_string, student_data);

        strtok(temp_string, ",");
        strtok(NULL, ",");

        char temp_ptr[20];

        strcpy(temp_ptr, strtok(NULL, ","));

        temp_duration = atof(temp_ptr);

        strcpy(student_name, strtok(NULL, ","));

        strcpy(objp->name, student_name);
        objp->duration = temp_duration;

        }

        return 1;
    }
    else{
        return 0;
    }

}

int checkForDuplicate(student students[], student temp_students[], int length){

    student temp_student[length];

    for(int a = 1; a < length; a++){

        strcpy(temp_student[a].name, students[a].name);
        temp_student[a].duration = students[a].duration;

            for(int i=0; temp_student[a].name[i]!='\0'; i++){
                 if(temp_student[a].name[i]>='a' && temp_student[a].name[i]<='z'){
                    temp_student[a].name[i] = temp_student[a].name[i] - 32;
                 }
            }
    }

    for(int i = 1; i < length; i++){
            if(temp_student[i].duration == 0){
                continue;
            }

        for(int j = i +1; j < length; j++){

                if(strcmp(temp_student[i].name, temp_student[j].name) == 0){
                        temp_student[i].duration += temp_student[j].duration;
                        temp_student[j].duration = 0;
                }

        }

        if(temp_student[i].duration != 0){
            allocate_surname(&students[i], length);
            temp_students[i].duration = temp_student[i].duration;
            strcpy(temp_students[i].name, students[i].name);
            strcpy(temp_students[i].surname, students[i].surname);
        }
    }
    return 1;
}

int allocate_surname(student *students, int length){

    char temp_data[50], temp_name[50] = "", temp_surname[50] = "", my_temp[50] = "";
    char *temp_temp;

    strcpy(temp_data, students->name);

    strcpy(my_temp, strtok(temp_data, " "));

    strcpy(temp_surname, my_temp);

    while(my_temp != NULL){
        temp_temp = strtok(NULL, " ");
        if(temp_temp == NULL){
            break;
        }
        strcpy(my_temp, temp_temp);

        if(my_temp != NULL){
            strcat(temp_name, " ");
            strcat(temp_name, temp_surname);
            strcpy(temp_surname, my_temp);
        }
    }
        strcpy(students->name, temp_name);
        strcpy(students->surname, temp_surname);
}

void sortTheList(student students[], int length) {

    student temp_student_1, temp_student_2;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {

                temp_student_1 = students[j];
                temp_student_2 = students[j+1];

            for(int i=0; temp_student_1.name[i]!='\0'; i++){
                 if(temp_student_1.name[i]>='a' && temp_student_1.name[i]<='z'){
                    temp_student_1.name[i] = temp_student_1.name[i] - 32;
                 }
            }

            for(int i=0; temp_student_1.surname[i]!='\0'; i++){
                 if(temp_student_1.surname[i]>='a' && temp_student_1.surname[i]<='z'){
                    temp_student_1.surname[i] = temp_student_1.surname[i] - 32;
                 }
            }

            for(int i=0; temp_student_2.name[i]!='\0'; i++){
                 if(temp_student_2.name[i]>='a' && temp_student_2.name[i]<='z'){
                    temp_student_2.name[i] = temp_student_2.name[i] - 32;
                 }
            }

            for(int i=0; temp_student_2.surname[i]!='\0'; i++){
                 if(temp_student_2.surname[i]>='a' && temp_student_2.surname[i]<='z'){
                    temp_student_2.surname[i] = temp_student_2.surname[i] - 32;
                 }
            }

            if (strcmp(temp_student_1.surname, temp_student_2.surname) > 0) {
                student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
            else if(strcmp(temp_student_1.surname, temp_student_2.surname) == 0){
                            if (strcmp(temp_student_1.name, temp_student_2.name) > 0) {
                                student temp = students[j];
                                students[j] = students[j + 1];
                                students[j + 1] = temp;
                            }
            }

        }
    }
}


void printStudent(const student *objp) {
    printf("\n%s%s %.2lf", objp->surname, objp->name, objp->duration);
}
