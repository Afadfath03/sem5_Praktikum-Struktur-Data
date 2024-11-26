#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string data;
    vector<Node*> children;

    Node(string value) {
        data = value;
    }
};

void tambahAnak(Node* parent, string value) {
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
    Node* root = new Node("A");

    tambahAnak(root, "B");
    tambahAnak(root, "C");
    tambahAnak(root, "D");

    tambahAnak(root->children[0], "E");
    tambahAnak(root->children[0], "F");

    tambahAnak(root->children[1], "G");

    cout << "Tree:" << endl;
    cetakTree(root);

    return 0;
}
