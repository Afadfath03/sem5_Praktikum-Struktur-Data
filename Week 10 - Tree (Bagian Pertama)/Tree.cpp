#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    vector<Node*> children;

    Node(int value) {
        data = value;
    }
};

void tambahAnak(Node* parent, int value) {
    Node* child = new Node(value);
    parent->children.push_back(child);
}

void cetakTree(Node* root, int depth = 0) {
    if (!root) return;

    for (int i = 0; i < depth; i++) cout << "  ";
    cout << root->data << endl;

    for (Node* child : root->children) {
        cetakTree(child, depth + 1);
    }
}

int main() {
    Node* root = new Node(1);

    tambahAnak(root, 2);
    tambahAnak(root, 3);
    tambahAnak(root, 4);

    tambahAnak(root->children[0], 5);
    tambahAnak(root->children[0], 6);

    tambahAnak(root->children[1], 7);

    cout << "Tree:" << endl;
    cetakTree(root);

    return 0;
}
