#ifndef PARENTSLL_H_INCLUDED
#define PARENTSLL_H_INCLUDED

#include <iostream>
using namespace std;

#include "childCDLL.h"

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define child(P) P->child

struct genre {
    string namaGenre;
    int jumlahLagu;
    int totalPutaran;
};

typedef struct genre infotypeParent;
typedef struct elmParent *adrParent;

struct elmParent {
    infotypeParent info;
    adrParent next;
    ListChild child;
};

struct ListParent {
    adrParent first;
};

// Pre Condition
void createList(ListParent &L);
adrParent alokasi(infotypeParent x);
int selectMenu();

// Insert
void insertFirst(ListParent &L, adrParent P);
void insertLast(ListParent &L, adrParent P);
//void insertAfter(ListParent &L, adrParent Prec, adrParent P);
void tambahNData(ListParent &L);

// Delete
void deleteFirst(ListParent &L, adrParent &P);
void deleteLast(ListParent &L, adrParent &P);
void deleteAfter(ListParent &L, adrParent Prec, adrParent &P);
void deleteGenre(ListParent &L);

// Find & Show
adrParent findElm(ListParent L, infotypeParent x);
void printInfo(ListParent L);

#endif // PARENTSLL_H_INCLUDED
