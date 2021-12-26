#include "parentSLL.h"
//#include "childCDLL.h"

int main()
{
    // TEST RELASI CUY
    int pilihan = 0;
    ListParent LP;
    ListChild LC;

//    adrParent P;

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
            tambahLagu(LP,LC);
            break;
        case 5:
            cariGenre(LP);
            break;
        case 6:
            deleteGenre(LP);
            break;
        }
        cout << endl;
        pilihan = selectMenu();
    }
    cout << "EXIT" << endl;

    return 0;
}
