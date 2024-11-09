#include <iostream>
#define MAX 100

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }
    
    bool isFull() { return top == MAX - 1; }

    bool isEmpty() { return top == -1; }

    void push(int x){
        if (isFull())
        {
            std::cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        std::cout << "Stack is empty\n";
        return -1; // Return a sentinel value
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Stack elements: ";
    s.display();
    std::cout << "Top element: " << s.peek() << "\n";
    s.pop();
    std::cout << "After popping, stack elements: ";
    s.display();
    return 0;
}
