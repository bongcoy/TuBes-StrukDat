#include "parentSLL.h"
//#include "childCDLL.h"

int main()
{
    // TEST PARENT CUY
    int pilihan = 0;
    infotypeParent inputGenre;
    ListParent LP;
    adrParent P;
//    adrChild C;

    pilihan = selectMenu();


    createList(LP);

//    createList(LP);
    while (pilihan != 0) {
        switch(pilihan){
        case 1:
//            P = alokasi(3);
//            insertFirst(LP, P);
//            P = alokasi(7);
//            insertFirst(LP, P);
//            P = alokasi(2);
//            insertFirst(LP, P);
//            P = alokasi(4);
//            insertFirst(LP, P);
            tambahNData(LP);
            break;
        case 2:
            cout<<"List Parent : "<<endl;
            printInfo(LP);
            break;
        case 3:
            cout<<"Masukkan genre yang ingin dicari: ";
            cin >> inputGenre.namaGenre;
            P = findElm(LP, inputGenre);
            if (P != NULL){
                cout << "Genre: " << info(P).namaGenre << endl;
                cout << "Jumlah lagu: " << info(P).jumlahLagu << endl;
                cout << "Total putaran: " << info(P).totalPutaran << endl;
            } else {
                cout << "GENRE TIDAK DITEMUKAN" << endl;
            }
            break;
        case 4:
            deleteGenre(LP);
            break;
        }
        cout << endl;
        pilihan = selectMenu();
    }
    cout << "EXIT" << endl;

    // TEST CHILD CUY
//    ListChild L;
//    adrChild P;
//    infotypeChild musik;
//
//    createList(L);
//
//    musik.judul = "A1";
//    musik.penyanyi = "Asoy";
//    musik.album = "Anjay";
//    musik.genre = "LoFi";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "B1";
//    musik.penyanyi = "Bsoy";
//    musik.album = "Bnjay";
//    musik.genre = "LoFi";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "C2";
//    musik.penyanyi = "Csoy";
//    musik.album = "Cnjay";
//    musik.genre = "Pop";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "D3";
//    musik.penyanyi = "Dsoy";
//    musik.album = "Dnjay";
//    musik.genre = "Jazz";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "E3";
//    musik.penyanyi = "Esoy";
//    musik.album = "Enjay";
//    musik.genre = "Jazz";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "F3";
//    musik.penyanyi = "Fsoy";
//    musik.album = "Fnjay";
//    musik.genre = "Jazz";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "G4";
//    musik.penyanyi = "Gsoy";
//    musik.album = "Gnjay";
//    musik.genre = "EDM";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "H4";
//    musik.penyanyi = "Hsoy";
//    musik.album = "Hnjay";
//    musik.genre = "EDM";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "I4";
//    musik.penyanyi = "Isoy";
//    musik.album = "Injay";
//    musik.genre = "EDM";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    musik.judul = "J4";
//    musik.penyanyi = "Jsoy";
//    musik.album = "Jnjay";
//    musik.genre = "EDM";
//    P = newElmChild(musik);
//    insertFirst(L,P);
//
//    printInfo(L);

    return 0;
}
