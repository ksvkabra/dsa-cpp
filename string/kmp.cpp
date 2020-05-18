// Knuth Morris Pratt pattern searching algorithm

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void kmp(string str, string pattern);
void lpsArray(vector<int> &lps, string pattern);
void printArray(vector<int> arr)
{
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}

int main()
{
  kmp("ABABDABACDABABCABAB", "ABABCABAB");
  return 0;
}

void kmp(string str, string pattern)
{
  int m = pattern.size();
  int n = str.size();

  vector<int> lps(m);
  lpsArray(lps, pattern);

  int i = 0;
  int j = 0;

  while (i < n)
  {
    cout << pattern[j] << "  " << str[i] << " j  " << j << " i " << i << endl;
    if (pattern[j] == str[i])
    {
      i++;
      j++;
    }

    if (j == m)
    {
      cout << " Found pattern at position " << i - j << endl;
      j = lps[j - 1];
    }

    else if (i < n && pattern[j] != str[i])
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}

void lpsArray(vector<int> &lps, string pattern)
{
  int length = 0;
  lps[0] = 0;
  int i = 1;
  int stringLength = pattern.size();
  while (i < stringLength)
  {
    if (pattern[i] == pattern[length])
    {
      length++;
      lps[i] = length;
      i++;
    }
    else
    {
      if (length != 0)
      {
        length = lps[length - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
  printArray(lps);
}
