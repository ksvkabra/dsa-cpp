#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MinHeap
{
  vector<int> heap;
  int capacity;
  int heap_size;

public:
  MinHeap(int i)
  {
    capacity = i;
    heap_size = 0;
    heap.resize(capacity);
  }
  void MinHeapify(int);
  int parent(int i) { return (i - 1) / 2; };
  int left(int i) { return (2 * i + 1); };
  int right(int i) { return (2 * i + 2); };
  int extractMin();
  void decreaseKey(int i, int new_val);

  // Returns the minimum key (key at root) from min heap
  int getMin() { return heap[0]; }

  // Deletes a key stored at index i
  void deleteKey(int i);

  // Inserts a new key 'k'
  void insertKey(int k);
};

void swap(int *, int *);

int main()
{
  MinHeap h(11);
  h.insertKey(3);
  h.insertKey(2);
  h.deleteKey(1);
  h.insertKey(15);
  h.insertKey(5);
  h.insertKey(4);
  h.insertKey(45);
  cout << h.extractMin() << " ";
  cout << h.getMin() << " ";
  h.decreaseKey(2, 1);
  cout << h.getMin();
  return 0;
}

void MinHeap::insertKey(int k)
{
  if (heap_size == capacity)
  {
    cout << "Overflow " << endl;
    return;
  }
  int i = heap_size;
  heap_size++;
  heap[i] = k;

  while (i != 0 && heap[parent(i)] > heap[i])
  {
    swap(&heap[parent(i)], &heap[i]);
    i = parent(i);
  }
}

void MinHeap::decreaseKey(int i, int new_val)
{
  heap[i] = new_val;
  while (i != 0 && heap[parent(i)] > heap[i])
  {
    swap(&heap[parent(i)], &heap[i]);
    i = parent(i);
  }
}

int MinHeap::extractMin()
{
  if (heap_size <= 0)
    return INT_MAX;
  if (heap_size == 1)
  {
    heap_size--;
    return heap[0];
  }

  // Store the minimum value, and remove it from heap
  int root = heap[0];
  heap[0] = heap[heap_size - 1];
  heap_size--;
  MinHeapify(0);

  return root;
}

void MinHeap::deleteKey(int i)
{
  decreaseKey(i, INT_MIN);
  extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && heap[l] < heap[smallest])
    smallest = l;
  if (r < heap_size && heap[r] < heap[smallest])
    smallest = r;
  if (smallest != i)
  {
    swap(&heap[i], &heap[smallest]);
    MinHeapify(smallest);
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}