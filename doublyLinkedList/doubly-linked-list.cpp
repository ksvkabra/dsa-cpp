/*
Reference - https://www.studytonight.com/data-structures/doubly-linked-list
*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  node *next;
  node *previous;
};

class DoublyLinkedList
{
  node *front;
  node *end;

public:
  DoublyLinkedList();
  void addFront(int);
  void addBack(int);
  void addAfter(node *, int);
  void addBefore(node *, int);
  void deleteNode(node *);
  void forwardTraverse();
  void backwardTraverse();
};

int main()
{
  DoublyLinkedList list;
  list.addFront(1);
  list.addFront(2);
  list.addFront(3);
  list.addBack(4);
  list.addBack(5);
  list.addBack(6);
  list.forwardTraverse();
  list.backwardTraverse();
  return 0;
}

void DoublyLinkedList::addFront(int item)
{
  node *newNode = new node();
  newNode->data = item;
  newNode->previous = NULL;
  newNode->next = front;
  if (front == NULL)
  {
    end = newNode;
  }
  else
  {
    front->previous = newNode;
  }
  front = newNode;
}
void DoublyLinkedList::addBack(int item)
{
  node *newNode = new node();
  newNode->data = item;
  newNode->previous = end;
  newNode->next = NULL;

  if (end == NULL)
  {
    front = newNode;
  }
  else
  {
    end->next = newNode;
  }
  end = newNode;
}
void DoublyLinkedList::addAfter(node *after, int item)
{
  node *temp = new node();
  temp->data = item;
  temp->next = after->next;
  temp->previous = after;
  after->next = temp;

  if (after->next == NULL)
  {
    end = temp;
  }
}
void DoublyLinkedList::addBefore(node *before, int item)
{
  node *temp = new node();
  temp->next = before;
  temp->previous = before->previous;
  temp->data = item;
  before->previous = temp;

  if (before->previous == NULL)
  {
    front = temp;
  }
}
void DoublyLinkedList::deleteNode(node *deleteNodeData)
{
  if (deleteNodeData->previous == NULL)
  {
    front = deleteNodeData->next;
    front->previous = NULL;
  }
  else if (deleteNodeData->next == NULL)
  {
    end = deleteNodeData->previous;
    end->next = NULL;
  }
  else
  {
    deleteNodeData->next->previous = deleteNodeData->previous;
    deleteNodeData->previous->next = deleteNodeData->next;
  }
}
void DoublyLinkedList::backwardTraverse()
{
  cout << "Elements of the list" << endl;
  node *tempNode = end;
  while (tempNode != NULL)
  {
    cout << tempNode->data << endl;
    tempNode = tempNode->previous;
  }
}
void DoublyLinkedList::forwardTraverse()
{
  cout << "Elements of the list" << endl;
  node *tempNode = front;
  while (tempNode != NULL)
  {
    cout << tempNode->data << endl;
    tempNode = tempNode->next;
  }
}
DoublyLinkedList::DoublyLinkedList()
{
  front = NULL;
  end = NULL;
}