#include <bits/stdc++.h>

using namespace std;

class LinkedList
{
  int data;
  LinkedList *node;

public:
  LinkedList(int, LinkedList *);
  void insertAtHead(int);
  void insertAtEnd(int);
  void deleteFromHead();
  void deleteFromEnd();

  void display();
};

int main()
{
  LinkedList *head = new LinkedList(0, NULL);
  head->insertAtHead(1);
  head->insertAtHead(2);
  head->insertAtHead(3);
  head->insertAtHead(4);
  head->insertAtEnd(5);
  head->insertAtEnd(6);
  head->deleteFromHead();
  head->deleteFromEnd();
  head->display();
  return 0;
}

void LinkedList::insertAtHead(int item)
{
  LinkedList *newNode = new LinkedList(item, NULL);
  newNode->node = this->node;
  this->node = newNode;
}
void LinkedList::insertAtEnd(int item)
{
  LinkedList *newNode = new LinkedList(item, NULL);
  LinkedList *tempNode = this;
  while (tempNode->node != NULL)
  {
    tempNode = tempNode->node;
  }
  tempNode->node = newNode;
}

void LinkedList::deleteFromHead()
{
  LinkedList *temp = new LinkedList((this->node)->data, this->node);
  this->node = (this->node)->node;
}
void LinkedList::deleteFromEnd()
{
  LinkedList *tempNode = this;
  while ((tempNode->node)->node != NULL)
  {
    tempNode = tempNode->node;
  }
  LinkedList *temp = new LinkedList((tempNode->node)->data, tempNode->node);
  tempNode->node = NULL;
}

void LinkedList::display()
{
  LinkedList *newNode = this->node;
  while (newNode != NULL)
  {
    cout << newNode->data << endl;
    newNode = newNode->node;
  }
}

LinkedList::LinkedList(int data, LinkedList *addr)
{
  this->data = data;
  node = addr;
}