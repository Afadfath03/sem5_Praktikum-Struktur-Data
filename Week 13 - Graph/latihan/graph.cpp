#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

void CreateGraph(Graph &G) {
    G.first = nullptr;
}

void InsertNode(Graph &G, char info) {
    adrNode newNode = new ElmNode;
    newNode->info = info;
    newNode->next = G.first;
    newNode->firstEdge = nullptr;
    G.first = newNode;
}

adrNode FindNode(Graph G, char info) {
    adrNode currentNode = G.first;
    while (currentNode != nullptr) {
        if (currentNode->info == info) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return nullptr;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge newEdge = new ElmEdge;
    newEdge->node = N;
    newEdge->next = nullptr;
    return newEdge;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge newEdge1 = AllocateEdge(N2);
    newEdge1->next = N1->firstEdge;
    N1->firstEdge = newEdge1;

    adrEdge newEdge2 = AllocateEdge(N1);
    newEdge2->next = N2->firstEdge;
    N2->firstEdge = newEdge2;
}

void PrintInfoGraph(Graph G) {
    adrNode currentNode = G.first;
    while (currentNode != nullptr) {
        cout << "Node " << currentNode->info << ": ";
        adrEdge currentEdge = currentNode->firstEdge;
        while (currentEdge != nullptr) {
            cout << currentEdge->node->info << " ";
            currentEdge = currentEdge->next;
        }
        cout << endl;
        currentNode = currentNode->next;
    }
}

void PrintBFS(Graph &G, adrNode start) {
    if (start == nullptr) return;

    queue<adrNode> q;
    unordered_set<adrNode> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        adrNode currentNode = q.front();
        q.pop();
        cout << currentNode->info << " ";

        adrEdge currentEdge = currentNode->firstEdge;
        while (currentEdge != nullptr) {
            if (visited.find(currentEdge->node) == visited.end()) {
                q.push(currentEdge->node);
                visited.insert(currentEdge->node);
            }
            currentEdge = currentEdge->next;
        }
    }
    cout << endl;
}

void PrintDFS(Graph &G, adrNode start) {
    if (start == nullptr) return;

    stack<adrNode> s;
    unordered_set<adrNode> visited;

    s.push(start);

    while (!s.empty()) {
        adrNode currentNode = s.top();
        s.pop();

        if (visited.find(currentNode) == visited.end()) {
            cout << currentNode->info << " ";
            visited.insert(currentNode);

            adrEdge currentEdge = currentNode->firstEdge;
            while (currentEdge != nullptr) {
                if (visited.find(currentEdge->node) == visited.end()) {
                    s.push(currentEdge->node);
                }
                currentEdge = currentEdge->next;
            }
        }
    }
    cout << endl;
}