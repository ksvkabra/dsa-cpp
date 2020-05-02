#include <bits/stdc++.h>

using namespace std;

class Deque
{
  vector<int> arr;

public:
  Deque()
  {
    cout << "initialised";
  }
  void insertFront(int item);
  void insertRear(int item);
  void deleteFront();
  void deleteRear();

  int getFront();
  int getRear();
  int isEmpty();
  int isFull();

  void printArray();
};

// Main function here
int main()
{
  Deque que;
  int choice;
  cout << "Enter your choice from below" << endl;
  cout << "1. Insert Rear" << endl
       << "2. Insert Front" << endl
       << "3. Delete Front" << endl
       << "4. Delete Rear" << endl
       << "5. Display" << endl
       << "6. GetRear" << endl
       << "7. GetFront" << endl
       << "8. Exit" << endl;
  do
  {
    cout << "Enter your choice" << endl;
    cin >> choice;
    int item;
    switch (choice)
    {
    case 1:
      cout << "Enter value to insert" << endl;
      cin >> item;
      que.insertRear(item);
      break;
    case 2:
      cout << "Enter value to insert" << endl;
      cin >> item;
      que.insertFront(item);
      break;
    case 3:
      que.deleteFront();
      break;
    case 4:
      que.deleteRear();
      break;
    case 5:
      que.printArray();
      break;
    case 6:
      que.getRear();
      break;
    case 7:
      que.getFront();
      break;
    case 8:
      cout << "ending" << endl;
      break;
    default:
      break;
    }
  } while (choice < 8);
  return 0;
}

// Class functions defenition
void Deque::insertFront(int item)
{
  bool fullOrNot = isFull();
  if (!fullOrNot)
  {
    arr.resize(arr.size() + 1);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[0] = item;
  }
  else
  {
    cout << "Overflow" << endl;
  }
}
void Deque::insertRear(int item)
{
  bool fullOrNot = isFull();
  if (!fullOrNot)
  {
    int previousLength = arr.size();
    arr.resize(arr.size() + 1);
    arr[arr.size() - 1] = item;
  }
  else
  {
    cout << "Overflow" << endl;
  }
}
void Deque::deleteFront()
{
  bool isEmptyOrNot = isEmpty();
  if (!isEmptyOrNot)
  {
    for (int i = 0; i < arr.size(); i++)
    {
      arr[i] = arr[i + 1];
    }
    arr.resize(arr.size() - 1);
  }
  else
  {
    cout << "Underflow" << endl;
  }
}
void Deque::deleteRear()
{
  bool isEmptyOrNot = isEmpty();
  if (!isEmptyOrNot)
  {
    arr.pop_back();
  }
  else
  {
    cout << "Underflow" << endl;
  }
}
int Deque::isEmpty()
{
  if (arr.size() < 1)
  {
    return true;
  }
  return false;
}
int Deque::isFull()
{
  if (arr.size() == 10)
  {
    return true;
  }
  return false;
}
int Deque::getFront()
{
  return arr[0];
}
int Deque::getRear()
{
  return arr[arr.size() - 1];
}

void Deque::printArray()
{
  cout << "Elements of array -- ";
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}