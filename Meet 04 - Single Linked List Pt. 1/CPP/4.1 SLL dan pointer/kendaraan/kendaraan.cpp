#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mobil
{
    string nama;
    string warna;
    string merk;
    int tahun;
    string jenis_transmisi;
    Mobil *next;
};

// Fungsi untuk menambahkan mahasiswa ke dalam linked list
void tambahMobil(Mobil *&head, string nama, string warna, string merk, int tahun, string jenis_transmisi)
{
    Mobil *newMobil = new Mobil();
    newMobil->nama = nama;
    newMobil->warna = warna;
    newMobil->merk = merk;
    newMobil->tahun = tahun;
    newMobil->jenis_transmisi = jenis_transmisi;
    newMobil->next = nullptr;

    if (head == nullptr)
    {
        head = newMobil;
    }
    else
    {
        Mobil *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newMobil;
    }
}

// Fungsi untuk menampilkan semua mahasiswa dalam linked list
void tampilkanMobil(Mobil *head)
{
    if (head == nullptr)
    {
        cout << "Daftar Mobil kosong." << endl;
        return;
    }

    Mobil *temp = head;
    while (temp != nullptr)
    {
        cout << "Nama       : " << temp->nama << endl;
        cout << "Warna      : " << temp->warna << endl;
        cout << "Merk       : " << temp->merk << endl;
        cout << "Tahun      : " << temp->tahun << endl;
        cout << "Transmisi  : " << temp->jenis_transmisi << endl;
        cout << "------------------------" << endl;
        temp = temp->next;
    }
}

// Fungsi untuk menghapus semua data mahasiswa dari linked list
void hapusMobil(Mobil *&head)
{
    while (head != nullptr)
    {
        Mobil *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Mobil* head = nullptr;

    tambahMobil(head, "Avanza", "Hitam", "Toyota", 2019, "Manual");
    tambahMobil(head, "Xenia", "Putih", "Daihatsu", 2018, "Automatic");
    tambahMobil(head, "Jazz", "Merah", "Honda", 2020, "Automatic");

    cout << "Daftar Mobil: " << endl;
    tampilkanMobil(head);

    hapusMobil(head);

    tampilkanMobil(head);

    return 0;
}