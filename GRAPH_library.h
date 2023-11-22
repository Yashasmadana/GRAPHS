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
    map<int, bool> topvisited; // for topological sorting im just making it separately so that i can use both topological sorting and dfs in same the program
    map<int, list<int>> adj;
    queue<int> q;
    stack<int> s; // for topological sorting

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    void BFS(int v);
// for topological sorting
void topologicalSort(int v);
void topdfs(int v, stack<int> &s);


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

void Graph::topologicalSort(int v)
{

    if (!topvisited[v])
    {
        topdfs(v, s);
    }
    while (!s.empty())
    {
        cout << s.top() << "->";
        s.pop();
    }
}

void Graph::topdfs(int v, stack<int> &s)
{
    // Mark the current node as visited and
    // print it
    topvisited[v] = true;
    
    for (int neighbour : adj[v])
    {
        if (!topvisited[neighbour])
        {
            topdfs(neighbour, s);
        }
    }

    s.push(v);
}
#endif
