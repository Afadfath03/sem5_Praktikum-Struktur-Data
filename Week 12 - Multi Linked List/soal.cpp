#include <iostream>
#include <string>
using namespace std;

struct Kategori {
    string namaKategori;
    Kategori* nextKategori;
};

struct Buku {
    string judul;
    string penulis;
    int tahun;
    int halaman;
    Kategori* kategori;
    Buku* nextBuku;
};

Buku* tambahBuku(Buku* head, string judul, string penulis, int tahun, int halaman) {
    Buku* newBuku = new Buku{judul, penulis, tahun, halaman, nullptr, head};
    return newBuku;
}

void tambahKategoriKeBuku(Buku* buku, string namaKategori) {
    Kategori* newKategori = new Kategori{namaKategori, buku->kategori};
    buku->kategori = newKategori;
}

void tampilkanBuku(Buku* head) {
    while (head) {
        cout << "Judul: " << head->judul << endl;
        cout << "Penulis: " << head->penulis << endl;
        cout << "Tahun: " << head->tahun << endl;
        cout << "Halaman: " << head->halaman << endl;
        cout << "Kategori: ";
        Kategori* kategori = head->kategori;
        while (kategori) {
            cout << kategori->namaKategori << " ";
            kategori = kategori->nextKategori;
        }
        cout << endl;
        head = head->nextBuku;
        cout << endl;
    }
}

int main() {
    Buku* perpustakaan = nullptr;

    perpustakaan = tambahBuku(perpustakaan, "Bumi Manusia", "Pramoedya Ananta Toer", 1980, 354);
    tambahKategoriKeBuku(perpustakaan, "Fantasy");
    tambahKategoriKeBuku(perpustakaan, "Novel");
    
    perpustakaan = tambahBuku(perpustakaan, "Sebuah Seni untuk Bersikap Bodo Amat", "Mark Manson", 2009, 246);
    tambahKategoriKeBuku(perpustakaan, "Psikologi");

    tampilkanBuku(perpustakaan);

    return 0;
}
