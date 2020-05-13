#include <iostream>
#include <vector>

using namespace std;

struct node
{
  int data;
  node *right;
  node *left;
};

class BinarySearchTree
{
private:
  node *root;

public:
  BinarySearchTree(/* args */);
  ~BinarySearchTree();

  void addNode(int item);
  void deleteNode(node *, int);
  void printNode();
  int searchNode(node *, int value, node *);
  void initializeSearch(int value);
  void inOrderTraversalWithoutrecursion();
  void inOrderTraversal(node *);
  void preOrderTraversal(node *);
  void postOrderTraversal(node *);
  void initializeDelete(int);
  int inOrderSuccessor(node *root);
};

int main()
{
  BinarySearchTree newTree;
  newTree.printNode();
  newTree.addNode(15);
  newTree.addNode(8);
  newTree.addNode(6);
  newTree.addNode(9);
  newTree.addNode(5);
  newTree.addNode(14);
  newTree.addNode(24);
  newTree.addNode(18);
  newTree.addNode(20);
  newTree.addNode(32);
  newTree.addNode(1);
  newTree.printNode();
  newTree.initializeSearch(24);
  newTree.inOrderTraversalWithoutrecursion();
  newTree.initializeDelete(5);
  newTree.initializeDelete(15);
  newTree.printNode();

  return 0;
}

BinarySearchTree::BinarySearchTree(/* args */)
{
  root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::addNode(int item)
{
  node *newNode = new node();
  newNode->data = item;
  newNode->left = NULL;
  newNode->right = NULL;
  if (!root)
  {
    root = newNode;
  }
  else
  {
    node *tempNode = root;
    node *previousNode = NULL;
    int flag = -1;
    while (tempNode != NULL)
    {
      if (item < (tempNode->data))
      {
        flag = 0;
        previousNode = tempNode;
        tempNode = tempNode->left;
      }
      else
      {
        flag = 1;
        previousNode = tempNode;
        tempNode = tempNode->right;
      }
    }
    flag ? previousNode->right = newNode : previousNode->left = newNode;
    tempNode = flag ? previousNode->right : previousNode->left;
  }
}

void BinarySearchTree::deleteNode(node *temp, int value)
{
  if (temp == NULL)
    return;
  else if (temp->data > value)
    deleteNode(temp->left, value);
  else if (temp->data < value)
    deleteNode(temp->right, value);
  else
  {
    if (temp->right == NULL && temp->left == NULL)
    {
      delete (temp);
    }
    else if (temp->left == NULL)
    {
      temp->data = temp->right->data;
      temp->right = NULL;
    }
    else if (temp->right == NULL)
    {
      temp->data = temp->left->data;
      temp->left = NULL;
      return;
    }
    else
    {
      temp->data = inOrderSuccessor(temp->right);
    }
  }
}

void BinarySearchTree::initializeDelete(int value)
{
  deleteNode(root, value);
}

void BinarySearchTree::initializeSearch(int value)
{
  int found = searchNode(root, value, NULL);
  if (found > 0)
  {
    cout << "found parent " << found << endl;
  }
}

int BinarySearchTree::searchNode(node *temp, int value, node *parent)
{
  if (temp == NULL)
  {
    return -1;
  }
  if (temp->data == value)
  {
    if (temp != root)
    {
      return parent->data;
    }
    return 1;
  }
  parent = temp;
  return temp->data > value ? searchNode(temp->left, value, parent) : searchNode(temp->right, value, parent);
}

void BinarySearchTree::printNode()
{
  inOrderTraversal(root);
  cout << endl;
  preOrderTraversal(root);
  cout << endl;
}

void BinarySearchTree::inOrderTraversal(node *temp)
{
  if (temp == NULL)
  {
    return;
  }

  inOrderTraversal(temp->left);

  cout << temp->data << " ";

  inOrderTraversal(temp->right);
}

void BinarySearchTree::inOrderTraversalWithoutrecursion()
{
  if (root == NULL)
  {
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
      cout << temp->data << " ";
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
  cout << endl;
}
void BinarySearchTree::postOrderTraversal(node *temp)
{
  if (temp == NULL)
  {
    return;
  }
  postOrderTraversal(temp->right);

  postOrderTraversal(temp->left);
  cout << temp->data << " ";
}

void BinarySearchTree::preOrderTraversal(node *temp)
{
  if (temp == NULL)
  {
    return;
  }

  cout << temp->data << " ";
  preOrderTraversal(temp->left);
  preOrderTraversal(temp->right);
}

int BinarySearchTree::inOrderSuccessor(node *root)
{
  int minimum = root->data;
  node *parent = NULL;
  while (root->left != NULL)
  {
    minimum = root->left->data;
    parent = root;
    root = root->left;
  }
  parent->left = NULL;
  return minimum;
}
