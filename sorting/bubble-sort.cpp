#include <bits/stdc++.h>

using namespace std;

void swap(int *, int *);

void printArray(int arr[], int);

int *bubbleSort(int *, int);

int main()
{
  int lengthOfArray;
  cout << "enter length of array" << endl;
  cin >> lengthOfArray;

  int arr[lengthOfArray];
  cout << "Enter elements of array" << endl;
  for (int i = 0; i < lengthOfArray; i++)
  {
    cin >> arr[i];
  }
  cout << endl;
  printArray(arr, lengthOfArray);

  int *sortedArray;

  sortedArray = bubbleSort(arr, lengthOfArray);
  printArray(sortedArray, lengthOfArray);
  return 0;
}

int *bubbleSort(int *arr, int length)
{
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < length - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j + 1], &arr[j]);
      }
    }
    printArray(arr, length);
  }
  return arr;
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

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
