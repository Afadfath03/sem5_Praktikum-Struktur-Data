#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa
{
    string nama;
    string nim;
    string jurusan;
    Mahasiswa *next;
};

// Fungsi untuk menambahkan mahasiswa ke dalam linked list
void tambahMahasiswa(Mahasiswa *&head, string nama, string nim, string jurusan) {
    Mahasiswa *newMahasiswa = new Mahasiswa();
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->jurusan = jurusan;
    newMahasiswa->next = nullptr;

    if (head == nullptr) {
        head = newMahasiswa;
    } else {
        Mahasiswa *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newMahasiswa;
    }
}

// Fungsi untuk menampilkan semua mahasiswa dalam linked list
void tampilkanMahasiswa(Mahasiswa *head) {
    if (head == nullptr) {
        cout << "Daftar mahasiswa kosong." << endl;
        return;
    }

    Mahasiswa *temp = head;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << endl;
        cout << "NIM: " << temp->nim << endl;
        cout << "Jurusan: " << temp->jurusan << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menghapus semua data mahasiswa dari linked list
void hapusMahasiswa(Mahasiswa *&head) {
    while (head != nullptr) {
        Mahasiswa *temp = head;
        head = head->next;
        delete temp;
    }
}

// Fungsi untuk menghapus mahasiswa berdasarkan NIM
void hapusMahasiswaNIM(Mahasiswa *&head, string nim) {
    Mahasiswa *temp = head;
    Mahasiswa *prev = nullptr;

    while (temp != nullptr && temp->nim != nim) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "NIM " << nim << " tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

// Fungsi untuk menambahkan mahasiswa pada sebelum NIM tertentu
void tambahSebelumNIM(Mahasiswa *&head, string nama, string nim, string jurusan, string nim_setelahnya) {
    Mahasiswa *newMahasiswa = new Mahasiswa();
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->jurusan = jurusan;

    if (head == nullptr || head->nim == nim_setelahnya) {
        newMahasiswa->next = head;
        head = newMahasiswa;
        return;
    }

    Mahasiswa *temp = head;
    
    while (temp->next != nullptr && temp->next->nim != nim_setelahnya) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "NIM " << nim_setelahnya << " tidak ditemukan." << endl;
        delete newMahasiswa;
    } else {
        newMahasiswa->next = temp->next;
        temp->next = newMahasiswa;
    }
}

int main()
{
    Mahasiswa *head = nullptr;

    tambahMahasiswa(head, "Andi", "123456", "Teknik Informatika");
    tambahMahasiswa(head, "Budi", "234567", "Sistem Informasi");
    tambahMahasiswa(head, "Cici", "345678", "Teknik Elektro");

    cout << "Daftar Mahasiswa: " << endl;
    tampilkanMahasiswa(head);

    hapusMahasiswa(head);

    tampilkanMahasiswa(head);

    return 0;
}