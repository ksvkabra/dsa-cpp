/*
Rearrange an array such that arr[i] = i
Given an array of elements of length N, ranging from 0 to N – 1.
All elements may not be present in the array.
If element is not present then there will be -1 present in the array.
Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
*/

#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int> &, int size);
void printArray(vector<int> arr, int size);

int main()
{
  vector<int> arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
  rearrange(arr, arr.size());
  printArray(arr, arr.size());
  return 0;
}

void rearrange(vector<int> &arr, int size)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] != i && arr[i] != -1)
    {
      int x = arr[i];

      while (arr[x] != -1 && arr[x] != x)
      {
        int y = arr[x];
        arr[x] = x;
        x = y;
      }

      arr[x] = x;
      if (arr[i] != i)
      {
        arr[i] = -1;
      }
    }
  }
}

void printArray(vector<int> arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}