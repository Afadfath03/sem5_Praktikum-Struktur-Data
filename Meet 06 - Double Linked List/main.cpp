#include <iostream>
#include <string>
using namespace std;
 
// Node structure for Double Linked List
struct Mahasiswa {
    int nim;
    string nama;
    Mahasiswa* prev;
    Mahasiswa* next;
};
 
// Function to create a new node
Mahasiswa* createNode(int nim, string nama) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}
 
// Function to insert node at the end
void insertEnd(Mahasiswa** head, int nim, string nama) {
    Mahasiswa* newNode = createNode(nim, nama);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Mahasiswa* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
 
// Function to display the list
void displayList(Mahasiswa* head) {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        cout << "NIM: " << temp->nim << ", Nama: " << temp->nama << endl;
        temp = temp->next;
    }
}
 
// Function to delete a node by NIM
void deleteByNIM(Mahasiswa** head, int nim) {
    Mahasiswa* temp = *head;
    while (temp != nullptr && temp->nim != nim) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
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
    cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
}
 
int main() {
    Mahasiswa* head = nullptr;
 
    // Menambahkan data mahasiswa
    insertEnd(&head, 101, "Budi");
    insertEnd(&head, 102, "Ani");
    insertEnd(&head, 103, "Siti");
 
    cout << "Daftar Mahasiswa:" << endl;
    displayList(head);
 
    // Menghapus mahasiswa dengan NIM tertentu
    cout << "\nMenghapus Mahasiswa dengan NIM 102:" << endl;
    deleteByNIM(&head, 102);
 
    cout << "\nDaftar Mahasiswa setelah penghapusan:" << endl;
    displayList(head);
 
    return 0;
}
 