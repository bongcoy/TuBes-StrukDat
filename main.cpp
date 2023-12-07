#include "parentSLL.h"

int main()
{
    string genre;
    int pilihan = 0;
    ListParent LP;
    ListChild LC;
    ListChild temp;

    adrParent P;

    pilihan = selectMenu();

    createListParent(LP);
    createListChild(LC);

    while (pilihan != 0) {
        switch(pilihan){
        case 1:
            tambahNParent(LP);
            break;
        case 2:
            printInfoParent(LP);
            break;
        case 3:
            bikinListChild(LC);
            break;
        case 4:
            masukkanLagu(LP,LC);
            break;
        case 5:
            printInfoChild(LC);
            break;
        case 6:
            cout << "Judul Playlist/Genre yang ingin dikosongkan : ";
            cin >> genre;
            P = findElmParent(LP,genre);
            kosongkanGenre(P);
            break;
        case 7:
            cariGenre(LP);
            break;
        case 8:
            deleteGenre(LP,P);
            break;
        case 9:
            hapusLaguDanRelasi(LP,LC);
            break;
        case 10:
            tukarChild(LP);
            break;
        case 11:
            cout << "Genre child yg ingin dihapus : ";
            cin >> genre;
            P = findElmParent(LP,genre);
            hapusRelasi(P,temp);

            cout << "Genre child yg ingin dibuat : ";
            cin >> genre;
            P = findElmParent(LP,genre);
            buatRelasi(P,temp);
            break;
        }
        cout << endl;
        pilihan = selectMenu();
    }
    cout << "EXIT" << endl;

    // Catatan : banyak fungsi yang memiliki lebih dari 1 responsibility agar tidak membuat banyak fungsi

    return 0;
}
