#include "parentSLL.h"

void createList(ListParent &L){
	first(L) = NULL;
}
adrParent alokasi(infotypeParent x){
	adrParent P = new elmParent;

    info(P) = x;
    next(P) = NULL;

    return P;
}
int selectMenu(){
	cout << "===== MENU =====" << endl;
    cout << "1. Tambah N data" << endl;
    cout << "2. Tampilkan semua data" << endl;
    cout << "3. Cari genre" << endl;
    cout << "4. Hapus genre" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu: ";

    int input = 0;
    cin >> input;

    return input;
}

void insertFirst(ListParent &L, adrParent P){
	adrParent Q;

    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertLast(ListParent &L, adrParent P){
	adrParent Q = first(L);

    if (first(L)==NULL){
        first(L)=P;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}
//void insertAfter(ListParent &L, adrParent Prec, adrParent P){
//
//}
void tambahNData(ListParent &L){
	adrParent p;
    int j = 0;
    infotypeParent genre;

    cout << "Jumlah data yang akan ditambahkan: ";
    cin >> j;

    for (int i = 0; i < j; i++){
        cout << "[" << i + 1 << "]" << endl;
        cout << "Masukkan data: " << endl;

        cout << "Nama genre: ";
        cin >> genre.namaGenre;
        genre.jumlahLagu = 0;
        genre.totalPutaran = 0;
        p = alokasi(genre);
        insertLast(L, p);
    }
}

void deleteFirst(ListParent &L, adrParent &P){
	P = first(L);
    if (next(first(L)) == NULL) {
        first(L) = NULL;
    } else {
        first(L) = next(first(L));
    }
    next(P) = NULL;
}
void deleteLast(ListParent &L, adrParent &P){
	if (next(first(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
    } else {
        adrParent q = first(L);
        while (next(next(q)) != NULL){
            q = next(q);
        }
        P=next(q);
        next(q)= NULL;
    }
}
void deleteAfter(ListParent &L, adrParent Prec, adrParent &P){
	if (next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    } else {
        cout << "data tidak valid" << endl;
    }
}
void deleteGenre(ListParent &L){
	adrParent p = NULL;
    adrParent q = first(L);
    infotypeParent genre;

    cout << "Masukkan genre yang ingin di hapus: ";
    cin >> genre.namaGenre;
    p = findElm(L, genre);

    if (p == first(L)) {
        deleteFirst(L, p);
    } else if (next(p) == NULL) {
        deleteLast(L, p);
    } else {
        while (next(q) != p) {
            q = next(q);
        }
        deleteAfter(L, q, p);
    }
}

adrParent findElm(ListParent L, infotypeParent x){
	bool ada = false;

    adrParent p = first(L);
    adrParent q = NULL;

    while (p != NULL && !ada){
        if (info(p).namaGenre == x.namaGenre){
            q = p;
            ada = true;
        }
        p = next(p);
    }
    return q;
}
void printInfo(ListParent L){
	adrParent P = first(L);
    int i = 1;

    if (first(L) != NULL){
        while (P != NULL){
            cout << "[" << i++ << "]" << endl;
            cout << "Genre: " << info(P).namaGenre << endl;
            cout << "Jumlah lagu: " << info(P).jumlahLagu << endl;
            cout << "Total putaran: " << info(P).totalPutaran << endl;
            P = next(P);
        }
        cout << endl;
    }else{
        cout << "List Kosong!" << endl;
    }
}
