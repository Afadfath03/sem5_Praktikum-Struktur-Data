#include <iostream>
#include <string>
#include "bilangan.cpp"
using namespace std;

int main(){
    Bilangan *head = nullptr;

    cout << "1. Menambahkan 7 bilangan ke SLL ";
    int prima[] = {2, 3, 5, 7, 11, 13, 17};
    
    for (int i = 0; i < 7; i++) {
        insertBilangan(head, prima[i]);
    }
    cout << "\n=================================\n" << endl;

    cout << "2. Menampilkan SLL: " << endl;
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    cout << "3. Tambah bilangan 1 di awal SLL: " << endl;
    TambahDiAwal(head, 1);
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    cout << "4. Tambah bilangan 19 di akhir SLL: " << endl;
    TambahDiAkhir(head, 19);
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    cout << "5. Tambah bilangan 10 sebelum angka 11 di SLL: " << endl;
    SisipkanAngkaSebelum(head, 10, 11);
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    cout << "6. Menghapus bilangan 1 di awal SSL: " << endl;
    hapusAwal(head);
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    cout << "7. Menghapus bilangan 19 di akhir SSL: " << endl;
    hapusAkhir(head);
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    cout << "8. Menghapus bilangan sebelum bilangan 11: " << endl;
    hapusSebelumPosisi(head, 11);
    viewBilangan(head);
    cout << "\n=================================\n" << endl;

    return 0;
}