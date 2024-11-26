#include <iostream>
using namespace std;

// Definisi struktur node untuk Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Fungsi untuk menambahkan elemen ke BST
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value); // Membuat node baru jika pohon kosong
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value); // Insert ke subtree kiri
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value); // Insert ke subtree kanan
    }

    return root; // Mengembalikan root
}

// Fungsi untuk melakukan pencarian elemen di BST
bool search(Node *root, int value)
{
    if (root == nullptr)
    {
        return false; // Elemen tidak ditemukan
    }

    if (root->data == value)
    {
        return true; // Elemen ditemukan
    }
    else if (value < root->data)
    {
        return search(root->left, value); // Cari di subtree kiri
    }
    else
    {
        return search(root->right, value); // Cari di subtree kanan
    }
}

// Fungsi untuk mencetak elemen BST secara in-order
void inOrderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);  // Kunjungi subtree kiri
        cout << root->data << " ";     // Cetak data node
        inOrderTraversal(root->right); // Kunjungi subtree kanan
    }
}

int main()
{
    Node *root = nullptr;

    // Memasukkan elemen ke dalam BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Menampilkan elemen BST secara in-order
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Mencari elemen dalam BST
    int key = 40;
    if (search(root, key))
    {
        cout << "Element " << key << " found in BST." << endl;
    }
    else
    {
        cout << "Element " << key << " not found in BST." << endl;
    }

    return 0;
}