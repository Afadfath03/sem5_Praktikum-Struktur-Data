#include <iostream>
#include <vector>
using namespace std;
 
// Kelas untuk merepresentasikan graf
class Graph {
private:
    int vertices;                       // Jumlah simpul (vertices)
    vector<vector<int>> adjList;        // Adjacency list
 
public:
    // Konstruktor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }
 
    // Menambahkan edge ke graf (graf tak berarah)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Hapus ini jika graf berarah
    }
 
    // Menampilkan graf
    void displayGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};
 
int main() {
    // Membuat graf dengan 5 simpul
    Graph g(5);
 
    // Menambahkan sisi
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
 
    // Menampilkan adjacency list
    cout << "Adjacency List Representation of the Graph:" << endl;
    g.displayGraph();
 
    return 0;
}