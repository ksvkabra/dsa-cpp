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
    left = NULL;
    right = NULL;
  }
};

class BinaryTree
{
private:
  node *root;

public:
  BinaryTree(/* args */);
  ~BinaryTree();

public:
  void insert(int);
  void preOrderTraversal();
  void inOrderTraversal(node *);
  void postOrderTraversal();
  void printTree();
  void deleteNode(int value);
  void deleteDeepest(node *);
};

int main()
{
  BinaryTree obj;
  obj.printTree();
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
  obj.deleteNode(4);
  obj.printTree();
  return 0;
}

BinaryTree::BinaryTree(/* args */)
{
  root = NULL;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::printTree()
{
  cout << "elements" << endl;
  inOrderTraversal(root);
  cout << endl;
}

void BinaryTree::inOrderTraversal(node *temp)
{
  if (temp == NULL)
  {
    return;
  }
  inOrderTraversal(temp->left);
  cout << temp->data << endl;
  inOrderTraversal(temp->right);
}

void BinaryTree::insert(int item)
{
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
      q.pop();
      break;
    }
    else
    {
      q.push(temp->left);
    }

    if (!temp->right)
    {
      temp->right = newNode;
      break;
    }
    else
    {
      q.push(temp->right);
    }
  }
}

void BinaryTree::deleteNode(int value)
{
  node *temp = root;
  queue<node *> q;
  q.push(temp);

  node *key_node = NULL;

  while (!q.empty())
  {
    temp = q.front();
    q.pop();

    if (temp->data == value)
    {
      key_node = temp;
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
  if (key_node)
  {
    int x = temp->data;
    deleteDeepest(temp);
    key_node->data = x;
  }
}

void BinaryTree::deleteDeepest(node *lastNode)
{
  queue<node *> q;
  node *temp = root;
  q.push(temp);
  while (!q.empty())
  {
    temp = q.front();
    q.pop();
    if (temp->right == lastNode)
    {
      temp->right = NULL;
      delete (lastNode);
      return;
    }

    if (temp->left == lastNode)
    {
      temp->left = NULL;
      delete (lastNode);
      return;
    }

    if (temp->right)
    {
      q.push(temp->right);
    }
    if (temp->left)
    {
      q.push(temp->left);
    }
  }
}