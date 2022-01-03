#include "childCDLL.h"

void createListChild(ListChild &L){
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
void insertFirstChild(ListChild &L, adrChild P){
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
void insertAfterChild(ListChild &L, adrChild Prec, adrChild P){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(P)) = P;
    next(Prec) = P;
}
void insertLastChild(ListChild &L, adrChild P){
    if (first(L) == NULL){
        insertFirstChild(L,P);
    }else{
        insertAfterChild(L,prev(first(L)),P);
    }
}
void addMusicGenre(adrChild &P, arrGenre x){
    // karena ga bisa langsung inisialisasi, jadi pake fungsi ini
    int i = 0;
    while (info(P).genre[i] != ""){
        info(P).genre[i] = x[i];
        i++;
    }
}

void deleteFirstChild(ListChild &L, adrChild &P){
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

void deleteAfterChild(ListChild &L, adrChild Prec, adrChild &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;

    next(P) = NULL;
    prev(P) = NULL;
}

void deleteLastChild(ListChild &L, adrChild &P){
    deleteAfterChild(L,prev(prev(first(L))),P);
}
void deleteLagu(ListChild &L, adrChild &C){
    // Kurang lebih sama dengan void deleteGenre() pada parent
    adrChild D = first(L);

    if (C == NULL){
        cout << "Lagu tidak ditemukan" << endl;
    }else{
        if (C == first(L)) {
            deleteFirstChild(L, C);
        } else if (next(C) == first(L)) {
            deleteLastChild(L, C);
        } else {
            while (next(D) != C) {
                D = next(D);
            }
            deleteAfterChild(L, D, C);
        }
    }

}

adrChild findElmChild(ListChild L, string x){
    adrChild P = first(L);

    while ((next(P) != first(L)) && (info(P).judul != x)){
        P = next(P);
    }

    if (P != NULL){
        return P;
    }else{
        return NULL;
    }
}

void printInfoChild(ListChild L){
    adrChild P = first(L);
    int i = 1;

    if (P != NULL){
        do {
            cout << "Lagu [" << i << "]" << endl;
            cout << "Judul lagu : " << info(P).judul << endl;
            cout << "Penyanyi : " << info(P).penyanyi << endl;
            cout << "Album : " << info(P).album << endl;
            cout << "Jumlah putar : " << info(P).jumlahPutar << endl;
            cout << "Genre : ";
            printMusicGenre(info(P));
            cout << endl;

            i++;
            P = next(P);

        }while (P != first(L));
    }else{
        cout << "TIDAK ADA LAGU PADA GENRE INI." << endl;
    }

    cout << endl;
}
void printMusicGenre(infotypeChild musik){
    int i = 0;
    while (i < NMAX){
        cout << musik.genre[i] << " ";
        i++;
    }
}
