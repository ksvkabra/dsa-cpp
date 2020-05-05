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
  void deleteNode(node *);
  void printNode();
  void inOrderTraversal(node *);
  void preOrderTraversal(node *);
  void postOrderTraversal(node *);
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

void BinarySearchTree::deleteNode(node *temp)
{
}

void BinarySearchTree::printNode()
{
  inOrderTraversal(root);
}

void BinarySearchTree::inOrderTraversal(node *temp)
{
  if (temp == NULL)
  {
    return;
  }

  inOrderTraversal(temp->left);

  cout << temp->data << " " << endl;

  inOrderTraversal(temp->right);
}

void BinarySearchTree::postOrderTraversal(node *temp)
{
}

void BinarySearchTree::preOrderTraversal(node *temp)
{
}