#include <iostream>
using namespace std;

void cetakAngka(int n) {
    if (n == 0) {
        return;
    }
    cetakAngka(n - 1);
    cout << n << " ";
}

int main() {
    int N;
    cout << "Masukkan angka N: ";
    cin >> N;

    cout << "Angka dari 1 hingga " << N << ": ";
    cetakAngka(N);
    cout << endl;

    return 0;
}
