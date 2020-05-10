#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr, int size);
void rotate(vector<int> &, int size, int);
void reverse(vector<int> &arr, int start, int end);
void swap(int *, int *);

int main()
{
  vector<int> arr{1, 2, 3, 4, 5, 6, 7};
  rotate(arr, arr.size(), 2);
  printArray(arr, arr.size());
  return 0;
}

void rotate(vector<int> &arr, int size, int rotations)
{
  reverse(arr, 0, rotations - 1);
  reverse(arr, rotations, size - 1);
  reverse(arr, 0, size - 1);
}

void reverse(vector<int> &arr, int start, int end)
{
  while (start < end)
  {
    swap(&arr[start], &arr[end]);
    start++;
    end--;
  }
}

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

void printArray(vector<int> arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}