#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() {
        head = nullptr;
    }

    // 1A. Insert First
    void insertFirst(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // 1B. Insert Last
    void insertLast(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // 1C. Insert After
    void insertAfter(int key, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    // 1D. Insert Before
    void insertBefore(int key, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node* newNode = new Node(data);
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = newNode;
            } else {
                head = newNode;
            }
            temp->prev = newNode;
        }
    }

    // 2A. Delete First
    void deleteFirst() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
    }

    // 2B. Delete Last
    void deleteLast() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    // 2C. Delete After
    void deleteAfter(int key) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr) {
            Node* delNode = temp->next;
            temp->next = delNode->next;
            if (delNode->next != nullptr) {
                delNode->next->prev = temp;
            }
            delete delNode;
        }
    }

    // 2D. Delete Before
    void deleteBefore(int key) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp != nullptr && temp->prev != nullptr) {
            Node* delNode = temp->prev;
            if (delNode->prev != nullptr) {
                delNode->prev->next = temp;
            } else {
                head = temp;
            }
            temp->prev = delNode->prev;
            delete delNode;
        }
    }

    // Update node data
    void update(int oldData, int newData) {
        Node* temp = head;
        while (temp != nullptr && temp->data != oldData) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->data = newData;
        }
    }

    // Search node
    Node* search(int key) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        return temp;
    }

    // View list
    void view() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoubleLinkedList dll;

    // Testing the functions
    dll.insertFirst(10);
    dll.insertLast(20);
    dll.insertAfter(10, 15);
    dll.insertBefore(20, 18);

    cout << "List after insertions: ";
    dll.view();

    dll.deleteFirst();
    cout << "List after deleting first: ";
    dll.view();

    dll.deleteLast();
    cout << "List after deleting last: ";
    dll.view();

    dll.deleteAfter(10);
    cout << "List after deleting after 10: ";
    dll.view();

    dll.deleteBefore(18);
    cout << "List after deleting before 18: ";
    dll.view();

    dll.update(18, 25);
    cout << "List after updating 18 to 25: ";
    dll.view();

    Node* found = dll.search(25);
    if (found != nullptr) {
        cout << "Node with data 25 found." << endl;
    } else {
        cout << "Node with data 25 not found." << endl;
    }

    return 0;
}