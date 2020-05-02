#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> &, int);

void enqueue(vector<int> &, int, int);

void dequeue(vector<int> &, int);

int main()
{
  vector<int> arr(0);
  int length = 0;
  int choice;
  do
  {
    cout << "Enter your choice from below" << endl;
    cout << "1. Insert" << endl
         << "2. Delete" << endl
         << "3. Display" << endl
         << "4. Exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      int item;
      cout << "Enter value to insert" << endl;
      cin >> item;
      enqueue(arr, length, item);
      printArray(arr, length);
      length = length + 1;
      break;
    case 2:
      dequeue(arr, length);
      length = length - 1;
      break;
    case 3:
      printArray(arr, length);
      break;
    case 4:
      cout << "ending" << endl;
      break;
    default:
      break;
    }

  } while (choice < 4);
  return 0;
}

void enqueue(vector<int> &arr, int length, int item)
{
  arr.resize(length + 1);
  for (int i = arr.size() - 1; i >= 0; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[0] = item;
}

void dequeue(vector<int> &arr, int length)
{
  arr.pop_back();
}

void printArray(vector<int> &arr, int length)
{
  cout << "Elements of array" << endl;
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}