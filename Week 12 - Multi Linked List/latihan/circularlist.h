#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <string>

struct Mahasiswa {
    std::string nama;
    std::string nim;
    char jenis_kelamin;
    float ipk;
};

typedef Mahasiswa infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address first;
};

void CreateList(List &L);

address alokasi(infotype x);

void dealokasi(address &P);

void insertFirst(List &L, address P);

void insertAfter(List &L, address Prec, address P);

void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);

void deleteAfter(List &L, address Prec, address &P);

void deleteLast(List &L, address &P);

address findElm(List L, infotype x);

void printInfo(List L);

#endif // CIRCULARLIST_H