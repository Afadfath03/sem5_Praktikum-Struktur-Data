#ifndef BILANGAN_H
#define BILANGAN_H

struct Bilangan {
    int Angka;
    Bilangan *next;
};

void insertBilangan(Bilangan *&head, int Angka);

void viewBilangan(Bilangan *head);

void TambahDiAwal(Bilangan *&head, int AngkaBaru);

void TambahDiAkhir(Bilangan *&head, int AngkaBaru);

void SisipkanAngkaSebelum(Bilangan *&head, int AngkaBaru, int AngkaSebelum);

void hapusAwal(Bilangan *&head);

void hapusAkhir(Bilangan *&head);

void hapusSebelumPosisi(Bilangan *&head, int Posisi);

#endif // BILANGAN_H