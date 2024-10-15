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