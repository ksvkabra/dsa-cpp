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

template <typename t>
void printPairOneD(vector<t> x)
{
  for (t i : x)
  {
    cout << i.first << " ";
    cout << i.second << endl;
  }
}

int main()
{
  pair<int, char> myFirstPair;
  myFirstPair = make_pair(1, 2);
  cout << myFirstPair.first << " ";
  cout << myFirstPair.second << endl;

  vector<pair<int, int>> arrOfPairs;

  for (int i = 0; i < 5; i++)
  {
    arrOfPairs.push_back(make_pair(i, i + 1));
  }
  printPairOneD(arrOfPairs);

  for (vector<pair<int, int>>::iterator itr = arrOfPairs.begin(); itr != arrOfPairs.end(); itr++)
  {
    cout << "value 1 " << itr->first << " "
         << "value 2 " << itr->second << endl;
  }
  return 0;
}