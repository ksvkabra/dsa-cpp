#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// number of characters in ASCII
#define d 256

void rabinKarp(string, string, int);

// main function starts here
int main()
{
  int prime = 101;
  rabinKarp("ABABDABACDABABCABAB", "ABABCABABAB", prime);
  return 0;
}

void rabinKarp(string str, string pattern, int prime)
{
  int m = pattern.size();
  int n = str.size();

  int i = 0, j = 0;
  int patternHash = 0;
  int stringHash = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
  {
    h = (h * d) % prime;
  }

  // hash value of pattern
  for (i = 0; i < m; i++)
  {
    patternHash = (d * patternHash + pattern[i]) % prime;
    stringHash = (d * stringHash + str[i]) % prime;
  }

  for (i = 0; i <= n - m; i++)
  {
    if (patternHash == stringHash)
    {
      for (j = 0; j < m; j++)
      {
        if (str[i + j] != pattern[j])
          break;
      }
      if (j == m)
      {
        cout << "pattern match at position " << i << endl;
      }
    }

    // calculate hash for next value
    if (i < n - m)
    {
      stringHash = (d * (stringHash - str[i] * h) + str[i + m]) % prime;

      if (stringHash < 0)
        stringHash = stringHash + prime;
    }
  }
}
