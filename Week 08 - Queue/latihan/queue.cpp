#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(const Queue &Q) {
    return Q.head == -1;
}

bool isFullQueue(const Queue &Q) {
    return (Q.tail + 1) % MAX_SIZE == Q.head;
}

void printInfo(const Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1  \t| Empty Queue" << endl;
        return;
    }

    int i = Q.head;
    cout << Q.head << " - " << Q.tail << "   \t| ";

    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Full Queue" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
    }
    Q.tail = (Q.tail + 1) % MAX_SIZE;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Empty Queue" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX_SIZE;
    }
    return x;
}

// No 1
// void enqueue1(Queue &Q, infotype x) {
//     if (isFullQueue(Q)) {
//         cout << "Full Queue" << endl;
//         return;
//     }
//     if (isEmptyQueue(Q)) {
//         Q.head = 0;
//     }
//     Q.tail++;
//     Q.info[Q.tail] = x;
// }

// infotype dequeue1(Queue &Q) {
//     if (isEmptyQueue(Q)) {
//         cout << "Empty Queue" << endl;
//         return -1;
//     }
//     infotype x = Q.info[Q.head];
//     for (int i = Q.head; i < Q.tail; i++) {
//         Q.info[i] = Q.info[i + 1];
//     }
//     Q.tail--;
//     if (Q.tail < Q.head) {
//         Q.head = -1;
//         Q.tail = -1;
//     }
//     return x;
// }

// No 2
// void enqueue2(Queue &Q, infotype x) {
//     if (isFullQueue(Q)) {
//         cout << "Full Queue" << endl;
//         return;
//     }
//     if (isEmptyQueue(Q)) {
//         Q.head = 0;
//     }
//     Q.tail = (Q.tail + 1) % MAX_SIZE;
//     Q.info[Q.tail] = x;
// }

// infotype dequeue2(Queue &Q) {
//     if (isEmptyQueue(Q)) {
//         cout << "Empty Queue" << endl;
//         return -1;
//     }
//     infotype x = Q.info[Q.head];
//     if (Q.head == Q.tail) {
//         Q.head = -1;
//         Q.tail = -1;
//     } else {
//         Q.head = (Q.head + 1) % MAX_SIZE;
//     }
//     return x;
// }

// No 3
// void enqueue3(Queue &Q, infotype x) {
//     if (isFullQueue(Q)) {
//         cout << "Full Queue" << endl;
//         return;
//     }
//     if (isEmptyQueue(Q)) {
//         Q.head = 0;
//     }
//     Q.tail = (Q.tail + 1) % MAX_SIZE;
//     Q.info[Q.tail] = x;
// }

// infotype dequeue3(Queue &Q) {
//     if (isEmptyQueue(Q)) {
//         cout << "Empty Queue" << endl;
//         return -1;
//     }
//     infotype x = Q.info[Q.head];
//     if (Q.head == Q.tail) {
//         Q.head = -1;
//         Q.tail = -1;
//     } else {
//         Q.head = (Q.head + 1) % MAX_SIZE;
//     }
//     return x;
// }