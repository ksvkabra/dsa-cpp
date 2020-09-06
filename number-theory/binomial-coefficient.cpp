// program to return binomial coefficient of any given c(n,k)

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

using namespace std;

int binomialCoeffRecursive(int n, int k)
{
  if (k == 0 || k == n)
  {
    return 1;
  }
  int sum = binomialCoeffRecursive(n - 1, k - 1) + binomialCoeffRecursive(n - 1, k);
  return sum;
}

int binomialCoefficientDp(int n, int k)
{
  vector<vector<int>> t(n + 1, vector<int>(k + 1, -1));

  for (int i = 0; i <= k; i++)
  {
    t[0][i] = 0;
  }

  for (int i = 0; i <= n; i++)
  {
    t[i][0] = 1;
  }

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < k + 1; j++)
    {
      t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
    }
  }
  // for (vector<int> i : t)
  // {
  //   for (int j : i)
  //   {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }

  return t[n][k];
}

int binomialMemoization(int n, int k)
{
  vector<int> t(k + 1, 0);
  t[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = min(i, k); j > 0; j--)
    {
      t[j] = t[j] + t[j - 1];
    }
  }
  return t[k];
}

int main()
{
  int n = 5;
  int k = 2;
  cout << binomialCoeffRecursive(n, k) << endl;
  cout << binomialCoefficientDp(n, k) << endl;
  cout << binomialMemoization(n, k);
  return 0;
}