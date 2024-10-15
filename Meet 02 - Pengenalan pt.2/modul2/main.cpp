#include <iostream>
using namespace std;

void Substract(int a, int b){
    cout << "Substract: " << a - b << endl;
}

int main()
{
    cout << "Input 2 number: ";
    int a, b;
    cin >> a >> b;

    Substract(a, b);
    return 0;
}

    /* Array
    int nilaiMahasiswa[3] = {80, 90, 100};

    cout << "Nilai mahasiswa index 0: " << nilaiMahasiswa[0] << endl;
    cout << "Nilai mahasiswa index 1: " << nilaiMahasiswa[1] << endl;
    cout << "Nilai mahasiswa index 2: " << nilaiMahasiswa[2] << endl;
    */

    /* 2 Dimension
    int nilai[2][2] = {
        {100, 220},
        {380, 440}
        };

    cout << endl;
    cout << nilai[0][0] << " " << nilai[0][1] << endl;
    cout << nilai[1][0] << " " << nilai[1][1] << endl;
    cout << endl;
   */

    /* x Dimension
    int nilai[3][2][2] ={
        {
            {100, 200},
            {300, 400}
        },
        {
            {500, 600},
            {700, 800}
        },
        {
            {900, 1000},
            {1100, 1200}
        }

    };

    cout << endl;
    cout << nilai[0][0][0] << " " << nilai[0][0][1] << " " << nilai[0][0][2] << endl;
    cout << nilai[0][1][0] << " " << nilai[0][1][1] << " " << nilai[0][1][2] << endl;
    cout << nilai[0][2][0] << " " << nilai[0][2][1] << " " << nilai[0][2][2] << endl;
    cout << endl;
  */
    
    /* POINTER
    int a = 10;
    int *b = &a;

    cout << "Nilai a    : " << a << endl;
    cout << "Alamat a   : " << &a << endl;
    cout << "Nilai b    : " << *b << endl;
    cout << "Alamat b   : " << b << endl;
     */