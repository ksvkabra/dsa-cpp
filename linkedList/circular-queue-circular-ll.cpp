#include <iostream>
#include <vector>

using namespace std;

struct node
{
  int data;
  node *next;
};

class CircularQueue
{
  node *front;
  node *rear;
  int lengthOfList;

public:
  CircularQueue()
  {
    front = NULL;
    rear = NULL;
    lengthOfList = 0;
  }

  void enQueue(int);
  void deQueue();

  void traverseQueue();
  int sizeOfQueue();

  int isQueueEmpty();
};

int main()
{
  CircularQueue myQueue;
  myQueue.enQueue(1);
  myQueue.enQueue(2);
  myQueue.enQueue(3);
  myQueue.traverseQueue();
  myQueue.deQueue();
  myQueue.traverseQueue();
  myQueue.traverseQueue();
  cout << myQueue.sizeOfQueue() << endl;
  return 0;
}

void CircularQueue::enQueue(int item)
{
  node *newNode = new node();
  newNode->data = item;
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

void CircularQueue::deQueue()
{
  node *tempNode = front;
  if (isQueueEmpty())
  {
    cout << "Underflow";
  }
  else
  {
    front = front->next;
    delete tempNode;

    if (front == NULL)
    {
      rear = NULL;
    }
    lengthOfList--;
  }
}

int CircularQueue::isQueueEmpty()
{
  return front == NULL;
}

int CircularQueue::sizeOfQueue()
{
  return lengthOfList;
}

void CircularQueue::traverseQueue()
{
  node *tempNode = front;
  cout << "List items -- ";
  while (tempNode != NULL)
  {
    cout << tempNode->data << " ";
    tempNode = tempNode->next;
  }
  cout << endl;
}