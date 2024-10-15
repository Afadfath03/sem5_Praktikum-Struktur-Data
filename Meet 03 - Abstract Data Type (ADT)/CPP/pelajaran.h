#ifndef PELAJARAN_H_INCLUDED 
#define PELAJARAN_H_INCLUDED
#include <iostream>

using namespace std;

struct pelajaran
{
    string namaMapel;
    int kodeMapel;
};

void createPelajaran(string namaPel, int kodePel, pelajaran &p);
//  
#endif // PELAJARAN_H_INCLUDED