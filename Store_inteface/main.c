#include <stdio.h>
#include <stdlib.h>
#include "sneakers.h"

#define MAX_SNEAKERS 100

void saveSneakersToFile(const Sneaker* sneakers, int count);
//void displaySneakers(const Sneaker* sneakers, int count);
void displaySneakers();


int main() {
    int choice;
    Sneaker sneakers[MAX_SNEAKERS];
    int count = 0;

    while (1) {
        printf("\n\t\t\t=======| Sneaker Manager |=======\n");
        printf("\n"); printf("\n");
        printf("\t\t1. Add a pair of sneakers\n");
        printf("\t\t2. Save sneakers to a file\n");
        printf("\t\t3. Display the sneakers array\n");
        printf("\t\t4. Search sneakers by name\n"); 
        printf("\t\t5. Quit\n"); 
        printf("\n"); printf("\n");
        printf("\t\tChoice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            addSneaker(&sneakers[count]);
            count++;
            break;
        case 2:
            saveSneakersToFile(sneakers, count);
            break;
        case 3:
            displaySneakers(sneakers);
            break;
        case 4:
            searchSneakersByName();
            break;
        case 5:
            printf("\n\t\t\t=======|  Program terminated... (^~^) |=======\n");
            printf("\n");
            exit(0);
        default:
            printf("\n\t\t\t=======| /!\ Invalid choice. Please try again./!\ |=======\n");
            break;
        }
        printf("\n");
    }

    return 0;
}

// Save sneakers to a file
void saveSneakersToFile(const Sneaker* sneakers, int count) {
    FILE* file;
    if (fopen_s(&file, "sneakers.txt", "a") != 0) {
        printf("\n\t\t\t=======| /!\ Unable to create/open the file./!\ |=======\n");
        return;
    }

    //fprintf(file, "----- Sneakers List -----\n");
    if (count == 0) {
        fprintf(file, "No sneakers available.\n");
    }
    else {
        for (int i = 0; i < count; i++) {
            fprintf(file, "Sneaker #%d\n", i + 1);
            fprintf(file, "Name: %s\n", sneakers[i].name);
            fprintf(file, "Description: %s\n", sneakers[i].description);
            fprintf(file, "Year: %d\n", sneakers[i].year);
            fprintf(file, "Price: %.2f euro\n", sneakers[i].price);
            fprintf(file, "-------------------------------------\n");
        }
    }

    fclose(file);
    printf("The sneakers have been saved to the 'sneakers.txt' file.\n");
}
