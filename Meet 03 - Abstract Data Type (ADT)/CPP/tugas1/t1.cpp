#include <iostream>
#include "t1.h"
using namespace std;

void inputMahasiswa(Mahasiswa &mhs) {
    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM: ";
    getline(cin, mhs.nim);
    cout << "Masukkan Nilai UTS: ";
    cin >> mhs.uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> mhs.uas;
    cout << "Masukkan Nilai Tugas: ";
    cin >> mhs.tugas;
    cin.ignore();
    mhs.nilaiAkhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

double hitungNilaiAkhir(double uts, double uas, double tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}