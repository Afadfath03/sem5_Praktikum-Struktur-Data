#ifndef BILANGAN_H
#define BILANGAN_H

struct Bilangan {
    int Angka;
    Bilangan *next;
};

void insertBilangan(Bilangan *&head, int Angka);

void viewBilangan(Bilangan *head);

void TambahDiAwal(Bilangan *&head, int AngkaBaru);

#endif // BILANGAN_H