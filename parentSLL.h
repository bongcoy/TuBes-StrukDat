#ifndef PARENTSLL_H_INCLUDED
#define PARENTSLL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define child(P) P->child

#include "childCDLL.h"

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
//    List_child child;
};

struct ListParent {
    adrParent first;
};

void createList(ListParent &L);
void insertFirst(ListParent &L, adrParent P);
void insertAfter(ListParent &L, adrParent Prec, adrParent P);
void deleteFirst(ListParent &L, adrParent &P);
void deleteAfter(ListParent &L, adrParent Prec, adrParent &P);

adrParent alokasi(infotypeParent x);
adrParent findElm(ListParent L, infotypeParent x);
void printInfo(ListParent L);

#endif // PARENTSLL_H_INCLUDED
