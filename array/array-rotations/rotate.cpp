
/*
Given an unsorted array arr[] of size N, rotate it by D elements (clockwise).

Input:
The first line of the input contains T denoting the number of testcases. First line of each test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

*/

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &, int, int);
void printArray(vector<int>);

int main()
{
  int T = 0;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int N, D;
    cout << "N denoting the size of the array and an integer D denoting the number size of the rotation" << endl;
    cin >> N >> D;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }

    rotate(arr, N, D);
    printArray(arr);
  }
  return 0;
}

void rotate(vector<int> &arr, int size, int rotations)
{
  vector<int> result(size);
  for (int i = 0; i < size; i++)
  {
    result[(i + size - rotations) % size] = arr[i];
  }
  for (int i = 0; i < size; i++)
  {
    arr[i] = result[i];
  }
}

void printArray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
