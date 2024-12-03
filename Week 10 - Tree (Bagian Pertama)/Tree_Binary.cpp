#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node *root, int value){
    if (root == nullptr) return false;

    if (root->data == value) return true;
    else if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}

void inOrderTraversal(Node *root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node *root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // int key = 40;
    // if (search(root, key))
    // {
    //     cout << "Element " << key << " found in BST." << endl;
    // }
    // else
    // {
    //     cout << "Element " << key << " not found in BST." << endl;
    // }

    return 0;
}
