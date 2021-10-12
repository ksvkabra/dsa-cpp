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

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    int low=0,mid=0;
	    int high=n-1;
	    while(mid<=high)
	    {
	        switch(arr[mid])
	        {
	            case 0:swap(arr[low++],arr[mid++]);
	                    break;
	            case 1:mid++;
	                    break;
	            case 2:swap(arr[mid],arr[high--]);
	                    break;
	        }
	    }
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;  
	}
}