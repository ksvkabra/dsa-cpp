#include <iostream>
#include <string>

using namespace std;

void matchPattern(string str, string p);

int main()
{
  matchPattern("AABAACAADAABAABA", "AABA");
  return 0;
}

void matchPattern(string str, string p)
{
  for (int i = 0; i < str.size(); i++)
  {
    int j = 0;
    if (str[i] == p[0])
    {
      for (j = 1; j < p.size(); j++)
      {
        if (str[i + j] != p[j])
        {
          break;
        }
      }
      if (j == p.size())
      {
        cout << "Pattern found at position " << i << endl;
      }
    }
  }
}
