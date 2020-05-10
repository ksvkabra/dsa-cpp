#include <iostream>
#include <vector>
#include <list>
// undirected graph

using namespace std;

struct node
{
  int data;
  int index;
  vector<node *> adjacencyList;
};
class GraphAdjacencyList
{
  vector<node *> nodes;

public:
  void addEdge(int u, int v);
  void addNode(int data);
  void deleteEdge(int u, int v);
  void deleteNode(int nodeToDelete);
  void printNodes();
  void printEdges();
  void bfs();
};

int main()
{
  GraphAdjacencyList graph;
  graph.addNode(1);
  graph.addNode(2);
  graph.addNode(3);
  graph.addNode(4);
  // graph.addEdge(1, 2);
  graph.addEdge(2, 4);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(3, 2);
  graph.printEdges();
  graph.bfs();
  return 0;
}

void GraphAdjacencyList::addNode(int data)
{
  node *newNode = new node();
  newNode->data = data;
  newNode->index = nodes.size();
  nodes.push_back(newNode);
  printNodes();
}

void GraphAdjacencyList::addEdge(int u, int v)
{
  node *y;
  node *z;
  for (node *x : nodes)
  {
    if (x->data == u)
    {
      y = x;
    }
    if (x->data == v)
    {
      z = x;
    }
  }
  if (y != z)
  {

    y->adjacencyList.push_back(z);
  }
  z->adjacencyList.push_back(y);
}

void GraphAdjacencyList::printNodes()
{
  cout << "nodes" << endl;
  for (node *x : nodes)
  {
    cout << x->data << " ";
  }
  cout << endl;
}

void GraphAdjacencyList::printEdges()
{
  cout << "edges" << endl;
  for (node *x : nodes)
  {
    for (node *y : x->adjacencyList)
    {
      cout << x->data << "->" << y->data << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void GraphAdjacencyList::bfs()
{
  vector<bool> visited(nodes.size());
  list<node *> queue;

  queue.push_back(nodes[0]);
  visited[0] = 1;

  while (!queue.empty())
  {
    node *s = queue.front();
    queue.pop_front();
    cout << s->data;

    for (node *i : s->adjacencyList)
    {
      if (!visited[i->index])
      {
        queue.push_back(i);
        visited[i->index] = 1;
      }
    }
  }
}