#include <bits/stdc++.h>

using namespace std;

int maxInArray(int arr[], int length);

void countingSort(int arr[], int length);

void printArray(int arr[], int length);

int main()
{
  int arr[] = {2, 3, 4, 5, 3, 2, 3, 4, 5, 2, 3, 4, 5, 3, 5, 6, 3, 2, 2, 4, 5, 6, 8, 7, 6, 5, 5, 4, 4, 3, 2, 4, 5, 3, 5, 3};
  int length = sizeof(arr) / sizeof(arr[0]);
  countingSort(arr, length);
  printArray(arr, length);
  return 0;
}

void printArray(int arr[], int length)
{
  cout << "Elements of array" << endl;
  for (int i = 0; i < length; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int maxInArray(int arr[], int length)
{
  int max = 0;
  for (int i = 0; i < length; i++)
  {
    if (max < arr[i])
    {
      max = arr[i];
    }
  }
  return max;
}

void countingSort(int arr[], int length)
{
  int max = maxInArray(arr, length);
  int countOfElemetsInArray[max + 1] = {0};
  for (int i = 0; i < length; i++)
  {
    countOfElemetsInArray[arr[i]] = countOfElemetsInArray[arr[i]] + 1;
  }

  int intermediateCountArray[max + 1] = {0};
  intermediateCountArray[0] = countOfElemetsInArray[0];
  for (int i = 1; i <= max; i++)
  {
    intermediateCountArray[i] = countOfElemetsInArray[i] + intermediateCountArray[i - 1];
  }

  int result[length];
  for (int i = length - 1; i >= 0; i--)
  {
    result[intermediateCountArray[arr[i]] - 1] = arr[i];
    --intermediateCountArray[arr[i]];
  }

  for (int i = 0; i < length; i++)
  {
    arr[i] = result[i];
  }
}