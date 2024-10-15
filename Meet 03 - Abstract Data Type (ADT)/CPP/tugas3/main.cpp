#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Random generator
    srand(static_cast<unsigned int>(std::time(0)));

    int array1[3][3];
    int array2[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            array1[i][j] = rand() % 100;
            array2[i][j] = rand() % 100;
        }
    }

    int a, b;
    a = rand() % 100;
    b = rand() % 100;

    int* ptr1 = &a;
    int* ptr2 = &b;

    // Array
    cout << "Array Normal" << endl;
    
    cout << "\nArray 1:" << endl;
    tampilkanArray(array1);
    cout << "\nArray 2:" << endl;
    tampilkanArray(array2);

    tukarArray(array1, array2, 1, 1);
    cout << "\nArray setelah ditukar (Baris 2, kolom 2)" << endl;

    cout << "\nArray 1:" << endl;
    tampilkanArray(array1);
    cout << "\nArray 2:" << endl;
    tampilkanArray(array2);

    cout << endl;

    // Pointer
    cout << "Pointer sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Pointer setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}
