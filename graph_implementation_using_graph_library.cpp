#include "GRAPH_library.h"

int main()
{
    Graph g;

    // directed graph
    g.dir_addEdge(0, 4);
    g.dir_addEdge(0, 3);
    g.dir_addEdge(1, 2);
    g.dir_addEdge(4, 1);
    g.dir_addEdge(4, 3);
    g.dir_addEdge(3, 5);
    g.dir_addEdge(0, 6);
    // Undirected graph
    g.addEdge(0, 4);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(3, 5);
    g.addEdge(0, 6);

    // implementing BFS with the starting node here(4);
    g.BFS(4);
    //implementing BFS with the starting node here(0);
    g.DFS(0);
    g.topologicalSort(0);
    return 0;
}
