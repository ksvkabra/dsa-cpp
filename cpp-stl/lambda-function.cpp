// using lambda functions in cpp
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

// find all the prime number

vector<int> primeNumbers(int x, int (*func)(int y))
{
  vector<int> primes(0);
  for (int i = 2; i <= x; i++)
  {
    if (func(i))
    {
      primes.push_back(i);
    }
  }
  return primes;
}

// calculate primefactors
vector<int> primeFactors(int x, bool (*func)(int x))

{
  vector<int> primes(0);
  for (int i = 1; i <= (x + 1) / 2; i++)
  {
    if (x % i == 0 && func(i))
    {
      primes.push_back(i);
    }
  }
  return primes;
}

bool checkPrime(int x)
{
  for (int i = 2; i <= sqrt(x); i++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  vector<int> result = primeNumbers(10, [](int x) {
    for (int i = 2; i <= sqrt(x); i++)
    {
      if (x % i == 0)
      {
        return 0;
      }
    }
    return 1;
  });
  for (vector<int>::iterator itr = result.begin(); itr < result.end(); ++itr)
  {
    cout << *itr << " ";
  }
  cout << endl;
  vector<int> primeValues = primeFactors(10, checkPrime);

  for (vector<int>::iterator itr = primeValues.begin(); itr < primeValues.end(); itr++)
  {
    cout << distance(primeValues.begin(), itr) << endl;
    cout << *itr << " ";
  }
  return 0;
}