#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;

  node(int item)
  {
    data = item;
    left = right = NULL;
  }
};

class Tree
{
  node *root;

public:
  Tree()
  {
    root = NULL;
  }
  void printTree();
  void inOrder(node *);
  void preOrder(node *);
  void postOrder(node *);
  void insert(int item);
};

int main()
{
  Tree obj;
  obj.insert(1);
  obj.insert(2);
  obj.printTree();

  obj.insert(3);
  obj.printTree();

  obj.insert(4);
  obj.insert(5);
  obj.insert(6);
  obj.insert(7);
  obj.insert(8);
  obj.insert(9);
  obj.printTree();

  return 0;
}

void Tree::insert(int item)
{
  cout << item << endl;
  node *newNode = new node(item);
  if (!root)
  {
    root = newNode;
    return;
  }
  node *temp = root;
  queue<node *> q;
  q.push(temp);
  while (!q.empty())
  {
    temp = q.front();
    q.pop();
    if (!temp->left)
    {
      temp->left = newNode;
      break;
    }

    if (!temp->right)
    {
      temp->right = newNode;
      break;
    }

    if (temp->left)
    {
      q.push(temp->left);
    }

    if (temp->right)
    {
      q.push(temp->right);
    }
  }
}

void Tree::inOrder(node *temp)
{
  if (temp == NULL)
  {
    return;
  }
  inOrder(temp->left);
  cout << temp->data << " ";
  inOrder(temp->right);
}

void Tree::preOrder(node *temp)
{
  if (temp == NULL)
  {
    return;
  }
  cout << temp->data << " ";
  preOrder(temp->left);
  preOrder(temp->right);
}

void Tree::postOrder(node *temp)
{
  if (temp == NULL)
  {
    return;
  }
  postOrder(temp->left);
  postOrder(temp->right);
  cout << temp->data << " ";
}

void Tree::printTree()
{
  inOrder(root);
  cout << endl;
  preOrder(root);
  cout << endl;
  postOrder(root);
  cout << endl;
}