#include <iostream>
#include <string>
#include "bilangan.cpp"
using namespace std;

int main(){
    Bilangan *head = nullptr;


    cout << "Menambahkan 7 bilangan ke SLL ";
    int prima[] = {2, 3, 5, 7, 11, 13, 17};
    
    for (int i = 0; i < 7; i++) {
        insertBilangan(head, prima[i]);
    }
    cout << "\n=================================\n" << endl;

    // cout << "Menampilkan SLL Bilangan Prima: " << endl;
    // viewBilangan(head);
    // cout << "\n=================================\n" << endl;

    // cout << "Tambah bilangan 1 di awal SLL: " << endl;
    // TambahDiAwal(head, 1);
    // viewBilangan(head);
    // cout << "\n=================================\n" << endl;
    return 0;
}