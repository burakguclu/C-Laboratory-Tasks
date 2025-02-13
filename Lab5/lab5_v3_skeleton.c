#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int id; // gamer id
    char name[20]; // gamer name
    char surname[20]; // gamer surname
    char genre[20]; // genre of gamer
    int followerCount; // follower Count of the gamer
} gamer;

void showRecords(FILE *filePtr);

int modifyFollowerCount(FILE *filePtr, unsigned int id, int multiplyFollower);
int insertGamer(FILE *filePtr, unsigned int id, char name[], char surname[], char genre[], int followerCount);
int removeGamer(FILE *filePtr, unsigned int id);
int viewGenreFollows(FILE *filePtr, char genre[], int exactFollower);

int main()
{
    unsigned int id;
    int multiplyFollower;
    int status;

    char name[20];
    char surname[20];
    char genre[20];
    int followerCount;

    int count;
    int exactFollower;

    FILE *filePtr;
    filePtr = fopen("gamer.bin","rb+");
    if (filePtr == NULL)
    {
        printf("Could not open gamer.bin");
        return;
    }

    showRecords(filePtr);

    int choice;

    printf("\nWhich operation do you choose?\n");
    printf("1 : Update Follower Count\n");
    printf("2 : Add Gamer\n");
    printf("3 : Delete Gamer\n");
    printf("4 : View Genre Info with Follower\n");
    printf("> ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("\nGamer id: ");
        scanf("%d",&id);
        printf("Multiplication value for follower count: ");
        scanf("%d",&multiplyFollower);
        status = modifyFollowerCount(filePtr, id, multiplyFollower);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No gamer with id %d\n", id);
        break;
    case 2:
        printf("\nGamer id: ");
        scanf("%d",&id);
        printf("Name: ");
        scanf("%s",name);
        printf("Surname: ");
        scanf("%s",surname);
        printf("Genre: ");
        scanf("%s",genre);
        printf("Follower Count: ");
        scanf("%d",&followerCount);
        status = insertGamer(filePtr, id, name, surname, genre, followerCount);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("There is already a gamer with id %d\n", id);
        break;
    case 3:
        printf("\nGamer id: ");
        scanf("%d",&id);
        status = removeGamer(filePtr, id);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No gamer with id %d\n", id);
        break;
    case 4:
        printf("\nGenre: ");
        scanf("%s",genre);
        printf("\nExact follower count: ");
        scanf("%d",&exactFollower);
        count = viewGenreFollows(filePtr, genre, exactFollower);
        if (count == 0)
            printf("No gamer in genre %s with follower count == %d\n", genre, exactFollower);
        else
            printf("There are %d gamers in genre %s with follower count == %d\n", count, genre, exactFollower);
        break;
    }

    fclose(filePtr);
    return 0;
}

void showRecords(FILE *filePtr)
{
    fseek(filePtr, 0, SEEK_SET);

    printf("\n%-3s %-20s %-20s %-20s %s\n",
           "ID",
           "Name",
           "Surname",
           "Genre",
           "Follower Count");

    while (!feof(filePtr))
    {
        gamer g;
        int result = fread(&g, sizeof(gamer), 1, filePtr);
        if (result != 0 && g.id != 0)
        {
            printf("%-3d %-20s %-20s %-20s %d\n",
                   g.id,
                   g.name,
                   g.surname,
                   g.genre,
                   g.followerCount);
        }
    }
}

int modifyFollowerCount(FILE *filePtr, unsigned int id, int multiplyFollower)
{
    fseek(filePtr, 0, SEEK_SET);

    while (!feof(filePtr))
    {
        gamer g;
        int result = fread(&g, sizeof(gamer), 1, filePtr);
        if (result != 0 && g.id == id)
        {
            g.followerCount *= multiplyFollower;

            fseek(filePtr, -sizeof(g), SEEK_CUR);
            fwrite(&g, sizeof(g), SEEK_CUR, filePtr);

            return 1;
        }
    }
    return 0;
}

int insertGamer(FILE *filePtr, unsigned int id, char name[], char surname[], char genre[], int followerCount)
{
    fseek(filePtr, 0, SEEK_SET);

    while (!feof(filePtr))
    {
        gamer g;
        int result = fread(&g, sizeof(gamer), 1, filePtr);
        if (result != 0 && g.id == id)
        {
            return 0;
        }
    }

    gamer g;

    fseek(filePtr, 0, SEEK_SET);
    while (!feof(filePtr))
    {
        int result = fread(&g, sizeof(gamer), 1, filePtr);
        if (result != 0 && g.id != 0 && g.id > id)
        {
            break;
        }
    }

    gamer new_gamer;
    new_gamer.id = id;
    strcpy(new_gamer.name, name);
    strcpy(new_gamer.surname, surname);
    strcpy(new_gamer.genre, genre);
    new_gamer.followerCount = followerCount;

    fseek(filePtr, -sizeof(gamer), SEEK_CUR);
    fwrite(&new_gamer, sizeof(gamer), 1, filePtr);
    fwrite(&g, sizeof(gamer), 1, filePtr);

    return 1;
}

int removeGamer(FILE *filePtr, unsigned int id)
{
    fseek(filePtr, 0, SEEK_SET);

    while (!feof(filePtr))
    {
        gamer g;
        int result = fread(&g, sizeof(gamer), 1, filePtr);
        if (result != 0 && g.id == id)
        {

            fseek(filePtr, -sizeof(g), SEEK_CUR);

            gamer blank_gamer = {0, "", "", "", 0};

            fwrite(&blank_gamer, sizeof(g), SEEK_CUR, filePtr);

            return 1;
        }
    }
    return 0;
}

int viewGenreFollows(FILE *filePtr, char genre[], int exactFollower)
{
    printf("\n%-3s %-20s %-20s %-20s %s\n",
           "ID",
           "Name",
           "Surname",
           "Genre",
           "Follower Count");

    fseek(filePtr, 0, SEEK_SET);
    int num_of_gamers = 0;

    while (!feof(filePtr))
    {
        gamer g;
        int result = fread(&g, sizeof(gamer), 1, filePtr);
        if (result != 0 && g.id != 0 && strcmp(g.genre, genre) == 0 && g.followerCount == exactFollower)
        {
            num_of_gamers++;

            printf("%-3d %-20s %-20s %-20s %d\n",
                   g.id,
                   g.name,
                   g.surname,
                   g.genre,
                   g.followerCount);
        }
    }
    return num_of_gamers;
}
