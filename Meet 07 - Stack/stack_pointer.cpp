#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = nullptr; }
    
    bool isEmpty() { return top == nullptr; }
    bool isFull() { return false; }
    
    void push(int x){
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    void pop(){
        if (isEmpty())
        {
            std::cout << "Stack Underflow\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        std::cout << "Stack is empty\n";
        return -1;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty\n";
            return;
        }
        Node *current = top;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{
    Stack s;
    s.isFull();
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