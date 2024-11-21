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
            std::cout << "Stack sudah Penuh\n";
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if (isEmpty()){
            std::cout << "Stack Kosong\n";
            return;
        }
        top--;
    }

    void peek() {
        if (isEmpty()) {
            std::cout << "Stack kosong\n";
            return;
        }

        std::cout << arr[top] << "\n";
    }

    void display(){
        if (isEmpty()){
            std::cout << "Stack kosong\n";
            return;
        }

        for (int i = top; i >= 0; i--){
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
    
    std::cout << "Element: "; 
    s.display();
    std::cout << "Element (Top): ";
    s.peek();

    // std::cout << "Element (Sebelum Pop): "; 
    // s.display();
    // s.pop();
    // std::cout << "Elemen (Setelah Pop): "; 
    // s.display();
    return 0;
}
