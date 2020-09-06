#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> arr)
{
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

// a *b = lcm(a,b) * gcd (a,b);
int lcm(int a, int b)
{
  return a * b / (a > b ? gcd(a, b) : gcd(b, a));
}

int lcmOfArray(vector<int> arr)
{
  int answer = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    answer = answer * arr[i] / gcd(answer, arr[i]);
  }
  return answer;
}

int gcdOfArray(vector<int> arr)
{
  int result = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    result = gcd(result, arr[i]);
  }
  return result;
}
int main()
{
  int a = 3;
  int b = 7;
  vector<int> arr{2, 4, 5, 7};
  sort(arr.begin(), arr.end());
  printVector(arr);
  cout << gcd(a, b) << endl;
  cout << lcm(a, b) << endl;
  cout << lcmOfArray(arr) << endl;
  cout << gcdOfArray(arr) << endl;
  return 0;
}