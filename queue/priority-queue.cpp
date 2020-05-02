#include <bits/stdc++.h>

using namespace std;

class PriorityQueue
{
  vector<int> data;
  vector<int> priority;
  int rear;

public:
  PriorityQueue(int length)
  {
    data.resize(length);
    priority.resize(length);
    rear = 0;
  }
  void insertItem(int item, int priority);
  int getHighestPriority();
  void deleteHighestPriority();
  void printData();
};

int main()
{
  PriorityQueue que(5);
  que.insertItem(1, 5);
  que.insertItem(2, 6);
  que.insertItem(3, 7);
  que.insertItem(1, 5);
  que.insertItem(2, 6);
  cout << que.getHighestPriority() << endl;

  que.printData();
  que.insertItem(3, 7);
  que.deleteHighestPriority();
  cout << que.getHighestPriority() << endl;
  que.deleteHighestPriority();
  que.deleteHighestPriority();
  que.insertItem(2, 6);
  que.insertItem(3, 7);
  que.insertItem(1, 5);
  que.insertItem(2, 6);
  que.deleteHighestPriority();
  cout << que.getHighestPriority() << endl;
  que.printData();
  return 0;
}

void PriorityQueue::insertItem(int item, int p)
{
  cout << rear << " " << data.size() << endl;
  if (rear > (data.size() - 1))
  {
    cout << "Overflow" << endl;
  }
  else
  {
    data[rear] = item;
    priority[rear] = p;
    rear++;
  }
}
void PriorityQueue::deleteHighestPriority()
{
  int max = -1;
  int index = -1;
  if (rear != -1)
  {
    for (int i = 0; i < rear; i++)
    {
      if (max < priority[i])
      {
        max = priority[i];
        index = i;
      }
    }
    for (int i = index; i < rear; i++)
    {
      data[i] = data[i + 1];
      priority[i] = priority[i + 1];
    }
    rear--;
  }
  else
  {
    cout << "UnderFlow" << endl;
  }
}
int PriorityQueue::getHighestPriority()
{
  int max = -1;
  int index = -1;
  for (int i = 0; i < rear; i++)
  {
    if (max < priority[i])
    {
      max = priority[i];
      index = i;
    }
  }
  return index;
}
void PriorityQueue::printData()
{
  for (int i = 0; i < rear; i++)
  {
    cout << data[i] << " -- " << priority[i] << endl;
  }
}
