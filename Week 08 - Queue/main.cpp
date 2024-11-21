#include <iostream>
#define MAX 5

using namespace std;

class Queue {
private:
    int items[MAX];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh! Tidak bisa menambah elemen.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        items[rear] = value;
        cout << "Ditambahkan: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong! Tidak ada elemen untuk dihapus.\n";
            return -1;
        }
        int data = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return data;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return;
        }
        cout << "Isi Queue: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Dihapus: " << q.dequeue() << endl;
    cout << "Dihapus: " << q.dequeue() << endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
