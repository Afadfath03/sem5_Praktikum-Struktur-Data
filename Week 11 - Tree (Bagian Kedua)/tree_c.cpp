// C Most Right
#include <iostream>
using namespace std;
 
// Definisi node untuk Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
 
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
 
// Fungsi untuk menambahkan node ke dalam BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
 
// Fungsi untuk mencari node paling kanan (most-right)
Node* findMostRight(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current;
}
 
// Fungsi utama
int main() {
    Node* root = nullptr;
 
    // Input data untuk BST
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 40);
 
    // Cari most-right node
    Node* mostRight = findMostRight(root);
    if (mostRight != nullptr) {
        cout << "Most-right node (nilai terbesar) adalah = " << mostRight->data << endl;
    } else {
        cout << "Tree kosong." << endl;
    }
 
    return 0;
}