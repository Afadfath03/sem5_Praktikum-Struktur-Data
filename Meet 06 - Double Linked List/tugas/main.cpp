#include "doublelist.cpp"
#include <iostream>

using namespace std;

int main(){
    List L;
    CreateList(L);

    // int n;
    // cout << "Berapa banyak mobil yang ingin dimasukkan? ";
    // cin >> n;

    // for (int i = 0; i < n; i++) {
    //     infotype kendaraan;
    //     cout << "\nMasukkan nomor polisi    : ";
    //     cin >> kendaraan.nopol;
    //     cout << "Masukkan warna Kendaraan : ";
    //     cin >> kendaraan.warna;
    //     cout << "Masukkan tahun kendaraan : ";
    //     cin >> kendaraan.thnBuat;

    //     address P = alokasi(kendaraan);
    //     insertLast(L, P);
    // }

    infotype kendaraan1, kendaraan2, kendaraan3;

    kendaraan1.nopol = "D001";
    kendaraan1.warna = "Putih";
    kendaraan1.thnBuat = 2000;
    insertLast(L, alokasi(kendaraan1));

    kendaraan2.nopol = "D002";
    kendaraan2.warna = "Hitam";
    kendaraan2.thnBuat = 2010;
    insertLast(L, alokasi(kendaraan2));

    kendaraan3.nopol = "D003";
    kendaraan3.warna = "Merah";
    kendaraan3.thnBuat = 2020;
    insertLast(L, alokasi(kendaraan3));

    cout << "\n==============" << endl;
    cout << "Data Kendaraan" << endl;
    printInfo(L);

    // cout << "\n==============" << endl;
    // infotype cari;
    // cout << "Masukkan nomor polisi yang ingin dicari: ";
    // cin >> cari.nopol;

    // address P = findElm(L, cari);
    // if (P != nullptr) {
    //     cout << endl;
    //     cout << "Nomor Polisi : " << P->info.nopol << endl;
    //     cout << "Warna        : " << P->info.warna << endl;
    //     cout << "Tahun        : " << P->info.thnBuat << endl;
    // } else {
    //     cout << "Data tidak ditemukan" << endl;
    // }

    cout << "\n==============" << endl;
    infotype hapus;
    cout << "Masukkan nomor polisi yang ingin dihapus: ";
    cin >> hapus.nopol;

    address P = findElm(L, hapus);
    if (P != nullptr) {
        deleteAfter(P->prev, P);
        dealokasi(P);
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    printInfo(L);
}