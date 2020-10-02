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

using namespace std;

template <typename t, typename u>
void print(map<t, u> arr)
{
  cout << "map data" << endl;
  for (typename map<t, u>::iterator itr = arr.begin(); arr.end() != itr; ++itr)
  {
    cout << itr->first << " " << itr->second << endl;
  }
  cout << endl;
}

int main()
{
  map<int, int> value;
  for (int i = 0; i < 5; i++)
  {
    value.insert(pair<int, int>(i, i + 5));
  }
  cout << value[1] << endl;
  for (map<int, int>::iterator itr = value.begin(); value.end() != itr; itr++)
  {
    cout << itr->first << " " << itr->second << endl;
  }
  print<int, int>(value);

  cout << value.count(1) << endl;
  pair<map<int, int>::iterator, map<int, int>::iterator> it;
  it = value.equal_range(1);

  cout << it.first->first << " " << it.first->second << endl;
  cout << it.second->first << " " << it.second->second << endl;

  return 0;
}