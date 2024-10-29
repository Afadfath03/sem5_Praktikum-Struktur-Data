#include <iostream>
#include "bilangan.h"
using namespace std;

void insertBilangan(Bilangan *&head, int Angka) {
    Bilangan *newBilangan = new Bilangan();
    newBilangan->Angka = Angka;
    newBilangan->next = nullptr;

    if (head == nullptr) {
        head = newBilangan;
    }
    else {
        Bilangan *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBilangan;
    }
}

void viewBilangan(Bilangan *head) {
    if (head == nullptr) {
        cout << "Daftar bilangan kosong" << endl;
        return;
    }

    Bilangan *temp = head;
    while (temp != nullptr) {
        cout << temp->Angka << " ";
        temp = temp->next;
    }
}

void TambahDiAwal(Bilangan *&head, int AngkaBaru) {
    Bilangan *newBilangan = new Bilangan;
    newBilangan->Angka = AngkaBaru;
    newBilangan->next = head;
    head = newBilangan;
}

void TambahDiAkhir(Bilangan *&head, int AngkaBaru) {
    Bilangan *newBilangan = new Bilangan;
    newBilangan->Angka = AngkaBaru;
    newBilangan->next = nullptr;

    if (head == nullptr) {
        head = newBilangan;
    }
    else {
        Bilangan *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBilangan;
    }
}

void SisipkanAngkaSebelum(Bilangan *&head, int AngkaBaru, int AngkaSebelum){
    Bilangan *newBilangan = new Bilangan;
    newBilangan->Angka = AngkaBaru;
    newBilangan->next = nullptr;

    if (head == nullptr) {
        head = newBilangan;
    }
    else {
        Bilangan *p = head;
        while (p->next != nullptr && p->next->Angka != AngkaSebelum) {
            p = p->next;
        }
        if (p->next == nullptr) {
            cout << "Posisi angka " << AngkaSebelum << " tidak ditemukan" << endl;
            return;
        }
        newBilangan->next = p->next;
        p->next = newBilangan;
    }
};

void hapusAwal(Bilangan *&head){
    Bilangan *hapus = head;
    head = head->next;
    delete hapus;
};

void hapusAkhir(Bilangan *&head){
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Bilangan *p = head;
    while (p->next->next != nullptr) {
        p = p->next;
    }
    delete p->next;
    p->next = nullptr;
};

void hapusSebelumPosisi(Bilangan *&head, int Posisi){
    if (head->Angka == Posisi) {
        cout << "Tidak ada bilangan sebelum " << Posisi << endl;
        return;
    }

    if (head->next->Angka == Posisi) {
        hapusAwal(head);
        return;
    }

    Bilangan *p = head;
    while (p->next->next != nullptr && p->next->next->Angka != Posisi) {
        p = p->next;
    }

    Bilangan *hapus = p->next;
    p->next = p->next->next;
    delete hapus;
};