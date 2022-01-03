#include "parentSLL.h"

void createListParent(ListParent &L){
	first(L) = NULL;
}
adrParent newElmParent(infotypeParent x){
	adrParent P = new elmParent;
	ListChild LC;

    info(P) = x;
    next(P) = NULL;
    createListChild(LC);
    child(P) = LC;

    return P;
}
int selectMenu(){
	cout << "===== MENU =====" << endl;
    cout << "1. Tambah N genre" << endl;
    cout << "2. Tampilkan Genre dan Lagu" << endl;
    cout << "3. Buat data lagu dan Tampilkan" << endl;
    cout << "4. Masukkan lagu ke Genre" << endl;
    cout << "5. Tampilkan List Lagu" << endl;
    cout << "6. Kosongkan lagu pada sebuah Genre" << endl;
    cout << "7. Cari genre" << endl;
    cout << "8. Hapus genre" << endl;
    cout << "9. Hapus lagu beserta relasinya" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu: ";

    int input = 0;
    cin >> input;
    cout << endl;

    return input;
}

void insertFirstParent(ListParent &L, adrParent P){
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
void insertLastParent(ListParent &L, adrParent P){
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
void insertAfterParent(ListParent &L, adrParent Prec, adrParent P){
    if (next(P) != NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }else{
        insertLastParent(L,P);
    }
}
void tambahNParent(ListParent &L){
	adrParent p;
    int j = 0;
    infotypeParent genre;

    cout << "Jumlah data yang akan ditambahkan: ";
    cin >> j;

    for (int i = 0; i < j; i++){
        cout << "[" << i + 1 << "]" << endl;
        cout << "Nama genre: ";
        cin >> genre.namaGenre;
        genre.jumlahLagu = 0;
        genre.totalPutaran = 0;
        p = newElmParent(genre);
        insertLastParent(L, p);
    }
}

void deleteFirstParent(ListParent &L, adrParent &P){
	P = first(L);
    if (next(first(L)) == NULL) {
        first(L) = NULL;
    } else {
        first(L) = next(P);
    }
    next(P) = NULL;
}
void deleteLastParent(ListParent &L, adrParent &P){
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
void deleteAfterParent(ListParent &L, adrParent Prec, adrParent &P){
	if (next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    } else {
        cout << "data tidak ditemukan" << endl;
    }
}
void deleteGenre(ListParent &L, adrParent &p){
    adrParent q = first(L);
    string masukanGenre;

    cout << "Masukkan genre yang ingin di hapus: ";
    cin >> masukanGenre;
    p = findElmParent(L, masukanGenre);

    if (p == NULL){
        cout << "Genre tidak ditemukan" << endl;
    }else{
        if (p == first(L)) {
            deleteFirstParent(L, p);
        } else if (next(p) == NULL) {
            deleteLastParent(L, p);
        } else {
            while (next(q) != p) {
                q = next(q);
            }
            deleteAfterParent(L, q, p);
        }
    }
}

adrParent findElmParent(ListParent L, string x){
	bool ada = false;

    adrParent p = first(L);
    adrParent q = NULL;

    while (p != NULL && !ada){
        if (info(p).namaGenre == x){
            q = p;
            ada = true;
        }
        p = next(p);
    }
    return q;
}
void cariGenre(ListParent L){
    string masukanGenre;
    adrParent P;

    cout<<"Masukkan genre yang ingin dicari: ";
    cin >> masukanGenre;
    P = findElmParent(L, masukanGenre);

    if (P != NULL){
        cout << "Genre ditemukan : " << endl;
        cout << "Nama Genre: " << info(P).namaGenre << endl;
        hitungTotalPutaranDanLagu(P);
        cout << "Jumlah lagu: " << info(P).jumlahLagu << endl;
        cout << "Total putaran: " << info(P).totalPutaran << endl;

        cout << endl;
        printInfoChild(child(P));
    } else {
        cout << "GENRE TIDAK DITEMUKAN" << endl;
    }
}
void printInfoParent(ListParent L){
	adrParent P = first(L);
    int i = 1;

    if (first(L) != NULL){
        while (P != NULL){
            cout << "Genre [" << i++ << "]" << endl;
            cout << "Genre: " << info(P).namaGenre << endl;
            hitungTotalPutaranDanLagu(P);
            cout << "Jumlah lagu: " << info(P).jumlahLagu << endl;
            cout << "Total putaran: " << info(P).totalPutaran << endl << endl;

            printInfoChild(child(P));
            P = next(P);
        }
        cout << endl;
    }else{
        cout << "List Kosong!" << endl;
    }
}

void bikinListChild(ListChild &LC){
    infotypeChild musik;
    adrChild C;

    musik.judul = "Dreams";
    musik.penyanyi = "Goodnyght";
    musik.album = "Sleep Cycles";
    musik.jumlahPutar = 5;
    arrGenre arr1 = {"LoFi","EDM"};
    C = newElmChild(musik);
    addMusicGenre(C,arr1);
    insertFirstChild(LC,C);

    musik.judul = "Shallow Pools";
    musik.penyanyi = "Kokoro";
    musik.album = "The Way Home";
    musik.jumlahPutar = 7;
    arrGenre arr2 = {"LoFi","Jazz"};
    C = newElmChild(musik);
    addMusicGenre(C,arr2);
    insertFirstChild(LC,C);

    musik.judul = "To The Bone";
    musik.penyanyi = "Pamungkas";
    musik.album = "Flying Solo";
    musik.jumlahPutar = 10;
    arrGenre arr3 = {"Pop","Jazz"};
    C = newElmChild(musik);
    addMusicGenre(C,arr3);
    insertFirstChild(LC,C);

    musik.judul = "Faded";
    musik.penyanyi = "Alan Walker";
    musik.album = "Different World";
    musik.jumlahPutar = 1;
    arrGenre arr4 = {"EDM","Pop"};
    C = newElmChild(musik);
    addMusicGenre(C,arr4);
    insertFirstChild(LC,C);

    musik.judul = "Alive";
    musik.penyanyi = "Krewella";
    musik.album = "Play Hard EP";
    musik.jumlahPutar = 9;
    arrGenre arr6 = {"EDM"};
    C = newElmChild(musik);
    addMusicGenre(C,arr6);
    insertFirstChild(LC,C);

    musik.judul = "Solitude";
    musik.penyanyi = "Billie Holiday";
    musik.album = "Solitude";
    musik.jumlahPutar = 4;
    arrGenre arr5 = {"LoFi","Jazz"};
    C = newElmChild(musik);
    addMusicGenre(C,arr5);
    insertFirstChild(LC,C);


    printInfoChild(LC);
}
void add1Music(ListParent &LP, ListChild LC, string genreP, string judul){
    adrParent P = findElmParent(LP,genreP);
    adrChild C = findElmChild(LC,judul);
    adrChild newMusic;

    if (P != NULL && C != NULL){
        newMusic = newElmChild(info(C));
        insertLastChild(child(P),newMusic);
    }
}
void masukkanLagu(ListParent &LP, ListChild LC){

    add1Music(LP,LC,"LoFi","Dreams");
    add1Music(LP,LC,"LoFi","Shallow Pools");

    add1Music(LP,LC,"Pop","To The Bone");
    add1Music(LP,LC,"Pop","Faded");

    add1Music(LP,LC,"Jazz","Solitude");
    add1Music(LP,LC,"Jazz","Shallow Pools");
    add1Music(LP,LC,"Jazz","To The Bone");

    add1Music(LP,LC,"EDM","Alive");
    add1Music(LP,LC,"EDM","Faded");
    add1Music(LP,LC,"EDM","Dreams");
}
void hitungTotalPutaranDanLagu(adrParent &P){
    adrChild lagu = first(child(P));
    int totalPutaran = 0;
    int totalLagu = 0;

    if (lagu != NULL){
        do {
            totalPutaran += info(lagu).jumlahPutar;
            totalLagu++;

            lagu = next(lagu);
        }while (lagu != first(child(P)));

        info(P).jumlahLagu = totalLagu;
        info(P).totalPutaran = totalPutaran;
    }else{
        info(P).jumlahLagu = 0;
        info(P).totalPutaran = 0;
    }

}
void kosongkanGenre(ListParent &LP){
    string genreP;
    adrParent P;
    adrChild C;

    cout << "Judul Playlist/Genre yang ingin dikosongkan : ";
    cin >> genreP;
    P = findElmParent(LP,genreP);
    do {
        deleteFirstChild(child(P),C);
        C = next(C);
    }while (C != first(child(P)));
}
void hapusLaguDanRelasi(ListParent &LP, ListChild &LC){
    string judulLagu;
    adrChild C;
    adrParent P = first(LP);

    cout << "Judul Lagu yang ingin dihapus : ";
    cin >> judulLagu;
    C = findElmChild(LC,judulLagu);

    deleteLagu(LC,C);

    if (C != NULL){
        while (P != NULL){
            C = findElmChild(child(P),judulLagu);

            if (C != NULL){
                deleteLagu(child(P),C);
            }

            P = next(P);
        }
    }
}
