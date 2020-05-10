#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct node
{
  int data;
  int index;
  list<node *> adjList;
  node()
  {
    data = 0;
    index = 0;
  }
};

class GraphList
{
  vector<node *> nodes;

public:
  void addEdge(int u, int v);
  void addNode(int data);
  void deleteEdge(int u, int v);
  void deleteNode(int nodeToDelete);
  void printNodes();
  void printEdges();
  void dfsRecursive(node *i, vector<bool> &visited);
  void dfsInitialization();
};

int main()
{
  GraphList graph;
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
  cout << endl;
  graph.dfsInitialization();
  return 0;
}

void GraphList::addNode(int data)
{
  node *newNode = new node();
  newNode->data = data;
  newNode->index = nodes.size();
  nodes.push_back(newNode);
}

void GraphList::addEdge(int u, int v)
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

    y->adjList.push_back(z);
  }
  z->adjList.push_back(y);
}

void GraphList::printNodes()
{
  cout << "nodes" << endl;
  for (node *x : nodes)
  {
    cout << x->data << " ";
  }
  cout << endl;
}

void GraphList::printEdges()
{
  cout << "edges" << endl;
  for (node *x : nodes)
  {
    for (node *y : x->adjList)
    {
      cout << x->data << "->" << y->data << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void GraphList::dfsInitialization()
{
  vector<bool> visited(nodes.size());
  visited[0] = 1;
  dfsRecursive(nodes[0], visited);
}

void GraphList::dfsRecursive(node *i, vector<bool> &visited)
{
  cout << i->data << " ";
  visited[i->index] = 1;
  for (node *j : i->adjList)
  {
    if (!visited[j->index])
    {
      dfsRecursive(j, visited);
    }
  }
}