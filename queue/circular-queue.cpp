/*
  Circular queue
  condition
  1. insertion
  - check if array empty means rear and front are equal.
  - check if front and rear == -1 then increment both.
  - check if rear is less than max length of array and not check if front is greater then 0 and assign 0 to rear.
  - check if array has space to insert.

  2. deletion
  - check if array has elements i.e. front != rear.
  - check if front and rear are equal then put -1 to both front and rear.
  - check if front is less than max length if not then compare with rear, if rear is less that front then assign 0 to front.
*/

#include <bits/stdc++.h>

using namespace std;

class CircularQueue
{
  int front;
  int rear;
  int max;
  vector<int> arr;

public:
  CircularQueue(int);

  void insert(int);
  void dequeue();
  void printArray();
};

int main()
{
  CircularQueue que(5);
  que.insert(1);
  que.insert(2);
  que.insert(3);
  que.insert(4);
  que.insert(5);
  que.insert(6);
  que.dequeue();
  que.insert(7);
  que.dequeue();
  que.insert(8);
  que.dequeue();
  que.insert(1);
  que.dequeue();
  que.insert(9);
  que.dequeue();
  que.dequeue();
  que.dequeue();
  que.dequeue();
  que.dequeue();
  que.dequeue();
  que.insert(9);
  que.printArray();
}

void CircularQueue::insert(int item)
{
  if (front == rear && front == -1)
  {
    rear++;
    front++;
    arr[rear] = item;
  }
  else if (front == rear)
  {
    rear++;
    arr[rear] = item;
  }
  else if (rear == max && front != 0)
  {
    rear = 0;
    arr[rear] = item;
  }
  else if (rear + 1 == front || (rear == max && front == 0))
  {
    cout << "Overflow" << endl;
  }
  else
  {
    rear++;
    arr[rear] = item;
  }
}
void CircularQueue::dequeue()
{
  if (front == -1)
  {
    cout << "Underflow" << endl;
  }
  else if (front == rear)
  {
    arr[front] = 0;
    front = -1;
    rear = -1;
  }
  else if (front == max && rear != max)
  {
    arr[front] = 0;
    front = 0;
  }
  else
  {
    arr[front] = 0;
    front++;
  }
}
void CircularQueue::printArray()
{
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}
CircularQueue::CircularQueue(int item)
{
  max = item;
  front = -1;
  rear = -1;
  arr.resize(max + 1);
}