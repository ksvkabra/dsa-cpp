#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

class BinaryTree
{
private:
  int treeHeight;
  node *root;
  node *last;
  int numberOfNodes;

public:
  BinaryTree(/* args */);
  ~BinaryTree();

public:
  void insert(int);
  void preOrderTraversal();
  void inOrderTraversal(node *);
  void postOrderTraversal();
  void printTree();
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
  obj.printTree();
  return 0;
}

BinaryTree::BinaryTree(/* args */)
{
  root = NULL;
  last = NULL;
  treeHeight = 0;
  numberOfNodes = 0;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::printTree()
{
  cout << "elements";
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

  cout << temp << " " << temp->data << endl;

  inOrderTraversal(temp->right);
}

void BinaryTree::insert(int item)
{
  node *newNode = new node();
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  if (root == NULL)
  {
    root = newNode;
    numberOfNodes++;
    treeHeight = ceil(sqrt(numberOfNodes));
    return;
  }
  node *temp = root;
  node *parent = NULL;
  vector<node *> stackOfNodes;
  stackOfNodes.push_back(temp);
  int countStackSize = 1;
  temp = temp->left;
  while (temp != NULL || stackOfNodes.size() > 0)
  {
    if (temp == NULL)
    {
      temp = stackOfNodes[countStackSize - 1];
      stackOfNodes.pop_back();
      countStackSize--;
      parent = temp;
      temp = temp->right;
    }
    else
    {
      stackOfNodes.push_back(temp);
      countStackSize++;
      parent = temp;
      temp = temp->left;
    }
  }
  cout << sqrt(numberOfNodes) << " " << treeHeight << "- item = " << item << endl;
  if (sqrt(numberOfNodes) == treeHeight)
  {
    cout << "enter" << endl;
    temp = root;
    parent = NULL;
    while (temp != NULL)
    {
      parent = temp;
      temp = temp->left;
    }
  }
  if (parent->left != NULL)
  {
    parent->right = newNode;
  }
  else
  {
    parent->left = newNode;
  }
  numberOfNodes++;
  treeHeight = ceil(sqrt(numberOfNodes));
}