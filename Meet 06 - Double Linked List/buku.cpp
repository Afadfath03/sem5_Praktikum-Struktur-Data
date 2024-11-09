#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int kode;
    string nama;
    string penerbit;
    int tahunTerbit;
    int stok;
    Buku* prev;
    Buku* next;
};

Buku* createNode(int kode, string nama, string penerbit, int tahunTerbit, int stok) {
    Buku* newNode = new Buku();
    newNode->kode = kode;
    newNode->nama = nama;
    newNode->penerbit = penerbit;
    newNode->tahunTerbit = tahunTerbit;
    newNode->stok = stok;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Buku** head, int kode, string nama, string penerbit, int tahunTerbit, int stok) {
    Buku* newNode = createNode(kode, nama, penerbit, tahunTerbit, stok);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Buku* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void displayList(Buku* head) {
    Buku* temp = head;
    while (temp != nullptr) {
        cout << endl;
        cout << "Kode: " << temp->kode 
            << "\nNama: " << temp->nama
            << "\nPenerbit: " << temp->penerbit 
            << "\nTahun Terbit: " << temp->tahunTerbit
            << "\nStok: " << temp->stok 
            << endl;

        temp = temp->next;
    }
}

// Function to delete a node by kode
void deleteByKode(Buku** head, int kode) {
    Buku* temp = *head;
    while (temp != nullptr && temp->kode != kode) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Buku dengan kode " << kode << " tidak ditemukan." << endl;
        return;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    cout << "Buku dengan kode " << kode << " berhasil dihapus." << endl;
}

int main() {
    Buku* head = nullptr;

    // Menambahkan data buku
    insertEnd(&head, 1, "A", "Udah Gk ada", 1945, 0);
    insertEnd(&head, 2, "B", "Kurang paham", 2004, 1);
    insertEnd(&head, 3, "C", "Tidak tahu", 2024, 2);

    cout << "Daftar Buku:" << endl;
    displayList(head);

    return 0;
}