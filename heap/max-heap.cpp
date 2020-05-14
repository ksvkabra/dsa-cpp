#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
  vector<int> heapData;
  int capacity;
  int heapSize;

public:
  MaxHeap(int i)
  {
    capacity = i;
    heapSize = 0;
    heapData.resize(capacity);
  }
  void insert(int value);
  void deleteNode(int i);
  void increaseValue(int i, int value);
  void maxHeapify(int i);
  int extractMax();
  int getMax() { return heapData[0]; }
  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return (i * 2) + 1; }
  int right(int i) { return (i * 2) + 2; }
};

void swap(int *, int *);

int main()
{
  MaxHeap h(11);
  h.insert(3);
  h.insert(2);
  h.deleteNode(1);
  h.insert(15);
  h.insert(5);
  h.insert(4);
  h.insert(45);
  cout << h.getMax() << " ";
  cout << h.extractMax() << " ";
  h.increaseValue(2, 1);
  cout << h.getMax();
  return 0;
}

void MaxHeap::insert(int value)
{
  if (heapSize == capacity)
  {
    cout << "Overflow";
  }

  int i = heapSize;
  heapData[i] = value;
  heapSize++;

  while (i != 0 && heapData[parent(i)] < heapData[i])
  {
    swap(&heapData[parent(i)], &heapData[i]);
    i = parent(i);
  }
}

void MaxHeap::increaseValue(int i, int value)
{
  heapData[i] = value;

  while (i != 0 && heapData[parent(i)] < heapData[i])
  {
    swap(&heapData[parent(i)], &heapData[i]);
    i = parent(i);
  }
}

int MaxHeap::extractMax()
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
  maxHeapify(0);

  return root;
}

void MaxHeap::deleteNode(int i)
{
  increaseValue(i, INT_MAX);
  extractMax();
}

void MaxHeap::maxHeapify(int i)
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
    maxHeapify(largest);
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}