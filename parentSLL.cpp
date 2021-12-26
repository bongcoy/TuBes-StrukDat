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
    cout << "2. Tampilkan semua genre" << endl;
    cout << "3. Bikin 10 lagu" << endl;
    cout << "4. Tambah lagu ke Genre" << endl;
    cout << "5. Cari genre" << endl;
    cout << "6. Hapus genre" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan menu: ";

    int input = 0;
    cin >> input;

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
        cout << "data tidak valid" << endl;
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

void printInfoParent(ListParent L){
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

void deleteGenre(ListParent &L){
    adrParent p = NULL;
    adrParent q = first(L);
    string masukanGenre;

    cout << "Masukkan genre yang ingin di hapus: ";
    cin >> masukanGenre;
    p = findElmParent(L, masukanGenre);

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

//    child(p) = NULL; //no match for operator, 'ListChild' and 'long long int'
}
void cariGenre(ListParent L){
    string masukanGenre;
    adrParent P;

    cout<<"Masukkan genre yang ingin dicari: ";
    cin >> masukanGenre;
    P = findElmParent(L, masukanGenre);

    if (P != NULL){
        cout << "Genre ditemukan : ";
        cout << "Genre: " << info(P).namaGenre << endl;
        cout << "Jumlah lagu: " << info(P).jumlahLagu << endl;
        cout << "Total putaran: " << info(P).totalPutaran << endl;
    } else {
        cout << "GENRE TIDAK DITEMUKAN" << endl;
    }
}
void bikinListChild(ListChild &LC){
    infotypeChild musik;
    adrChild C;

    musik.judul = "LoFi1";
    musik.penyanyi = "Asoy";
    musik.album = "Anjay";
    musik.jumlahPutar = 5;
    musik.genre = "LoFi";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "LoFi2";
    musik.penyanyi = "Bsoy";
    musik.album = "Bnjay";
    musik.jumlahPutar = 7;
    musik.genre = "LoFi";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "Pop1";
    musik.penyanyi = "Csoy";
    musik.album = "Cnjay";
    musik.jumlahPutar = 10;
    musik.genre = "Pop";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "Jazz1";
    musik.penyanyi = "Dsoy";
    musik.album = "Dnjay";
    musik.jumlahPutar = 7;
    musik.genre = "Jazz";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "Jazz2";
    musik.penyanyi = "Esoy";
    musik.album = "Enjay";
    musik.jumlahPutar = 10;
    musik.genre = "Jazz";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "Jazz3";
    musik.penyanyi = "Fsoy";
    musik.album = "Fnjay";
    musik.jumlahPutar = 4;
    musik.genre = "Jazz";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "EDM1";
    musik.penyanyi = "Gsoy";
    musik.album = "Gnjay";
    musik.jumlahPutar = 1;
    musik.genre = "EDM";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "EDM2";
    musik.penyanyi = "Hsoy";
    musik.album = "Hnjay";
    musik.jumlahPutar = 2;
    musik.genre = "EDM";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "EDM3";
    musik.penyanyi = "Isoy";
    musik.album = "Injay";
    musik.jumlahPutar = 3;
    musik.genre = "EDM";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    musik.judul = "EDM4";
    musik.penyanyi = "Jsoy";
    musik.album = "Jnjay";
    musik.jumlahPutar = 4;
    musik.genre = "EDM";
    C = newElmChild(musik);
    insertFirstChild(LC,C);

    printInfoChild(LC);
}
void addMusic(ListParent &LP, ListChild LC, string genreP, string judul){
    adrParent P = findElmParent(LP,genreP);
    adrChild C = findElmChild(LC,judul);
    adrChild newMusic;

    if (P != NULL && C != NULL && info(C).genre == genreP){
        newMusic = newElmChild(info(C));
        insertLastChild(child(P),newMusic);
    }
}

void tambahLagu(ListParent &LP, ListChild LC){
    adrParent P;

    addMusic(LP,LC,"LoFi","LoFi1");
    addMusic(LP,LC,"LoFi","LoFi2");
    P = findElmParent(LP,"LoFi");
    hitungTotalPutaran(P);
    info(P).jumlahLagu = 2;

    addMusic(LP,LC,"Pop","Pop1");
    P = findElmParent(LP,"Pop");
    hitungTotalPutaran(P);
    info(P).jumlahLagu = 1;

    addMusic(LP,LC,"Jazz","Jazz1");
    addMusic(LP,LC,"Jazz","Jazz2");
    addMusic(LP,LC,"Jazz","Jazz3");
    P = findElmParent(LP,"Jazz");
    hitungTotalPutaran(P);
    info(P).jumlahLagu = 3;

    addMusic(LP,LC,"EDM","EDM1");
    addMusic(LP,LC,"EDM","EDM2");
    addMusic(LP,LC,"EDM","EDM3");
    addMusic(LP,LC,"EDM","EDM4");
    P = findElmParent(LP,"EDM");
    hitungTotalPutaran(P);
    info(P).jumlahLagu = 4;
}
void hitungTotalPutaran(adrParent &P){
    adrChild lagu = first(child(P));
    int total = 0;

    do {
        total += info(lagu).jumlahPutar;

        lagu = next(lagu);
    }while (lagu != first(child(P)));

    info(P).totalPutaran = total;
}
