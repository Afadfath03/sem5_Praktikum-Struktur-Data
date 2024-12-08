//B Most Left
#include <iostream>
using namespace std;
 
// Struktur untuk merepresentasikan node BST
struct Node {
    int data;
    Node* left;
    Node* right;
 
    // Konstruktor untuk membuat node baru
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
 
// Fungsi untuk memasukkan nilai ke BST
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
 
// Fungsi untuk menemukan most-left node
Node* findMostLeftNode(Node* root) {
    if (root == nullptr) {
        return nullptr; // BST kosong
    }
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}
 
// Fungsi utama
int main() {
    Node* root = nullptr;
 
    // Memasukkan nilai ke dalam BST
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 7);
 
    // Mencari most-left node
    Node* mostLeft = findMostLeftNode(root);
 
    if (mostLeft != nullptr) {
        cout << "Most-left tree adalah = " << mostLeft->data << endl;
    } else {
        cout << "Tree kosong." << endl;
    }
 
    return 0;
}