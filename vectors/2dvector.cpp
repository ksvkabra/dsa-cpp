#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> arr[4];

  vector<vector<int>> vect(5, vector<int>(5, 0));

  for (int i = 0; i < 4; i++)
  {
    cout << "here";
    cout << arr[i].size() << endl;
  }

  for (int i = 0; i < vect.size(); i++)
  {
    cout << i << endl;
    for (int j = 0; j < vect.size(); j++)
    {
      cout << vect[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}