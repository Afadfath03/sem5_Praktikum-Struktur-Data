#include "singelist.cpp"

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    std::cout << std::endl;

    address P = findElm(L, 8);

    if (P != NULL) {
        std::cout << P->info << " Ditemukan dalam list" << std::endl;
    } else {
        std::cout << P->info << " tidak ditemukan" << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "Total info dari kelima elemen adalah " 
            << totalElm(L) 
            << std::endl;

    return 0;
}