#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int v, int u)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (auto j : adj[i])
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

int main()
{
  int V = 5;
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 4);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  printGraph(adj, V);
  return 0;
}