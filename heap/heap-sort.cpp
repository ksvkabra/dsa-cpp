#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MaxHeap
{
  vector<int> heapData;
  int capacity;
  int heapSize;

public:
  MaxHeap(int cap)
  {
    capacity = cap;
    heapSize = 0;
    heapData.resize(capacity);
  }

  void insert(int);
  void deleteKey(int i);
  void maxHeapify(int, vector<int> &);
  void increaseValue(int, int);
  void heapSort(vector<int> &);
  void sort();
  int extractMax(vector<int> &);
  int parent(int i) { return (i - 1) / 2; }
  int right(int i) { return (i * 2) + 1; }
  int left(int i) { return (i * 2) + 2; }
};

void swap(int *, int *);

int main()
{
  MaxHeap heap(11);
  heap.insert(1);
  heap.insert(10);
  heap.insert(50);
  heap.insert(32);
  heap.insert(12);
  heap.insert(90);
  heap.insert(100);
  heap.insert(56);
  heap.insert(120);
  heap.insert(73);
  heap.insert(12);
  heap.sort();
  return 0;
}

void MaxHeap::insert(int item)
{
  if (heapSize == capacity)
  {
    cout << "Overflow";
  }

  int i = heapSize;
  heapData[i] = item;
  heapSize++;
  int parentIndex = parent(i);
  while (i != 0 && heapData[parentIndex] < heapData[i])
  {
    swap(&heapData[parentIndex], &heapData[i]);
    i = parentIndex;
    parentIndex = parent(i);
  }
}

void MaxHeap::deleteKey(int i)
{
  increaseValue(i, INT_MAX);
  extractMax(heapData);
}

void MaxHeap::increaseValue(int i, int value)
{
  heapData[i] = value;

  int parentIndex = parent(i);
  while (i != 0 && heapData[parentIndex] < heapData[i])
  {
    swap(&heapData[parentIndex], &heapData[i]);
    i = parentIndex;
  }
}

int MaxHeap::extractMax(vector<int> &heapData)
{
  if (heapSize <= 0)
  {
    return INT_MIN;
  }
  if (heapSize == 1)
  {
    heapSize--;
    return heapData[0];
  }

  int root = heapData[0];
  heapData[0] = heapData[heapSize - 1];
  heapSize--;
  maxHeapify(0, heapData);

  return root;
}

void MaxHeap::maxHeapify(int i, vector<int> &heapData)
{
  int l = left(i);
  int r = right(i);

  int largest = i;
  if (l < heapSize && heapData[l] > heapData[largest])
  {
    largest = l;
  }
  if (r < heapSize && heapData[r] > heapData[largest])
  {
    largest = r;
  }

  if (largest != i)
  {
    swap(&heapData[largest], &heapData[i]);
    maxHeapify(largest, heapData);
  }
}

void MaxHeap::sort()
{
  vector<int> copyOfHeap{heapData};
  cout << endl;
  for (int i = 0; i < capacity; i++)
  {
    cout << extractMax(copyOfHeap) << " ";
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}