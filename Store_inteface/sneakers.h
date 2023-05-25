#ifndef SNEAKERS_H
#define SNEAKERS_H

#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_SNEAKERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int year;
    float price;
} Sneaker;


void addSneaker(Sneaker* sneaker);
void displaySneakers(Sneaker* sneaker);
void displaySneakerInfo(const Sneaker* sneakers, int count);

#endif  // SNEAKERS_H
