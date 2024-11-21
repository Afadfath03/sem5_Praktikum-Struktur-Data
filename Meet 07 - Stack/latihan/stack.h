#ifndef STACK_H
#define STACK_H

const int MAX = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void CreateStack(Stack &S);

void push(Stack &S, infotype x);

infotype pop(Stack &S);

void printInfo(const Stack &S);

void balikStack(Stack &S);

void pushAscending(Stack &S, int x);

void getInputStream(Stack &S);

#endif // STACK_H