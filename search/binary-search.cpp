#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int length);

int binarySearch(int arr[], int low, int high, int item);

int main()
{
  int arr[] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 45, 67, 78};
  int high = sizeof(arr) / sizeof(arr[0]);
  cout << binarySearch(arr, 0, 11, 4);
}

int binarySearch(int arr[], int low, int high, int item)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == item)
    {
      return mid;
    }
    else if (arr[mid] > item)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
    return binarySearch(arr, low, high, item);
  }
  else
  {
    return -1;
  }
}