#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num;
    cout << "Masukkan bilangan : ";
    cin >> num;

    if (num < 0) {
        cout << "Faktorial tidak terdefinisi untuk bilangan negatif." << endl;
    } else {
        cout << "Rumus Faktorial: n! = n x (n-1) x (n-2) x ... x 1" << endl;
        cout << "Faktorial dari " << num << " adalah " << factorial(num) << endl;
    }

    return 0;
}