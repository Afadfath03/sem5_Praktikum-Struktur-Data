#include <iostream>
 
using namespace std;
 
// Definisi struktur node
struct Node {
    int data;
    Node* next;
};
 
// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
 
// Fungsi untuk menyisipkan node setelah node tertentu
void insertAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be NULL." << endl;
        return;
    }
    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
 
// Fungsi untuk menghapus node setelah node tertentu
void deleteAfter(Node* prevNode) {
    if (prevNode == nullptr || prevNode->next == nullptr) {
        cout << "The given previous node is not valid or has no next node." << endl;
        return;
    }
    Node* temp = prevNode->next;
    prevNode->next = temp->next;
    delete temp;
}
 
// Fungsi untuk memperbarui data node setelah node tertentu
void updateAfter(Node* prevNode, int newData) {
    if (prevNode == nullptr || prevNode->next == nullptr) {
        cout << "The given previous node is not valid or has no next node." << endl;
        return;
    }
    prevNode->next->data = newData;
}
 
// Fungsi untuk melakukan pencarian node
Node* search(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
 
// Fungsi untuk menampilkan linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
 
int main() {
    // Membuat linked list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
 
    cout << "Linked List: ";
    printList(head);
 
    // Mencari node dengan nilai tertentu
    int key = 2;
    Node* foundNode = search(head, key);
    if (foundNode) {
        cout << "Node dengan nilai " << key << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << key << " tidak ditemukan." << endl;
    }
 
    // Menyisipkan node setelah node dengan nilai 2
    insertAfter(foundNode, 4);
    cout << "Setelah menyisipkan 4 setelah node dengan nilai 2: ";
    printList(head);
 
    // Memperbarui node setelah node dengan nilai 2
    updateAfter(foundNode, 5);
    cout << "Setelah memperbarui node setelah 2 menjadi 5: ";
    printList(head);
 
    // Menghapus node setelah node dengan nilai 2
    deleteAfter(foundNode);
    cout << "Setelah menghapus node setelah 2: ";
    printList(head);
 
    return 0;
}