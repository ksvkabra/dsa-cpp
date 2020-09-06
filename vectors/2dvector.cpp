#include <iostream>
#include <vector>

using namespace std;

void printVectorOneDimensional(vector<int> arr)
{
  for (int i : arr)
  {
    cout << i << " ";
  }
  cout << endl;
}

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

  vector<int> arrNew(4);
  arrNew.resize(3);
  arrNew.insert(arrNew.begin() + 1, 4);
  printVectorOneDimensional(arrNew);
  arrNew.clear();
  printVectorOneDimensional(arrNew);
  return 0;
}