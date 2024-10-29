#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);

address alokasi(infotype x);

void dealokasi(address &P);

void printInfo(List &L);

void insertFirst(List &L, address P);

address findElm(List &L, infotype x);

int totalElm(List &L);

#endif // SINGLELIST_H