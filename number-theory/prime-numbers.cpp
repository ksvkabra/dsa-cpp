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

void printVectorOneDimensional(vector<int>);
vector<int> findAllPrimes(int);
int checkIfPrime(int);

int main()
{
  vector<int> listOfPrimes = findAllPrimes(5);
  printVectorOneDimensional(listOfPrimes);
  return 0;
}

int checkIfPrime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (!(n % i))
    {
      return false;
    }
  }
  return true;
}

vector<int> findAllPrimes(int range)
{
  vector<int> primes;
  for (int i = 2; i <= range; i++)
  {
    if (checkIfPrime(i))
    {
      primes.push_back(i);
    }
  }
  return primes;
}

void printVectorOneDimensional(vector<int> arr)
{
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}