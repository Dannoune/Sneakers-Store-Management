#include <stdio.h>
#include "sneakers.h"

// Add a pair of sneakers
void addSneaker(Sneaker* sneaker) {
    system("cls");
    printf("\n\t\t\t======= Add a pair of sneakers =======\n");

    printf("\t\tName -> ");
    scanf_s("\t\t %[^\n]", sneaker->name, sizeof(sneaker->name));

    printf("\t\tDescription -> ");
    scanf_s("\t\t %[^\n]", sneaker->description, sizeof(sneaker->description));

    printf("\t\tYear -> ");
    scanf_s("\t\t%d", &sneaker->year);

    printf("\t\tPrice -> ");
    scanf_s("\t\t%f", &sneaker->price);
    printf("\n");
    printf("\n");
    printf("\t\t\t| Pair of sneakers added successfully ;) |\n");
    printf("\n");
    printf("\n");
}

// Display the sneakers array
void displaySneakers(Sneaker* sneaker) {
    //char searchName[MAX_NAME_LENGTH];
    FILE* file;
    if (fopen_s(&file, "sneakers.txt", "r") != 0) {
        printf("\n\t\t\t=======| /!\ Unable to open the file./!\ |=======\n");
        return;
    }

    printf("\n\t\t\t=======| Sneakers Array |=======\n");
    char line[200];
    printf("\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("\t\t | %s", line);
        for (int i = 0; i < 4; i++) {
            fgets(line, sizeof(line), file);
            printf("\t\t | %s", line);
        }
        //printf("================================\n");
    }

    fclose(file);
}

// Search sneakers by name
void searchSneakersByName() {
    char searchName[MAX_NAME_LENGTH];
    printf("\n\t\t\t=======| search for pairs |=======\n");
    printf("\n");
    printf("\n");
    printf("\t\tEnter the name of the sneakers to search: ");
    scanf_s("\t\t %s", searchName, sizeof(searchName));

    FILE* file;
    if (fopen_s(&file, "sneakers.txt", "r") != 0) {
        printf("\n\t\t\t=======| /!\ Unable to open the file./!\ |=======\n");
        return;
    }

    printf("\n\t\t\t=======| Sneakers Search Results |=======\n");
    char line[200];
    printf("\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, searchName) != NULL) {
            printf("\t\t | %s", line);
            for (int i = 0; i < 4; i++) {
                fgets(line, sizeof(line), file);
                printf("\t\t | %s", line);
            }
            //printf("================================\n");
        }
    }

    fclose(file);
}

