#include "parentSLL.h"

int main()
{
    int pilihan = 0;
    ListParent LP;
    ListChild LC;

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
            kosongkanGenre(LP); // sebelum : hapusRelasi(LP)
            break;
        case 6:
            cariGenre(LP);
            break;
        case 7:
            deleteGenre(LP);
            break;
        }
        cout << endl;
        pilihan = selectMenu();
    }
    cout << "EXIT" << endl;

    return 0;
}
