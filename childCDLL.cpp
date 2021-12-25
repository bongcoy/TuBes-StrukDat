#include "childCDLL.h"

void createList(ListChild &L){
	first(L) = NULL;
}
adrChild newElmChild(infotypeChild infoChild){
	adrChild P = new elmChild;

    info(P) = infoChild;
    next(P) = NULL;
    prev(P) = NULL;

    infoChild.jumlahPutar = 0;

    return P;
}
void insertFirst(ListChild &L, adrChild P){
	if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
        prev(P) = first(L);
	}else{
		prev(P) = prev(first(L));
		next(prev(first(L))) = P;

		next(P) = first(L);
		prev(first(L)) = P;
	}
}
void insertAfter(ListChild &L, adrChild Prec, adrChild P){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(P)) = P;
    next(Prec) = P;
}
void insertLast(ListChild &L, adrChild P){
    insertAfter(L,prev(first(L)),P);
}
void deleteFirst(ListChild &L, adrChild &P){
    if (next(first(L)) == first(L)){
        P = first(L);

        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }else{
        P = first(L);
        next(prev(first(L))) = next(first(L));
        prev(next(first(L))) = prev(first(L));
        first(L) = next(first(L));

        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter(ListChild &L, adrChild Prec, adrChild &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;

    next(P) = NULL;
    prev(P) = NULL;
}

void deleteLast(ListChild &L, adrChild &P){
    deleteAfter(L,prev(first(L)),P);
}

adrChild findElm(ListChild L, infotypeChild x){
    adrChild P = first(L);

    while ((next(P) != first(L)) && (info(P).judul != x.judul)){
        P = next(P);
    }

    if (P != NULL){
        return P;
    }else{
        return NULL;
    }
}

void printInfo(ListChild L){
    adrChild P = first(L);
    int i = 1;

    do {
        cout << "Lagu [" << i << "]" << endl;
        cout << "Judul lagu : " << info(P).judul << endl;
        cout << "Penyanyi : " << info(P).penyanyi << endl;
        cout << "Album : " << info(P).album << endl;
        cout << "Jumlah putar : " << info(P).jumlahPutar << endl;
        cout << "Genre : " << info(P).genre << endl;
        i++;
        P = next(P);

    }while (P != first(L));

    cout << endl;
}
