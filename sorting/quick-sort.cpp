#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int length);

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int arr[], int low, int high);

int randomPivot(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
  int arr[] = {6, 4, 7, 3, 8, 2, 9, 5};
  quickSort(arr, 0, 7);
  printArray(arr, 8);
  return 0;
}

int partition(int arr[], int low, int high)
{
  int i = low - 1;
  int pivot = arr[high];

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

int randomPivot(int arr[], int low, int high)
{
  srand(time(NULL));
  int random = low + rand() % (high - low);

  // Swap A[random] with A[high]
  swap(arr[random], arr[high]);

  return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = randomPivot(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
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
