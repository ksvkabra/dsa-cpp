#include <bits/stdc++.h>

using namespace std;

int linearSearch(int arr[], int length, int item);

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = sizeof(arr) / sizeof(arr[0]);
  int elementToSearch = 4;
  int position = linearSearch(arr, length, elementToSearch);
  if (position == -1)
  {
    cout << "Item not found";
  }
  else
  {
    cout << "item found at position " << position + 1;
  }
  return 0;
}

int linearSearch(int arr[], int length, int item)
{
  for (int i = 0; i < length; i++)
  {
    if (arr[i] == item)
    {
      return i;
    }
  }
  return -1;
};
