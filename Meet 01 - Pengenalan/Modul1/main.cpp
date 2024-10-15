#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    string hasil;
    cout << "Input: ";
    cin >> a;

    for (int i = a; i > 0; i--) {

        for (int j = 0; j < a - i; j++) {
            cout << "  ";
        }

        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}