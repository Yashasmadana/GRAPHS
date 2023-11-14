#ifndef GRAPH_H
#define GRAPH_H
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    queue<int> q;

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    void BFS(int v);

    void dir_addEdge(int v, int w);
};

void Graph::BFS(int v)
{

    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << "->";
        list<int>::iterator itr;
        for (itr = adj[node].begin(); itr != adj[node].end(); itr++)
        {
            if (!visited[*itr])
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
    }
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::dir_addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
    // adj[w].push_back(v);
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << "->";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
#endif