#include <iostream> 
#include <conio.h> 
#include <stdlib.h> 
#include "mahasiswa.cpp"

using namespace std; 

int main() 
{ 
  mahasiswa mhs; 
  inputMhs(mhs); 
  cout << "rata-rata = " << rata2(mhs); 
  return 1;
} 