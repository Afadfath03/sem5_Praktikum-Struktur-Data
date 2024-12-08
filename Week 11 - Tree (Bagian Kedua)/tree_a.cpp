//A Delete
#include <iostream>
using namespace std;
 
// Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
 
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
 
// Fungsi untuk menambahkan Node ke Binary Tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
 
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
 
// Fungsi untuk mencari nilai terkecil di subtree kanan
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
 
// Fungsi untuk menghapus Node dari Binary Tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
 
    // Menavigasi ke node yang ingin dihapus
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node ditemukan
 
        // Kasus 1: Node tanpa anak
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
 
        // Kasus 2: Node dengan satu anak
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
 
        // Kasus 3: Node dengan dua anak
        Node* temp = findMin(root->right); // Cari pengganti dari subtree kanan
        root->data = temp->data;          // Ganti nilai root dengan nilai pengganti
        root->right = deleteNode(root->right, temp->data); // Hapus pengganti
    }
 
    return root;
}
 
// Traversal Inorder untuk menampilkan tree
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
 
int main() {
    Node* root = nullptr;
 
    // Masukkan nilai ke Binary Tree
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 18);
    insert(root, 35);
 
    cout << "Binary Tree Inorder Awal: ";
    inorderTraversal(root);
    cout << endl;
 
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Binary Tree (Inorder)\n";
        cout << "2. Hapus Node\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;
 
        switch (choice) {
            case 1:
                cout << "Binary Tree Inorder: ";
                inorderTraversal(root);
                cout << endl;
                break;
 
            case 2: {
                int valueToDelete;
                cout << "Masukkan nilai node yang ingin dihapus: ";
                cin >> valueToDelete;
                root = deleteNode(root, valueToDelete);
                cout << "Node " << valueToDelete << " telah dihapus.\n";
                break;
            }
 
            case 3:
                cout << "Keluar dari program.\n";
                break;
 
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (choice != 3);
 
    return 0;
}