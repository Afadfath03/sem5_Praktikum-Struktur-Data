#include <iostream>
#define MAX 5

using namespace std;

class Queue {
private:
    string items[MAX];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() const { return front == -1; }

    bool isFull() const { return (rear + 1) % MAX == front; }

    void enqueue(string value) {
        if (isFull()) {
            cout << "Antrian penuh\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        items[rear] = value;
        cout << "Tambah antrian: " << value << endl;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Antrian penuh\n";
            return "";
        }
        string data = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return data;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Antrian penuh\n";
            return;
        }
        cout << "Daftar Antrian: ";
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

    q.enqueue("Visas");
    q.enqueue("Kaleido");
    q.enqueue("Reich");
    q.enqueue("Rise");
    q.enqueue("Rium");
    q.enqueue("Veda");

    cout << endl;
    q.display();
    cout << endl;

    cout << "Telah dilayani : " << q.dequeue() << endl;
    cout << "Telah dilayani : " << q.dequeue() << endl;
    cout << "Telah dilayani : " << q.dequeue() << endl;
    cout << "Telah dilayani : " << q.dequeue() << endl;
    cout << "Telah dilayani : " << q.dequeue() << endl;

    cout << "Semua warga telah dilayani" << endl;

    return 0;
}
