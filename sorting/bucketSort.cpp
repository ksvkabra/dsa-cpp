#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void bucketSort(vector<double> &arr, int size);
void printArray2d(vector<vector<double>> arr, int size);
void printArrayDouble(vector<double> arr, int size);
void printArrayInt(vector<int> arr, int size);
double findMaximum(vector<double> arr, int size);
void swap(double *x, double *y);

int main()
{
  vector<double> arr{
      0.25,
      0.36,
      0.58,
      0.41,
      0.29,
      0.22,
      0.45,
      0.79,
      0.01,
      0.69,
  };

  bucketSort(arr, arr.size());
  printArrayDouble(arr, arr.size());
  return 0;
}

void bucketSort(vector<double> &arr, int size)
{
  double maxValue = findMaximum(arr, size);
  vector<vector<double>> bucket(floor(maxValue * 10) + 1);
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 1)
    {
      bucket[0].push_back(arr[i]);
      continue;
    }
    bucket[floor(arr[i] * 10)].push_back(arr[i]);
  }

  for (int i = 0; i < bucket.size(); i++)
  {
    sort(bucket[i].begin(), bucket[i].end());
  }

  int k = 0;
  for (int i = 0; i < bucket.size(); i++)
  {
    for (int j = 0; j < bucket[i].size(); j++)
    {
      arr[k] = bucket[i][j];
      k++;
    }
  }
}
void printArray2d(vector<vector<double>> arr, int size)
{
  cout << "Elements of array";
  for (vector<double> y : arr)
  {
    for (double x : y)
    {
      cout << x << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printArrayDouble(vector<double> arr, int size)
{
  cout << "Array elements" << endl;
  for (double i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}

void printArrayInt(vector<int> arr, int size)
{
  cout << "Array elements" << endl;
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}

double findMaximum(vector<double> arr, int size)
{
  double max = 0;
  for (int i = 0; i < size; i++)
  {
    if (max < arr[i])
    {
      max = arr[i];
    }
  }
  return max;
}