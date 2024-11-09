#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <string>

using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList* next;
    ElmList* prev;
};

typedef ElmList* address;

struct List {
    address First;
    address Last;
};

void CreateList(List &L);

address alokasi(infotype x);

void dealokasi(address &P);

void printInfo(const List &L);

void insertLast(List &L, address P);

address findElm(const List &L, infotype x);

void deleteAfter(address Prec, address &P);

#endif