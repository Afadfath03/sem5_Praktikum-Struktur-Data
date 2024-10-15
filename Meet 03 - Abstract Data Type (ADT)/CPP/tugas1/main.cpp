#include <iostream>
#include "t1.cpp"
using namespace std;

int main() {
    const int Max = 10;
    Mahasiswa mhs[Max];
    
    cout << "Masukkan jumlah mahasiswa: ";
    int n;
    cin >> n;
    cin.ignore();

    if (n > Max) {
        cout << "Jumlah mahasiswa melebihi batas" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "Mahasiswa ke-" << i + 1 << endl;
        inputMahasiswa(mhs[i]);
    }

    cout << endl;
    cout << "Daftar Mahasiswa" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai UTS   : " << mhs[i].uts << endl;
        cout << "Nilai UAS   : " << mhs[i].uas << endl;
        cout << "Nilai Tugas : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << endl;
    }

    return 0;
}