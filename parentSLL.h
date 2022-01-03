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
void createListParent(ListParent &L);
adrParent newElmParent(infotypeParent x);
int selectMenu();

// Insert
void insertFirstParent(ListParent &L, adrParent P);
void insertLastParent(ListParent &L, adrParent P);
void insertAfterParent(ListParent &L, adrParent Prec, adrParent P);
void tambahNParent(ListParent &L);

// Delete
void deleteFirstParent(ListParent &L, adrParent &P);
void deleteLastParent(ListParent &L, adrParent &P);
void deleteAfterParent(ListParent &L, adrParent Prec, adrParent &P);
void deleteGenre(ListParent &L);

// Find & Print
adrParent findElmParent(ListParent L, string x);
void cariGenre(ListParent L);
void printInfoParent(ListParent L);

// Child Relation
void bikinListChild(ListChild &LC);
void add1Music(ListParent &LP, ListChild LC, string genreP, string judul);
void masukkanLagu(ListParent &LP, ListChild LC);
void hitungTotalPutaran(adrParent &P);
void kosongkanGenre(ListParent &LP);

#endif // PARENTSLL_H_INCLUDED
