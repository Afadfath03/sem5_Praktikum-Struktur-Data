#include "graph.cpp"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(C, D);

    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    PrintDFS(G, A);

    cout << "\nBFS dari A: ";
    PrintBFS(G, A);

    return 0;
}
