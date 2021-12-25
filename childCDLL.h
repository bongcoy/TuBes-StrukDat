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

void createList(ListChild &L); //sama
adrChild newElmChild(infotypeChild infoChild); //sama

void insertFirst(ListChild &L, adrChild P);
void insertAfter(ListChild &L, adrChild Prec, adrChild P); //sama
void insertLast(ListChild &L, adrChild P);
void deleteFirst(ListChild &L, adrChild &P);
void deleteAfter(ListChild &L, adrChild Prec, adrChild &P); //sama
void deleteLast(ListChild &L, adrChild &P);

adrChild findElm(ListChild L, infotypeChild x);
void printInfo(ListChild L);


#endif // CHILDCDLL_H_INCLUDED
