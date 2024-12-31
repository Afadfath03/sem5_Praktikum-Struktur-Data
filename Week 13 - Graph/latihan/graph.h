#ifndef GRAPH_H
#define GRAPH_H

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct Graph {
    adrNode first;
};

struct ElmNode {
    char info;
    adrNode next;
    adrEdge firstEdge;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, char info);
adrNode FindNode(Graph G, char info);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintBFS(Graph &G, adrNode start);
void PrintDFS(Graph &G, adrNode start);


#endif