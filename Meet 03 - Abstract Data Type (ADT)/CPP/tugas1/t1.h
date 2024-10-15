#ifndef T1_INCLUDED
#define T1_INCLUDED

#include <iostream>
using namespace std;

struct Mahasiswa { 
    string nama; 
    string nim; 
    double uts; 
    double uas; 
    double tugas; 
    double nilaiAkhir; 
}; 

void inputMahasiswa(Mahasiswa &mhs);

double hitungNilaiAkhir(double uts, double uas, double tugas);

#endif // T1_INCLUDED