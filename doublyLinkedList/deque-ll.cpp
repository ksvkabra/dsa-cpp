#include <bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  node *next;
  node *previous;
};

class Dequeue
{
  node *front;
  node *rear;
  int lengthOfList;

public:
  Dequeue()
  {
    front = NULL;
    rear = NULL;
    lengthOfList = 0;
  }
  void insertFront(int item);
  void insertEnd(int item);

  void deleteFront();
  void deleteEnd();

  int getFront();
  int getEnd();
  void traverseFront();
  void traverseBackward();

  int getSize();
  int isEmpty();
  void erase();
};

int main()
{
  Dequeue elements;
  elements.insertFront(1);
  elements.insertFront(2);
  elements.insertFront(3);
  elements.insertEnd(4);
  elements.insertEnd(5);
  elements.insertEnd(6);
  elements.traverseFront();
  cout << "size - " << elements.getSize() << endl;
  cout << "front - " << elements.getFront() << endl;
  cout << "rear - " << elements.getEnd() << endl;
  elements.deleteEnd();
  elements.deleteEnd();
  elements.deleteFront();
  elements.traverseFront();
  elements.traverseBackward();
  cout << "size - " << elements.getSize() << endl;
  elements.erase();
  elements.traverseBackward();
  return 0;
}

void Dequeue::insertFront(int item)
{
  node *newNode = new node();
  newNode->data = item;
  newNode->previous = NULL;
  newNode->next = front;

  if (front == NULL)
  {
    rear = newNode;
  }
  else
  {
    front->previous = newNode;
  }
  front = newNode;
  lengthOfList++;
}

void Dequeue::insertEnd(int item)
{
  node *newNode = new node();
  newNode->data = item;
  newNode->previous = rear;
  newNode->next = NULL;
  if (rear == NULL)
  {
    front = newNode;
  }
  else
  {
    rear->next = newNode;
  }
  rear = newNode;
  lengthOfList++;
}

void Dequeue::deleteFront()
{
  if (!isEmpty())
  {
    node *tempNode = front;
    front = front->next;
    if (front == NULL)
    {
      rear = NULL;
    }
    else
    {
      front->previous = NULL;
    }
    delete tempNode;
    lengthOfList--;
  }
  else
  {
    cout << "Underflow" << endl;
  }
}

void Dequeue::deleteEnd()
{
  if (!isEmpty())
  {
    node *tempNode = rear;
    rear = rear->previous;
    if (rear == NULL)
    {
      front = NULL;
    }
    else
    {
      rear->next = NULL;
    }
    delete tempNode;
    lengthOfList--;
  }
  else
  {
    cout << "Underflow" << endl;
  }
}

int Dequeue::getFront()
{
  if (isEmpty())
  {
    return -1;
  }
  return front->data;
}

int Dequeue::getEnd()
{
  if (isEmpty())
  {
    return -1;
  }
  return rear->data;
}

void Dequeue::traverseFront()
{
  if (isEmpty())
  {
    cout << "underflow";
  }
  else
  {
    node *tempNode = front;
    cout << "Elements of list"
         << " --- ";
    while (tempNode != NULL)
    {
      cout << tempNode->data << " ";
      tempNode = tempNode->next;
    }
  }

  cout << endl;
}

void Dequeue::traverseBackward()
{
  if (isEmpty())
  {
    cout << "Underflow";
  }
  else
  {
    node *tempNode = rear;
    cout << "Elements of list"
         << " --- ";

    while (tempNode != NULL)
    {
      cout << tempNode->data << " ";
      tempNode = tempNode->previous;
    }
  }

  cout << endl;
}

int Dequeue::getSize()
{
  return lengthOfList;
}

int Dequeue::isEmpty()
{
  return front == NULL;
}

void Dequeue::erase()
{
  rear = NULL;
  while (front != NULL)
  {
    node *tempNode = front;
    front = front->next;
    delete tempNode;
  }
  lengthOfList = 0;
}