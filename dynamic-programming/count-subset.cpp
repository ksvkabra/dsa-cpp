// count number of subsets with given sum

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int countSubSets(vector<int> arr, int n, int sum) {
    vector<vector<int>>t(n+1, vector<int>(sum+1, INT_MAX));

    for (int i=0; i<sum+1; i++) {
        t[0][i] = 0;
    }

    for (int i=0; i<n+1; i++) {
        t[i][0] = 1;
    }

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<sum+1; j++) {
            if (arr[i-1] <= j) {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
                continue;
            }
            t[i][j] = t[i-1][j];
        }
    }
    for (vector<int> i: t) {
        for (int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];
}

int main() {
    vector<int> arr{ 2, 3, 5, 6, 8, 10 };
    int sum = 10;
    cout<<countSubSets(arr, 6, sum)<<endl;
    return 0;
}