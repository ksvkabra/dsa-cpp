#include <bits/stdc++.h>

using namespace std;

void swap(int *, int *);

void printArray(int arr[], int);

int *insertionSort(int *, int);

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

  sortedArray = insertionSort(arr, lengthOfArray);
  printArray(sortedArray, lengthOfArray);
  return 0;
}

int *insertionSort(int *arr, int length)
{
  for (int i = 0; i < length; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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
