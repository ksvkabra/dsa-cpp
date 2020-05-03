#include <bits/stdc++.h>

using namespace std;

class LinkedList
{
  int data;
  LinkedList *node;

public:
  LinkedList(int, LinkedList *);
  void push(int item);
  void pop();
  void display();
};

int main()
{
  LinkedList *head = new LinkedList(0, NULL);
  head->push(1);
  head->display();
  head->push(2);
  head->display();
  head->push(3);
  head->display();
  head->push(4);
  head->display();
  head->pop();
  head->display();
  return 0;
}

void LinkedList::push(int item)
{
  LinkedList *newNode = new LinkedList(item, NULL);
  newNode->node = this->node;
  this->node = newNode;
}

void LinkedList::pop()
{
  this->node = (this->node)->node;
}

void LinkedList::display()
{
  LinkedList *tempNode = this->node;
  while (tempNode != NULL)
  {
    cout << tempNode->data;
    tempNode = tempNode->node;
    cout << endl;
  }
}
LinkedList::LinkedList(int item, LinkedList *node)
{
  this->node = node;
  this->data = item;
}