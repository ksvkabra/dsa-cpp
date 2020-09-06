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

vector<int> primeFactors(int number);
void printVectorOneDimensional(vector<int>);

int main()
{
  int num = 10;
  vector<int> resultArray = primeFactors(45);
  printVectorOneDimensional(resultArray);
  return 0;
}

vector<int> primeFactors(int number)
{
  vector<int> primeFactorsList;

  if (!(number % 2))
  {
    primeFactorsList.push_back(2);
    number /= 2;
  }

  while (!(number % 2))
  {
    number /= 2;
  }
  cout << number << endl;
  for (int i = 3; i < sqrt(number); i += 2)
  {
    if (!(number % i))
    {
      primeFactorsList.push_back(i);
    }
  }

  if (number > 2)
    primeFactorsList.push_back(number);
  return primeFactorsList;
}

void printVectorOneDimensional(vector<int> arr)
{
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}