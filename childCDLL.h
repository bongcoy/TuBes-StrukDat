#ifndef CHILDCDLL_H_INCLUDED
#define CHILDCDLL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

struct lagu {
    string judul;
    string penyanyi;
    string album;
    int jumlahPutar;
    string genre;
};

typedef lagu infotypeChild;
typedef struct elmChild *adrChild;

struct elmChild{
    infotypeChild info;
    adrChild next;
    adrChild prev;
};

struct ListChild{
    adrChild first;
};

// Pre condition
void createListChild(ListChild &L); //sama
adrChild newElmChild(infotypeChild infoChild); //sama

// Insert
void insertFirstChild(ListChild &L, adrChild P);
void insertAfterChild(ListChild &L, adrChild Prec, adrChild P); //sama
void insertLastChild(ListChild &L, adrChild P);

// Delete
void deleteFirstChild(ListChild &L, adrChild &P);
void deleteAfterChild(ListChild &L, adrChild Prec, adrChild &P); //sama
void deleteLastChild(ListChild &L, adrChild &P);

// Find & Show
adrChild findElmChild(ListChild L, string x);
void printInfoChild(ListChild L);

#endif // CHILDCDLL_H_INCLUDED
