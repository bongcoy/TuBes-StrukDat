#include "childCDLL.h"
void createList(ListChild &L){
	first(L) = NULL;
    last(L) = NULL;
}
void newElmChild(infotypeChild infoChild, adrChild &P){
	P = new elmChild;

    info(P) = infoChild;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}
void insertFirst(ListChild &L, adrChild P){
	if (first(L) == NULL){

	}else{
		prev(P) = Prev(first(L));
		next(P) = first(L);
	}
}
void insertLast(ListChild &L, adrChild P){

}
void insertAfter(adrChild Prec, adrChild P){
	if (next(Prec)==NULL){
        insertLast(L,P);
    }else{
        next(P) = next(Prec);
        prev(next(Prec)) = P;
        next(Prec) = P;
        prev(P) = Prec;
    }
}
}
void deleteFirst(ListChild &L, adrChild &P){

}
void deleteLast(ListChild &L, adrChild &P){

}
void deleteAfter(adrChild Prec, adrChild &P){
	if (next(Prec) != NULL){
		P = next(Prec);
	    next(Prec) = next(P);
	    prev(next(P)) = Prec;
	}

    next(P) = NULL;
    prev(P) = NULL;
}

adrChild findElm(ListChild L, infotypeChild x){

}
void printInfo(ListChild L){

}
