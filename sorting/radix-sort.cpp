#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void radixSort(vector<int> &arr, int size);
void countingSort(vector<int> &arr, vector<int> digits, int size);
int findMaxInArray(vector<int> arr, int size);
int lengthOfNumber(int number);
void printArray(vector<int> arr, int size);

int main()
{
  vector<int> arr{143, 163, 131, 141};
  printArray(arr, arr.size());

  radixSort(arr, arr.size());
  printArray(arr, arr.size());
  return 0;
}

void radixSort(vector<int> &arr, int size)
{
  int max = findMaxInArray(arr, size);
  int cycles = lengthOfNumber(max);
  for (int i = 1; i <= cycles; i++)
  {
    vector<int> oneDigits(size);
    for (int j = 0; j < size; j++)
    {
      oneDigits[j] = (arr[j] % (int)pow(10, i)) / pow(10, i - 1);
    }
    countingSort(arr, oneDigits, size);
  }
}

void countingSort(vector<int> &arr, vector<int> oneDigits, int size)
{
  int max = findMaxInArray(oneDigits, size);
  vector<int> count(max + 1);
  for (int i = 0; i < size; i++)
  {
    count[oneDigits[i]] += 1;
  }
  for (int i = 1; i < count.size(); i++)
  {
    count[i] = count[i] + count[i - 1];
  }

  vector<int> result(size);
  for (int i = size - 1; i >= 0; i--)
  {
    result[count[oneDigits[i]] - 1] = arr[i];
    count[oneDigits[i]]--;
  }
  for (int i = 0; i < size; i++)
  {
    arr[i] = result[i];
  }
}

int findMaxInArray(vector<int> arr, int size)
{
  int max = 0;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int lengthOfNumber(int number)
{
  int x = number;
  int i = 0;
  if (x == 0)
  {
    return 1;
  }
  while (x > 0)
  {
    i++;
    x = x / 10;
  }
  return i;
}
void printArray(vector<int> arr, int size)
{
  cout << "Array elements" << endl;
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}