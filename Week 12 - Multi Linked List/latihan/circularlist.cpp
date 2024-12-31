#include "circularlist.h"
#include <iostream>

void CreateList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

address createData(std::string nama, std::string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertFirst(List &L, address P) {
    if (L.first == nullptr) {
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        L.first = P;
        last->next = L.first;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == nullptr) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != nullptr) {
        P = L.first;
        if (L.first->next == L.first) {
            L.first = nullptr;
        } else {
            address last = L.first;
            while (last->next != L.first) {
                last = last->next;
            }
            L.first = P->next;
            last->next = L.first;
        }
        P->next = nullptr;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != nullptr && Prec->next != L.first) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != nullptr) {
        if (L.first->next == L.first) {
            P = L.first;
            L.first = nullptr;
        } else {
            address last = L.first;
            address precLast = nullptr;
            while (last->next != L.first) {
                precLast = last;
                last = last->next;
            }
            P = last;
            precLast->next = L.first;
        }
        P->next = nullptr;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    if (P != nullptr) {
        do {
            if (P->info.nim == x.nim) {
                return P;
            }
            P = P->next;
        } while (P != L.first);
    }
    return nullptr;
}

void printInfo(List L) {
    address P = L.first;
    if (P != nullptr) {
        do {
            std::cout   << "Nama: " << P->info.nama << "\n"
                        << "NIM : " << P->info.nim << "\n"
                        << "L/P : " << P->info.jenis_kelamin << "\n"
                        << "IPK : " << P->info.ipk << "\n"
            << std::endl;
            P = P->next;
        } while (P != L.first);
    }
}