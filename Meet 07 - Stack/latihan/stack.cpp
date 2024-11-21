#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S){ S.top = -1; };

void push(Stack &S, infotype x){
    if (S.top == MAX - 1){ cout << "Stack sudah penuh\n"; return;}

    S.info[++S.top] = x;
};

infotype pop(Stack &S){
    if (S.top == -1){ cout << "Stack kosong\n"; return -1;}

    return S.info[S.top--];
};

void printInfo(const Stack &S){
    if (S.top == -1){ cout << "Stack kosong\n"; return;}

    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--){
        cout << S.info[i] << " ";
    }

    cout << "\n";
};

void balikStack(Stack &S) {
    if (S.top == -1) return;

    Stack temp;
    CreateStack(temp);

    while (S.top != -1) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    CreateStack(temp);

    while (S.top != -1 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char inputan;

    while (true) {
        inputan = cin.get();

        if (isdigit(inputan)) {
            if (S.top == MAX - 1) {
                cout << "Stack sudah penuh\n";
                break;
            }

            push(S, inputan - '0');
        }

        if (inputan == '\n') {
            break;
        }
    }
}