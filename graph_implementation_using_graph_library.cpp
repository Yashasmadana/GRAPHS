#include "GRAPH_library.h"

int main()
{
    Graph g;
    g.dir_addEdge(0, 4);
    g.dir_addEdge(0, 3);
    g.dir_addEdge(1, 2);
    g.dir_addEdge(4, 1);
    g.dir_addEdge(4, 3);
    g.dir_addEdge(3, 5);
    g.dir_addEdge(0, 6);
    // Function call
    g.BFS(4);

    return 0;
}
