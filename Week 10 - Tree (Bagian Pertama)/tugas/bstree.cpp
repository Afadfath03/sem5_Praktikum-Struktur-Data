#include <iostream>
#include "bstree.h"

using namespace std;

address alokasi(infotype x) {
    address NodeBaru = new Node;
    NodeBaru->info = x;
    NodeBaru->left = nullptr;
    NodeBaru->right = nullptr;
    return NodeBaru;
}

void insertNode(address &root, infotype x) {
    if (root == nullptr) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    } else {
        return; // x == root->info
    }
}

address findNode(infotype x, address root) {
    if (root == nullptr || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != nullptr) {
        printInorder(root->left);
        std::cout << root->info << " - ";
        printInorder(root->right);
    }
}

int hitungJumlahNode(address root){
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root){
    if (root == nullptr) {
        return 0;
    } else {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

int hitungKedalaman(address root, int start) {
    if (root == nullptr) {
        return start;
    } else {
        int Kiri = hitungKedalaman(root->left, start + 1);
        int Kanan = hitungKedalaman(root->right, start + 1);
        return max(Kiri, Kanan);
    }
}