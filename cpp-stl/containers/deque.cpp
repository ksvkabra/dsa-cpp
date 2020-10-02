#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>

using namespace std;

template <typename T>
void printOneDeque(deque<T> arr)
{
  for (T i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}

int main()
{
  deque<int> arr(5);
  printOneDeque<int>(arr);

  // delete old values and assigns new values to deque
  arr.assign(5, 2);
  printOneDeque<int>(arr);

  arr.assign(6, 2);
  printOneDeque<int>(arr);

  cout << arr.back() << endl;
  cout << *arr.begin() << endl;

  // returns constant iterators to begin and end
  cout << *arr.cbegin() << endl;
  cout << *arr.cend() << endl;

  // emplace(position iterator, value) -> insertion
  arr.emplace(arr.cbegin() + 2, 5);
  cout << *arr.cbegin() << endl;

  arr.emplace_back(4);
  arr.emplace_front(4);
  printOneDeque<int>(arr);

  arr.insert(arr.begin() + 4, 10);
  printOneDeque<int>(arr);

  cout << arr.empty() << endl;

  cout << arr.max_size() << endl;
  return 0;
}